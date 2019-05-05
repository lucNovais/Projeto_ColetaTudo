//-----PROJETO COLETA TUDO-----

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "colors.h" //Biblioteca de cores

//TAD para o jogador
typedef struct tjogador
{
	int vidas;
	int pontos;
	char tipo;
	char nome[50];

}TPlayer;

//Função que inicializa o jogador
void PlayerStart(TPlayer *player)
{
	system("cls");
	
	player->vidas = 3;
	player->pontos = 0;
	player->tipo = '*';
	
	foreground(YELLOW);
	
	printf("Informe o nome do Jogador(a): ");
	fflush(stdin);
	fgets(player->nome, 50, stdin);
	
	foreground(WHITE);
	printf("\n\nBem vindo ao coleta tudo %s \n", player->nome);
	
	system("pause");
	system("cls");
}

//Função que será responsável por inicializar o jogo
void Start(TPlayer *player)
{
	int i, j;
	char matriz[16][16];
	
	PlayerStart(player);
	
	for(i = 0; i < 16; i++)
		for(j = 0; j < 16; j++)
			matriz[i][j] = '_';
	
	matriz[8][8] = '*';
	
	foreground(BLUE);
	printf("-------------------COLETA TUDO!-------------------\n");
	
	foreground(WHITE);
	printf("\nJogador(a): ");
	foreground(GREEN);
	printf("%s", player->nome);
	foreground(WHITE);
	printf("Vidas: ");
	foreground(GREEN);
	printf("%d", player->vidas);
	foreground(WHITE);
	printf("\nPontuação: ");
	foreground(GREEN);
	printf("%d\n", player->pontos);
	
	
	foreground(RED);	
		
	//Temporário, posteriormente isso ficará em um GameLoop
	printf(" __________________________________________________\n\n[ ");		
	for(i = 0; i < 16; i++)
	{
		for(j = 0; j < 16; j++)
		{
			if(matriz[i][j] == '_')
			{
				foreground(WHITE);
				printf("|%c|", matriz[i][j]);
			}
				
			else if(matriz[i][j] == '*')
			{
				foreground(WHITE);
				printf("|");
				foreground(GREEN);
				printf("%c", matriz[i][j]);
				foreground(WHITE);
				printf("|");
			}		
		}
		if(i != 15)
		{
			foreground(RED);
			printf(" ]\n[ ");
		}
			
		else
		{
			foreground(RED);
			printf(" ]");
		}		
	}
	foreground(RED);
	
	printf("\n __________________________________________________ ");
	printf("\n\n");
	
	foreground(WHITE);//Muda as cores do texto
}

void SubMenu2()
{
	foreground(BLUE);
	
	printf("\t-----Instruçoes para jogar COLETA TUDO!-----\n");
	
	foreground(WHITE);
	
	printf("\n1) MOVIMENTAÇÃO: \n\nW - Mover para cima;\nS - Mover para baixo;");
	printf("\nA - Mover para a esquerda;\nD - Mover para a direita.\n");
	printf("\n\n2) OBJETIVO: \n\nO objetivo do jogo é coletar os símbolos que são iguais ao do seu personagem no mapa, em que a cada\n");
	printf("vez que você coleta 5 símbolos, o seu personagem muda de aparência e você precisa coletar os símbolos\n");
	printf("correspondentes ao seu personagem, evitando encostar nos outros.\n\n");
}

void MSG_MENU()
{	
	foreground(BLUE);
	
	printf("----------COLETA TUDO!----------\n");
	
	foreground(WHITE);
	
	printf("\n\t1. JOGAR");
	printf("\n\t2. COMO JOGAR");
	printf("\n\t3. OPÇÕES");
	printf("\n\t4. SAIR");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	SetConsoleTitle("Coleta Tudo!");
	
	TPlayer player;
	
	int opcao = 0;
	
	do
	{
		system("cls");
		
		MSG_MENU();
		
		foreground(YELLOW);
		
		printf("\n\nDigite sua opção: ");
		fflush(stdin);
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1:
				system("cls");
				
				//Chamar função para começar o jogo;
				
				Start(&player);
				
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
				foreground(RED);
				
				printf("\n-----Saindo do jogo!-----\n\n");
				break;
			default:
				printf("\n-----Opção inválida!-----\n\n");
		}
		
	}while(opcao != 4);
	
	foreground(WHITE);
	
	system("pause");
	return 0;
}
