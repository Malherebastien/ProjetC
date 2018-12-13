#include <semaphore.h>

struct fifo {
    sem_t mutex;
    sem_t vide;
    sem_t plein;
    int tete;
    int queue;
    char buffer[];
};

int enfiler(struct fifo fifo) {
    return 0;
}