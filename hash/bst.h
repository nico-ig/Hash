#ifndef _BST_
#define _BST_

#include "hash.h"

typedef struct no_bst
{
  no_t *no_hash;             /* Elemento da tabela hash */
  struct no_bst *esq, *dir;  
} no_bst;

/* Insere um no da tabela hash na bst, retorna o no inserido na bst */
no_bst *insereBST(no_bst *raiz, no_t *no);

/* Imprime a bst em ordem */
void imprimeBST(no_bst *no);

/* Libera toda a memoria utilizada pela bst */
void destroiBST(no_bst *no);

#endif
