#include "normalizacao.h"
/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 *
 *  @return <#return value description#>
 */
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

/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 *
 *  @return <#return value description#>
 */
int normalizacao_rgb(unsigned char ***matriz, int altura, int largura){
	unsigned char r = 0, g = 0, b = 0, media = 0;
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
	}
    return 1;
}