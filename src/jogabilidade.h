#ifndef JOGABILIDADE_H
#define JOGABILIDADE_H

#include "comum.h"
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
 *  @param pontos_jogador_1 <#pontos_jogador_1 description#>
 *  @param pontos_jogador_2 <#pontos_jogador_2 description#>
 *  @param melhor_jogo      <#melhor_jogo description#>
 *
 *  @return <#return value description#>
 */
int fim_de_jogo(int pontos_jogador_1, int pontos_jogador_2, int melhor_jogo);

#endif