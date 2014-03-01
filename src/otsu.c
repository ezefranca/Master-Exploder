#include "otsu.h"

void otsu_binarizacao(unsigned char ***matriz, unsigned char ***saida, int altura, int largura)
/* método de otsu - referencia teórica wiki.icmc.usp.br/images/b/bb/Otsu_e_derivadas.pdf‎ */
{
  int histograma[256];
  double probabilidade[256], omega[256]; /* probabilidade de ser cinza */
  double myu[256];
  double max_sigma, sigma[256];
  int i, x, y, z; /* variaveis para os loops for */
  int limiar; /* limiar para binarização */
  int r = 0, g = 0, b = 0, media = 0;

  /* geração do histograma */
  for (i = 0; i < 256; i++) histograma[i] = 0;
    for (y = 0; y < altura; y++)
      for (x = 0; x < largura; x++) {
        for (z = 0; z < 3; z++)
          histograma[matriz[y][x][z]]++;
      }
  /* calculo da probabilidade */
      for ( i = 0; i < 256; i ++ ) {
        probabilidade[i] = (double)histograma[i] / (altura * largura);
      }

  /* omega e myu*/
      omega[0] = probabilidade[0];
      myu[0] = 0.0;
      for (i = 1; i < 256; i++) {
        omega[i] = omega[i-1] + probabilidade[i];
        myu[i] = myu[i-1] + i*probabilidade[i];
      }


/* Maximização do sigma, determina o valor de Limiar ideal */
  //Não entendi 100% a ideia aqui...
      limiar = 0;
      max_sigma = 0.0;
      for (i = 0; i < 255; i++) {
        if (omega[i] != 0.0 && omega[i] != 1.0)
          sigma[i] = pow(myu[255]*omega[i] - myu[i], 2) / (omega[i]*(1.0 - omega[i]));
        else
          sigma[i] = 0.0;
        if (sigma[i] > max_sigma) {
          max_sigma = sigma[i];
          limiar = i;
        }
      }

  /* saida da binarização */

      for (y = 0; y < altura; y++)
        for (x = 0; x < largura; x++){
          r = matriz[y][x][0];
          g = matriz[y][x][1];
          b = matriz[y][x][2];

        media = (r + g + b) / 3;
        //printf("%d\n", media);

        if(media > limiar) {
          matriz[y][x][0] = 0;
          matriz[y][x][1] = 0;
          matriz[y][x][2] = 0;
        }
        else{
          matriz[y][x][0] = 255;
          matriz[y][x][1] = 255;
          matriz[y][x][2] = 255;
        }
      }

}