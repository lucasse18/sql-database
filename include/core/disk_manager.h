/** @file disk_manager.h
 *  @brief Protótipos de função do gerenciador de espaço em disco.
 *
 *  Este arquivo contém os protótipos, variáveis globais e macros
 *  usados pelo gerenciador de espaço em disco.
 *
 *  @author Lucas Santos Eleutério
 *  @bug Sem bugs conhecidos.
 */

#ifndef SQL_DATABASE_DISK_MANAGER_H
#define SQL_DATABASE_DISK_MANAGER_H

/** @var dsk_blk_id_t Definição do tipo que representa o id de um bloco.
 */
typedef int dsk_blk_id_t;

/** @brief Inicializa as estruturas de controle do banco.
 *
 *  Cria um arquivo a ser usado para armazenar o banco e inicializa as estruturas de controle
 *  utilizadas para gerenciar os blocos dentro do arquivo criado.
 *
 *  @param dbsiz Número máximo de blocos que o banco de dados poderá utilizar.
 *  @return 0 se sucesso
 *          1 se memória insuficiente para as estruturas de controle
 *          2 se espaço em disco insuficiente para armazenar o banco
 */
int dm_init(int dbsiz);

/** @brief Grava o conteúdo de um frame no disco.
 *
 *  @param data Endereço do início da área de dados do frame a ser lido.
 *  @param block Endereço do bloco no qual a gravação será efetuada.
 *  @return  0 se sucesso
 *          -1 se escrita falhou
 */
int dm_block_write(void *data, dsk_blk_id_t block);

/** @brief Copia o conteúdo de um bloco do disco para um frame.
 *
 *  @param data Endereço do início da área de dados do frame a ser (sobr)escrito.
 *  @param block Endereço do bloco a ser lido.
 *  @return  0 se sucesso
 *          -1 se leitura falhou
 */
int dm_block_read(void *out, dsk_blk_id_t block);


#endif //SQL_DATABASE_DISK_MANAGER_H
