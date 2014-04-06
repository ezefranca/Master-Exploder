#ifndef FILTROS_H
#define FILTROS_H

#define LAPLACE 0
#define FOURIER 1
#define SOBEL	 2
#define PREWITT 3
#define LINEAR  4

void filtro_laplaciano(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);
void filtro_mediana(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);
void filtro_media(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);
void filtro_borda(unsigned char ***matriz, unsigned char ***saida, int altura, int largura);

#endif
