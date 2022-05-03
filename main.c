#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *somadorLinha(void * arg);

int count = 0;

int tamanho = 0;

int * matriz;

int main () {
    int entrada = 0;

    scanf("%d", &tamanho);

    pthread_t threads[tamanho];

    matriz = malloc((tamanho * tamanho) * sizeof(int));

    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            scanf("%d", &entrada);
            matriz[i*tamanho + j] = entrada;
        }
    }

    for (int i=0; i<tamanho; i++){
        int* pos = malloc(sizeof(int)); 
        *pos = i; 
        pthread_create(&(threads[i]), NULL, somadorLinha, pos);
    }

    for (int i = 0; i < tamanho; i++){
        pthread_join(threads[i], NULL);
    }

    printf("%d", count);
    return 0;
}

void * somadorLinha(void * arg){
        int pos = *(int*)arg;
        int somaSub = 0;

        for (int e = 0; e < tamanho; e++){
            somaSub += matriz[pos*tamanho + e];
        }

        pthread_mutex_lock(&mutex);
        count += somaSub;
        pthread_mutex_unlock(&mutex);
        free(arg);
}
    