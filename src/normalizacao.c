#include "normalizacao.h"

int normalizacao_preto_e_branco(unsigned char ***matriz, int altura, int largura){

	unsigned char preto_e_branco;

    for (int i = 1; i < altura-1; i++)
    {
        for (int j = 1; j < largura-1; j++)
        {
            preto_e_branco = (matriz[i][j][0] + matriz[i][j][1] + matriz[i][j][2]) / 3;
						if(preto_e_branco < 0)
						preto_e_branco = preto_e_branco * -1;

            matriz[i][j][0] = preto_e_branco;
            matriz[i][j][1] = preto_e_branco;
            matriz[i][j][2] = preto_e_branco;
					//	printf("%d, %d: ---\n",i,j);
        }
    }
		//printf("TERMINOU DE NORMALIZAR\n");
    return 0;
}
