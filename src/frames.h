#ifndef FRAME_H
#define FRAME_H

#include "comum.h"

/**
 *  <#Description#>
 */
void tela_sprite();
/**
 *  <#Description#>
 */
void tela_vencedor();
/**
 *  <#Description#>
 */
void tela_perdedor();
/**
 *  <#Description#>
 */
void tela_abertura();
/**
 *  <#Description#>
 *
 *  @param pontos_jogador_1 <#pontos_jogador_1 description#>
 *  @param pontos_jogador_2 <#pontos_jogador_2 description#>
 *  @param contador         <#contador description#>
 */
void tela_jogo(int pontos_jogador_1, int pontos_jogador_2, int contador);

#endif