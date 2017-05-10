/** @file buffer_manager.c
 *  @brief Implementação das estruturas e funções do gerenciador de memória.
 *
 *  Este arquivo contém as estruturas e funções que implementam o funcionamento
 *  do gerenciador de memória.
 *
 *  @author Lucas Santos Eleutério
 *  @bug Sem bugs conhecidos.
 */

#include "core/buffer_manager.h"
#include "util/debug.h"
#include <stdbool.h>

/** @var buffer_pool Ponteiro global para o diretório de páginas
 */
struct memory_frame *buffer_pool;

// TODO receber PAGE_SIZE como parametro na main
/** @def PAGE_SIZE Tamanho máximo da página em bytes
 */
#define PAGE_SIZE 4096

// TODO documentar a estrutura
/** @struct
 */
struct memory_frame {
  int blk_addr;
  int pin_cnt;
  bool is_dirty;
  void *data;
};

int bm_init(size_t bufsiz) {
  buffer_pool = malloc(bufsiz * sizeof(struct memory_frame));
  check_mem(buffer_pool);

  size_t i;
  for(i = 0; i < bufsiz; i++) {
    buffer_pool[i] = {.blk_addr = 0, .pin_cnt = 0, .is_dirty = false, .data = malloc(PAGE_SIZE)};
    check_mem(buffer_pool[i].data);
  }
  return 0;

error:
  if(buffer_pool != NULL) {
    i = 0;
    while(i < bufsiz && buffer_pool[i].data != NULL) {
      free(buffer_pool[i].data);
      i++;
    }
    free(buffer_pool);
  }
  return -1;
}
