/** @file buffer_manager.h
 *  @brief Este arquivo contém os protótipos de função, variáveis globais e macros
 *  usados pelo gerenciador de memória.
 */

#ifndef SQL_DATABASE_BUFFER_MANAGER_H
#define SQL_DATABASE_BUFFER_MANAGER_H


#include <stdlib.h>
#include <core/disk_manager.h>

/** @brief Inicializa as estruturas de controle do gerenciador de memória.
 *
 *  Aloca uma área de memória a ser gerenciada (buffer pool) e inicializa
 *  os frames (endereço, pin_count e dirty_bit).
 *
 *  @param bufsiz Quantidade de frames a serem alocados no buffer pool.
 *  @return  0, se sucesso.
 *          -1, se fracasso (memória insuficiente).
 */
int bm_init(size_t bufsiz);

/** @brief Requisita a presença de um bloco do disco no buffer pool.
 *
 *  Defere a transferência de um bloco do disco para um frame do buffer pool ao
 *  gerenciador de espaço em disco, caso este bloco não esteja presente na memória.
 *  Um frame é escolhido para receber o bloco de acordo com alguma política de substituição
 *  e tem seu pin_count incrementado. Se o dirty_bit do frame escolhido tiver um valor
 *  diferente de zero, seu conteúdo deve ser gravado em disco. Se não houver nenhum frame
 *  candidato à substituição (todos têm pin_count > 0), o processo é abortado.
 *
 *  @param blk_id Identificador do bloco a ser trazido para a memória.
 *  @return Endereço da área de dados do frame que contém o bloco requisitado, se sucesso.
 *          NULL, se fracasso.
 */
void *bm_get_block(disk_block_id_t blk_id);


#endif //SQL_DATABASE_BUFFER_MANAGER_H
