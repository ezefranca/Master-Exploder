#include "filtros.h"

//Matriz do Laplaciano
/********************
 | 0 -1  0|
 |-1  4 -1|
 | 0 -1  0|
 *******************/
void filtro_laplaciano(unsigned char ***matriz, unsigned char ***saida, int altura, int largura){
  int l;
  for (int i = 1; i < altura - 1; i++){
    for (int j = 1; j< largura - 1; j++){
        //l = 128 + (matriz[i-1][j][0] + matriz[i][j-1][0] - 4*matriz[i][j][0] +  matriz[i][j+1][0] + matriz[i+1][j][0]);
        l=128+(matriz[i-1][j][0] + matriz[i][j-1][0] + matriz[i][j+1][0] + matriz[i+1][j][0] - 4*matriz[i][j][0]);
        if( l > 255) l = 255;
        else{
          saida[i][j][0] = l;
          saida[i][j][1] = l;
          saida[i][j][2] = l;

        }
    }
  }
}

//----------------------------------------------------------------------------------------------------------//
void filtro_borda(unsigned char ***matriz, unsigned char ***saida, int altura, int largura)
{

  int g1, g2;
  float divisor, **temp;

  divisor = 0;

  temp = malloc(altura * sizeof(float *));

  for(int i = 0; i < altura; i++) {
    temp[i] = malloc(largura * sizeof(float));

    for(int j = 0; j < largura; j++){
      if(i > 0 && i < altura - 1 && j > 0 && j < largura - 1) {
        g1  =   matriz[i-1][j-1][0] -   matriz[i-1][j+1][0];
        g1 += 2*matriz[ i ][j-1][0] - 2*matriz[ i ][j+1][0];
        g1 +=   matriz[i+1][j-1][0] -   matriz[i+1][j+1][0];

        g2  =   matriz[i-1][j-1][0] -   matriz[i+1][j-1][0];
        g2 += 2*matriz[i-1][ j ][0] - 2*matriz[i+1][ j ][0];
        g2 +=   matriz[i-1][j+1][0] -   matriz[i+1][j+1][0];

        temp[i][j] = sqrt(g1*g1 + g2*g2);

        if(divisor < temp[i][j])
        {
          divisor = temp[i][j];
        }
      }
      else
      {
        temp[i][j] = 0;      }
    }
  }

  for(int i = 0; i < altura; i++) {
    for(int j = 0; j < largura; j++) {
      saida[i][j][0] = (temp[i][j] / divisor) * 255 + 0.5;
      saida[i][j][1] = (temp[i][j] / divisor) * 255 + 0.5;
      saida[i][j][2] = (temp[i][j] / divisor) * 255 + 0.5;
    }
	free(temp[i]);
  }
  free(temp);

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

void filtro_media(unsigned char ***matriz, unsigned char ***saida, int altura, int largura){
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

        for(int k = 9; k > 0; k--)
          for(int l = 0; l < k; l++){
            n = n + buffer[l];

            n = n/9;


            if (n < 0)   n = 0;
            if (n > 255) n = 255;

            //printf("%d\n", n);

            saida[i][j][0] = n;
            saida[i][j][1] = n;
            saida[i][j][2] = n;
          }

      }
    else{
      saida[i][j][0] = matriz[i][j][0];
      saida[i][j][1] = matriz[i][j][1];
      saida[i][j][2] = matriz[i][j][2];
    }
  }
}
