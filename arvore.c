//TAD ÁRVORE
//ESTE DOCUMENTO POSSUI OS TRÊS ARQUIVOS DE UM TAD ÁRVORE, CADA PARTE DEVE ESTAR EM UM ARQUIVO SEPARADO
//GUILHERME HENRIQUE LOURENÇO 
#include <stdlib.h>
#include <stdio.h>

//PARTE DO ARQUIVO DE CABEÇALHO : arvore.h
struct noArv{
	char info;
	struct noArv* esq;
	struct noArv* dir;
};

typedef struct noArv NoArv;

NoArv* arv_criavazia(void);
NoArv* arv_cria(char c, NoArv* e, NoArv* d);
NoArv* arv_libera(NoArv* a);
int arv_vazia(NoArv* a);
int arv_pertence(NoArv* a, char c);
void arv_imprime(NoArv* a);
int arv_altura(NoArv* a);
NoArv* arv_copia(NoArv* a);
int arv_igual(NoArv* a, NoArv* b);
int arv_folhas(NoArv* a);
int arv_intermediarios(NoArv* a);
int arv_balanceada(NoArv* a);


//PARTE DO ARQUIVO PRINCIPAL : main.c
int main(int argc, char* argv[]){
	
	{
		//teste da parte de cópia
		printf("\n\nTESTE DE COPIA DE ARVORE\n\n");
		NoArv* folha1 = arv_cria('d',arv_criavazia(),arv_criavazia());
		NoArv* folha2 = arv_cria('e',arv_criavazia(),arv_criavazia());
		NoArv* folha3 = arv_cria('f',arv_criavazia(),arv_criavazia());
		NoArv* folha4 = arv_cria('g',arv_criavazia(),arv_criavazia());
	
		NoArv* no1 = arv_cria('b',folha1,folha2);
		NoArv* no2 = arv_cria('c',folha3,folha4);
	
		NoArv* raiz = arv_cria('a',no1,no2);
	
		printf("Altura da arvore: %d",arv_altura(raiz));
		printf("\nArvore Inicial: \n");
		arv_imprime(raiz);
		printf("\n\nEndereco da raiz original: %p",raiz);
		printf("\n\nArvore Copia: \n");
		NoArv* copia = arv_copia(raiz);
		printf("Altura da copia: %d",arv_altura(copia));
		printf("\nImpressao da copia:\n");
		arv_imprime(copia);
		printf("\n\nEndereco da copia: %p",copia);
	}
	
	
	{
		//teste de igualdade entre duas árvores
		printf("\n\nTESTE DE IGUALDADE DE ARVORE\n\n");
		NoArv* folha1 = arv_cria('b',arv_criavazia(),arv_criavazia());
		NoArv* folha2 = arv_cria('c',arv_criavazia(),arv_criavazia());
	
		NoArv* raiz = arv_cria('a',folha1,folha2);
	
		NoArv* folha3 = arv_cria('e',arv_criavazia(),arv_criavazia());
		NoArv* folha4 = arv_cria('f',arv_criavazia(),arv_criavazia());
	
		NoArv* raiz2 = arv_cria('d',folha3,folha4);
	
		NoArv* raiz3 = arv_copia(raiz);
	
		printf("\n\nArvore 1: \n");
		arv_imprime(raiz);
		printf("\n\nArvore 2: \n");
		arv_imprime(raiz2);
		printf("\n\nArvore 3: \n");
		arv_imprime(raiz3);
	
		if(arv_igual(raiz,raiz2)){
			printf("\nA primeira e a segunda arvores sao iguais!");
		}else{
			printf("\nA primeira e a segunda arvores sao diferentes!");
		}
	
		if(arv_igual(raiz,raiz3)){
			printf("\nA primeira e a terceira arvores sao iguais!");
		}else{
			printf("\nA primeira e a terceira arvores sao diferentes!");
		}
	}
	
	{
		//teste da verificação de balanceamento de uma árvore
		printf("\n\nTESTE DE BALANCEAMENTO AVL DE ARVORE\n\n");
		NoArv* folha1 = arv_cria('b',arv_criavazia(),arv_criavazia());
		NoArv* folha2 = arv_cria('c',arv_criavazia(),arv_criavazia());
		NoArv* folha3 = arv_copia(folha1);
		NoArv* folha4 = arv_copia(folha2);
	
		NoArv* no1 = arv_cria('a',folha1,folha2);
		NoArv* no2 = arv_cria('a',folha3,folha4);
	
		NoArv* raiz1 = arv_cria('x',no1,no2);
	
	
		NoArv* f1 = arv_cria('b',arv_criavazia(),arv_criavazia());
		NoArv* f2 = arv_cria('c',f1,arv_criavazia());
		NoArv* f3 = arv_cria('d',f2,arv_criavazia());
		NoArv* f4 = arv_cria('e',f3,arv_criavazia());	
	
		NoArv* raiz2 = arv_cria('a',f4,arv_criavazia());
	
		printf("Primeira Arvore: ");
		arv_imprime(raiz1);
		if(arv_balanceada(raiz1)){
			printf("\nA primeira arvore e Balanceada! ");
		}else{
			printf("\nA primeira arvore nao e Balanceada! ");
		}
	
		printf("\n\nSegunda Arvore: ");
		arv_imprime(raiz2);
		if(arv_balanceada(raiz2)){
			printf("\nA segunda arvore e Balanceada!");
		}else{
			printf("\nA segunda arvore nao e Balanceada!");
		}
	}
	
	{
		//contagem do número de folhas de uma árvore
		printf("\n\nTESTE DE CONTAGEM DE FOLHAS DE ARVORE\n\n");
		NoArv* folha1 = arv_cria('b',arv_criavazia(),arv_criavazia());
		NoArv* folha2 = arv_cria('c',arv_criavazia(),arv_criavazia());
	
		NoArv* raiz = arv_cria('a',folha1,folha2);
	
		printf("Arvore: \n");
		arv_imprime(raiz);
		printf("Quantidade de folhas: %d",arv_folhas(raiz));
	}
	
	{
		//contagem do número de intermediários em uma árvore
		printf("\n\nTESTE DE CONTAGEM DE INTERMEDIARIOS DE ARVORE\n\n");
		NoArv* folha1 = arv_cria('b',arv_criavazia(),arv_criavazia());
		NoArv* folha2 = arv_cria('c',arv_criavazia(),arv_criavazia());
		NoArv* no1 = arv_cria('a',folha1,folha2);
		NoArv* folha3 = arv_copia(folha1);
		NoArv* folha4 = arv_copia(folha2);
		NoArv* no2 = arv_cria('a',folha3,folha4);
		NoArv* raiz = arv_cria('z',no1,no2);
	
		printf("Arvore: \n");
		arv_imprime(raiz);
		printf("\nQuantidade de intermediarios: %d",arv_intermediarios(raiz));
		printf("\nQuantidade de folhas: %d\n",arv_folhas(raiz));
	}
	
	system("pause");
	return 0;
}


//PARTE DO ARQUIVO DE FUNÇÕES : arvore.c

//cria um nó vazio da arvore
NoArv* arv_criavazia(void){ 
	return NULL;
}

//cria um nó alocado dinamicamente
NoArv* arv_cria(char c, NoArv* e, NoArv* d){
	NoArv* p = (NoArv*)malloc(sizeof(NoArv));
	p->info = c;
	p->esq = e;
	p->dir = d;
	return p;
}

//libera um nó e sua sub arvore
NoArv* arv_libera(NoArv* a){
	if(!arv_vazia(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

//verifica se uma arvore é vazia 1-se for vazia 0-se não for
int arv_vazia(NoArv* a){
	return a == NULL;
}

//verifica se um elemento pertence à arvore 1-se pertence e 0-se não pertence
int arv_pertence(NoArv* a, char c){
	if(arv_vazia(a)){
		return 0;
	}else{
		return a->info == c||
			arv_pertence(a->esq,c) ||
			arv_pertence(a->dir,c);
	}
}

//imprime a raiz e sua sub árvore
void arv_imprime(NoArv* a){
	if(!arv_vazia(a)){
		printf(" %c ",a->info);
		arv_imprime(a->esq);
		arv_imprime(a->dir);
	}
}

//devolve como retorno a altura da árvore
int arv_altura(NoArv* a){
	if(a == NULL){
		return -1;
	}else{
		int he = arv_altura(a->esq);
		int hd = arv_altura(a->dir);
		if(he < hd){
			return hd + 1;
		}else{
			return he + 1;
		}
	}
}

//copia uma árvore
NoArv* arv_copia(NoArv* a){
	if(arv_vazia(a)){
		return NULL;
	}
	NoArv* r = (NoArv*)malloc(sizeof(NoArv));
	r->info = a->info;
	r->esq = arv_copia(a->esq);
	r->dir = arv_copia(a->dir);
	return r;
}

//verifica se duas árvores são iguais 1-se forem iguais e 0-se não forem
int arv_igual(NoArv* a, NoArv* b){
	if(a==b){
		return 1;
	}
	if(a==NULL || b==NULL){
		return 0;
	}
	if((a->info==b->info) && (arv_igual(a->esq,b->esq)) && (arv_igual(a->dir,b->dir))){
		return 1;
	}else{
		return 0;
	}
}

//devolve o numero de folhas de uma árvore(nós sem filhos)
int arv_folhas(NoArv* a){
	if(a==NULL){
		return 0;
	}
	if(a->esq==NULL && a->dir==NULL){
		return 1;
	}else{
		return arv_folhas(a->esq) + arv_folhas(a->dir);
	}
}

//devolve o número de intermediarios de uma árvore(nós com pelo menos um filho)
int arv_intermediarios(NoArv* a){
	if(a==NULL){
		return 0;
	}
	if(a->esq==NULL && a->dir==NULL){
		return 0;
	}else{
		return (1 + arv_intermediarios(a->esq) + arv_intermediarios(a->dir));
	}
}

//verifica se a árvore e balanceada no sentido avl 1- se for balanceada e 0-se não for balanceada
int arv_balanceada(NoArv* a){
	int he;
	int hd;
	
	if(a==NULL){
		return 1;
	}
	
	he = arv_altura(a->esq);
	hd = arv_altura(a->dir);
	
	if(abs(he-hd)<=1 && arv_balanceada(a->esq) && arv_balanceada(a->dir)){
		return 1;
	}
	return 0;
}
