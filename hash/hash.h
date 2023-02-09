#ifndef _HASH_
#define _HASH_

typedef struct no
{
  int chave;            
  int indice;           /* Indice que ocupa na tabela t */
  int t;                /* A qual tabela pertence (t1 ou t2) */
} no_t;

/* Define duas tabelas hash de mesmo tamanho e de enderecamento aberto */
typedef struct hash
{
  no_t **t1;            
  no_t **t2;            
  no_t *excluido;       /* Endereco para o qual no excluidos apontam */
  int m;                
} hash_t;

/* Funcao que retorna uma estrutura com duas tabelas hash */
hash_t *iniciaHash(int m);

/* Funcao que insere uma chave na tabela hash e retorna a posicao dela em t1
   Caso a chave ja esteja no hash retorna a posicao em t1 ou t2 */
int incluiHash(hash_t *hash, int chave);

/* Caso exista um no com a chave em uma das tabelas hash remove ele 
   e retorna 1 em caso de sucesso e 0 caso contrario */
int removeHash(hash_t *hash, int chave);

/* Procura um no em t1 e t2 com a chave, caso esteja em t1 retorna o indice, 
   caso esteja em t2 retorna o indice + m e, caso nao encontre, retorna -1 */
int buscaHash(hash_t *hash, int chave);

/* Imprime o hash ordenado por chave */
void imprimeHash(hash_t *hash);

/* Desaloca toda a memoria utilizada pelo hash */
void encerraHash(hash_t *hash);

#endif
