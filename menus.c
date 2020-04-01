#include "menus.h"

NODE* menurem(TAB *a,NODE* raiz,int t){
    char lixo;
    char taux[100];
    int op;
    do{
    printf("**************************************************\n");
    printf("*\n");
    printf("*    1-remover elemento na arvore\n");
    printf("*    2-remover todas as vogais na arvore\n");
    printf("*    3-remover todas as consoantes na arvore\n");
    printf("*    4-remover todas as letras maiusculas na arvore\n");
    printf("*    5-remover todas as letras minusculas na arvore\n");
    printf("*    6-sair\n");
    printf("*\n");
    do{
        
        printf("Digite a opção desejada: ");
        scanf(" %s",taux);
        op=atoi(taux);
  } while ((op<1)||(op>6));
   raiz = opcaoRemovePorChaves(raiz,op);
    if(op==1){
        while(1){
            printf("Digite o elemento q quer remover da arvore B:\n");
            printf("Para parar de remover digite : -  \n");            
            scanf(" %c",&lixo);
            if(lixo=='-')break;
            a = retira(a,lixo,t);
            raiz = opcaoRemove(raiz,&lixo);
            Imprime(a,0);
        }
    }else if(op==2){
        remove_vog(a,t);
        Imprime(a,0);
    }else if(op==3){
        remove_cons(a,t);
        Imprime(a,0);
    }else if(op==4){
        remove_Mai(a, t);
        Imprime(a,0);
    }else if(op==5){
        remove_Mini(a,t);
        Imprime(a,0);
    }
    
    }while(op!=6);
    imprimeArvore(raiz);
    return raiz;
}

NODE* menuins(TAB* a,NODE* raiz,int t){
    char l;
    float f;
    do{
    setbuf(stdin, NULL);
    printf("Digite a letra a ser inserida: ");
    scanf(" %c", &l);
    }while((l<65||l>90)&&(l<97 ||l>122));
    do{
    printf("Digite a frequencia da letra a ser inserida: ");
    scanf(" %f", &f);
    }while((f<0||f>100));
    TAB* elem=Busca(a,l);
    if(!elem){
    raiz = opcaoAdicionaLetra(raiz,f,l);
    }
    a=Insere(a,l,f,verfica_max(l),verfica_vog(l),t);
    imprimeArvore(raiz);
    Imprime(a,0);
    return raiz;
}

NODE* menufreqalt(TAB* a,NODE*raiz){
    char l;
    float f;
    do{
    printf("Digite a letra que deseja alterar a frequencia: ");
    scanf(" %c", &l);
    }while((l<65||l>90)&&(l<97 ||l>122));
    do{
    printf("Digite a nova frequencia: ");
    scanf("%f", &f);
    }while((f<0||f>100));
    TAB *elem;
    elem=Busca(a,l);
    if(elem){
        int i;
        for(i=0;i<elem->nchaves;i++){
        if (elem->chave[i]->l==l){
            elem->chave[i]->f=f;
            break;
        }
        }
        raiz = opcaoAlteraFrequencia(raiz,f,l);
    }else{
        printf("Este elemento n existe na arvore.\n\n");
    }
    return raiz;

}

void menucod(TAB* a,char* palavra,NODE* raiz,int op){
    int p,tam;
    if(op == 1){
            p=0;
            tam=strlen(palavra);
            while(p<tam){
                if (Busca(a,palavra[p])){
                    acha_nv(a,palavra[p],0);
                    rastreia_cod(a,palavra[p]);
                }else{
                    printf("?");
                }
                p++;
            }
            printf("\n");
    } else if(op == 2){
        opcaoCodifica(raiz,palavra);
    } else if( op == 3){
        printf("Código na árvore B:\n");
        p=0;
            tam=strlen(palavra);
            while(p<tam){
                if (Busca(a,palavra[p])){
                rastreia_cod(a,palavra[p]);
                }else{
                printf("?");
                }
                p++;
            }
            printf("\n");
        printf("Código na árvore de Huffman:\n");                    
        opcaoCodifica(raiz,palavra);
    }
}
void menu_busca_cla(TAB* a){
    int op;
    do{
    printf("**************************************************\n");
    printf("*\n");
    printf("*    1-buscar todas as vogais\n");
    printf("*    2-buscar todas as consoantes\n");
    printf("*    3-buscar todas as minusculas\n");
    printf("*    4-buscar todas as maiusculas\n");
    printf("*    5-sair\n");
    printf("*\n");
    do{
        char taux[1000];
        printf("Digite a opção desejada: ");
        scanf(" %s",taux);
        op=atoi(taux);
  } while ((op<1)||(op>5));
    if(op==1){
        busca_vog(a);
    }else if(op==2){
        busca_cons(a);
    }else if(op==3){
        busca_min(a);
    }else if(op==4){
        busca_max(a);
    }
    }while(op!=5);
}
void busca_vog(TAB* a){
    if(a){
        int i,j;
        char vet[5]={'a','e','i','o','u'};
        char vet1[5]={'A','E','I','O','U'};
        TAB *elem = NULL;
        for(i=0;i<5;i++){
            elem=Busca(a,vet[i]);
            if(elem){
                for(j=0;j<elem->nchaves;j++){
                    if (elem->chave[j]->l==vet[i]){
                        printf("Esta letra %c existe na arvore:\n",vet[i]);
                        printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[j]->f, strinvog(elem,j),strinmax(elem,j));
                        break;
                    }
                }
            }
            
        }
        for(i=0;i<5;i++){
            elem=Busca(a,vet1[i]);
            if(elem){
                for(j=0;j<elem->nchaves;j++){
                    if (elem->chave[j]->l==vet1[i]){
                        printf("Esta letra %c existe na arvore:\n",vet1[i]);
                        printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[j]->f, strinvog(elem,j),strinmax(elem,j));
                        break;
                    }
                }
            }
            
        }
    }
}
void busca_cons(TAB* a){
    if(a){
        int i,j;
        char vet[21]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
        char vet1[21]={'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
        for(i=0;i<21;i++){
            TAB *elem = NULL;
            elem=Busca(a,vet[i]);
            if(elem){
                for(j=0;j<elem->nchaves;j++){
                    if (elem->chave[j]->l==vet[i]){
                        printf("Esta letra %c existe na arvore:\n",vet[i]);
                        printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[j]->f, strinvog(elem,j),strinmax(elem,j));
                        break;
                    }
                }
            }
            
        }
        for(i=0;i<21;i++){
            TAB *elem = NULL;
            elem=Busca(a,vet1[i]);
            if(elem){
                for(j=0;j<elem->nchaves;j++){
                    if (elem->chave[j]->l==vet1[i]){
                        printf("Esta letra %c existe na arvore:\n",vet1[i]);
                        printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[j]->f, strinvog(elem,j),strinmax(elem,j));
                        break;
                    }
                }
            }
            
        }
    }
}
void busca_max(TAB* a){
    if(a){
        int i,j;
        char vet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        TAB* elem=NULL;
        for(i=0;i<26;i++){
            elem=Busca(a,vet[i]);
            if(elem){
                for(j=0;j<elem->nchaves;j++){
                    if (elem->chave[j]->l==vet[i]){
                        printf("Esta letra %c existe na arvore:\n",vet[i]);
                        printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[j]->f, strinvog(elem,j),strinmax(elem,j));
                        break;
                    }
                }
            }
            
        }
    }
}
void busca_min(TAB* a){
    if(a){
        int i,j;
        char vet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(i=0;i<26;i++){
            TAB *elem = NULL;
            elem=Busca(a,vet[i]);
            if(elem){
                for(j=0;j<elem->nchaves;j++){
                    if (elem->chave[j]->l==vet[i]){
                        printf("Esta letra %c existe na arvore:\n",vet[i]);
                        printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[j]->f, strinvog(elem,j),strinmax(elem,j));
                        break;
                    }
                }
            }
            
        }
    }
}
void menuelem(TAB* a,NODE* raiz){
    char l;
    do{
    printf("Digite a letra que deseja obter informação: ");
    scanf(" %c", &l);
    }while((l<65||l>90)&&(l<97 ||l>122));
    TAB *elem = NULL;
    elem=Busca(a,l);
    printf("\n\n");
    opcaoMostraNos(raiz,&l);
    if(elem){
        int i;
        for(i=0;i<elem->nchaves;i++){
            if (elem->chave[i]->l==l){
                printf("Arvore B:\n");
                printf("Esta letra existe na arvore:\n");
                printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[i]->f, strinvog(elem,i),strinmax(elem,i));
                break;
            }
        }
        
    }else{
        printf("Este elemento não existe na arvore.\n\n");
    }
}

char* strinvog(TAB* elem,int i){
    char static vogal[]="vogal";
    char static cons[]="consoante";
    if(elem->chave[i]->v){
       return vogal;
    }
    return cons;
}

char* strinmax(TAB* elem,int i){
    char static maiu[]="maiuscula";
    char static minu[]="minuscula";
    if(elem->chave[i]->c){
       return maiu;
    }
    return minu;
}

void remove_vog(TAB *a, int t){
    if(a){
        int i,j;
        char vet[5]={'a','e','i','o','u'};
        char vet1[5]={'A','E','I','O','U'};
        for(i=0;i<5;i++){
            a = retira(a,vet[i],t);
            a = retira(a,vet1[i],t);
        }
    }
}

void remove_cons(TAB *a, int t){
    if(a){
        int i;
        char vet[21]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
        char vet1[21]={'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
        for(i=0;i<21;i++){
            a = retira(a,vet[i],t);
            a = retira(a,vet1[i],t);
        }
    }
}

void remove_Mai(TAB *a, int t){
    if(a){
        int i;
        char vet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        for(i=0;i<26;i++){
            a = retira(a,vet[i],t);
        }
    }
}

void remove_Mini(TAB *a, int t){
    if(a){
        int i;
        char vet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(i=0;i<26;i++){
            a = retira(a,vet[i],t);
        }
    }
}

int verfica_vog(char l){
  if (((l==97) || (l==101) || (l==105) || (l==111) || (l==117))||((l==65) || (l==69) || (l==73) || (l==79) || (l==85))) return 1;
  return 0;  
}

int verfica_max(char l){
  if (l>=65 && l<=90) return 1;
  return 0;  
}

void corrige(TAB*a,int t){
    while(!a->chave){
		a = a->filho[0];
    }
}
int ler_existe(){
    FILE* existe;
    int e;
    existe=fopen("existe.txt","rt");
    if(!existe) exit(1);
    fscanf(existe,"%d",&e);
    fclose(existe);
    return e;
}
void ler_nomes(int e){
    FILE *nomes;
    int i=0;
    nomes=fopen("nome.txt","rt");
    if(!nomes) exit(1);
    printf("Nomes dos arquivos disponiveis:\n");
    do
    {
    i++;
    char* nome = (char*) malloc(sizeof(char)*120);
    fscanf(nomes,"%s",nome);
    printf("%s\n",nome);
    } while (i<e);
    fclose(nomes);
    printf("\n\n\n\n");
}
int verifica_nomes(char* nome,int e){
    FILE *nomes;
    int i=0;
    nomes=fopen("nome.txt","rt");
    if(!nomes){
       printf("Erro ao abrir o arquivo para salvar\n");
       exit(1);
      }
   
    do{
        i++;
        char nomeaq[120];
        fscanf(nomes,"%s",nomeaq);
        if (!strcmp(nomeaq,nome)){
            fclose(nomes);
            return 1;
        }
    } while (i<e);
    fclose(nomes);
    return 0;
}
int escreve_nomes(int e,char* nome){
    FILE *nomes;
    nomes=fopen("nome.txt","a");
    if(!nomes){
        printf("Erro ao abrir o arquivo para salvar\n");
        exit(1);
    }
    fprintf(nomes,"%s",nome);
    e+=1;
    fclose(nomes);
    return e;
}
void escreve_existe(int e){
    FILE* existe;
    existe=fopen("existe.txt","wt");
    if(!existe){
      printf("Erro ao abrir o arquivo para salvar\n");
      exit(1);
    }
    fprintf(existe,"%d",e);
    fclose(existe);
}
void salva_arquivo(char *nome,TAB* a){
    char vetl[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char vet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    FILE *wr;
    TAB* elem;
    wr=fopen(nome,"w");
    if(!wr){
    printf("Nao abriu o arquivo para salvar");
    exit(1);
    };
  for(int i=0;i<26;i++){
    elem=Busca(a,vetl[i]);
    if (elem){
      for(int j=0;j<elem->nchaves;j++){
        if(elem->chave[j]->l==vetl[i]){
        fprintf(wr,"%c %.2f %d %d\n",elem->chave[j]->l,elem->chave[j]->f,elem->chave[j]->v,elem->chave[j]->c);
        break;
        }
      }
    }
  }
  for(int i=0;i<26;i++){
    elem=Busca(a,vet[i]);
    if (elem){
        for(int j=0;j<elem->nchaves;j++){
          if(elem->chave[j]->l==vet[i]){
          fprintf(wr,"%c %.2f %d %d\n",elem->chave[j]->l,elem->chave[j]->f,elem->chave[j]->v,elem->chave[j]->c);
          break;
          }
        }
    }
  }
  fclose(wr);
}
void Escreve_arqui(TAB *a){
  char nome[120];
  printf("Digite o nome do arquivo(exemplo: Alanturin.txt)\n");
  scanf("%s", nome);
  salva_arquivo(nome,a);
  int e;
  e=ler_existe();
  int v;
  v=verifica_nomes(nome,e);
  if(!v){
  e=Escreve_aux(e,nome);
  escreve_existe(e);
  return;
  }
}
int Escreve_aux(int e,char *nome){
  FILE* nomes;
  if(e>0){//caso nome nao esteja vazio
      e=escreve_nomes(e,nome);
      return e;
  }
  nomes=fopen("nome.txt","wr");
  if(!nomes){
   printf("Erro ao abrir o arquivo para salvar\n");
   exit(1);
  }
  fprintf(nomes,"%s\n",nome);
  fclose(nomes);
  e+=1;
  return e;
}