#ifndef JOGABILIDADE_H
#define JOGABILIDADE_H

#include <time.h>
#include "comum.h"

/* Constantes */
#define PEDRA 2
#define TESOURA 1
#define PAPEL 0
#define EMPATE 0
#define JOGADOR_2 2
#define JOGADOR_1 1

#define MINION_1 0
#define MINION_2 1
#define MINION_3 2
#define MINION_4 3
#define MINION_5 4

/**
 *  <#Description#>
 *
 *  @param jogador_1 <#jogador_1 description#>
 *  @param jogador_2 <#jogador_2 description#>
 *
 *  @return <#return value description#>
 */
int ganhador_rodada(int jogador_1, int jogador_2);
/**
 *  <#Description#>
 *
 *  @param jogador_1 <#jogador_1 description#>
 *  @param jogador_2 <#jogador_2 description#>
 *
 *  @return <#return value description#>
 */
int ganhador_jogo(int jogador_1, int jogador_2);
/**
 *  <#Description#>
 *
 *  @param jogador <#jogador description#>
 *
 *  @return <#return value description#>
 */
int fazer_jogada_melhor(int jogador);

/**
 *  <#Description#>
 *
 *  @param jogador <#jogador description#>
 *
 *  @return <#return value description#>
 */
int fazer_jogada_pior(int jogador);

/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
Minion *rand_boss(bool *minion_4_usado);

/**
 *  <#Description#>
 *
 *  @param pontos_jogador_1 <#pontos_jogador_1 description#>
 *  @param pontos_jogador_2 <#pontos_jogador_2 description#>
 *  @param melhor_jogo      <#melhor_jogo description#>
 *
 *  @return <#return value description#>
 */
int fim_jogada(int pontos_jogador_1, int pontos_jogador_2, int melhor_jogo);

/**
 *  <#Description#>
 *
 *  @param respeito      <#respeito description#>
 *
 *  @return <#return value description#>
 */
int fim_de_jogo(int respeito);

#endif