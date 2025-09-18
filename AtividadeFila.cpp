// Fila com Inser��o, Remo��o, Mostrar toda fila, Cheio/Vazio, Implementa��o Din�mica, localiza��o de elemento,
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

// Estrutura da fila
typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

// Inicializa fila
bool inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
    
    if(f->inicio==NULL && f->fim==NULL)
    return true;
    else
    return false;
}

// Verifica se a fila est� vazia
bool filaVazia(FILA* f) {
    return (f->inicio == NULL);
}

// Inser��o no fim
bool inserirNaFila(FILA* f, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (!novo) return false; // erro de aloca��o
    novo->reg = reg;
    novo->prox = NULL;

    if (f->fim) { // se j� existe fim
        f->fim->prox = novo;
    } else { // se a fila estava vazia
        f->inicio = novo;
    }
    f->fim = novo;
    return true;
}

// Remo��o do in�cio
bool removerDaFila(FILA* f, REGISTRO* reg) {
    if (filaVazia(f)) return false;
    PONT apagar = f->inicio;
    *reg = apagar->reg;
    f->inicio = apagar->prox;
    if (f->inicio == NULL) { // se esvaziou
        f->fim = NULL;
    }
    free(apagar);
    return true;
}

// Mostrar todos os elementos da fila
void exibirFila(FILA* f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    PONT atual = f->inicio;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

int menu(int resposta){
	
	
}

int main (){
	FILA f;
	int num_element, numAux=0, resposta;
	
	int init = inicializarFila(&f);
	if(init==true)
	printf("Inicializa��o bem sucedida!\n");
	else
	printf("Inicializa��o Falha =()\n");
	
	printf("Quantos elementos deseja inserir?\n");
	scanf("%d", &num_element);
	printf("\n");
	while(numAux<num_element){
		REGISTRO reg;
		
		printf("Digite o valor do %i elemento:\n", numAux+1);
		scanf("%d", &reg.chave);
		
		inserirNaFila(&f, reg);
		numAux++;
	}
	system("cls");
	printf("Inser��o bem sucedida!\n");
	
	printf("Digite:\n1-Mostrar Topo\n2-Remover no\n");
	scanf("%d", &resposta);
	}
	

