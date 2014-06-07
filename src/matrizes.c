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