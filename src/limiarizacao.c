#include "limiarizacao.h"

int limiarizacao(unsigned char ***matriz, int altura, int largura){
	int r = 0, g = 0, b = 0, media = 0;
	int i, j;
	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++){

				r = matriz[i][j][0];
				g = matriz[i][j][1];
				b = matriz[i][j][2];

				media = (r + g + b) / 3;
				//printf("%d\n", media);

				if(media < 128) {
					matriz[i][j][0] = 0;
					matriz[i][j][1] = 0;
					matriz[i][j][2] = 0;
				}
				else{
					matriz[i][j][0] = 255;
					matriz[i][j][1] = 255;
					matriz[i][j][2] = 255;
				}
			}
		}
		return 1;
}