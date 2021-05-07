#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alinhas.h"
#include "menu.h"
#include <stdio_ext.h>
void Menu(){

    printf("\n================= MENU ====================");
    printf("\n1-> Alinha1");
    printf("\n2-> Alinha2");
    printf("\n3-> Alinha3");
    printf("\n4-> Alinha4");
    printf("\n5-> Alinha5");
    printf("\n6-> Alinha6");
    printf("\n7-> Alinha7");
    printf("\n8-> Extra1");
    printf("\n9-> Extra2");
    printf("\n10-> Extra3");
    printf("\n11-> Extra4");
    printf("\n12-> Listar Sets");
    printf("\n13-> Listar Parts");
    printf("\n14-> Listar PartsSets");
    printf("\n15-> Sair");
    printf("\n================= MENU ====================\n");

}

void answer(Sets* sets, Parts* parts, PartsSets* partsets){
int escolha;
char string[500];
char tema[500];
char classe[500];
char conjunto[500];
char part_num[500];
Elementos* alinha1 = NULL; //uso da alinha 1
Elementos *alinha2= NULL; //uso da alinha 2
Lista *alinha3= NULL; //uso da alinha 3
int qt_stock = 0; //uso da alinha 4
int qt_quantity_set = 0; //uso da alinha 5
Duo* alinha6 = NULL; //uso da alinha 6
Lista *alinha6_pt2 = NULL; //uso da alinha 6
DuoListas* alinha7 = NULL; //uso da alinha 7
Elementos *alinha7_pt2 = NULL; //uso da alinha 7
int newStock_8 = 0; //uso da alinha 8
Lista *alinha9 = NULL; //uso da alinha 9


do{
system("clear");
Menu();
scanf("%d",&escolha);
__fpurge(stdin);
switch(escolha){
    case 1:
           system("clear");
           printf("\nInserir tema: ");
           fgets(string,500,stdin);
           sscanf(string,"%[^\n]",tema);
           __fpurge(stdin);
           alinha1=Search_Sets_Theme(sets,tema);
           Listar_elements(alinha1);
           alinha1 = destroy_elements(alinha1);
           printf("\npressiona qualquer tecla para voltar...\n");
           getchar();
           system("clear");
           break;
    
    case 2: system("clear");
            printf("\nInserir conjunto: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",conjunto);
           __fpurge(stdin);
            printf("\nInserir classe: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",classe);
            __fpurge(stdin);
            alinha2 = search_Parts_Classe(parts, search_PartsofSet(partsets,conjunto),classe);
            Listar_elements(alinha2);
            alinha2 = destroy_elements(alinha2);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;
    
    case 3: 
            system("clear");
            printf("\nInserir conjunto: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",conjunto);
           __fpurge(stdin);
            alinha3 = search_PartsofSet_Lista(partsets,conjunto);
            Parts_dados(parts,alinha3);
            alinha3 = destroy_lista(alinha3);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;
    
    case 4: 
            system("clear");
            qt_stock = Sum_Stock(parts);
            printf("\nNumero total no stock: %d \n", qt_stock);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;
    
    case 5: 
            system("clear");
            printf("\nInserir conjunto: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",conjunto);
           __fpurge(stdin);
            qt_quantity_set = Sum_quantity(partsets,conjunto);
            printf("\nQuantidade total de Pecas do Conjunto: %d \n", qt_quantity_set);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;
    
    case 6: 
            system("clear");
            alinha6 = procurar_parts(partsets);
            alinha6_pt2 = mais_aparece(partsets,alinha6);
            printf("\nA mais frequente: %s \n", alinha6_pt2->name);
            destroy_Duo(alinha6);
            destroy_lista(alinha6_pt2);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    case 7: 
            system("clear");
            alinha7 = procurar_sets(partsets);
            alinha7_pt2 = possiveis_construir(parts,alinha7);
            Listar_elements(alinha7_pt2);
            destroy_elements(alinha7_pt2);
            destroy_DuoListas(alinha7);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    case 8: 
            system("clear");
            printf("\nInserir ID da peca: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",part_num);
            __fpurge(stdin);
            printf("\nInserir nova quantidade de stock: ");
            scanf("%d",&newStock_8);
            __fpurge(stdin);
            parts = Change_stock(parts,part_num,newStock_8);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;
    case 9: 
            system("clear");
            printf("\nInserir conjunto: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",conjunto);
           __fpurge(stdin);
            alinha9 = search_PartsofSet_Lista(partsets,conjunto);
            parts = Add_Parts_of_Set(parts,alinha9);
            destroy_lista(alinha9);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    case 10:
            system("clear");
            printf("\nInserir classe: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",classe);
            __fpurge(stdin);
            parts = Destroy_parts_by_classe(parts,classe);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    case 11:
            system("clear");
            printf("\nInserir tema: ");
            fgets(string,500,stdin);
            sscanf(string,"%[^\n]",tema);
            __fpurge(stdin);
            sets = Destroy_Sets_by_theme(sets,tema);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    case 12:
            system("clear");
            Listar_Sets(sets);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    case 13:
            system("clear");
            Listar_Parts(parts);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    case 14:
            system("clear");
            Listar_PartsSets(partsets);
            printf("\npressiona qualquer tecla para voltar...\n");
            getchar();
            system("clear");
            break;

    default: break;
  }
}
while(escolha>0 && escolha<15);

}

