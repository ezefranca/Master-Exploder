#ifndef CONTROLE_H
#define CONTROLE_H

#include <math.h>
#include "fecho.h"
/**
 *  <#Description#>
 */

typedef struct _poligono poligono;

typedef struct _controle{
    poligono *fecho;          
    int selecionado;
    double razao;
} controle;

controle *c;

int verificacoes[10];
int padrao;
int contador_global;

int calcula_padrao(poligono *fecho, area *b);

#endif