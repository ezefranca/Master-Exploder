#include "limiarizacao.h"

int limiarizacao(unsigned char ***matriz, int altura, int largura){
	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++)
			for(int k = 0; k < 3; k++){
				if(matriz[i][j][k] < 128)
					matriz[i][j][k] = 0;
				else
					matriz[i][j][k] = 255;
			}
		}
		return 1;
}