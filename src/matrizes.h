#ifndef MATRIZES_H
#define MATRIZES_H

#include "comum.h"
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
 *  @param atual  <#atual description#>
 *  @param primeiro   <#primeiro description#>
 *  @param matriz  <#matriz description#>
 */
void subtrai_matriz(unsigned char ***atual, unsigned char ***primeiro, unsigned char ***matriz);
#endif
