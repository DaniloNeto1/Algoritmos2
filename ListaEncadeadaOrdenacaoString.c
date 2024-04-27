//Listas encadeadas - ordenação em listas encadeadas de strings
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    char *item;
    Cell *next;
};



struct ListaE{
    Cell *head;
};


Cell* criar_celula(char key[]){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}


int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}



void inserir_primeiro(char key[], ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}


void inserir_ultimo(char key[], ListaE *l){
    Cell *aux, *novo;
    
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}


int remover(char key[], ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key)){
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);

            return 1;
        }

    }

    return 0;
}


void imprimir(ListaE *l){
    Cell *aux;
    
    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%s\n", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}


int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}

void bubblesort_recursivo(ListaE* l, int n){
    Cell *auxA;
    char *x;
    if(n==1 || l==NULL)
        return;
    else{
        for(auxA=l->head; auxA->next!=NULL; auxA=auxA->next){
            if(strcmp(auxA->item, auxA->next->item) > 0){
                x=auxA->item;
                auxA->item=auxA->next->item;
                auxA->next->item=x;
            }
        }
        bubblesort_recursivo(l, n-1);
    }
}


int main(){
    ListaE *l=criar_listaE();
    int num;
    scanf("%d", &num);
    do
    {
        char *nome=malloc(sizeof(char)*50);
        scanf("%s", nome);
        inserir_ultimo(nome, l);
        num--;
    }while(num>0);
    //selectsort2(l);
    bubblesort_recursivo(l, tamanho_LE(l));
    imprimir(l);
    liberar_LE(l);
    return 0;
}