/* AVISO: implementação não testada */

#include <stdlib.h>
#include <string.h> //memcpy
#include <util/linked_list.h>

typedef struct UTIL_LIST_NODE {
  void *data; /**< Ponteiro para a área de dados do nó */
  struct UTIL_LIST_NODE *next; /**< Ponteiro para o próximo nó da lista, NULL quando inexistente */
} node_t;

struct UTIL_LINKED_LIST {
  size_t memb_count; /**< Quantidade de membros atualmente armazenados pela lista */
  size_t data_size; /**< Tamanho de cada membro da lista */
  node_t *head;
  node_t *tail;
};

list_t *list_create(size_t data_size) {
  list_t *new = NULL;
  if((new = malloc(sizeof(list_t))) != NULL) {
    new->memb_count = 0;
    new->data_size = data_size;
    if((new->head = malloc(sizeof(node_t))) != NULL)
      new->tail = new->head;
    else {
      free(new);
      new = NULL;
    }
  }
  return new;
}

list_t *list_destroy(list_t *list) {

}

int list_append(list_t *list, const void *data) {
  node_t *new = NULL;
  if((new = malloc(sizeof(node_t))) != NULL) {
    if((new->data = malloc(list->data_size)) != NULL) {
      memcpy(new->data, data, list->data_size);
      list->;
      return 0;
    }
    free(new);
    return 1;
  }
  return 2;
}

int list_remove(list_t *list, const void *key) {

}
