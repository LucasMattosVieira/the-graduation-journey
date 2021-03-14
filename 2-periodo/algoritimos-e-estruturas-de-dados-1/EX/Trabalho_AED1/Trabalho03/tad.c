#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct lista{
    int vet[maximo];
    int fim;
};



Lista *cria_lista(){
    Lista *p;
    p = (Lista *) malloc(sizeof(Lista));

    if(p != NULL){
        p->fim = 0; //Se p foi alocado, fim recebe 0
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



int remove_elemento_par(Lista *p){
    if(p == NULL || lista_vazia(p) == 1){
        return 0; // Falha: N�o exite elemento algum ou p n�o foi alocado
    }
    // Percorrer a lista at� achar o elemento ou acabar a lista
    int i = 0, aux = 0, j = 0, aux1 = 0, aux2 = 0;
    while(aux < p->fim && p->vet[aux] % 2 != 0){
        aux++;
    }
    //printf("\nAux: %d\n",aux);
    if(aux == p->fim){
        return 0; // N�o existe o elemento na lista
    }

    //Se existe pelo menos 1 �mpar na lista:
    // Remo��o e deslocamento dos n�meros � frente do removido
    for(i = 0; i < p->fim;){
        printf("\n\t%d\t\n",i);
        if(p->vet[i] % 2 == 0){
            //printf("\n\t%d\t\n",i);
            for(j = i; j < p->fim; j++){
                p->vet[j] = p->vet[j + 1];
            }
            p->fim--;
        }else{
            i++;
        }
    }

    return 1;
}



void imprime(Lista *p){
    int i;
    printf("Lista --> \n");
    for(i = 0; i < p->fim; i++){
        printf("%d\t", p->vet[i]);
    }
}

int maior_elemento(Lista *p, int *mai){
    int i, maior;
    if(lista_vazia(p) == 1){
        return 0;
    }
    *mai = p->vet[p->fim - 1];
    return 1;
}



int tamanho_lista(Lista *p, int *tam){
    if(p == NULL){
        return 0;
    }
    *tam = p->fim;
    return 1;
}



int verifica_igualdade(Lista *p, Lista *q){
    /*
    A fun��o verifica_igualdade retornar� 0 se p ou q
    n�o est�o alocados OU se as listas n�o s�o iguais
    */
    if(p == NULL || q == NULL){
        return 0;
    }
    int i, tam_p, tam_q;
    tamanho_lista(p, &tam_p);
    tamanho_lista(q, &tam_q);
    if(tam_p != tam_q){
        //Listas diferentes!
        return 0;
    }else{
        for(i = 0; i < p->fim; i++){//Tanto faz p->fim OU q->fim
            if(p->vet[i] != q->vet[i]){
                return 0;
            }
        }
    }
    return 1;
}



int intercala_listas(Lista *p, Lista *q, Lista **Li3){
    Lista *L3 = *Li3;
    int tam_p, tam_q, i, j, auxP, auxQ;
    tamanho_lista(p, &tam_p);
    tamanho_lista(q, &tam_q);
    if((tam_p + tam_q) > maximo){
        return 0; //A quantidade de elementos ultrapassa a suportada por uma lista
    }
    int tam_L3 = tam_p + tam_q;
    auxP = 0;
    auxQ = 0;
    for(i = 0; i < tam_L3; i++){
        if(p->vet[auxP] < q->vet[auxQ]){
            L3->vet[i] = p->vet[auxP];
            auxP++;
        }else{
            L3->vet[i] = q->vet[auxQ];
            auxQ++;
        }
    }
    L3->fim = tam_L3;
    return 1;
}
