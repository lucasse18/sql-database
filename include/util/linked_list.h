/* AVISO: implementação não testada */

#ifndef SQL_DATABASE_LINKED_LIST_H
#define SQL_DATABASE_LINKED_LIST_H


typedef UTIL_LINKED_LIST list_t;

list_t *list_create(size_t data_size);
list_t *list_destroy(list_t *list);
int list_append(list_t *list, const void *data);
int list_remove(list_t *list, const void *key);
int list_get(list_t *list, const void *key, void *dest);


#endif //SQL_DATABASE_LINKED_LIST_H
