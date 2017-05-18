/** @file file_manager.h
 *  @brief Este arquivo contém os protótipos de função, variáveis globais e macros
 *  usados pelo gerenciador de arquivos.
 */

#ifndef SQL_DATABASE_FILE_MANAGER_H
#define SQL_DATABASE_FILE_MANAGER_H


/** @brief Inicializa as estruturas de controle do gerenciador de arquivos.
 *
 *  Aloca uma área de memória para armazenar o diretório de frames e inicializa os membros dessa
 *  estrutura.
 *
 *  @return  0, se sucesso.
 *          -1, se fracasso (memória insuficiente).
 */
int fm_init();

/** @brief Insere uma nova entrada (tabela) no diretório de arquivos.
 *
 *  Requisita ao gerenciador de espaço em disco a alocação de um bloco para armazenar a tabela,
 *  inicializa suas estruturas de controle a insere ao final do diretório de arquivos (lista de
 *  tabelas).
 *
 *  @param file_name String que representa o nome da tabela a ser inserida.
 *  @return  0, se sucesso.
 *           1, se memória insuficiente para as estruturas de controle.
 *           2, se espaço em disco insuficiente para armazenar a tabela.
 */
int file_dir_append(const char *file_name);

/** @brief Remove uma entrada (tabela) do diretório de arquivos.
 *
 *  Busca a tabela a ser removida no diretório de arquivos e, se a encontra, notifica o gerenciador
 *  de espaço em disco que os blocos da tabela não estão mais em uso e remove a tabela do diretório
 *  de arquivos.
 *
 *  @param file_name String que representa o nome da tabela a ser removida.
 *  @return  0, se sucesso.
 *          -1, se fracasso (tabela não encontrada).
 */
int file_dir_delete(const char *file_name);


#endif //SQL_DATABASE_FILE_MANAGER_H
