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
	int vidas, posX, posY;
	int pontos, moveu;
	char tipo;
	char nome[50];

}TPlayer;

//TAD para o inimigo
typedef struct tinimigo
{
	int posX, posY;
	char tipo;
}TEnemy;

//Função que inicializa o jogador
void PlayerStart(TPlayer *player)
{
	system("cls");
	
	player->vidas = 3;
	player->pontos = 0;
	player->tipo = '*';
	player->posX = 8;
	player->posY = 8;
	player->moveu = 0;
	
	foreground(YELLOW);
	
	printf("Informe o nome do Jogador(a): ");
	fflush(stdin);
	fgets(player->nome, 50, stdin);
	
	foreground(WHITE);
	printf("\n\nBem vindo ao coleta tudo %s \n", player->nome);
	
	system("pause");
	system("cls");
}

void AddEnemy(TPlayer player, char matriz[16][16], int num)
{
	int i, aux;
	TEnemy inimigos[num];
	
	for(i = 0; i < 5; i++)
	{
		aux = rand() % 4;
		
		if(player.pontos <= 300)
		{
			if(aux == 0 || aux == 1)
				inimigos[i].tipo = '#';
			else
				inimigos[i].tipo = '+';
		}
		else
		{
			if(aux == 0 || aux == 1 || aux == 3)
				inimigos[i].tipo = '#';
			else
				inimigos[i].tipo = '+';
		}
		inimigos[i].posX = (rand() % 15);
		inimigos[i].posY = (rand() % 15);
		
		if(inimigos[i].posX == player.posX)
		{
			while(inimigos[i].posX == player.posX)
			{
				inimigos[i].posX = (rand() % 15);
			}
		}
		if(inimigos[i].posY == player.posY)
		{
			while(inimigos[i].posY == player.posY)
			{
				inimigos[i].posY = (rand() % 15);
			}
		}
		
		matriz[inimigos[i].posX][inimigos[i].posY] = inimigos[i].tipo;
	}

}

//Função recursiva para gerenciar os elementos durante o jogo e imprimir o que está acontecendo
void GameManager(TPlayer *player, char matriz[16][16]) 
{
	int i, j;
	char comando;
	
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
	
	matriz[player->posX][player->posY] = player->tipo;
	
	if(player->moveu == 5)
	{
		AddEnemy(*player, matriz, 5);
		player->moveu = 0;
	}
	
	foreground(BLUE);
	printf("-------------------COLETA TUDO!-------------------\n");
	
	foreground(RED);	
		
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
				
			else if(matriz[i][j] == player->tipo)
			{
				foreground(WHITE);
				printf("|");
				foreground(GREEN);
				printf("%c", matriz[i][j]);
				foreground(WHITE);
				printf("|");
			}
			else if(matriz[i][j] == '#')
			{
				foreground(WHITE);
				printf("|");
				foreground(RED);
				printf("%c", matriz[i][j]);
				foreground(WHITE);
				printf("|");
			}
			else if(matriz[i][j] == '+')
			{
				foreground(WHITE);
				printf("|");
				foreground(BLUE);
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
	
	foreground(YELLOW);
	
	if(player->vidas > 0)
	{
		printf("\nDigite seu comando: ");
		fflush(stdin);
		comando = getch();
		
		if(comando == 'a' && player->posY > 0)
		{
			matriz[player->posX][player->posY] = '_'; //Retira o caractere do jogador e atribui como espaço vazio do mapa
			player->posY--; //Atualzia a posição do jogador de acordo com o input do usuario
			player->moveu++;
			
			if(matriz[player->posX][player->posY] == '#')
				player->vidas--;
			else if(matriz[player->posX][player->posY] == '+')
				player->pontos += 5;
			
			system("cls");
			GameManager(player, matriz);
		}
		else if(comando == 'd' && player->posY < 15)
		{
			matriz[player->posX][player->posY] = '_';
			player->posY++;
			player->moveu++;
			
			
			if(matriz[player->posX][player->posY] == '#')
				player->vidas--;
			else if(matriz[player->posX][player->posY] == '+')
				player->pontos += 5;
			
			
			system("cls");
			GameManager(player, matriz);
		}
		else if(comando == 's' && player->posX < 15)
		{
			matriz[player->posX][player->posY] = '_';
			player->posX++;
			player->moveu++;
			
			
			if(matriz[player->posX][player->posY] == '#')
				player->vidas--;
			else if(matriz[player->posX][player->posY] == '+')
				player->pontos += 5;
			
			
			system("cls");
			GameManager(player, matriz);
		}
		else if(comando == 'w' && player->posX > 0)
		{
			matriz[player->posX][player->posY] = '_';
			player->posX--;
			player->moveu++;
			
			
			if(matriz[player->posX][player->posY] == '#')
				player->vidas--;
			else if(matriz[player->posX][player->posY] == '+')
				player->pontos += 5;
			
			
			system("cls");
			GameManager(player, matriz);
		}
		else if(comando == 'p') //Comando para sair do jogo e voltar ao menu, ainda está bugado
		{
			char aux;
			
			foreground(RED);
			printf("\nTem certeza que deseja sair? (s/n) ");
			fflush(stdin);
			scanf("%c", &aux);
			
			if(aux == 's')
				return;
			else if(aux == 'n')
			{
				system("cls");
				GameManager(player, matriz);
			}
			else
			{
				printf("\nInforme uma opção válida!\n");
				system("pause");
				
				system("cls");
				GameManager(player, matriz);
			}
				
		}
		else
		{
			printf("\nInforme uma opção válida!\n");
			system("pause");
			
			system("cls");
			GameManager(player, matriz);
		}
			

	}
	else //Condicional caso o jogador perca o numero total de vidas, ainda nao foi possivel testar...
	{
		system("cls");
		foreground(RED);
		printf("\nFIM DE JOGO!\n");
		foreground(WHITE);
		printf("\nSua pontuação: ");
		foreground(GREEN);
		printf("%d\n\n", player->pontos);
		
		return;
	}
	
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
	
	GameManager(player, matriz);
	
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
	printf("Se deseja SAIR durante uma partida, pressione P!\n\n");
}

void MSG_MENU()
{	
	foreground(BLUE);
	srand(time(NULL));
	
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
