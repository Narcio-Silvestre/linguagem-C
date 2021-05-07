#include <stdio.h>
#include "auxiliares.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma region ESTRUTUTA AUXILIAR ELEMENTOS
//criar novo elemento da estrutura elemento
Elementos* new_element(const char* name){
  Elementos* element = (Elementos*) malloc(sizeof(Elementos));
  assert(element);
  element->name = strdup(name);
  element->next = NULL;
  return element;
}

//insercao a cabeca da estrutura elemento
Elementos* head_Insert_element(Elementos* lista, Elementos* nodo){
 if(!lista) return nodo;
 nodo->next = lista;
 return nodo;
}

//insercao a cauda da estrutura elemento
Elementos* tail_Insert_element(Elementos* lista, Elementos* nodo){
 if(!lista) return nodo;
 if((strcmp(lista->name,nodo->name)==0)){
    nodo = destroy_elements(nodo);
    return lista;   
 }
lista->next = tail_Insert_element(lista->next,nodo);
 return lista;
}

//contar elementos da estrutura elemento
int count_elements(Elementos *lista){
  int count=0;
  Elementos *aux = lista;
  while (aux)
  {
    count++;
    aux = aux->next;
  }
  return count;
}

//destruir estrutura elemento
Elementos* destroy_elements(Elementos *lista){
  Elementos *next = NULL;
  while (lista)
  {
      next = lista->next;
      free(lista->name);
      free(lista);
      lista = next;
  }
  return lista;
}

//listar estrutura elemento
void Listar_elements(Elementos* Lista){
  while (Lista){
    printf("\n %s \n",Lista->name);
    Lista = Lista->next;
  }
}

//procurar elemento na estrutura elemento
bool procurar_elemento(Elementos* lista, char* name){
  Elementos *aux = lista;
  while(aux){
    if(strcmp(aux->name,name)==0) return true;
    aux = aux->next;
  }
  return false;
}
#pragma endregion

#pragma region ESTRUTUTA AUXILIAR LISTAS
//criar novo elemento da estrutura listas
Lista* new_element_Lista(const char* name, int quantity){
  Lista* element = (Lista*) malloc(sizeof(Lista));
  assert(element);
  element->name = strdup(name);
  element->quantity = quantity;
  element->next = NULL;
  return element;
}

//insercao a cauda da estrutura listas
Lista* tail_Insert_element_Lista(Lista* lista, Lista* nodo){
 if(!lista) return nodo;
 else if((strcmp(lista->name,nodo->name)==0) && (nodo->quantity>=0))
        {
          lista->quantity += nodo->quantity;
          nodo = destroy_lista(nodo);
        }
        else
        {
          lista->next = tail_Insert_element_Lista(lista->next,nodo);
        }
    
 return lista;
}

//insercao a cabeca da estrutura listas
Lista* head_Insert_element_lista(Lista* lista, Lista* nodo){
 if(!lista) return nodo;
 nodo->next = lista;
 return nodo;
}

//destruir estrutura listas
Lista* destroy_lista(Lista* lista){
  Lista *next = NULL;
  while (lista)
  {
      next = lista->next;
      free(lista->name);
      free(lista);
      lista = next;
  }
  return lista;
}

//procurar elemento na estrutura listas
bool procurar_lista(Lista* lista, char* name){
  Lista *aux = lista;
  while(aux){
    if(strcmp(aux->name,name)==0) return true;
    aux = aux->next;
  }
  return false;
}

//listar estrutura listas
void Listar_listas(Lista* Lista){
  while (Lista){
    printf("\n %s \t %d",Lista->name, Lista->quantity);
    Lista = Lista->next;
  }
}

#pragma endregion

#pragma region ESTRUTURA AUXILIAR DUO ELEMENTOS
//destruir estrutura Duo baseada em elementos, lista de listas.
Duo* destroy_Duo(Duo* lista){
  Duo *next = NULL;
  while (lista)
  {
      next = lista->next;
      lista->elements = destroy_elements(lista->elements);
      free(lista->name);
      free(lista);
      lista = next;
  }
  return lista;
}

//criar novo elemento da estrutura Duo baseada em elementos, lista de listas.
Duo* new_element_Duo(const char* name){
  Duo* element = (Duo*) malloc(sizeof(Duo));
  assert(element);
  element->name = strdup(name);
  element->quantity = 0;
  element->next = NULL;
  element->elements = NULL;
  return element;
}

//insercao a cauda da estrutura Duo baseada em elementos, lista de listas.
Duo* tail_Insert_element_Duo(Duo* lista, Duo* nodo,Elementos* nodo_elem){
 if(!lista){
   nodo->elements =  nodo_elem;
   nodo->quantity++;
   return nodo;  
 } 
 else if((strcmp(lista->name,nodo->name)==0))
        {
          nodo = destroy_Duo(nodo);
          if(procurar_elemento(lista->elements,nodo_elem->name)){
            destroy_elements(nodo_elem);
            return lista;
          } 
          lista->elements = head_Insert_element(lista->elements,nodo_elem);
          lista->quantity++;
          return lista;
        }
        else
        {
          lista->next = tail_Insert_element_Duo(lista->next,nodo,nodo_elem);
        }
    
 return lista;
}

//listar estrutura Duo baseada em elementos, lista de listas.
void Listar_Duo(Duo* Lista){
  while (Lista){
    printf("\n %s %d",Lista->name,Lista->quantity);
    Lista = Lista->next;
  }
}

#pragma endregion

#pragma region ESTRUTURA AUXILIAR DUO LISTAS
//destruir estrutura Duo baseada em listas, lista de listas.
DuoListas* destroy_DuoListas(DuoListas* lista){
  DuoListas *next = NULL;
  while (lista)
  {
      next = lista->next;
      lista->listas = destroy_lista(lista->listas);
      free(lista->name);
      free(lista);
      lista = next;
  }
  return lista;
}

//novo elemento da estrutura Duo baseada em listas, lista de listas.
DuoListas* new_element_DuoListas(const char* name){
  DuoListas* element = (DuoListas*) malloc(sizeof(DuoListas));
  assert(element);
  element->name = strdup(name);
  element->next = NULL;
  element->listas = NULL;
  return element;
}

//insercao a cauda da estrutura Duo baseada em listas, lista de listas.
DuoListas* tail_Insert_element_DuoListas(DuoListas* lista, DuoListas* nodo,Lista* nodo_elem){
 if(!lista){
   nodo->listas =  nodo_elem;
   return nodo;  
 } 
 else if((strcmp(lista->name,nodo->name)==0))
        {
          nodo = destroy_DuoListas(nodo);
          if(procurar_lista(lista->listas,nodo_elem->name)){
            destroy_lista(nodo_elem);
            return lista;
          } 
          lista->listas = head_Insert_element_lista(lista->listas,nodo_elem);
          return lista;
        }
        else
        {
          lista->next = tail_Insert_element_DuoListas(lista->next,nodo,nodo_elem);
        }
    
 return lista;
}

//listar estrutura Duo baseada em listas, lista de listas.
void Listar_DuoListas(DuoListas* Lista){
  while (Lista){
    printf("\n %s ",Lista->name);
    Lista = Lista->next;
  }
}

#pragma endregion