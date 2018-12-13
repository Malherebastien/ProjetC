#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

struct fifo {
    sem_t mutex;
    sem_t vide;
    sem_t plein;
    int tete;
    int queue;
    char *tableau[N];
};

/*
 * Ajoute une commande à la file
 */
void enfiler(struct fifo fifo, char string[]) {
    if (sem_wait(fifo.plein) == -1) {
        perror("enfiler - sem_wait - fifo pleine");
        exit(EXIT_FAILURE);
    }
    if (sem_wait(fifo.mutex) == -1) {
        perror("enfiler - sem_wait - mutex");
        exit(EXIT_FAILURE);
    }

    fifo.tableau[fifo.tete] = string;
    fifo.tete = (fifo.tete + 1) % N;

    if (sem_post(fifo.mutex) == -1) {
        perror("enfiler - sem_post - mutex");
        exit(EXIT_FAILURE);
    }
    if (sem_post(fifo.vide) == -1) {
        perror("enfiler - sem_post - fifo vide");
        exit(EXIT_FAILURE);
    }
}

char * retirer(struct fifo fifo) {
    if (sem_wait(fifo.vide) == -1) {
        perror("retirer - sem_wait - fifo vide");
        exit(EXIT_FAILURE);
    }
    if (sem_wait(fifo.mutex) == -1) {
        perror("retirer - sem_wait - mutex");
        exit(EXIT_FAILURE);
    }

    char *c = fifo.tableau[fifo.queue];
    fifo.queue = (fifo.queue + 1) % N;

    if (sem_post(fifo.mutex) == -1) {
        perror("retirer - sem_post - mutex");
        exit(EXIT_FAILURE);
    }
    if (sem_post(fifo.plein) == -1) {
        perror("retirer - sem_post - fifo plein");
        exit(EXIT_FAILURE);
    }

    return c;
}

