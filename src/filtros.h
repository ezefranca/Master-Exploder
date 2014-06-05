#ifndef FILTROS_H
#define FILTROS_H

#include <stdlib.h>

#define LAPLACE 0
#define FOURIER 1
#define SOBEL	 2
#define PREWITT 3
#define LINEAR  4
/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void filtro_laplaciano(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);
/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void filtro_mediana(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);
/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void filtro_media(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);
/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void filtro_borda(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);

#endif
