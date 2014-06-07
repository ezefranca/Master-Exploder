#ifndef CONTROLE_H
#define CONTROLE_H

#include <math.h>
#include "fecho.h"
/**
 *  <#Description#>
 */

typedef struct _poligono poligono;

typedef struct {
    poligono *fecho;          
    int selecionado;
} controle;

#endif