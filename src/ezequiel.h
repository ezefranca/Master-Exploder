#ifndef EZEQUIEL_H
#define EZEQUIEL_H

#include <math.h>

typedef struct {
    int r;       // vermelho
    int g;       // verde
    int b;       // azul
} Rgb;

typedef struct {
    double h;       // hue
    double s;       // 
    double v;       //
} Hsv;

int distancia_euclidiana(unsigned char r_velho, unsigned char g_velho, unsigned char b_velho, unsigned char r_atual, unsigned char g_atual, unsigned char b_atual);
void removedor_ruidos(unsigned char ***matriz, int vizinhos, int localX, int localY);
void valorizador_de_bordas(unsigned char ***matriz, int vizinhos, int localX, int localY);
void rgb_para_hsv(Rgb *cores, Hsv *cores_hsv);

#endif
