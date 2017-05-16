/* AVISO: implementação não testada */
/* TODO reescrever fifo para fazer uso da estrutura de listas definida em linked_list.h */

#ifndef UTIL_FIFO_H
#define UTIL_FIFO_H


#include <stdlib.h>

typedef struct UTIL_FIFO fifo_t;

fifo_t *fifo_create(size_t nmemb, size_t memb_size);
fifo_t *fifo_destroy(fifo_t *fifo);
size_t fifo_size(fifo_t *fifo);
int fifo_append(fifo_t *fifo, const void *data);
int fifo_get(fifo_t *fifo, void *dest);


#endif //UTIL_FIFO_H
