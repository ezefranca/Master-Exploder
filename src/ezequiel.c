#include "ezequiel.h"

//Funcoes de teste em processamento de imagens

int distancia_euclidiana(unsigned char r_velho, unsigned char g_velho, unsigned char b_velho, unsigned char r_atual, unsigned char g_atual, unsigned char b_atual){

    int soma_r = r_velho - r_atual;
    int soma_g = g_velho - g_atual;
    int soma_b = b_velho - b_atual;

    int quadrado = (soma_r * soma_r) + (soma_g * soma_g) + (soma_b * soma_b) ;
    int euclidiana = sqrt(quadrado);

    return euclidiana;
}

void removedor_ruidos(unsigned char ***matriz, int vizinhos, int localX, int localY){

    for (int k = 0; k < 3; k++)
    {
        if ((matriz [localX][localY][k] == 255) &&
            (matriz [localX - vizinhos][localY - vizinhos][k] != 255) &&
            (matriz [localX + vizinhos][localY + vizinhos][k] != 255))
        {
            matriz[localX][localY][k] = 0;
               // printf("vizinho FDP");
        }
    }
    return;
}

void valorizador_de_bordas(unsigned char ***matriz, int vizinhos, int localX, int localY){

    for (int i = 1; i < vizinhos; ++i)
    {
        for (int k = 0; k < 2; k++)
        {
            if ((matriz [localX][localY][k] == 255) &&
                (matriz [localX - i][localY - i][k] == 255) &&
                (matriz [localX + i][localY + i][k] == 255))
            {
                matriz[localX][localY][k] = 255;
                matriz[localX][localY][k] = 255;
                matriz[localX + 5][localY][k] = 255;
                matriz[localX][localY + 5][k] = 255;
                matriz[localX + 6][localY][k] = 0;
                matriz[localX][localY + 6][k] = 0;
                matriz[localX + 7][localY][k] = 0;
                matriz[localX][localY + 7][k] = 0;
                   // printf("vizinho FDP");
            }
        }
    }
    return;
}

void rgb_para_hsv(Rgb *cores, Hsv *cores_hsv){

  float vermelho = (float)cores->r/255;
  float verde = (float)cores->g/255;
  float azul = (float)cores->b/255;
  
  float cMax, cMin;
  
  if(vermelho >= azul && vermelho >= verde){
    if(verde > azul) cMin = azul;
    else cMin = verde;
    cMax = vermelho;
  }else if(azul >= verde){
    if(verde > vermelho) cMin = vermelho;
    else cMin = verde;
    cMax = azul;
  }else{
    if(vermelho > azul) cMin = azul;
    else cMin = vermelho;
    cMax = verde;
  }
  
  float delta = cMax - cMin;

  if(delta != 0){
    if(cMax == vermelho){
      if(verde >= azul) cores_hsv->h = 60 * ((verde - azul) / delta);
      else cores_hsv->h = 60 * ((verde - azul) / delta) + 360;
    }
    
    else if(cMax == verde) cores_hsv->h = 60 * ((azul - vermelho) / delta) + 120;
    else cores_hsv->h = 60 * ((vermelho - verde) / delta) + 240;
  }
  else cores_hsv->h = 0;
  
  cores_hsv->s = delta/cMax * 100;
  cores_hsv->v = cMax * 100;
}
