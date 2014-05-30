#ifndef JOGABILIDADE_H
#define JOGABILIDADE_H

#include "comum.h"

int ganhador_rodada(int jogador_1, int jogador_2);

int ganhador_jogo(int jogador_1, int jogador_2);

int fazer_jogada_melhor(int jogador);

int fim_de_jogo(int pontos_jogador_1, int pontos_jogador_2, int melhor_jogo);

#endif