#include "tarvb.h"
#include "avh.h"

void corrige(TAB*a,int t);
int verfica_vog(char l);
int verfica_max(char l);
void menuelem(TAB* a,NODE* raiz);
NODE* menuins(TAB* a,NODE* raiz,int t);
NODE* menufreqalt(TAB* a,NODE* raiz);
void menucod(TAB* a,char* palavra,NODE* raiz,int op);
NODE* menurem(TAB* a,NODE* raiz,int t);
void remove_vog(TAB *a, int t);
void remove_cons(TAB *a, int t);
void remove_Mai(TAB *a, int t);
void remove_Mini(TAB *a, int t);
char* strinvog(TAB* elem,int i);
char* strinmax(TAB* elem,int i);
void ler_nomes(int e);
int ler_existe();
int verifica_nomes(char* nome,int e);
int escreve_nomes(int e,char* nome);
void escreve_existe(int e);
void salva_arquivo(char *nome,TAB* a);
int Escreve_aux(int e,char *nome);
void Escreve_arqui(TAB *a);
void busca_vog(TAB* a);
void busca_cons(TAB* a);
void busca_max(TAB* a);
void busca_min(TAB* a);
void menu_busca_cla(TAB* a);