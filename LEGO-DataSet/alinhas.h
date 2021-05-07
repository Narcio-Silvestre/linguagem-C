#ifndef _ALINHAS_H_
#define _ALINHAS_H_
#include "estruturas.h"
#include "auxiliares.h"
#include <stdbool.h>

#pragma region ALINHA_1
Elementos* Search_Sets_Theme(Sets* Lista,char* theme);
#pragma endregion

#pragma region ALINHA_2

Elementos* search_PartsofSet(PartsSets* lista,char* Sets_num);

Parts* Search_Part_Num(Parts* Lista, char* part_Num);

Elementos* search_Parts_Classe(Parts* lista,Elementos* elements,char* classe);


#pragma endregion

#pragma region ALINHA_3

Lista* search_PartsofSet_Lista(PartsSets* lista , char* Sets_num);

void Parts_dados(Parts *lista,Lista *parts);

#pragma endregion

#pragma region ALINHA_4
int Sum_Stock(Parts *lista);
#pragma endregion

#pragma region ALINHA_5

int Sum_quantity(PartsSets *lista, char* set_num);
#pragma endregion

#pragma region ALINHA_6
Duo* procurar_parts(PartsSets* partsSets);

Lista* mais_aparece(PartsSets* partsSets, Duo* novo);

#pragma endregion

#pragma region ALINHA_7
DuoListas* procurar_sets(PartsSets* partsSets);

bool encontrar_part(Parts* lista, char* name, int quant);

bool isPossible(Parts* parts,Lista* aux, int stockMaior);

int maior_stock(Parts* parts);


Elementos* possiveis_construir(Parts* parts, DuoListas* novo);
#pragma endregion

#pragma region  EXTRA_1
Parts* Change_stock(Parts* lista, char* part_num, int newStock);

#pragma endregion

#pragma region EXTRA_2
Parts* Add_Parts_of_Set(Parts* lista, Lista* parts);
Parts* add_stock(Parts* Lista, char* part_Num, int plusStock);
#pragma endregion

#pragma region EXTRA_3
Parts* Destroy_parts_by_classe(Parts *lista, char* classe);

#pragma endregion

#pragma region EXTRA_4
Sets* Destroy_Sets_by_theme(Sets *lista, char* theme);

#pragma endregion

#endif

