#ifndef FECHO_H
#define FECHO_H

#include "comum.h"
#include <math.h>

// Referencia teorica
// http://www.cs.princeton.edu/courses/archive/spr03/cs226/lectures/geo.4up.pdf
// http://pt.wikipedia.org/wiki/Exame_de_Graham
// http://w3.impa.br/~emilio/cg/convex_hull/relatorio.pdf

#define MAX     10000 /* numero maximo de pontos no poligono do fecho convexo */

#define DIMENSAO   2 // DIMENSAO 2 
#define X       0    // indice coordenada X
#define Y       1    // indice coordenada Y

#define TRUE    1
#define FALSE   0
#define PI  3.1415926   
#define EPSILON 0.000001    /* paranaue que nao eh, mas eh suficiente para ser zero */

typedef double ponto[DIMENSAO];

typedef struct {
    int n;          /* numero de pontos no poligono */
    ponto p[MAX];   /* array com os pontos do poligono */
} poligono;

// Macros para comparacao, encontrar valor maximo e minimo

#define max(A, B)       ((A) > (B) ? (A) : (B))
#define min(A, B)       ((A) < (B) ? (A) : (B))

ponto primeiro_ponto;      //primeiro ponto no fecho;


void copia_ponto(ponto a, ponto b);
void swap_ponto(ponto a, ponto b);
double distancia(ponto a, ponto b);
double area_triangulo_com_sinal(ponto a, ponto b, ponto c);
double triangulo_area(ponto a, ponto b, ponto c);
bool sentido_anti_horario(ponto a, ponto b, ponto c);
bool sentido_horario(ponto a, ponto b, ponto c);
bool colinear(ponto a, ponto b, ponto c);
void print_poligono(poligono *p);
void fecho_convexo(ponto entrada[], int n, poligono *fecho);
void ordena_e_remove_duplicados(ponto entrada[], int *n);
int GRAHAM(unsigned char ***matriz, int altura, int largura);
bool mais_a_esquerda(ponto *p1, ponto *p2);
bool menor_angulo(ponto *p1, ponto *p2);

#endif