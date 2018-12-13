#include <semaphore.h>

struct fifo {
    sem_t mutex;
    sem_t vide;
    sem_t plein;
    int tete;
    int queue;
    char tableau[1000][100];
    char buffer[];
};

/*
 * Ajoute une commande à la file
 */
int enfiler(struct fifo fifo) {
    return 0;
}

