#include "normalizacao.h"

int normalizacao_preto_e_branco(unsigned char ***matriz, int altura, int largura){

	unsigned char preto_e_branco;

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            preto_e_branco = (matriz[i][j][0] + matriz[i][j][1] + matriz[i][j][2]) / 3;
            matriz[i][j][0] = preto_e_branco;
            matriz[i][j][1] = preto_e_branco;
            matriz[i][j][2] = preto_e_branco;
        }
    }
    return 0;
}
