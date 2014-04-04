#ifndef FILTROS_H
#define FILTROS_H

#define LAPLACE {0, -1, 0, -1, 4, -1, 0, -1, 0}
#define FOURIER {0, -1, 0, -1, 8, -1, 0, -1, 0}
#define SOBEL	{0, -1, 0, -1, 8, -1, 0, -1, 0}
#define PREWITT {0, -1, 0, -1, 4, -1, 0, -1, 0}

int normalizacao_preto_e_branco(unsigned char ***matriz, int altura, int largura, int id_filtro);

#endif