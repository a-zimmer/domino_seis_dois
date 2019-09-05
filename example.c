#include <stdio.h>
#include <stdlib.h>

typedef struct lista_dupla {
	int value;
	struct lista_dupla *prev, *next;
} ListaDupla;

ListaDupla *init()
{
	return NULL;
}

ListaDupla *insert(ListaDupla *l, int value)
{
	ListaDupla *new = malloc(sizeof(ListaDupla));
	new->value = value;

	// Lista vazia
	if(l == NULL){
		new->next = NULL;
		new->prev = NULL;
		return new;
	}

	ListaDupla *last, *al = l;

	while(al != NULL && al->value >= value){
		last = al;
		al = al->next;
	}

	// Inserção no início
	if(al == l){
		new->next = l;
		new->prev = NULL;
		l->prev = new;
		return new;
	}

	// Inserção no final
	if(al == NULL){
		new->next = NULL;
		new->prev = last;
		last->next = new;
		return l;
	}

	//Inserção no meio
	new->next = al;
	new->prev = last;
	al->prev = new;
	last->next = new;

	return l;
}

ListaDupla *delete(ListaDupla *l, int value)
{
	ListaDupla *al = l;

	// Lista vazia
	if(l == NULL) return NULL;

	while(al != NULL && al->value != value){
		al = al->next;
	}

	// Elemento não encontrado
	if(al == NULL) return l;

	// Elemento único
	if(al->next == NULL && al->prev == NULL){
		free(al);
		return NULL;
	}

	ListaDupla *ret;

	// Exclusão no início
	if(al->prev == NULL){
		ret = al->next;
		ret->prev = NULL;
		free(al);
		return ret;
	}

	// Exclusão no final
	if(al->next == NULL){
		al->prev->next = NULL;
		free(al);
		return l;
	}

	// Exclusão no meio
	al->prev->next = al->next;
	al->next->prev = al->prev;
	free(al);

	return l;
}

void print_list(ListaDupla *l)
{
	if(l == NULL){
		printf("A lista nao contem itens.\n");
		return;
	}

	int i;
	ListaDupla *last;

	printf("Ordem decrescente:\n");
	for(i = 0; l != NULL; l = l->next, i++){
		last = l;
		printf("%s%d", i ? " " : "", l->value);
	}
	printf("\n");

	printf("Ordem crescente:\n");
	for(i = 0, l = last; l != NULL; l = l->prev, i++){
		printf("%s%d", i ? " " : "", l->value);
	}
	printf("\n");
}

int main()
{
	int n;
	ListaDupla *l = init();

	printf("Insira elementos na lista (0 para acabar):\n");
	while(scanf("%d", &n), n){
		l = insert(l, n);
	}

	printf("Delete elementos da lista (0 para acabar):\n");
	while(scanf("%d", &n), n){
		l = delete(l, n);
	}

	print_list(l);

	return 0;
}