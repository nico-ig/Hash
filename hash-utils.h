#ifndef _HASHUTILS_
#define _HASHUTILS_

#include "hash.h"

/* Funcao que dada uma chave k retorna a posicao dela na tabela h1 */
int h1(int chave, int m);

/* Funcao que dada uma chave k retorna a posicao dela na tabela h2 */
int h2(int chave, int m);

/* Funcao que retorna 1 se no nao for null e nao for um no excluido */
int ehValido(no_t *no, no_t *excluido);

/* Atualiza o indice e tabela de um no e retorna o no atualizado */
no_t *atualizaNo(no_t **no, int t, int i);

/* Funcao que cria um no para a tabela hash, em caso de sucesso retorna
   ele e em caso de falha retorna NULL */
no_t *criaNo(int chave);

#endif
