#include <stdlib.h>
#include <stdbool.h>
#include <string.h> //memcpy
#include <util/fifo.h>

struct UTIL_FIFO {
  size_t max_memb; /**< Quantidade máxima de membros armazenáveis na fila */
  size_t memb_size; /**< Tamanho de cada membro da fila */
  size_t max_bytes; /**< Derivado de max_memb * memb_size, representa o tamanho maximo armazenável */
  size_t memb_count; /**< Quantidade de membros já armazenados na fila */
  size_t write_pointer; /**< Indica onde a escrita será efetuada */
  size_t read_pointer; /**< Indica onde a leitura será efetuada */
  void *data;
};

fifo_t *fifo_create(size_t nmemb, size_t memb_size) {
  fifo_t *new = NULL;
  if(nmemb > 0 && memb_size > 0) {
    if((new = malloc(sizeof(struct _FIFO))) != NULL) {
      if((new->data = malloc(nmemb)) != NULL) {
        new->max_memb = nmemb;
        new->memb_size = memb_size;
        new->max_bytes = nmemb * memb_size;
        new->memb_count = 0;
        new->write_pointer = 0;
        new->read_pointer = 0;
      } else {
        free(new);
        new = NULL;
      }
    }
  }
  return new;
}

fifo_t *fifo_destroy(fifo_t *fifo) {
  if(fifo != NULL) {
    if(fifo->data != NULL)
      free(fifo->data);
    free(fifo);
  }
  return NULL;
}

//not part of the API, doesn't check for NULL
bool fifo_isFull(fifo_t *fifo) {
  if(fifo->memb_count < fifo->max_memb)
    return false;
  return true;
}

//not part of the API, doesn't check for NULL
bool fifo_isEmpty(fifo_t *fifo) {
  if(fifo->memb_count > 0)
    return true;
  return false;
}

size_t fifo_size(fifo_t *fifo) {
  return fifo->memb_count;
}

int fifo_append(fifo_t *fifo, const void *data) {
  if(fifo != NULL) {
    if (!fifo_isFull(fifo)) {
      memcpy(fifo->data + fifo->write_pointer, data, fifo->memb_size);
      fifo->write_pointer = (fifo->write_pointer + fifo->memb_size) % fifo->max_bytes;
      fifo->memb_count++;
      return 0;
    }
    return 1;
  }
  return 2;
}

int fifo_get(fifo_t *fifo, void *dest) {
  if(fifo != NULL) {
    if (!fifo_isEmpty(fifo)) {
      memcpy(dest, fifo->data + fifo->read_pointer, fifo->memb_size);
      fifo->read_pointer = (fifo->read_pointer + fifo->memb_size) % fifo->max_bytes;
      fifo->memb_count--;
      return 0;
    }
    return 1;
  }
  return 2;
}
