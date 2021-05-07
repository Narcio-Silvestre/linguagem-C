#include "estruturas.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#pragma region ESTRUTURAS DOS PARTS
#pragma region FUNCOES E PPROCEDIMENTOS
//criar nodo da estrutura parts
Parts* new_cell_Parts(const char* PartNumber,const char* name ,const char* class,  int stock){
  Parts* aux = (Parts*) malloc(sizeof(Parts));
  assert(aux);
  aux->part_num = strdup(PartNumber);
  aux->name = strdup(name);
  aux->classe = strdup(class);
  aux->stock = stock;
  aux->next = NULL;
  return aux;
}

//insercao a cabeca da estrutura parts
Parts* head_Insert_Parts(Parts* Lista, Parts* cell){ 
  if(!Lista) return cell;
  cell->next = Lista;
  return cell;
}

//listar a estrutura parts
void Listar_Parts(Parts* Lista){
  while (Lista){
    printf("\n  %s  %s  %s  %d",Lista->part_num,Lista->name, Lista->classe,Lista->stock);
    Lista = Lista->next;
  }
}

//remover da estrutura parts
Parts* remove_parts(Parts* Lista){
  Parts *prox = NULL;
  while(Lista){
    prox = Lista->next;
    free(Lista->classe);
    free(Lista->name);
    free(Lista->part_num);
    free(Lista);
    Lista = prox;
  }
  return Lista;
}

#pragma endregion
#pragma endregion

#pragma region ESTRUTURAS DOS SETS
#pragma region FUNCOES E PROCEDIMENTOS
//novo nodo da estrutura sets
Sets* new_cell_Sets(const char* setNumber,const char* name,const char*theme, int year){
  Sets* aux = (Sets*) malloc(sizeof(Sets));
  assert(aux);
  aux->name = strdup(name); 
  aux->set_num = strdup(setNumber);
  aux->theme = strdup(theme);
  aux->year = year;
  aux->next = NULL;
  return aux;
}

//insercao a cabeca da estrutura sets
Sets* head_Insert_Sets(Sets* Lista, Sets* cell){ 
  if(!Lista) return cell;
  cell->next = Lista;
  return cell;
}

//listar a estrutura sets
void Listar_Sets(Sets* Lista){
  while (Lista){
    printf("\n %s  %s  %d  %s",Lista->set_num,Lista->name, Lista->year,Lista->theme);
    Lista = Lista->next;
  }
}

//destruir a estrutura sets
Sets* remove_Sets(Sets* Lista){
  Sets *prox = NULL;
  while(Lista){
    prox = Lista->next;
    free(Lista->name);
    free(Lista->set_num);
    free(Lista->theme);
    free(Lista);
    Lista = prox;
  }
  return Lista;
}

#pragma endregion


#pragma endregion

#pragma region ESTRUTURAS DOS PARTSETS
#pragma region FUNCOES E PROCEDIMENTOS
//novo nodo da estrutura partsets
PartsSets* new_cell_partSet(const char* setNumber, int quantity,const char *partNum){
  PartsSets* aux = (PartsSets*) malloc(sizeof(PartsSets));
  assert(aux);
  aux->part_num = strdup(partNum);
  aux->set_num = strdup(setNumber);
  aux->quantity = quantity;
  aux->next = NULL;
  return aux;
}

//insercao a cabeca da estrutura partsets
PartsSets* head_Insert_PartsSets(PartsSets* Lista, PartsSets* cell){
  if(!Lista) return cell;
  cell->next = Lista;
  return cell;
}

//listar da estrutura partsets
void Listar_PartsSets(PartsSets* Lista){
  while (Lista){
    printf("\n %s  %d  %s",Lista->set_num,Lista->quantity, Lista->part_num);
    Lista = Lista->next;
  }
}

//destruir estrutura partsets
PartsSets* remove_PartSets(PartsSets* Lista){
  PartsSets *prox = Lista;
  while(Lista){
    prox = Lista->next;
    free(Lista->part_num);
    free(Lista->set_num);
    free(Lista);
    Lista = prox;
  }
  return Lista;
}

#pragma endregion
#pragma endregion


