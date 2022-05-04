#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"

struct  lista{
    int qnt;
    struct ED_LE cont[MAX];
};

Lista* cria_lista(){
    Lista *l; 
    l = (Lista*) malloc(sizeof(Lista));
    if ( l != NULL )
        l->qnt = 0;
    return l;
}

void libera_lista(Lista *l){
    free(l);
}

int lista_cheia(Lista *l){
    return (l->qnt == MAX);
}

int lista_vazia(Lista *l){
    return (l->qnt == 0);
}

int insere_lista_inicio(Lista *l, struct ED_LE elem){
    if (lista_cheia(l))
        return 0;
    for (int i = l->qnt-1; i >= 0; i--)
        l->cont[i+1] = l->cont[i];
    l->cont[0] = elem;
    l->qnt++;
    return 1;
}

int insere_lista_final(Lista *l, struct ED_LE elem){
    if (lista_cheia(l))
        return 0;
    l->cont[l->qnt] = elem;
    l->qnt++;
    return 1;
}

int insere_lista_ordenada(Lista *l, struct ED_LE elem){
    if (lista_cheia(l))
        return 0;
    int i;
    for (i = l->qnt-1; i >= 0 && l->cont[i].dado > elem.dado; i--)
        l->cont[i+1] = l->cont[i];
    l->cont[i+1] = elem;
    l->qnt++;
    return 1;
}

int remove_lista_inicio(Lista *l){
    if (lista_vazia(l))
        return 0;
    for (int i = 0; i < l->qnt-1; i++)
        l->cont[i] = l->cont[i+1];
    l->qnt--;
    return 1;
}

int remove_lista_final(Lista *l){
    if (lista_vazia(l))
        return 0;
    l->qnt--;
    return 1;
}

int remove_lista(Lista *l, struct ED_LE elem){
    if (lista_vazia(l))
        return 0;
    int i;
    for (i = 0; i < l->qnt && l->cont[i].dado != elem.dado; i++);
    if (i == l->qnt)
        return 0;
    for (int j = i; j < l->qnt-1; j++)
        l->cont[j] = l->cont[j+1];
    l->qnt--;
    return 1;
}

int consulta_lista_pos(Lista *l, int pos, struct ED_LE *elem){
    if (lista_vazia(l) || pos<0 || pos>=l->qnt)
        return 0;
    *elem = l->cont[pos];
    return 1;
}

int consulta_lista_dad(Lista *l, int dado){
    if (lista_vazia(l))
        return 0;
    for (int i = 0; i < l->qnt; i++)
        if (l->cont[i].dado == dado)
        {
            return i;
        }
    return -1;
}

void imprime_lista(Lista *l){
    if (lista_vazia(l))
        printf("Lista Vazia!\n");
    else{
        printf("Lista: ");
        for (int i = 0; i < l->qnt; i++)
            printf("[%d]", l->cont[i].dado);
        printf("\n\n");
    }
}