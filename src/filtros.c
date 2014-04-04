#include "filtros.h"

int aplica_filtro(unsigned char ***matriz, int altura, int largura, int id_filtro){

	unsigned char preto_e_branco;

	switch id_filtro{
		case 0:
		filtro[3][3] = LAPLACE;
		break;
		case 1:
		filtro[3][3] = FOURIER;
		break;
		case 2:
		filtro[3][3] = SOBEL;
		break;
		case 3:
		filtro[3][3] = PREWITT;
		break;
	}

    for (int i = 1; i < altura - 1; i++)
    {
        for (int j = 1; j < largura - 1; j++)
        {
        	for (int k = 0; k < 3; k++)
        	{

        		matriz[i-1][j-1][k] = matriz[i-1][j-1][k] * filtro[0][0];
        		matriz[i-1][j][k]   = matriz[i-1][j][k] * filtro[0][1];
        		matriz[i-1][j+1][k] = matriz[i-1][j+1][k] * filtro[0][2];
        		matriz[i][j-1][k]   = matriz[i][j-1][k] * filtro[1][0];
        		matriz[i][j][k]     = matriz[i][j][k] * filtro[1][1];
        		matriz[i+1][j][k]   = matriz[i+1][j][k] * filtro[1][2];
        		matriz[i][j+1][k]   = matriz[i][j+1][k] * filtro[2][0];
        		matriz[i+1][j+1][k] = matriz[i+1][j+1][k] * filtro[2][1];
        		matriz[i+1][j-1][k] = matriz[i+1][j-1][k] * filtro[2][2];
        	}
            

            matriz[i][j][0] = preto_e_branco;
            matriz[i][j][1] = preto_e_branco;
            matriz[i][j][2] = preto_e_branco;
        }
    }
    return;
}