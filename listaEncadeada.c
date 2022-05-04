#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} node;


node *start_node() {
    return NULL;
}

void add_node(node **n,int number){
    node *aux = (node*) malloc(sizeof(node));
    aux->number = number;
    aux->next = *n;
    *n = aux;
}

void add_last_node(node **n,int number){
    if (*n != NULL) return add_last_node(&(*n)->next, number);
    add_node(n,number);
}

int add_index_node(node **n, int number, int index){
    if (*n == NULL && index !=0) return 0; // caso o index não existir
    if (index != 0) return add_index_node(&(*n)->next,number,index -1);
    add_node(n,number);
    return 1;
}

void print_nodes(node *n){
    if (n == NULL){
        printf("Lista Vazia\n");
        return;
    }
    for (; n != NULL; n = n->next){
        printf("%d ",n->number);
    }
    printf("\n");
}

int del_first_node(node **n){
    if (*n == NULL)
        return 0;
    node *temp = *n;
    *n = (*n)->next;
    free(temp);
    return 1;
}

void free_nodes(node **n){
    if (*n == NULL)
        return;
    free_nodes(&(*n)->next);
    free(*n);
    *n = NULL;
}



int main(int argc, char const *argv[]){
    node* l = start_node();
    add_index_node(&l,100,0);
    add_index_node(&l,200,0);
    add_index_node(&l,300,0);
    add_index_node(&l,400,0);
    add_index_node(&l,500,4);
    print_nodes(l);
    free_nodes(&l);
    return 0;
}
