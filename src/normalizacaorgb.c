int normalizacaorgb(unsigned char ***matriz, int altura, int largura){
	unsigned char r = 0, g = 0, b = 0, media = 0;
	int i, j;
	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++){

				r = matriz[i][j][0];
				g = matriz[i][j][1];
				b = matriz[i][j][2];

				media = (r + g + b);
				//printf("%d\n", media);
				if(!media){

				matriz[i][j][0] = r / media;
				matriz[i][j][1] = g / media;
				matriz[i][j][2] = b / media;
				
				}
				
				else{
				
				matriz[i][j][0] = 0;
				matriz[i][j][1] = 0;
				matriz[i][j][2] = 0;

				}
		}
	return 1;
	}
}
	