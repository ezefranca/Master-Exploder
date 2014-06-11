#ifndef MATRIZES_H
#define MATRIZES_H

#define DIMENSAO_P   3 // DIMENSAO 3

#include "comum.h"

typedef int ponto[DIMENSAO_P];

/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void matriz_copia(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);

/**
 *  <#Description#>
 *
 *  @param bitmap  <#bitmap description#>
 *  @param matriz   <#matriz description#>
 */
void bitmap_para_matriz(ALLEGRO_BITMAP *bitmap, unsigned char ***matriz);

/**
 *  <#Description#>
 *
 *  @param atual  <#atual description#>
 *  @param primeiro   <#primeiro description#>
 *  @param matriz  <#matriz description#>
 */
void subtrai_matriz(unsigned char ***atual, unsigned char ***primeiro, unsigned char ***matriz);

/**
 *  Desenha na matriz a reta a partir de 2 pontos.
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *	@param matriz <#matriz description#>
 *
 */
void desenha_reta(ponto a, ponto b, char ***matriz);
#endif
