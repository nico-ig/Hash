#include <stdlib.h>
#include <math.h>

#include "hash-utils.h"

int h1(int chave, int m)
{
  return chave % m;
}

int h2(int chave, int m)
{
  return floor( m * (chave * 0.9 - floor(chave * 0.9)) );
}

int ehValido(no_t *no, no_t *excluido)
{
  return ( no && (no != excluido) );
}

no_t *atualizaNo(no_t **no, int t, int i)
{
  (*no)->t = t;
  (*no)->indice = i;
  
  return *no;
}

no_t *criaNo(int chave)
{
  no_t *no;

  if ( ! (no = malloc(sizeof(no_t))) )
    return NULL;

  no->chave = chave;
  no->indice = -1;
  no->t = 0;

  return no;
}



