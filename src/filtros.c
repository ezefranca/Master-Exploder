	#include "filtros.h"

	//Matriz do Laplaciano
	/*
	| 0 -1  0|
	|-1  4 -1|
	| 0 -1  0|
	*/
	void laplaciano(unsigned char ***matriz, unsigned char ***saida, int altura, int largura){
		int l;
		for (int i = 1; i < altura - 1; i++)
		for (int j = 1; j< largura - 1; j++)
		for (int k = 0; k < 3; k++)
		{
			l = (matriz[i-1][j][k] + matriz[i][j-1][k] + matriz[i][j+1][k] + matriz[i+1][j][k] - 4*matriz[i][j][k]);
			//Normalizacao, menor que zero eh preto, maior que zero eh branco
			if( l > 255 || l < 0 ){
				if(l > 255) l = 255;
				else l = 0;
			}
			else saida[i][j][k] = l;
		}
	}

	void filtro_mediana(unsigned char ***matriz, unsigned char ***saida, int altura, int largura){

		unsigned char buffer[9];
		int k = 0, n = 0;

		for (int i = 0; i < altura; i++) {
			for(int j = 0; j < largura; j++)

			if(i > 0 && i < altura - 1 && j > 0 && j < largura - 1) {

				k = 0;

				for(int di = -1; di <= 1; di++)
				for(int dj = -1; dj <= 1; dj++) {

					buffer[k] = matriz[i + di][j + dj][0];
					// buffer[k] = imagem[i + di][j + dj][1];
					// buffer[k] = imagem[i + di][j + dj][2];
					k++;
				}

				for(int k = 8; k > 0; k--)
				for(int l = 0; l < k; l++){

					if(buffer[l] > buffer[l + 1]) {
						n = buffer[l];
						buffer[l] = buffer[l + 1];
						buffer[l + 1] = n;
					}

					saida[i][j][0] = buffer[4];
					saida[i][j][1] = buffer[4];
					saida[i][j][2] = buffer[4];
				}

			}
			else{
				saida[i][j][0] = matriz[i][j][0];
				saida[i][j][1] = matriz[i][j][1];
				saida[i][j][2] = matriz[i][j][2];
			}
		}
	}
