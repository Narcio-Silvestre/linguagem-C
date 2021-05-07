#include "readfiles.h"
#include <stdio.h>

//funcao para ler os partsets e armazenar na estrutura partsets
PartsSets* readPartsSets(PartsSets* Lista){
  FILE *partsSets;
  char string[1000];
  char set_num[300];
  int quantity;
  char part_num[300];
  
  if((partsSets=fopen("parts_sets.tsv","r"))==NULL){
    printf("Impossível abrir o ficheiro pretendido!");
    return NULL;
  }

  fgets(string,1000,partsSets);
  while(!feof(partsSets)){
    fgets(string,1000,partsSets);
    sscanf(string,"%s\t%d\t%[^\n]",set_num, &quantity, part_num);
    Lista = head_Insert_PartsSets(Lista,new_cell_partSet(set_num,quantity,part_num));
  }
  fclose(partsSets);
  return Lista;
}

//funcao para ler os parts e armazenar na estrutura part
Parts* readParts(Parts* Lista){
  FILE *Parts;
  char string[1000];
  char part_num[100];
  char name[300];
  char classe[100];
  int stock;

  if((Parts=fopen("parts.tsv","r"))==NULL){
    printf("Impossível abrir o ficheiro pretendido!");
    return NULL;
  }

  fgets(string,1000,Parts);
  while(!feof(Parts)){
    fgets(string,1000,Parts);
  	sscanf(string,"%s\t%[^\t]\t%[^\t]\t%d",part_num, name, classe, &stock);
    Lista = head_Insert_Parts(Lista,new_cell_Parts(part_num,name,classe,stock));
  }
  fclose(Parts);
  return Lista;
}

//funcao para ler os sets e armazenar na estrutura sets
Sets* readSets(Sets* Lista){
  FILE *Sets;
  char string[1000];
  char set_num[300];
  char name[200];
  char theme[150];
  int year;

  if((Sets=fopen("conjuntos.tsv","r"))==NULL){
    printf("Impossível abrir o ficheiro pretendido!");
    return NULL;
  }

  fgets(string,1000,Sets);

  while(!feof(Sets)){
    fgets(string,1000,Sets);
	  sscanf(string,"%s\t%[^\t]\t%d\t%[^\n]",set_num, name, &year, theme);
    Lista = head_Insert_Sets(Lista,new_cell_Sets(set_num,name,theme,year));
  }
  fclose(Sets);
  return Lista;
}

//funcao para ler os partsets ate certo numero e armazenar na estrutura partsets
PartsSets* readPartsSets_2(PartsSets* Lista, const int linhas){
  FILE *partsSets;
  char string[1000];
  char set_num[300];
  int quantity;
  char part_num[300];
  int i=1;

  if((partsSets=fopen("parts_sets.tsv","r"))==NULL){
    printf("Impossível abrir o ficheiro pretendido!");
    return NULL;
  }

  fgets(string,1000,partsSets);
  while(i<linhas){
    fgets(string,1000,partsSets);
    sscanf(string,"%s\t%d\t%[^\n]",set_num, &quantity, part_num);
    Lista = head_Insert_PartsSets(Lista,new_cell_partSet(set_num,quantity,part_num));
    i++;
  }
  fclose(partsSets);
  return Lista;
}

//funcao para ler os part ate certo numero e armazenar na estrutura part
Parts* readParts_2(Parts* Lista, const int linhas){
  FILE *Parts;
  char string[1000];
  char part_num[300];
  char name[300];
  char classe[150];
  int stock;
  int i=1;

  if((Parts=fopen("parts.tsv","r"))==NULL){
    printf("Impossível abrir o ficheiro pretendido!");
    return NULL;
  }

  fgets(string,1000,Parts);
  while(i<linhas){
    fgets(string,1000,Parts);
  	sscanf(string,"%s\t%[^\t]\t%[^\t]\t%d",part_num, name, classe, &stock);
    Lista = head_Insert_Parts(Lista,new_cell_Parts(part_num,name,classe,stock));
    i++;
  }
  fclose(Parts);
  return Lista;
}

//funcao para ler os sets ate certo numero e armazenar na estrutura sets
Sets* readSets_2(Sets* Lista, const int linhas){
  FILE *Sets;
  char string[1000];
  char set_num[300];
  char name[200];
  char theme[150];
  int year;
  int i = 1;

  if((Sets=fopen("conjuntos.tsv","r"))==NULL){
    printf("Impossível abrir o ficheiro pretendido!");
    return NULL;
  }

  fgets(string,1000,Sets);

  while(i<linhas){
    fgets(string,1000,Sets);
	  sscanf(string,"%s\t%[^\t]\t%d\t%[^\n]",set_num, name, &year, theme);
    Lista = head_Insert_Sets(Lista,new_cell_Sets(set_num,name,theme,year));
    i++;
  }
  fclose(Sets);
  return Lista;
}
