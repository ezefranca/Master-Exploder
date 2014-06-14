#ifndef EZEQUIEL_H
#define EZEQUIEL_H

#include <math.h>
/**
 *  <#Description#>
 */
typedef struct {
    int r;       // vermelho
    int g;       // verde
    int b;       // azul
} RGB;

/**
 *  <#Description#>
 */
typedef struct {
    double h;       // hue
    double s;       // 
    double v;       //
} HSV;

/**
 *  <#Description#>
 *
 *  @param primeiro <#primeiro description#>
 *  @param atual    <#atual description#>
 *  @param i        <#i description#>
 *  @param j        <#j description#>
 *
 *  @return <#return value description#>
 */
int distancia_euclidiana(unsigned char ***primeiro, unsigned char ***atual, int i, int j);
/**
 *  <#Description#>
 *
 *  @param matriz   <#matriz description#>
 *  @param vizinhos <#vizinhos description#>
 *  @param localX   <#localX description#>
 *  @param localY   <#localY description#>
 */
void removedor_ruidos(unsigned char ***matriz, int vizinhos, int localX, int localY);
/**
 *  <#Description#>
 *
 *  @param matriz   <#matriz description#>
 *  @param vizinhos <#vizinhos description#>
 *  @param localX   <#localX description#>
 *  @param localY   <#localY description#>
 */
void valorizador_de_bordas(unsigned char ***matriz, int vizinhos, int localX, int localY);
/**
 *  <#Description#>
 *
 *  @param cores     <#cores description#>
 *  @param cores_hsv <#cores_hsv description#>
 */
void rgb_para_hsv(RGB *cores, HSV *cores_hsv);

#endif
