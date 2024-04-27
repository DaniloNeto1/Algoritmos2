//Pilhas encadeadas - balanço de parênteses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct PilhaE PilhaE;

struct Cell{
    int item;
    Cell *next;
};


struct PilhaE{
    Cell *topo;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


void empilhar(int key, PilhaE *p){
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}


int desempilhar(PilhaE *p){
    Cell *aux;
    int item = ' ';

    if (!pilhaE_vazia(p)){
        aux = p->topo;
        
        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}


void imprimir_pilha(PilhaE *p){
    Cell *aux;

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%d\n", aux->item);

            aux = aux->next;
        }
    }
}


int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

void parentese(char vet[]){
     PilhaE *p=criar_pilhaE();
     int i, x=strlen(vet);

     if(vet[0]==')')
         printf("incorrect\n");
     else{
         for(i=0; i<x; i++){
             switch(vet[i]){
                 case '(':
                    empilhar(vet[i], p);
                    break;
                     
                 case ')':
                     if(pilhaE_vazia(p))
                         empilhar(vet[i], p);
                     else
                         desempilhar(p);
                    break;
             }
         }
         if(pilhaE_vazia(p))
             printf("correct\n");
         else
             printf("incorrect\n");
     }
}

int main (){
    int num, i;
    char key[100];
    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%s", key);
        parentese(key);
    }
    return 0;
}