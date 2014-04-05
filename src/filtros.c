#include "filtros.h"

void criar_filtro(unsigned char **filtro, int id_filtro){
	switch (id_filtro){
		case LAPLACE:
		filtro[0][0] = -1;
		filtro[0][1] = -1;
		filtro[0][2] = -1;
		filtro[1][0] = -1;
		filtro[1][1] =  8;
		filtro[1][2] = -1;
		filtro[2][0] = -1;
		filtro[2][1] = -1;
		filtro[2][2] = -1;
		break;
		case FOURIER:
		filtro[0][0] = -1;
		filtro[0][1] = -1;
		filtro[0][2] = -1;
		filtro[1][0] = -1;
		filtro[1][1] =  8;
		filtro[1][2] = -1;
		filtro[2][0] = -1;
		filtro[2][1] = -1;
		filtro[2][2] = -1;
		break;
		case SOBEL:
		filtro[0][0] = -1;
		filtro[0][1] = -1;
		filtro[0][2] = -1;
		filtro[1][0] = -1;
		filtro[1][1] =  8;
		filtro[1][2] = -1;
		filtro[2][0] = -1;
		filtro[2][1] = -1;
		filtro[2][2] = -1;
		break;
		case PREWITT:
		filtro[0][0] = -1;
		filtro[0][1] = -1;
		filtro[0][2] = -1;
		filtro[1][0] = -1;
		filtro[1][1] =  8;
		filtro[1][2] = -1;
		filtro[2][0] = -1;
		filtro[2][1] = -1;
		filtro[2][2] = -1;
		break;
		default:
		filtro[0][0] = 1;
		filtro[0][1] = 1;
		filtro[0][2] = 1;
		filtro[1][0] = 1;
		filtro[1][1] = 1;
		filtro[1][2] = 1;
		filtro[2][0] = 1;
		filtro[2][1] = 1;
		filtro[2][2] = 1;
		break;
	}
return;
}

int aplica_filtro(unsigned char ***matriz, int altura, int largura, int id_filtro){

	criar_filtro(filtro, id_filtro);
	int auxiliar[9];
	for (int i = 1; i < altura - 1; i++)
	{
		for (int j = 1; j < largura - 1; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				auxiliar[0] = matriz[i-1][j-1][k] * filtro[0][0];
				auxiliar[1] = matriz[i-1][j][k] * filtro[0][1];
				auxiliar[2] = matriz[i-1][j+1][k] * filtro[0][2];
				auxiliar[3] = matriz[i][j-1][k] * filtro[1][0];
				auxiliar[4] = matriz[i][j][k] * filtro[1][1];
				auxiliar[5] = matriz[i+1][j][k] * filtro[1][2];
				auxiliar[6] = matriz[i][j+1][k] * filtro[2][0];
				auxiliar[7] = matriz[i+1][j+1][k] * filtro[2][1];
				auxiliar[8] = matriz[i+1][j-1][k] * filtro[2][2];

				for(int p=0; p<=8; p++){
					if(auxiliar[p] < 0)
					auxiliar[p] = 0;
					if(auxiliar[p] > 255)
					auxiliar[p] = 255;
				}


				matriz[i-1][j-1][k] = auxiliar[0];
				matriz[i-1][j][k]   = auxiliar[1];
				matriz[i-1][j+1][k] = auxiliar[2];
				matriz[i][j-1][k]   = auxiliar[3];
				matriz[i][j][k]     = auxiliar[4];
				matriz[i+1][j][k]   = auxiliar[5];
				matriz[i][j+1][k]   = auxiliar[6];
				matriz[i+1][j+1][k] = auxiliar[7];
				matriz[i+1][j-1][k] = auxiliar[8];
			}
		}
	}
	return 0;
}
