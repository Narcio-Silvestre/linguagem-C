/*
*Author: Nárcio Silvestre
*Date: 05/04/2021
*Contact: narciosilvestre16@gmail.com
*/

/// @file stacks.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


/**
 * @brief Estrutura para guarda pilha de inteiro.
 * 
 */
typedef struct _pilha{
    int numero; ///< numero inteiro
    struct _pilha* next; ///< apontador para o proximo
    struct _pilha* last; ///< apontador para o ultimo
}Pilha;

/**
 * @brief Funcao para criar novo nodo.
 * 
 * @param[in] number
 * @param[out] nodo 
 * @return Pilha* 
 */
Pilha* new_cell(int number){
    Pilha* nodo =(Pilha*)malloc(sizeof(Pilha)); ///< Novo nodo
    assert(nodo);
    nodo->numero = number;
    nodo->last = NULL;
    nodo->next = NULL;
return nodo;
}

/**
 * @brief Funcao para adicionar um elemento a Pilha.
 * Se pilha estiver vazia retorna nodo.
 * Se pilha não estiver vazia retorna a principal.
 * com o novo nodo
 * @param[in] principal 
 * @param[in] nodo
 * @param[out] nodo
 * @param[out] principal 
 * @return Pilha* 
 */
Pilha* push_pilha(Pilha* principal,Pilha* nodo){
    if(!principal){
        return nodo;
    }
    else{
        principal->next = nodo;
        nodo->last = principal;
        principal = nodo;
        return principal;
    }
}

/**
 * @brief Funcao para remover o elemento do topo da Pilha.
 * Retorna a principal caso esteja vazio.
 * Retorna a principal sem o elemento do topo caso nao esteja vazia.
 * @param[in] principal 
 * @param[out] principal 
 * @return Pilha* 
 */

Pilha* pop_pilha(Pilha* principal){
    if(!principal){
        return principal;
    }
    else{
        Pilha* aux = principal->last;
        aux->next = NULL;
        free(principal);
        principal = aux;
        return principal;
    }
}

/**
 * @brief Funcao para mostrar o primeiro elemento da Pilha.
 * 
 * @param principal 
 */
void top_pilha(Pilha* principal){
    if(!principal){
       printf("««Pilha is empty!»»\n");
    }
    else{
        printf("First element: %d \n", principal->numero);
    }
}

/**
 * @brief Funcao para procurar de maneira recursiva um valor na pilha.
 * 
 * @param principal 
 * @param numero 
 * @return Pilha* 
 */
Pilha* search_recursiva(Pilha* principal, int numero){
    if(!principal->last || principal->numero==numero)
        return principal;
    else principal = search_recursiva(principal->last,numero);  
        return principal;  
}

/**
 * @brief Funcao para somar dois valores da pilha.
 * 
 * @param principal 
 * @param num1 
 * @param num2 
 * @return Pilha* 
 */

Pilha* soma(Pilha* principal, int num1, int num2){
    if((search_recursiva(principal,num1)->numero!=NULL) && (search_recursiva(principal,num2)->numero!=NULL))
        return push_pilha(principal,new_cell(num1+num2));
    else
        return principal;
}

/**
 * @brief Funcao para subtrair dois valores da pilha.
 * 
 * @param principal 
 * @param num1 
 * @param num2 
 * @return Pilha* 
 */

Pilha* sub(Pilha* principal, int num1, int num2){
    if((search_recursiva(principal,num1)->numero!=NULL) && (search_recursiva(principal,num2)->numero!=NULL))
        return push_pilha(principal,new_cell(num1-num2));
    else
        return principal;
}

/**
 * @brief Funcao para multiplicar dois valores da pilha.
 * 
 * @param principal 
 * @param num1 
 * @param num2 
 * @return Pilha* 
 */

Pilha* mult(Pilha* principal, int num1, int num2){
    if((search_recursiva(principal,num1)->numero!=NULL) && (search_recursiva(principal,num2)->numero!=NULL))
        return push_pilha(principal,new_cell(num1*num2));
    else
        return principal;
}

/**
 * @brief Funcao para dividir dois valores da pilha.
 * 
 * @param principal 
 * @param num1 
 * @param num2 
 * @return Pilha* 
 */

Pilha* divisao(Pilha* principal, int num1, int num2){
    if((search_recursiva(principal,num1)->numero!=NULL) && (search_recursiva(principal,num2)->numero!=NULL) && (num2 != 0))
        return push_pilha(principal,new_cell(num1/num2));
    else
        return principal;
}



/// Funcao principal 
void main(){
    Pilha *nova=NULL;
    nova=push_pilha(nova, new_cell(3));
    nova=push_pilha(nova, new_cell(6));
    nova=push_pilha(nova, new_cell(12));
    nova=push_pilha(nova, new_cell(1));
    nova=pop_pilha(nova);
    top_pilha(nova);
    top_pilha(nova=soma(nova,6,3));
    top_pilha(nova=sub(nova,6,3));
    top_pilha(nova=mult(nova,6,3));
    top_pilha(nova=divisao(nova,6,3));
    
}
