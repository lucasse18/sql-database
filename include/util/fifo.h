#ifndef UTIL_FIFO_H
#define UTIL_FIFO_H


//FIXME works as expected when storing ints but valgrind throws some shady errors

#include <stdlib.h>

typedef struct UTIL_FIFO fifo_t;

fifo_t *fifo_create(size_t nmemb, size_t memb_size);
fifo_t *fifo_destroy(fifo_t *fifo);
size_t fifo_size(fifo_t *fifo);
int fifo_append(fifo_t *fifo, const void *data);
int fifo_get(fifo_t *fifo, void *dest);


#endif //UTIL_FIFO_H
