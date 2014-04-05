#ifndef FILTROS_H
#define FILTROS_H

#define LAPLACE 0
#define FOURIER 1
#define SOBEL	 2
#define PREWITT 3
#define LINEAR  4

unsigned char filtro[3][3];


int aplica_filtro(unsigned char ***matriz, int altura, int largura, int id_filtro);
void criar_filtro(unsigned char **filtro, int id_filtro);

#endif
