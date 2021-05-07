#ifndef _AUXILIARES_H_
#define _AUXILIARES_H_
#include <stdbool.h>
#pragma region ESTRUTURA AUXILIAR ELEMENTOS
typedef struct _elementos{
 char* name;
 struct _elementos *next;
}Elementos;

Elementos* new_element(const char* name);

Elementos* head_Insert_element(Elementos* lista, Elementos* nodo);

Elementos* tail_Insert_element(Elementos* lista, Elementos* nodo);

int count_elements(Elementos *lista);

Elementos* destroy_elements(Elementos *lista);

void Listar_elements(Elementos* Lista);

bool procurar_elemento(Elementos* lista, char* name);

#pragma endregion

#pragma region ESTRUTURA AUXILIAR LISTAS
typedef struct _lista{
 char* name;
 int quantity;
 struct _lista *next;
}Lista;

Lista* new_element_Lista(const char* name, int quantity);

Lista* tail_Insert_element_Lista(Lista* lista, Lista* nodo);

Lista* head_Insert_element_lista(Lista* lista, Lista* nodo);

Lista* destroy_lista(Lista* lista);

void Listar_listas(Lista* Lista);
#pragma endregion

#pragma region ESTRUTUR AUXILIAR DUO ELEMENTOS
typedef struct _duo{
    char* name;
    int quantity;
    struct _duo* next;
    Elementos* elements;
}Duo;

Duo* destroy_Duo(Duo* lista);

Duo* new_element_Duo(const char* name);

Duo* tail_Insert_element_Duo(Duo* lista, Duo* nodo,Elementos* nodo_elem);

void Listar_Duo(Duo* Lista);
#pragma endregion

#pragma region ESTRUTUR AUXILIAR DUO LISTAS
typedef struct _duolistas{
    char* name;
    struct _duolistas* next;
    Lista* listas;
}DuoListas;

DuoListas* destroy_DuoListas(DuoListas* lista);

DuoListas* new_element_DuoListas(const char* name);

DuoListas* tail_Insert_element_DuoListas(DuoListas* lista, DuoListas* nodo,Lista* nodo_elem);

void Listar_DuoListas(DuoListas* Lista);
#pragma endregion

#endif