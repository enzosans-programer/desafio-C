#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>

// Cores Globais - Onde todas as funções podem usar
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

void desenhoTitulo() {
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
	
	printf("               \033[32m/\\1/\\\033[0m          \n");
	printf("                 \033[33m|\033[0m            \n");
	printf("         \033[93mOOOOOOOOOOOOOOO\033[0m      \n");          
	printf("       \033[93mOOOOOOOOOOOOOOOOOOO\033[0m    \n");
	printf("\033[34mMMMMM\033[94mMMMM\033[34mMMMM\033[94mMMMM\033[34mMMMM\033[94mMMMM\033[34mMMMM\033[94mMMMMMM\033[0m\n");
}


int mostrarMenu() {
	int opcao;
	
	while (1) {
		limparTela();
		
		// Título/Desenho no topo
		desenhoTitulo();
		
		// Menu interativo abaixo do desenho
		tocarMusica("sounds\\menu.wav");
		printf("\nBem-vindo a Clandor!\n\n");
		printf("1 - JOGAR\n");
		printf("2 - CRÉDITOS\n");
		printf("3 - SAIR\n\n");
		printf("Escolha uma opção: ");
		
		if (scanf("%d", &opcao) != 1) {
			while (getchar() != '\n'); // Limpa buffer
			printf("Opção inválida! Pressione Enter para continuar.\n");
			getchar();
			continue;
		}
		
		switch (opcao) {
		case 1:
			printf("\nIniciando novo jogo...\n");
			Sleep(5000);
			limparTela();
			return 1;
		case 2:
			printf("\nFeito por: ENZO\n");
			printf("Edições: Enzotubers Memezado\n");
			printf("Pressione Enter para voltar...");
			getchar(); getchar();
			break;
		case 3:
			printf("\nSaindo...\n");
			Sleep(1000);
			exit(0);
		default:
			printf("Opção inválida! Pressione Enter para continuar.\n");
			getchar(); getchar();
		}
	}
}

void pararMusica(){
	tocarMusica("sounds\\nada.wav");
}

void slime(){
	int decisao, s1;
	printf("um slime apareçeu!!!\n");
	printf("iniciar batalha? 1-sim|2-não\n");
	scanf("%d", &decisao);
	if(decisao == 1){
	printf("uma batalha começou!\n");
	printf("ver status do oponente-1|atacar-2|piedade-3|itens-4\n");
	scanf("%d", &s1);
	switch (s1) {
	case 1:
	printf("slime: VIDA %s/ATAQUE 2/DEFESA 1|\n");
		break;
	case 2:
		//TODO
		break;
	case 3:
	printf("voçe vez um desistir!\n");
		break;
	case 4:
		break;
	default:
		//TODO
		break;
	}
	}
}


int main(int argc, char *argv[]) {	
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	
	if (mostrarMenu()) {
		int loop, h;
		Usuario jogador = { "", 100, 10, 5, 0, 0, 1, 0 };
		
		//tocarMusica("sounds\\ling.wav");
		//Sleep(1000); // 1 segundo
		
		for (loop = 1; loop == 1;) {
			tocarMusica("sounds\\elevador.wav");
			
			printf("Digite seu nome: ");
			scanf(" %[^\n]", jogador.nome);
			
			printf("\n%s%s%s, esse é seu nome? 1-Sim | 2-Não\n", azul, jogador.nome, reset);
			
			scanf("%d", &h);
			
			if (h == 1) {
				printf("Começando o jogo...\n");
				Sleep(5000);
				limparTela();
				break;
			}
		}
		
		tocarMusica("sounds\\intro.wav");
		
		printf("Feito por %sENZO%s...\n\n", azul, reset);
		Sleep(3000);
		
		printf("%sEnzotubers Memezado%s edições apresenta...\n\n", azul, reset);
		Sleep(4000);
		
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
		Sleep(5000);
		
		limparTela();
		Sleep(4000);
		
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
		
		Sleep(3000);
		
		printf("\nEntre os dois pedaços há um enorme mar chamado O DESCONHECIDO...\n");
		printf("    _    _     _ \n");
		printf("   /    /     /  \n");
		printf("___\\____\\_____\\__%s\n", reset);
		
		Sleep(6000);
		
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
		
		Sleep(6000);
		limparTela();
		
		printf("Mas %smonstros sombrios%s de um reino vizinho invadiram a terra de Clandor e lançaram %slobos%s e %sslimes%s no reino...\n", preto, reset, marrom, reset, verdeclaro, reset);
		printf("                          /   \\   \\_ \n");
		printf("____________              |  O      \\ \n");
		printf("|  \\     /  |             |_________/ \n");
		printf("|  ()   ()  |     ________/    | \n");
		printf("|    ___    |    / //          | \n");
		printf("|   /   \\   |    \\|/___________/ \n");
		printf("|___________|       | ||    | || \n");
		
		Sleep(6000);
		limparTela();
		printf("O seu objetivo é entrar no reino, derrotar o rei %sdragão%s e acabar com a guerra...\n", roxo, reset);
		Sleep(7000);
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("e aqui começa a sua jornada %s%s%s\n", marrom, jogador.nome, reset);
		Sleep(3000);
		printf("%sBOA SORTE%s\n", vermelho, reset);
		Sleep(3000);
		printf("%sVOÇE VAI PRECISAR%s\n", vermelho, reset);
		Sleep(5500);
		limparTela();
		Sleep(3000);
		printf("%s HA HA HA HA\n", vermelho);
		Sleep(1290);
		printf("%s HA HA HA HA\n", vermelho);
		Sleep(7000);
		printf("%sRRRRRRRR     UUUU     UUUU   NNNNN     NNN\n", vermelho);
		printf("RRRRRRRRRR   UUUU     UUUU   NNNNNNN   NNN\n");
		printf("RRR    RRR   UUUU     UUUU   NNN NNNN  NNN\n");
		printf("RRRRRRRRR    UUUU     UUUU   NNN  NNNN NNN\n");
		printf("RRRRRRRR     UUUU     UUUU   NNN   NNNNNNN\n");
		printf("RRR  RRRR    UUUUUUUUUUUUU   NNN    NNNNNN\n");
		printf("RRR    RRR   UUUUUUUUUUUUU   NNN     NNNNN%s\n", reset);
		Sleep(4000);
		printf("BOAS ESCOLHAS\n");
		Sleep(3000);
		printf("adeus\n");
		Sleep(3000);
		for(int i=1;i<=10500;i++){
			printf("01");
		}
		pararMusica();
		Sleep(3000);
		tocarMusica("sounds\\mar.wav");
		printf("voçe chegou a ilha de clandor");
		Sleep(2000);
		printf("consegue ouvir o som do mar, a batida das folhas, \n");
		
	}
	
	return 0;
}
