#ifndef CONTROLE_H
#define CONTROLE_H

#include <math.h>
#include "fecho.h"

/**
 *  <#Description#>
 */

typedef struct _poligono poligono;
typedef struct _area area;

typedef struct _mao
{
    ponto menor_x;
    ponto maior_x; 
    ponto menor_y;
    ponto maior_y;
    int qtd_branco;
    int area_fecho;
} MAO;

typedef struct _controle{
    poligono *fecho;          
    int selecionado;
    int max_x;
    int max_y;
    int min_x;
    int min_y;
    int qtd_branco;
    double razao;
} controle;

controle *c;
MAO *pedra_inicial;

int verificacoes[10];
int padrao;
int contador_global;


/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
int calcula_padrao(poligono *f, area *b, MAO *pedra_inicial);

/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void captura_pedra(MAO *pedra_inicial, poligono *fecho, area *b);

#endif