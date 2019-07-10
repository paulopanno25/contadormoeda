#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void disponibilizaBolas(int Bolas[]){
	int i;
	for(i=0;i<=15;i++){
		Bolas[i]=1;
	}
}

float insereMoedas(float* valor){
	int op,quantidade=1;
	printf("Qual o valor que deseja inserer?\n");
	printf("1-5 centavos\n");
	printf("2-10 centavos\n");
	printf("3-25 centavos\n");
	printf("4-50 centavos\n");
	printf("5-1 Real\n");
	scanf("%d",&op);
	printf("Quantas moedas dessa deseja inserir?\n");
	scanf("%d",&quantidade);
	switch(op){
		case(1):
			*valor+=0.05*quantidade;
		break;
		case(2):
			*valor+=0.10*quantidade;
		break;
		case(3):
			*valor+=0.25*quantidade;
		break;
		case(4):
			*valor+=0.50*quantidade;
		break;
		case(5):
			*valor+=1*quantidade;
		break;
	}

	return *valor;
}

void mostraBolasDisponiveis(int Bolas[]){
	int i;
	for(i=0;i<=15;i++){
		if(Bolas[i]!=0){
			printf("%d ",i+1);
		}
	}
	printf("\n");
}

void Jogo(int Bolas[],int* encacapadas){
	int i,j;
	printf("Qual bola deseja tentar encaçapar?\n");
	mostraBolasDisponiveis(Bolas);
	scanf("%d",&i);
	j=rand()%100;
	if(j>=50){
		printf("Encaçapou!\n");
		Bolas[i-1]=0;
		(*encacapadas)++;
	}else{
		printf("Não Encaçapou.\n");
	}
}

void Menu(int* valorTotal, int* fichas,int* ativo,int* encacapadas){
	int Bolas[16];
	int op;
	char o;
	float valor=0;
	disponibilizaBolas(Bolas);
	system("clear");
		printf("Dinheiro total: R$ %d\n",*valorTotal);
		printf("1-Inserir moedas.\n");
		printf("2-Usar ficha.\n");
		printf("3-Jogar.\n");
		scanf("%d",&op);
		switch(op){
			case(1):
				if(insereMoedas(&valor)<1){
					printf("Valor insuficiente insira mais moedas.\n");
				}
				else{
					*valorTotal+=valor;
					while(valor>0){
						++(*fichas);
						--valor;
					}
				}
			break;
			case(2):
				if((*ativo)==1){
					printf("Você já tem uma ficha ativa\n");
					setbuf(stdin,NULL);
					o=getchar();
					break;
				}
				if(fichas>0){
					(*fichas)--;
					(*ativo)=1;
					disponibilizaBolas(Bolas);
					printf("Todas as bolas estão disponiveis de novo!\n");
				}
				else printf("Você não possui fichas.\n");
			break;
			case(3):
				if((*ativo)==1)
					Jogo(Bolas,encacapadas);
				else printf("Você não usou uma ficha.\n");
			break;
		}

}

void main(){
	int valorTotal=0;
	int fichas=0,ativo=0;
	int op=0,play=1;
	int encacapadas=0;
	srand(time(NULL));

	while(play){
		if(encacapadas==15){
			ativo=0;
			encacapadas=0;
		}
		system("clear");
		printf("-----------------------------------\n");
		printf("------------Suas Fichas %d---------\n",fichas);
		printf("-----------------------------------\n");
		printf("\n\n\n\n");
		printf("1-Menu\n");
		scanf("%d",&op);
		if(op==1){
			Menu(&valorTotal,&fichas,&ativo,&encacapadas);
		}
	}
}