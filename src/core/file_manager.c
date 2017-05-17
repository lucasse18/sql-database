/** @file file_manager.c
 *  @brief Implementação das estruturas e funções do gerenciador de arquivos.
 *
 *  Este arquivo contém as estruturas e funções que implementam o funcionamento
 *  do gerenciador de arquivos.
 *
 *  @author Lucas Santos Eleutério
 */

#include <stdlib.h>
#include <core/file_manager.h>
#include <core/disk_manager.h>
#include <util/debug.h>

/** @var page_size Declaração da variável que representa o tamanho máximo da página em bytes.
 */
extern size_t page_size;

/** @struct BLOCK_DIR_ENTRY Estrutura que representa uma entrada no diretório de blocos.
 */
typedef struct BLOCK_DIR_ENTRY {
  disk_block_id_t *blocks; /**< Vetor de blocos desta entrada (tamanho [page_size - sizeof(next)]). */
  struct BLOCK_DIR_ENTRY *next; /**< Ponteiro para a próxima entrada do diretório de blocos. */
} block_dir_entry_t;

/** @struct BLOCK_DIR Estrutura que representa o diretório de blocos.
 */
typedef struct BLOCK_DIR {
  block_dir_entry_t *head; /**< Referência para o primeiro elemento do diretório. */
  block_dir_entry_t *tail; /**< Referencia para o ultimo elemento do diretório para insersão O(1). */
  size_t n_members; /**< Número de elementos no diretório de blocos. */
} block_dir_t;

/** @struct FILE_DIR Estrutura que representa o diretório de arquivos (lista de tabelas).
 */
typedef struct FILE_DIR {
  char *file_name; /**< Nome da tabela */
  block_dir_t *file_blocks; /**< Diretório de blocos com os endereços dos blocos onde a tabela é armazenada. */
  struct FILE_DIR *next; /**< Ponteiro para a próxima entrada do diretório de arquivos. */
} file_dir_t;

/** @var file_dir Ponteiro global para o diretório de arquivos.
 */
file_dir_t *file_dir = NULL;

/* Documentada em core/file_manager.h */
int fm_init() {
  check_mem(file_dir = malloc(sizeof(file_dir_t)));
  file_dir->file_name = NULL;
  file_dir->file_blocks = NULL;
  file_dir->next = NULL;
  return 0;

  error:
  return -1;
}

/** @brief Insere uma nova entrada ao final do diretorio de blocos.
 *  @return  0 se sucesso.
 *          -1 se fracasso (memória insuficiente).
 */
int block_dir_append() {

}

/* Documentada em core/file_manager.h */
int file_dir_append(const char *file_name) {

}

/** @brief Busca uma tabela no diretório de arquivos.
 *  @return Endereço da tabela, se sucesso.
 *          NULL, se fracasso.
 */
file_dir_t *file_dir_search();

/** @brief Salva em disco o conteúdo dos diretórios de arquivos e de blocos
 *  @return  0 se sucesso.
 *          -1 se fracasso (escrita falhou).
 */
int fm_sync() {

}
