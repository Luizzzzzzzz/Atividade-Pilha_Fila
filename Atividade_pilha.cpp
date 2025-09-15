// Pilha com Inser��o, remo��o,mostrar Topo, verifica��o cheio_vazio e implementa��o din�mica
// tem como salvar como .cpp pq tem bool
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int CHAVE; //apelido para o int

typedef struct {
        CHAVE chave;
} REGISTRO; //Cria uma estrutura registro que possue a chave do tipo chave de antes, para guardar o endere�o de cada n� eu acho

typedef struct aux {
        REGISTRO reg;
        struct aux* prox;
} ELEMENTO; //cria a struct elemento que possui o reg do tipo registro e ela se auto referencia e faz um ponteiro para prox, 
//que vai ter o endere�o do pr�prio n�

typedef ELEMENTO* PONT; //da o apelido do ponteiro de ELEMENTO de PONT

typedef struct{
        PONT topo;       
}pilha; //ponteiro para a estrutura ELEMENTO que vai apontar pro topo da pilha, acho que � o tal n� cabe�a

void inicializar_pilha (pilha* p) {
     p->topo = NULL;
}// cria o ponteiro p para a estrutura pilha, p acessa o elemento topo da pilha e define o endere�o como null

bool pilha_vazia (pilha* p) {
     if (p-> topo == NULL) 
     return true;
     else
     return false;
] // checa se a pilha ta vazia vendo se o primeiro n� ta vazio

void exibir_topo(pilha* p) {
     printf("Topo da Pilha: \n%i\n", p->topo); // imprimi o que est� contido no ponteiro p que aponta para o topo da estrutura pilha
}

bool push(pilha* p, REGISTRO reg) {// inser��o na pilha
    
     PONT novo = (PONT) malloc(sizeof(ELEMENTO));// cria um novo n� do tipo elemento e aloca este ponteiro com mem�ria do tamanho da estrutura elemento
     if(novo==NULL)//testa se a aloca��o deu certo
     return false;
     
     novo->reg = reg;//novo acessa o registro e recebe o conte�do do registro anterior
     novo->prox = p->topo;//novo com o conteudo do registro antigo aponta para o topo da pilha
     p->topo=novo;//ponteiro p que acessa o topo da estrutura pilha e recebe o novo elemento
     
     return true;
} 

bool pop(pilha* p, REGISTRO* reg) {//exclus�o de elemento
    
     if ( p->topo == NULL) //checa se a pilha ta vazia, acho que da pra usar a fun��o pilha_vazia
     return false;
     
     *reg = p->topo->reg;
     PONT apagar = p->topo;
     p->topo = p->topo->prox;
     free(apagar);
     return true;
}
