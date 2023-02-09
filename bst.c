#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

/* Cria um no e retorna ele em caso de sucesso ou NULL caso contrario */
no_bst *criaNoBST(no_t *no_hash)
{
  no_bst *no;
  
  if ( ! (no = malloc(sizeof(no_bst))) )
    return NULL;

  no->no_hash = no_hash;
  no->esq = NULL;
  no->dir = NULL;

  return no;
}

no_bst *insereBST(no_bst *no, no_t *no_hash)
{
  if ( !no )
    return criaNoBST(no_hash);

  if ( no_hash->chave < no->no_hash->chave )
    no->esq = insereBST(no->esq, no_hash);

  else if ( no_hash->chave > no->no_hash->chave )
    no->dir = insereBST(no->dir, no_hash);

  return no;
}

void imprimeBST(no_bst *no)
{
  if ( !no )
    return;

  /* No do hash */
  no_t *no_h = no->no_hash;

  imprimeBST(no->esq);
  
  printf("%d,T%d,%d\n", no_h->chave, no_h->t, no_h->indice);

  imprimeBST(no->dir);
}

void destroiBST(no_bst *no)
{
  if ( !no )
    return;

  destroiBST(no->esq);
  destroiBST(no->dir);
  free(no);
}
