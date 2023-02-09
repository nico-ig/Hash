#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "hash.h"
#include "hash-utils.h"
#include "bst.h"

hash_t *iniciaHash(int m)
{
  hash_t *hash;

  //Aloca espaço para os ponteiros para t1, t2, excluido e m
  if ( ! (hash = malloc((sizeof(no_t**) * 2) + (sizeof(no_t*)) + sizeof(int))) )
    return NULL;

  /* Aloca t1 */
  if ( ! (hash->t1 = malloc(sizeof(no_t*) * m)) )
    return NULL;

  /* Aloca t2 */
  if ( ! (hash->t2 = malloc(sizeof(no_t*) * m)) )
    return NULL;

  /* Inicia as tabelas */
  for ( int i = 0; i < m; i++ )
  {
    hash->t1[i] = NULL;
    hash->t2[i] = NULL;
  }

  hash->m = m;
  hash->excluido = malloc(0);
  return hash;
}

int incluiHash(hash_t *hash, int chave)
{
  no_t *no, **no1, **no2;
  int i, j, m, b;
  
  b = buscaHash(hash, chave);

  /* A chave ja esta no hash, retorna a posica dela em t1 ou t2 */
  if ( b != -1 )
    return b;

  /* Erro ao alocar o no */
  if ( ! (no = criaNo(chave)) )
    return -1;

  m = hash->m;
  i = h1(chave, m);
  no1 = &(hash->t1[i]);
  
  /* Ja existe uma chave valida */
  if ( ehValido(*no1, hash->excluido) )
  {
    /* Calcula a posicao em t2 da chave que estava em t1 */
    j = h2((*no1)->chave, m);
    no2 = &(hash->t2[j]);

    /* Move a chave que estava em T1 para T2 */
    *no2 = atualizaNo(no1, 2, j);
  }

  /* Insere a nova chave em T1 */
  *no1 = atualizaNo(&no, 1, i);

  /* Retorna o indice da chave em T1 */
  return i;
}

int buscaHash(hash_t *hash, int chave)
{
  int i = h1(chave, hash->m);
  int j = h2(chave, hash->m);

  no_t *no1 = hash->t1[i];
  no_t *no2 = hash->t2[j];

  /* t1 tem uma chave, ela nao foi excluida e eh igual a chave procurada */
  if ( ehValido(no1, hash->excluido) && (no1->chave == chave) )
   return i;

  /* t2 tem uma chave, ela nao foi excluida e eh igual a chave procurada */
  if ( ehValido(no2, hash->excluido) && (no2->chave == chave) )
    return j + hash->m;

  /* A chave nao esta nem em t1 nem em t2 */
  return -1;
}

int removeHash(hash_t *hash, int chave)
{
  int i = buscaHash(hash, chave);

  /* A chave nao esta no hash */
  if ( i == -1 )
    return 0;

  /* A chave esta em t1 */
  if ( i < hash->m )
  {
    /* Libera o no e marca como excluido */
    free(hash->t1[i]);
    hash->t1[i] = hash->excluido;
  } 

  /* A chave esta em t2 */
  else
  {
    /* Acerta o indice */
    i = i - hash->m;

    /* Libera o no e marca como excluido */
    free(hash->t2[i]);
    hash->t2[i] = hash->excluido;  
  }

  return 1;
}

void imprimeHash(hash_t *hash)
{
  no_t *no1, *no2;
  no_bst *T = NULL;

  /* Insere os nos validos na bst */
  for ( int i = 0; i < hash->m; i++)
  {
    no1 = hash->t1[i];
    no2 = hash->t2[i];

    if ( ehValido(no1, hash->excluido) )
      T = insereBST(T, no1);

    if ( ehValido(no2, hash->excluido) )
      T = insereBST(T, no2);
 }

  imprimeBST(T);
  destroiBST(T);
}

void encerraHash(hash_t *hash)
{
  no_t *no1, *no2;

  /* Libera todos os nos */
  for ( int i = 0; i < hash->m; i++ )
  {
    no1 = hash->t1[i];
    no2 = hash->t2[i];

    if ( ehValido(no1, hash->excluido) )
      free(no1);

    if ( ehValido(no2, hash->excluido) )
      free(no2);
  }

  /* Libera as duas tabelas e o hash */
  free(hash->t1);
  free(hash->t2);
  free(hash->excluido);
  free(hash);
}
