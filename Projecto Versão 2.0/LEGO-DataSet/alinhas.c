#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "alinhas.h"


#pragma region ALINHA_1
//procurar conjuntos pelo tema
Elementos* Search_Sets_Theme(Sets* Lista,char* theme){
Sets* aux = Lista;
Elementos *aux2 = NULL; //lista para guardar os conjuntos encontrados
while (aux)
{
  if(strcmp(aux->theme,theme) == 0){
      aux2 = head_Insert_element(aux2,new_element(aux->set_num)); //se encontrar adicionar numa lista
  }
  aux = aux->next;
}
return aux2; //retornar lista
}
#pragma endregion

#pragma region ALINHA_2

Elementos* search_PartsofSet(PartsSets* lista,char* Sets_num){
  PartsSets *aux = lista;
  Elementos *parts = NULL;
  while(aux){
    if(strcmp(aux->set_num,Sets_num)==0){
      parts =tail_Insert_element(parts,new_element(aux->part_num));
    }
    aux = aux->next;
  }
  return parts;
}

Parts* Search_Part_Num(Parts* Lista, char* part_Num){
Parts* aux = Lista;
while (aux)
{
  if(strcmp(aux->part_num,part_Num) == 0)
      return new_cell_Parts(aux->part_num,aux->name,aux->classe,aux->stock);
  aux=aux->next;
}
return aux;
}


Elementos* search_Parts_Classe(Parts* lista,Elementos* elements,char* classe){
  Elementos *parts = NULL;
  Parts* search = NULL;
  Elementos *aux = elements;
  while(aux){
    search = Search_Part_Num(lista,aux->name);
    if(search && (strcmp(search->classe,classe)==0))
      parts =head_Insert_element(parts,new_element(search->part_num));
    search = remove_parts(search);
    aux = aux->next;
  }
  elements = destroy_elements(elements);
  return parts;
}
#pragma endregion

#pragma region ALINHA_3

Lista* search_PartsofSet_Lista(PartsSets* lista , char* Sets_num){
  PartsSets *aux = lista;
  Lista *parts = NULL;
  while(aux){
    if(strcmp(aux->set_num,Sets_num)==0){
      parts =tail_Insert_element_Lista(parts,new_element_Lista(aux->part_num,aux->quantity));
    }
    aux = aux->next;
  }
  return parts;
}

void Parts_dados(Parts *lista,Lista *parts){
  Parts *aux = NULL;
  Lista *helper = parts;
  while(helper){
    aux = Search_Part_Num(lista,helper->name);
    if(aux){
      printf("\n Part_Num:%s \t Name:%s \t Classe:%s \t Stock:%d \t Quantity:%d \n",aux->part_num,aux->name,aux->classe,aux->stock,helper->quantity);
      aux = remove_parts(aux);
    }
    helper = helper->next;  
  }
}

#pragma endregion

#pragma region ALINHA_4
int Sum_Stock(Parts *lista)
{
  Parts *aux = lista;
  int count = 0;
  int i=0;
  while(aux)
  {  
    count += aux->stock;
    aux = aux->next;
  }
  return count;
}

#pragma endregion

#pragma region ALINHA_5

int Sum_quantity(PartsSets *lista, char* set_num)
{
  PartsSets *aux = lista;
  int count = 0;
  while(aux) 
  { if(strcmp(aux->set_num,set_num)==0)
      count += aux->quantity;
    aux = aux->next;
  }
  return count;
}

#pragma endregion

#pragma region ALINHA_6

Duo* procurar_parts(PartsSets* partsSets){
Duo* novo = NULL;
Elementos *auxElem = NULL; 
PartsSets *auxPatSet = partsSets;

while(auxPatSet){
    auxElem = new_element(auxPatSet->set_num);
    novo = tail_Insert_element_Duo(novo,new_element_Duo(auxPatSet->part_num),auxElem);
    auxPatSet = auxPatSet->next;
    
}

return novo;
}

Lista* mais_aparece(PartsSets* partsSets, Duo* novo){
Duo* aux_novo = novo;
int maior = 0;
char* key = NULL; 
while(aux_novo){
    if(aux_novo->quantity > maior){
        maior = aux_novo->quantity;
        key = aux_novo->name;
    }
    aux_novo = aux_novo->next;
}
return new_element_Lista(key,maior);
}


#pragma endregion

#pragma region ALINHA_7
DuoListas* procurar_sets(PartsSets* partsSets){
DuoListas* novo = NULL;
Lista *auxElem = NULL; 
PartsSets *auxPatSet = partsSets;

while(auxPatSet){
    auxElem = new_element_Lista(auxPatSet->part_num,auxPatSet->quantity);
    novo = tail_Insert_element_DuoListas(novo,new_element_DuoListas(auxPatSet->set_num),auxElem);
    auxPatSet = auxPatSet->next;
}

return novo;
}

bool encontrar_part(Parts* lista, char* name, int quant){
  while(lista){
    if(strcmp(lista->part_num,name) == 0)
    {
       if(lista->stock >= quant) return true;
       return false;
    }
    lista = lista->next;
  }
  return false;
}

bool isPossible(Parts* parts,Lista* aux, int stockMaior){
  bool possible = false;
  while(aux){
      if(aux->quantity > stockMaior) return false;
      if(encontrar_part(parts,aux->name,aux->quantity))
        {
          aux = aux->next;
          possible = true;
        }
      else{
        possible = false;
        break;
      }
    }
    return possible;
}

Elementos* possiveis_construir(Parts* parts, DuoListas* novo){
  DuoListas* aux = novo;
  Parts* aux_part = parts;
  bool possible = false;
  int stockMaior = maior_stock(aux_part);
  Elementos *lista = NULL;
  while(aux){
    possible = isPossible(aux_part,aux->listas,stockMaior);
    if(possible)
      lista = tail_Insert_element(lista,new_element(aux->name));
    aux = aux->next;
  }
  return lista;
}

int maior_stock(Parts* parts){
  int maior =0;
  Parts* aux = parts;
  while(aux){
    if(aux->stock > maior)
      maior = aux->stock;
    aux = aux->next;
  }
  return maior;
}
#pragma endregion

#pragma region  EXTRA_1
Parts* Change_stock(Parts* lista, char* part_num, int newStock)
{
  Parts* aux = lista;
  while (strcmp(aux->part_num,part_num) != 0)
  {
    aux = aux->next;
  }
  if(aux && (newStock >= 0))
   aux->stock = newStock;
  return lista;
}

#pragma endregion

#pragma region EXTRA_2
Parts* add_stock(Parts* Lista, char* part_Num, int plusStock){
Parts* aux = Lista;
while (aux)
{
  if(strcmp(aux->part_num,part_Num) == 0)
  {
    aux->stock += plusStock;
    return Lista;
  }   
  aux=aux->next;
}
return Lista;
}

Parts* Add_Parts_of_Set(Parts* lista, Lista* parts){
  Lista* aux = parts;
  while (aux)
  {     
    lista = add_stock(lista,aux->name,aux->quantity);
    aux = aux->next;
  }
  return lista;
}
#pragma endregion

#pragma region EXTRA_3
Parts* Destroy_parts_by_classe(Parts *lista, char* classe){
  if(!lista) return lista;
  if(strcmp(lista->classe,classe)==0){
    Parts *prox = lista->next;
    free(lista->classe);
    free(lista->name);
    free(lista->part_num);
    free(lista);
    lista = Destroy_parts_by_classe(prox,classe);
  }
  else{
    lista->next = Destroy_parts_by_classe(lista->next,classe);
  }
  return lista;
}
#pragma endregion

#pragma region EXTRA_4
Sets* Destroy_Sets_by_theme(Sets *lista, char* theme){
  if(!lista) return lista;
  if(strcmp(lista->theme,theme)==0){
    Sets *prox = lista->next;
    free(lista->name);
    free(lista->set_num);
    free(lista->theme);
    free(lista);
    lista = Destroy_Sets_by_theme(prox,theme);
  }
  else{
    lista->next = Destroy_Sets_by_theme(lista->next,theme);
  }
  return lista;
}
#pragma endregion
