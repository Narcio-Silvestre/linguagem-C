/*
*Author: Nárcio Silveste<narciosilvestre16@gmail.com>
*Author: Fábio Rodrigues
*Date: 07/04/2021
*
*/
#pragma region INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "estruturas.h"
#include "auxiliares.h"
#include "alinhas.h"
#include "readfiles.h"
#include "menu.h"
#pragma endregion

#pragma region PROGRAMA PRINCIPAL
int main(){


#pragma region LER FICHEIROS
system("clear");
printf("\nLendo os Ficheiros...\n");

#pragma region LER SETS
Sets *sets = NULL;
sets = readSets(sets); // ler o ficheiro dos sets

#pragma endregion

#pragma region LER PARTS_SETS
PartsSets *partsSets = NULL;
partsSets = readPartsSets(partsSets); // ler o ficheiro dos partsets

#pragma endregion

#pragma region LER PARTS
Parts *parts = NULL;
parts = readParts(parts); // ler o ficheiro dos parts
#pragma endregion

#pragma endregion

#pragma region MENU
//menu
answer(sets,parts,partsSets);
#pragma endregion

#pragma region  DESTRUIR FICHEIROS
//destruir estruturas dos finheiros
sets = remove_Sets(sets);
partsSets = remove_PartSets(partsSets);
parts = remove_parts(parts);
#pragma endregion
return 0;
}
#pragma endregion

