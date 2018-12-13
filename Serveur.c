#include <stdio.h>
#include <sys/stat.h>
#include <semaphore.h>

#define NOM_SHM "/mon_shm_8200200" //Si tu veux savoir si tu peux prendre ta voiture, envoie HALEINE, au 8200200

#define N 10

#define TAILLE_SHM (sizeof(struct fifo) + N)

int main() {
    int shm_fd = shm_open(NOM_SHM, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if (shm_fd == -1) {
        perror("Serveur - shm_open");
        exit(EXIT_SUCCESS);
    }

    if (shm_unlink(NOM_SHM) == -1) {
        perror("Serveur - shm_unlink");

    }
}