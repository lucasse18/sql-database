/** @file buffer_manager.c
 *  @brief Implementação das estruturas e funções do gerenciador de memória.
 *
 *  Este arquivo contém as estruturas e funções que implementam o funcionamento
 *  do gerenciador de memória.
 *
 *  @author Lucas Santos Eleutério
 */

#include <stdbool.h>
#include <core/buffer_manager.h>
#include <util/debug.h>
#include <util/fifo.h>

/** @var page_size Declaração da variável que representa o tamanho máximo da página em bytes.
 */
extern size_t page_size;

/** @struct FRAME_DIR_ENTRY Estrutura que representa uma entrada no diretório de frames.
 */
typedef struct FRAME_DIR_ENTRY {
  size_t blk_addr;  /**< Endereço do bloco representado pelo frame */
  size_t pin_cnt;   /**< Número de requisições ativas do frame */
  bool is_dirty; /**< true se o frame foi modificado */
} frame_t;

/** @var buffer_pool Ponteiro global para as páginas gerenciadas pelo buffer pool. Cada frame é
 *  acessado por meio de seu índice no diretório. Exemplo para obter o endereço do i-ésimo frame:
 *  @code void *endereco_frame_i = buffer_pool + (i * page_size);
 */
void *buffer_pool = NULL;
/* TODO usar vetor dinâmico para buffer_pool */

/** @var frame_dir Ponteiro global para o diretório de frames.
 */
frame_t *frame_dir = NULL;

/** @var unused_frames Ponteiro global para a fila de frames com pin_count = 0
 */
fifo_t *unused_frames = NULL;

/** @brief Aplica uma política de substituição e seleciona um frame para ser substituído.

 *  @return Endereço do frame selecionado se sucesso.
 *          NULL se fracasso (nenhum frame candidato a substituição).
 */
frame_t *bm_replace();

/** @brief Solicita a escrita do frame selecionado para substituição no disco.
 *
 *  Quando um frame selecionado para ser substituído tem seu campo "is_dirty" igual a true, esta
 *  função é chamada para escrever seu conteúdo no disco antes da substituição.
 *
 *  @param frame Frame a ser escrito.
 *  @return  0 se sucesso.
 *          -1 se fracasso (escrita falhou).
 */
int bm_writeout(frame_t *frame);

/* Documentada em core/buffer_manager.h */
int bm_init(size_t bufsiz) {
  check_mem(buffer_pool = malloc(bufsiz * page_size));
  check_mem(frame_dir = malloc(bufsiz * sizeof(struct frame_dir_entry)));

  unused_frames = fifo_create(bufsiz, sizeof(frame_t *));
  check(unused_frames, "Error trying to allocate unused frames fifo.");

  for(size_t i = 0; i < bufsiz; i++) {
    frame_dir[i] = (frame_t){.blk_addr = 0, .pin_cnt = 0, .is_dirty = false};
    fifo_append(unused_frames, (const void *)&frame_dir[i]);
  }
  return 0;

error:
  if(buffer_pool != NULL)
    free(buffer_pool);

  if(frame_dir != NULL)
    free(frame_dir);

  if(unused_frames != NULL)
    unused_frames = fifo_destroy(unused_frames);

  return -1;
}

/* Documentada em core/buffer_manager.h */
void *bm_get_block(disk_block_id_t blk_id) {

}

