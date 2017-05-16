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

extern size_t page_size;

typedef struct BLOCK_DIR {
  disk_block_id_t *blocks;
  struct BLOCK_DIR *next;
} block_dir_t;

typedef struct FILE_DIR {
  char *file_name;
  block_dir_t *file_blocks;
} file_dir_t;


