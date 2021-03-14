
#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct dados{
    int vet[maximo];
    int fim;
};

Lista *inicializar_lista(){
    Lista *p;
    p = (Lista *) malloc(sizeof(Lista));

    if(p != NULL){
        p->fim = 0;
    }

    return p;
}

int lista_vazia(Lista *p){
    if(p->fim == 0){
        return 1; //Lista vazia
    }else{
        return 0; //Lista N�O vazia
    }
}

int lista_cheia(Lista *p){
    if(p->fim == maximo){
        return 1; //Lista Cheia
    }else{
        return 0; //Lista N�O cheia
    }
}

int insere_ord(Lista *p, int num){
    /*
    - Lista est� cheia;
    - Lista est� vazia;
    - Novo elemento menor que o primeiro n� da lista;
    - Novo elemento maior ou igual ao �ltimo n� da lista;
    - Novo elemento entre o 1� e o �ltimo n� da lista;
    */

    //Para lista cheia
    if(p == NULL || lista_cheia(p) == 1){
        return 0;
    }

    //Para lista vazia ou elemento >= �ltimo da lista
    if(lista_vazia(p) == 1 || num >= p->vet[p->fim-1]){
        p->vet[p->fim] = num; //Insere o elemento
    }else{
        //Para todas as outras situa��es
        int i, aux = 0;
        while(num >= p->vet[aux]){
            aux++;
        }
        for(i = p->fim; aux < i; i--){
            p->vet[i] = p->vet[i-1];
        }
        p->vet[aux] = num;
    }
    p->fim++;
    return 1;
}



int remove_ord(Lista *p, int n){
    /*
    - Lista pode estar vazia;
    - Elemento n�o est� na lista;
    - Elemento � o �ltimo n� da lista;
    - Elemento est� entre o 1� e o pen�ltimo n� da lista.
    */
    if(p == NULL || lista_vazia(p) == 1 || n < p->vet[0] || n > p->vet[p->fim - 1]){
        return 0; // Falha
    }
    // Percorrer a lista at� achar o elemento ou acabar a lista
    int i = 0, aux = 0;
    while(aux < p->fim && p->vet[aux] < n){
        aux++;
    }
    if(aux == p->fim || p->vet[aux] > n){ //N�o existe elemento
        return 0; // N�o existe o elemento na lista
    }
    // Remo��o e deslocamento dos n�meros � frente do removido
    for(i = aux; i < p->fim; i++){
        p->vet[i] = p->vet[i+1];
    }
    p->fim--;
    return 1;
}

void imprime(Lista *p){
    int i;
    printf("Lista --> \n");
    for(i = 0; i < p->fim; i++){
        printf("%d\t", p->vet[i]);
    }
}

int menor_elemento(Lista *p, int *men){
    if(lista_vazia(p) == 1){
        return 0;
    }
    *men = p->vet[0];
    return 1;
}



int tamanho_lista(Lista *p, int *tam){
    if(p == NULL){
        return 0;
    }
    *tam = p->fim;
    return 1;
}
