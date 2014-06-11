#include "matrizes.h"

/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void matriz_copia(unsigned char ***matriz, unsigned char ***saida, int altura, int largura){
for (int i = 0; i < altura; i++)
      {
          for (int j = 0; j < largura; j++)
          {
              for (int k = 0; k < 3; k++)
              {
                  saida[i][j][k] = matriz[i][j][k];
              }
          }
      }
}

void bitmap_para_matriz(ALLEGRO_BITMAP *bitmap, unsigned char ***matriz){
	ALLEGRO_LOCKED_REGION *region = al_lock_bitmap(bitmap, ALLEGRO_PIXEL_FORMAT_ARGB_8888, ALLEGRO_LOCK_READWRITE);
	
	char *row = region->data;

	for(int y = 0; y < altura; y++) {
		char *pixel = row;

		for(int x = 0; x < largura; x++) {
			matriz[y][x][0] = *pixel;
			pixel++;

			matriz[y][x][1] = *pixel;
			pixel++;

			matriz[y][x][2] = *pixel;
			pixel += 2;
      // matriz[y][x][2] = *pixel;
      // pixel++;

      // matriz[y][x][1] = *pixel;
      // pixel++;

      // matriz[y][x][0] = *pixel;
      // pixel++;
		}
    row += region->pitch;
  }
  al_unlock_bitmap(bitmap);	
}
/**
 *  <#Description#>
 *
 *  @param atual  <#atual description#>
 *  @param primeiro   <#primeiro description#>
 *  @param matriz  <#matriz description#>
 */
void subtrai_matriz(unsigned char ***atual, unsigned char ***primeiro, unsigned char ***matriz){

    int r , g , b;

	//printf("luminus %s %d", pegar_configuracao("LUMINUS", "camera", config), string_para_int(pegar_configuracao("LUMINUS", "camera", config)));
    for (int y = game->_vizinhos; y < altura - game->_vizinhos; y++){
      for (int x = game->_vizinhos; x < largura - game->_vizinhos; x++){
        r = abs(atual[y][x][0] -  primeiro[y][x][0]);
        g = abs(atual[y][x][1] -  primeiro[y][x][1]);
        b = abs(atual[y][x][2] -  primeiro[y][x][2]);

		//Verificação da luminosidade.
        if ((r + g + b) > game->luminus)
        {
          matriz[y][x][0] = 255;
          matriz[y][x][1] = 255;
          matriz[y][x][2] = 255;
        }

        else
        {
          matriz[y][x][0] = 0;
          matriz[y][x][1] = 0;
          matriz[y][x][2] = 0;
        }   
      }
    }
  }
  
/**
 *  Desenha na matriz a reta a partir de 2 pontos.
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *	@param matriz <#matriz description#>
 *
 */
void desenha_reta(ponto a, ponto b, unsigned char ***matriz){
	double coeficiente_angular;
	double coeficiente_linear;
	int j, ix, fimx, iy, fimy;
	bool usar_y = false;
	
	coeficiente_angular = (double) (b[Y] - a[Y])/(b[X] - a[X]);
	coeficiente_linear = (double) a[Y] - (coeficiente_angular * a[X]);
	
	//printf("Alfa %f\n", coeficiente_angular/*coeficiente_angular, coeficiente_linear*/);
	//printf("Beta %d\n", coeficiente_linear);
	
	//Verificando se o coeficiente angular é positivo ou negativo, ou se é zero.
	if(b[X] > a[X]){
		//Coeficiente negativo
		ix = a[X];
		fimx = b[X];
	}
	else if(b[X] < a[X]){
		//Coeficiente positivo
		ix = b[X];
		fimx = a[X];
	}
	else {
		usar_y = true;
		//Verificando qual Y é maior.
	}
	if(b[Y] > a[Y]){
		iy = a[Y];
		fimy = b[Y];
	}
	else {
		iy = b[Y];
		fimy = a[Y];
	}
		
	//Se X de ambos é igual é necessário fazer o loop com Y.
	if(!usar_y){
		for(ix; ix <= fimx; ix++){
			j = ix * coeficiente_angular + coeficiente_linear;
			matriz[j][ix][0] = 0;
			matriz[j][ix][1] = 0;
			matriz[j][ix][2] = 255;
			matriz[j][ix][3] = 1;
		}
		for(iy; iy < fimy; iy++){
			j = (iy - coeficiente_linear) / coeficiente_angular;
			matriz[iy][j][0] = 0;
			matriz[iy][j][1] = 0;
			matriz[iy][j][2] = 255;
			matriz[iy][j][3] = 1;
		}
	}
	else {
		//i = ao eixo Y, j = eixo X.
		for(iy; iy <= fimy; iy++){
			matriz[iy][a[X]][0] = 0;
			matriz[iy][a[X]][1] = 0;
			matriz[iy][a[X]][2] = 255;
			matriz[iy][a[X]][3] = 1;
		}
	}
}