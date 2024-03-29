/*=======================================================================*/
/*           Trabalho de AED II - Indice remissivo com árvores           */
/* Nome: Arthur Alexsander Martins Teodoro                               */
/* MAtrícula: 0022427         Data: 23/11/2016                           */
/*=======================================================================*/

/*=======================================================================*/
/*                        BIBLIOTECAS USADAS                             */
/*=======================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "listadup.h"
#include "arvoreBin.h"

/*=======================================================================*/
/*                         ESTRUTURA CRIADA                              */
/*=======================================================================*/
struct no
{
  char plv[33];
  Lista ocorrencias;
  struct no *esq;
  struct no *dir;
};

/*=======================================================================*/
/*CRIA ARVORE BINARIA VAZIA - FUNCAO QUE CRIA ARVORE VAZIA               */
/*IN: VOID   OUT: PONTEIRO PARA ARVORE VAZIA                             */
/*=======================================================================*/
ArvBin criaArvBinVazia(void)
{
  return NULL;
}

/*=======================================================================*/
/*INSERE ARVORE BINARIA - FUNCAO QUE INSERE ELEMENTO NA ARVORE           */
/*IN: RAIZ, PALAVRA   OUT: PONTEIRO PARA ARVORE                          */
/*=======================================================================*/
ArvBin insereArvBin(ArvBin arv, char* palavra)
{
  
  if(arv == NULL)
  {
    arv = (ArvBin) malloc(sizeof(struct no));
    strcpy(arv->plv, palavra);
    arv->ocorrencias = criaLista();
    arv->esq = arv->dir = NULL;
    return arv;
  }
  else if(strcmp(palavra, arv->plv) < 0)
  {
    arv->esq = insereArvBin(arv->esq, palavra);
  }
  else
  {
    arv->dir = insereArvBin(arv->dir, palavra);
  }
  return arv;
}

/*=======================================================================*/
/*BUSCA ARVORE BINARIA - FUNCAO QUE BUSCA UM ELEMENTO NA ARVORE          */
/*IN: RAIZ, PALAVRA   OUT: PONTEIRO PARA ARVORE                          */
/*=======================================================================*/
ArvBin buscaArvBin(ArvBin raiz, char* palavra)
{
  if(raiz == NULL)
    return NULL;

  if(strcmp(raiz->plv, palavra) > 0)
    return buscaArvBin(raiz->esq, palavra);

  if(strcmp(raiz->plv, palavra) < 0)
    return buscaArvBin(raiz->dir, palavra);

  return raiz;
}

/*=======================================================================*/
/*DESTROI ARVORE BINARIA - FUNCAO QUE DESTROI A ARVORE                   */
/*IN: RAIZ   OUT: PONTEIRO NULO                                          */
/*=======================================================================*/
void destroiArvBin(ArvBin raiz)
{

  if(raiz != NULL)
  {
    destroiArvBin(raiz->esq);
    destroiArvBin(raiz->dir);
    destroiLista(raiz->ocorrencias);
    free(raiz);
    raiz = NULL;
  }
}

/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ   OUT: VOID                                                   */
/*=======================================================================*/
void insereOcorrenciaArvBin(ArvBin raiz, char* palavra, int linha)
{

  ArvBin inserir = buscaArvBin(raiz, palavra);
  if(inserir != NULL)
  {
    if(!existeLista(inserir->ocorrencias, linha))
      insereLista(inserir->ocorrencias, tamanhoLista(inserir->ocorrencias), linha);
  }

}

/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ   OUT: PALAVRA                                                */
/*=======================================================================*/
char* retornaPalavraArvBin(ArvBin raiz)
{
  return raiz->plv;
}

/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ   OUT: LISTA DO NO                                            */
/*=======================================================================*/
Lista retornaListaArvBin(ArvBin raiz)
{
  return raiz->ocorrencias;
}


/*=======================================================================*/
/*INSERE OCORRENCIA ARVORE BINARIA - FUNCAO INSERE PAGINA NA ARVORE      */
/*IN: RAIZ, VETOR DESTINO   OUT: VOID                                    */
/*=======================================================================*/
void caminhaInOrdemArvBin(ArvBin raiz, char* vetor)
{
  if(raiz != NULL)
  {
    char string[500];

    caminhaInOrdemArvBin(raiz->esq, vetor);
    sprintf(string, "%s ", raiz->plv);
    strcat(vetor, string);
    caminhaInOrdemArvBin(raiz->dir, vetor);
  }
}