/** @file file_manager.c
 *  @brief Este arquivo contém as estruturas e funções que implementam o funcionamento
 *  do gerenciador de arquivos.
 */

#include <stdlib.h>
#include <core/file_manager.h>
#include <core/disk_manager.h>
#include <util/debug.h>

/** @var page_size
 *  @brief Declaração da variável que representa o tamanho máximo da página em bytes.
 */
extern size_t page_size;

typedef struct PAGE {

} page_t;

/** @struct DISK_BLOCK
 *  @brief Estrutura que representa um bloco do disco.
 */
typedef struct DISK_BLOCK {
  disk_block_id_t block_id; /**< Identificador do bloco */
  u_int16_t free; /**< Espaço livre no bloco */
} block_t;

/** @struct BLOCK_DIR_ENTRY
 *  @brief Estrutura que representa uma entrada no diretório de blocos.
 */
typedef struct BLOCK_DIR_ENTRY {
  block_t *blocks; /**< Blocos da tabela (tamanho [page_size - sizeof(blocks) - sizeof(blocks->free)]). */
  struct BLOCK_DIR_ENTRY *next; /**< Ponteiro para a próxima entrada do diretório de blocos. */
} block_dir_entry_t;

/** @struct BLOCK_DIR
 *  @brief Estrutura que representa o diretório de blocos.
 */
typedef struct BLOCK_DIR {
  block_dir_entry_t *head; /**< Referência para o primeiro elemento do diretório. */
  block_dir_entry_t *tail; /**< Referencia para o ultimo elemento do diretório para insersão O(1). */
  size_t n_members; /**< Número de elementos no diretório de blocos. */
} block_dir_t;

/** @struct FILE_DIR
 *  @brief Estrutura que representa o diretório de arquivos (lista de tabelas).
 */
typedef struct FILE_DIR {
  char *file_name; /**< Nome da tabela. */
  block_dir_t *file_blocks; /**< Diretório de blocos com os endereços dos blocos da tabela. */
  struct FILE_DIR *next; /**< Ponteiro para a próxima entrada do diretório de arquivos. */
} file_dir_t;

/** @var file_dir
 *  @brief Ponteiro global para o diretório de arquivos.
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
 *  @return  0, se sucesso.
 *          -1, se fracasso (memória insuficiente).
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

/** @brief Salva em disco o conteúdo dos diretórios de arquivos e de blocos.
 *  @return  0, se sucesso.
 *          -1, se fracasso (escrita falhou).
 */
int fm_sync() {

}

/** @brief Busca por um bloco com um dado espaço livre em uma tabela.
 *  @param file_name Tabela onde a busca é efetuada.
 *  @param size Quantidade de bytes livres buscada.
 *  @return Endereço do bloco que atende às condições, se encontrado.
 *          0, se nenhum bloco que atenda às condições foi encontrado.
 */
disk_block_id_t block_search_free(char *file_name, size_t size);
