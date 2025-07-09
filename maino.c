#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


typedef struct {
    char nome[50];
    int vida, ataque, defesa;
    int xp, nivel, ouro;
}   Usuario;

typedef struct {
    int vida, ataque, defesa, xp;
} Monstro;

void tocarMusica(const char* caminhoRelativo) {
    char caminhoExecutavel[MAX_PATH];
    char caminhoCompleto[MAX_PATH];

    if (GetModuleFileNameA(NULL, caminhoExecutavel, MAX_PATH) == 0) {
        printf("Erro ao obter o caminho do executável.\n");
        return;
    }

    // Remove o nome do executável para obter apenas o diretório
    char* ultimaBarra = strrchr(caminhoExecutavel, '\\');
    if (ultimaBarra != NULL) {
        *ultimaBarra = '\0'; // Termina a string no último '\'
    }

    // Concatena o caminho do diretório com o caminho relativo da música
    snprintf(caminhoCompleto, MAX_PATH, "%s\\%s", caminhoExecutavel, caminhoRelativo);

    // Toca a música de forma assíncrona
    if (!PlaySoundA(caminhoCompleto, NULL, SND_FILENAME | SND_ASYNC)) {
        printf("Erro ao tocar o som: %s\n", caminhoCompleto);
    } 
}


int main(){
	int i, loop, h;
	Usuario jogador;
	
	for(loop = 1;loop == 1;){
		//Chama a função de tocar musica
		tocarMusica("sounds\\elevador.wav");
	
		printf("digite seu nome: ");
		scanf(" %[^\n]s", jogador.nome);
		printf("\n"); 
		printf("%s esse e seu nome 1sim 2nao\n", jogador.nome);
		scanf("%d", &h);
		if(h == 1){
			printf("comecando o jogo...\n");
			sleep(5);
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			break;
		}
	}
	
	tocarMusica("sounds\\intro.wav");
    
	printf("feito por ENZO...\n");
	printf("\n");
	
	sleep(4);
	
	printf("Enzotubers Memezado edicoes apresenta...\n");
	printf("\n");
	
	sleep(5);
	
	printf("A JORNADA POR CLANDOR\n");
	
	sleep(2);
	
	for(i = 1;i <= 9; i++){
		printf("\n");
		printf("\n");
		printf("\n");
	}
	
	sleep(1);
	
	for(i = 1;i <= 9; i++){
		printf("\n");
		printf("\n");
		printf("\n");
	}
	sleep(3);
	
	printf("a muito tempo existiam duas formas de vida humanos e monstros...\n");
	printf("     _____\n");
	printf(" O  |     |\n");
	printf("/|\\ |O  O |\n");
	printf("/ \\ |_____|\n");
	
	sleep(3);
	
	printf("elas viviam em harmonia ate que uma enorme guerra separou o continente em 2\n");
	printf("       ______  \n");
	printf("       \\    / \n");	
	printf("       /    \\ \n");
	printf("\\      |    |       /\n");
	printf(" \\ \\   \\    /    / /\n");
	printf("  \\ \\ \\ \\__/  / / /\n");
	
	sleep(3);
	
	printf("\n");
	printf("entre os dois pedacos a um enorme mar chamado O DESCONHECIDO...\n");
	printf("    _    _     _ \n");
	printf("   /    /     /  \n");
	printf("___\\____\\_____\\__\n");
	
	sleep(6);
	
	printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
    
	return 0;
}
