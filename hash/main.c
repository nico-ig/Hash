/* 
 * Feito por Nico Ramos - GRR20210574 
 */

#include <stdio.h>

#include "hash.h"

#define M 11            /* Tamanho da tabela Hash */

int main()
{
  hash_t *hash;
  int chave;
  char op;

  if ( ! (hash = iniciaHash(M)) )
    return 0;

  while ( scanf("%c %d", &op, &chave) != EOF )
  {
    switch (op)
    {
      case 'i':
        incluiHash(hash, chave);
        break;

      case 'r':
        removeHash(hash, chave);
        break;

      case '\n':
        break;

      default:
        fprintf(stderr, "Operacao %c invalida.\n", op);
        break;
    }
  }

  imprimeHash(hash);
  encerraHash(hash); 
  return 1;
}
