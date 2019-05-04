#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void SubMenu2()
{
	printf("\t-----Instruçoes para jogar COLETA TUDO!-----\n");
	printf("\n1) MOVIMENTAÇÃO: \n\nW - Mover para cima;\nS - Mover para baixo;");
	printf("\nA - Mover para a esquerda;\nD - Mover para a direita.\n");
	printf("\n\n2) OBJETIVO: \n\nO objetivo do jogo é coletar os símbolos que são iguais ao do seu personagem no mapa, em que a cada\n");
	printf("vez que você coleta 5 símbolos, o seu personagem muda de aparência e você precisa coletar os símbolos\n");
	printf("correspondentes ao seu personagem, evitando encostar nos outros.\n");
}

void MSG_MENU()
{
	printf("----------COLETA TUDO!----------\n");
	printf("\n\t1. JOGAR");
	printf("\n\t2. COMO JOGAR");
	printf("\n\t3. OPÇÕES");
	printf("\n\t4. SAIR");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = 0;
	
	do
	{
		system("cls");
		
		MSG_MENU();
		
		printf("\n\nDigite sua opção: ");
		fflush(stdin);
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				system("cls");
				
				//Chamar função para começar o jogo;
				
				system("pause");
				break;
			case 2:
				system("cls");
				
				SubMenu2();
				
				system("pause");
				break;
			case 3:
				system("cls");
				
				//Chama o menu de opções;
				
				system("pause");
				break;
			case 4:
				printf("\n-----Saindo do jogo!-----\n\n");
				break;
			default:
				printf("\n-----Opção inválida!-----\n\n");
		}
		
	}while(opcao != 4);
	
	system("pause");
	return 0;
}
