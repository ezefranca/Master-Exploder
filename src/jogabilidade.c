#include "jogabilidade.h"
#include <time.h>


int ganhador_rodada(int jogador_1, int jogador_2){
	if(jogador_1 == jogador_2)
		return EMPATE;
	
	if(jogador_1 == PEDRA && jogador_2 == PAPEL)
		return JOGADOR_2;
	
	if(jogador_2 == PEDRA && jogador_1 == PAPEL)
		return JOGADOR_1;
	
	if(jogador_1 > jogador_2)
		return JOGADOR_1;
	else 
		return JOGADOR_2;
}

int ganhador_jogo(int jogador_1, int jogador_2){
	if(jogador_1 == jogador_2){
		return EMPATE;
	}
	if(jogador_1 > jogador_2){
		return JOGADOR_1;
	}
	else 
		return JOGADOR_2;
}

//Retorna a jogada vencedora. Exemplo: Se jogador colocar tesoura, a funcao retorna Pedra.
int fazer_jogada_melhor(int jogador){
	if(jogador == PEDRA)
		return PAPEL;
	return jogador + 1;
}

int fazer_jogada_pior(int jogador) {
	if(jogador == PAPEL)
		return PEDRA;
	return jogador - 1;
}

int rand_boss() {
	int randomic = srand(abs(time(NULL))); 
	
}

int fim_de_jogo(int pontos_jogador_1, int pontos_jogador_2, int melhor_jogo){
	//Verifica se jogadas sao impares.
	if((melhor_jogo % 2) > 0)
		return (pontos_jogador_1 > (melhor_jogo/2) || pontos_jogador_2 > (melhor_jogo/2));
	else
		return (pontos_jogador_1 > (melhor_jogo/2) || pontos_jogador_2 > (melhor_jogo/2) || (pontos_jogador_1 + pontos_jogador_2) == melhor_jogo);
}