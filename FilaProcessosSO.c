#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//Autores: Milena Valenze e Lucas Maracaípe

struct Process{
	int ID;
	char name[30];
	struct Process *prox;
};

typedef struct Process Process;

Process *New, *first1, *last1, *aux, *first2, *last2; //New é o novo processo. first1 é o primeiro da fila(prioritário). last1 é o último dos prioritarios

AddProcess(){//Sempre adicionar no final da lista, pois é uma fila
	int choose;

	New=(Process *)malloc(sizeof(Process));
	printf("ID: ");
	scanf("%i", &New->ID);
	printf("Nome: ");
	scanf("%s", &New->name);
	printf("Preferencial(1) ou comum(2)?\n");
	scanf("%i", &choose);
	
	if(choose==1){
		if(first1 == NULL){
			first1=New;
		}else if(first1 != NULL){
			New->prox=first2;
			last1->prox=New;
		}
		last1=New;
		last1->prox=first2;
	}else if(choose == 2){
		if(first2==NULL){
			first2=New;
		} else if(last2 != NULL){
			last2->prox=New;
		}
		last2=New;
		last2->prox=NULL;
		if(last1 != NULL){
			last1->prox = first2;
		}
	}
	printf("Pronto.\n");
}

Execute(){ //O processo vai para o final da fila

	if(first1 != NULL){
		aux=first1;
		if(first1->prox != first2)
			first1=first1->prox;
		else if(first1->prox == first2){
			first1=NULL;
			last1=NULL;
		}
	}
	
	else if(first1 == NULL && first2 != NULL){
		aux=first2;
		if(first2->prox != NULL)
			first2=first2->prox;
	}
	
	if(last2 == NULL){
		first2=aux;
		last2=aux;
		last2->prox=NULL;
	}
	else if(last2 != NULL){
		last2->prox=aux;
		last2=aux;
		last2->prox=NULL;
	}

	printf("\nPronto.\n");
}

EndProcess(){ //Irá remover apenas os primeiros da fila, já que esses serão executados primeiro
	if(first1 == NULL && first2 == NULL){
		printf("\nLista vazia!\n\n");
		return (0);
	}
	if(first1 != NULL){
		aux=first1;
		if(first1->prox == first2){
			first1 = NULL;
			last1 = NULL;
		}
		else if(first1->prox != first2){
			first1 = aux->prox;
		}
		free(aux);
	}else
	if(first1 == NULL && first2 != NULL){
		aux=first2;
		first2=aux->prox;
		free(aux);
	}
}

PrintList(){

	if(first1 == NULL && first2 == NULL){
		printf("\nLista vazia!\n\n");
		return (0);
	}
	else if(first1!=NULL){
		aux=first1;
	}
	else if(first1==NULL && first2!=NULL){
		aux=first2;
	}
		
	printf("\nLista:\n");
	while(aux!=NULL){
		printf("%i %s\n", aux->ID, aux->name);
		aux=aux->prox;
	}
}

main()
{
	setlocale(LC_ALL,"Portuguese");
	
	first1=NULL;
	first2=NULL;
	last1=NULL;
	last2=NULL;
	
	int opc;
	
	first1=NULL;
	last1=NULL;
	
	printf("Primeiro adicione um processo...\n");
	AddProcess();

	Menu:
		printf("\n*************Menu*************\n");
		printf("1- Adicionar processo\n");
		printf("2- Executar processo\n");
		printf("3- Finalizar processo\n");
		printf("4- Listar processos\n");
		printf("5- Sair\n\n");
		printf("Opção: ");
		scanf("%i", &opc);
		system("cls");
		switch(opc){
			case 1:
				printf("1- Adicionar processo\n");
				AddProcess();
			break;
			
			case 2:
				printf("2- Executar processo\n");
				Execute();
			break;
			
			case 3:
				printf("3- Finalizar processo\n");
				EndProcess();
			break;
			
			case 4:
				printf("4- Listar processos\n");
				PrintList();
			break;
			
			case 5:
				printf("5- Sair\n\n");
				return(0);
			break;
		}
	goto Menu;

	return(0);
}
