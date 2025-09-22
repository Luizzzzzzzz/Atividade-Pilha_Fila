// Fila com Insercao, Remocao, Mostrar toda fila, Cheio/Vazio, Implementacao Dinamica, localizacao de elemento,
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int CHAVE; 

typedef struct {
        CHAVE chave;
} REGISTRO; 

typedef struct aux {
        REGISTRO reg;
        struct aux* prox;
} ELEMENTO; 

typedef ELEMENTO* PONT; 

typedef struct{
        PONT inicio;
		PONT fim;       
}FILA; 

bool inicializarFila (FILA* f) {
     f->inicio = NULL;
     f->fim = NULL;
     
    if(f->inicio == NULL && f->fim == NULL)
    return true;
    else
    return false;
}

bool filaVazia (FILA* f) {
     return (f->inicio == NULL); 
}

void mostrarFila(FILA* f) {
	
	system("cls");
	if(filaVazia(f)){
		printf("Fila Vazia");
		return;
	}
	PONT atual = f->inicio;
	printf("Fila: \n");	
	
	while (atual!=NULL){
		printf("%i\n", atual->reg.chave); 
		atual = atual->prox;
	}
     
}

bool inserirFila(FILA* f, REGISTRO reg) {
    
     PONT novo = (PONT) malloc(sizeof(ELEMENTO));
     if(novo==NULL)
     return false;
     
     novo->reg=reg;
     novo->prox=NULL;
     
     if(f->fim) {
     	f->fim->prox=novo;
	 } else {
	 	f->inicio=novo;
	 }
     
     f->fim=novo;
     return true;
} 

bool removerFila(FILA* f, REGISTRO* reg) {
    if (filaVazia(f)) 
		return false;
		
    PONT apagar = f->inicio;
    *reg = apagar->reg;
    f->inicio = apagar->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(apagar);
    return true;
}

int searchElemento(FILA* f, CHAVE chave) {
	PONT atual = f->inicio;
	int lugar = 0;
	
	while (atual != NULL) {
        if (atual->reg.chave == chave) 
			return lugar;
			
        atual = atual->prox;
        lugar++;
    }
    return -1;
}

int main (){
	FILA f;
	int num_element, numAux=0, resposta;
	
	int init = inicializarFila(&f);
	if(init==true)
	printf("Inicializacao bem sucedida!\n");
	else
	printf("Inicializacao Falha =()\n");
	
	printf("Quantos elementos deseja inserir?\n");
	scanf("%d", &num_element);
	printf("\n");
	
	while(numAux<num_element){
		REGISTRO reg;
		
		printf("Digite o valor do %i elemento:\n", numAux+1);
		scanf("%d", &reg.chave);
		
		inserirFila(&f, reg);
		numAux++;
	}
	system("cls");
	printf("Insercao bem sucedida!\n");
	
	printf("Digite:\n1-Mostrar Fila\n2-Remover no\n3-Procurar item\n");
	scanf("%d", &resposta);
	
	switch(resposta){
		case 1:
			mostrarFila(&f);
			break;
		case 2: 
		REGISTRO removido;
			removerFila(&f, &removido);
			printf("Elemento removido: %d\n", removido.chave);
			mostrarFila(&f);
			break;
		case 3:
			int chave;
			system("cls");
            printf("Digite o valor a localizar: \n");
            scanf("%d", &chave);
            int pos = searchElemento(&f, chave);
            if (pos == -1) 
				printf("Elemento nao encontrado.\n");
            else 
				printf("Elemento encontrado na %d posicao:\n", pos+1);
            break;
	}
}
	

