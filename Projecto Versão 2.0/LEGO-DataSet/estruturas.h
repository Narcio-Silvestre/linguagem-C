#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_

#pragma region ESTRUTURAS DOS PARTS
typedef struct _parts{
  char* part_num;
  char* name;
  char* classe;
  int stock;
  struct _parts *next;
}Parts;

Parts* new_cell_Parts(const char* PartNumber,const char* name ,const char* classe,  int stock);
Parts* head_Insert_Parts(Parts* Lista, Parts* cell);
void Listar_Parts(Parts* Lista);
Parts* remove_parts(Parts* Lista);
#pragma endregion

#pragma region ESTRUTURAS DOS SETS
typedef struct _sets{
char* set_num;
char* name;
char* theme;
int year;
struct _sets* next;
}Sets;

Sets* new_cell_Sets(const char* setNumber,const char* name,const char*theme, int year);
Sets* head_Insert_Sets(Sets* Lista, Sets* cell);
void Listar_Sets(Sets* Lista);
Sets* remove_Sets(Sets* Lista);

#pragma endregion

#pragma region ESTRUTURAS DOS PARTSETS
typedef struct _partsSets{
  char* set_num;
  char* part_num;
  int quantity;
  struct _partsSets *next;
}PartsSets;


PartsSets* new_cell_partSet(const char* setNumber, int quantity,const char *partNum);

PartsSets* head_Insert_PartsSets(PartsSets* Lista, PartsSets* cell);

void Listar_PartsSets(PartsSets* Lista);

PartsSets* remove_PartSets(PartsSets* Lista);


#pragma endregion



#endif

