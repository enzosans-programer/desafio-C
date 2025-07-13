#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>

// Estrutura do jogador
typedef struct {
	char nome[50];
	int vida, ataque, defesa, sexo;
	int xp, nivel, ouro;
} Usuario;

// Estrutura do monstro
typedef struct {
	int vida, ataque, defesa, xp;
} Monstro;

// Função para tocar música
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
		*ultimaBarra = '\0';
	}
	
	// Concatena o diretório com o caminho relativo da música
	snprintf(caminhoCompleto, MAX_PATH, "%s\\%s", caminhoExecutavel, caminhoRelativo);
	
	// Usa PlaySound genérico
	if (!PlaySoundA(caminhoCompleto, NULL, SND_FILENAME | SND_ASYNC)) {
		printf("Erro ao tocar o som: %s\n", caminhoCompleto);
	}
}

// Limpa a tela com várias linhas em branco
void limparTela() {
	int i;
	for (i = 0; i < 30; i++) {
		printf("\n");
	}
}

int main(int argc, char *argv[]) {	
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	
	int i, loop, h;
	Usuario jogador = { "", 100, 10, 5, 0, 0, 1, 0 };
	
	// Cores ANSI (funcionam no Windows Terminal / PowerShell moderno)
	const char *vermelho = "\033[31m";
	const char *amarelo = "\033[93m";
	const char *azul = "\033[34m";
	const char *verde = "\033[32m";
	const char *reset = "\033[0m";
	const char *verdeclaro = "\033[92m";
	const char *azulclaro = "\033[94m";
	const char *rosa = "\033[95m";
	const char *roxo = "\033[35m";
	const char *marrom = "\033[33m";
	const char *preto = "\033[90m";
	const char *branco = "\033[98m";
	
	tocarMusica("sounds\\ling.wav");
	Sleep(1000); // 1 segundo
	
	for (loop = 1; loop == 1;) {
		tocarMusica("sounds\\elevador.wav");
		
		printf("Digite seu nome: ");
		scanf(" %[^\n]", jogador.nome);
		
		printf("\n%s%s%s, esse é seu nome? 1-Sim | 2-Não\n", azul, jogador.nome, reset);
		
		scanf("%d", &h);
		
		if (h == 1) {
			printf("Começando o jogo...\n");
			Sleep(1000);
			limparTela();
			break;
		}
	}
	
	tocarMusica("sounds\\intro.wav");
	
	printf("Feito por %sENZO%s...\n\n", azul, reset);
	Sleep(1000);
	
	printf("%sEnzotubers Memezado%s edições apresenta...\n\n", azul, reset);
	Sleep(2000);
	
	printf("AAAAAA      jjjjjjjj OOOOOO RRRRR  NN  N AAAAAA DDDDD  AAAAA\n");
	printf("A    A         jj    O    O R   R  N N N A    A D    D A   A\n");
	printf("A    A       jjjj    OOOOOO R   RR N  NN A    A DDDDDD A   A\n");
	printf("\n");
	printf("    PPPP  OOOOO RRRRR\n");
	printf("    P___P O   O R   R\n");
	printf("    P     OOOOO R   RR\n");
	printf("\n");
	printf("%sCCCCCC LL     AAAAAAAA NNNN  NN DDDDD   OOOOOOO RRRRR%s\n", amarelo, reset);
	printf("%sCC     LL     AA    AA NN NN NN DD   DD OO   OO RR   R%s\n", amarelo, reset);
	printf("%sCC     LL     AAAAAAAA NN  NNNN DD   DD OO   OO RRRRRR%s\n", amarelo, reset);
	printf("%sCCCCCC LLLLLL AA    AA NN   NNN DDDDD   OOOOOOO RR  RRR%s\n", amarelo, reset);
	Sleep(2000);
	
	limparTela();
	Sleep(500);
	
	printf("%sHá muito tempo existiam duas formas de vida: humanos e monstros...\n", marrom);
	printf("     _____\n");
	printf(" O  |     |\n");
	printf("/|\\ |O  O |\n");
	printf("/ \\ |_____|\n");
	
	Sleep(2000);
	
	printf("Elas viviam em harmonia até que uma enorme guerra separou o continente em dois...\n");
	printf("       ______  \n");
	printf("       \\    / \n");
	printf("       /    \\ \n");
	printf("\\      |    |       /\n");
	printf(" \\ \\   \\    /    / /\n");
	printf("  \\ \\ \\ \\__/  / / /\n");
	
	Sleep(2000);
	
	printf("\nEntre os dois pedaços há um enorme mar chamado O DESCONHECIDO...\n");
	printf("    _    _     _ \n");
	printf("   /    /     /  \n");
	printf("___\\____\\_____\\__%s\n", reset);
	
	Sleep(3000);
	
	limparTela();
	
	printf("Mais um humano, apelidado %s%s%s, muitos anos depois decidiu ir atrás dos monstros para ajudá-los...\n", vermelho, jogador.nome, reset);
	printf("                                                     %s/\\1/\\%s 	|\n", verde, reset);
	printf("                                                       %s|%s        |\n", marrom, reset);
	printf("                                               %sOOOOOOOOOOOOOOO%s  |\n", amarelo, reset);
	printf("OOOOOOO                                      %sOOOOOOOOOOOOOOOOOOO%s|\n", amarelo, reset);
	printf("|OOO__|%sOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO%s|\n", azulclaro, reset);
	printf("|  |  |%sOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO%s|\n", azul, reset);
	printf("|  \\__|%sOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO%s|\n", azulclaro, reset);
	printf("\\_____|%sOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO%s|\n", azul, reset);
	
	Sleep(3000);
	limparTela();
	
	printf("Mas %smonstros sombrios%s de um reino vizinho invadiram a terra de Clandor e lançaram %slobos%s e %sslimes%s no reino...\n", preto, reset, marrom, reset, verdeclaro, reset);
	printf("                          /   \\   \\_ \n");
	printf("____________              |  O      \\ \n");
	printf("|  \\     /  |             |_________/ \n");
	printf("|  ()   ()  |     ________/    | \n");
	printf("|    ___    |    / //          | \n");
	printf("|   /   \\   |    \\|/___________/ \n");
	printf("|___________|       | ||    | || \n");
	
	Sleep(3000);
	printf("O seu objetivo é entrar no reino, derrotar o rei %sdragão%s e acabar com a guerra...\n", roxo, reset);
	Sleep(2000);
	
	printf("Bem-vindo a Clandor\n");
	printf("                              %s/\\1/\\%s          |\n", verde, reset);
	printf("_________                       %s|%s            |\n", marrom, reset);
	printf("NOVO JOGO|              %sOOOOOOOOOOOOOOO%s      |\n", amarelo, reset);          
	printf("%sJOGAR%s    |            %sOOOOOOOOOOOOOOOOOOO%s    |\n", amarelo, reset, amarelo, reset);
	printf("MENU     |%sMMMMM%sMMMM%sMMMM%sMMMM%sMMMM%sMMMM%sMMMM%sMMMMMM%s|\n", azul, azulclaro, azul, azulclaro, azul, azulclaro, azul, azulclaro, reset);
	
	return 0;
}
