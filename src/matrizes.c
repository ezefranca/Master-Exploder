#include "matrizes.h"

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
