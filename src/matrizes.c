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
    int _vizinhos = 100;
    int r , g , b;

	//printf("luminus %s %d", pegar_configuracao("LUMINUS", "camera", config), string_para_int(pegar_configuracao("LUMINUS", "camera", config)));
    for (int y = _vizinhos; y < altura - _vizinhos; y++){
      for (int x = _vizinhos; x < largura - _vizinhos; x++){
        r = abs(atual[y][x][0] -  primeiro[y][x][0]);
        g = abs(atual[y][x][1] -  primeiro[y][x][1]);
        b = abs(atual[y][x][2] -  primeiro[y][x][2]);

		//Verificação da luminosidade.
        if ((r + g + b) > 150)
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