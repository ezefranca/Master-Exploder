#ifndef FECHO_H
#define FECHO_H

#include "comum.h"

// Referencia teorica
// http://www.cs.princeton.edu/courses/archive/spr03/cs226/lectures/geo.4up.pdf
// http://www.ime.usp.br/~cris/aulas/09_2_331/slides/aula18.pdf
// http://w3.impa.br/~emilio/cg/convex_hull/relatorio.pdf

#define MAXIMO     10000 /* numero maximo de pontos no poligono do fecho convexo */

#define DIMENSAO   3 // DIMENSAO 3
#define X       0    // indice coordenada X
#define Y       1    // indice coordenada Y
#define Z       2    // indice coordenada Z

#define TRUE    1
#define FALSE   0
#define PI  3.1415926
#define EPSILON 0.00000001    /* paranaue que nao eh, mas eh suficiente para ser zero */

typedef int ponto[DIMENSAO];
/**
 *  <#Description#>
 */
 #pragma message "XXXXXXXXXXXX"
typedef struct _poligono{
    int n;          /* numero de pontos no poligono */
    ponto p[MAXIMO];   /* array que vira uma matriz 10000x2 com os pontos do poligono */
} poligono;

typedef struct _area
{
	long int qtd_preto;
	long int qtd_branco;
}area;

// Macros para comparacao, encontrar valor maximo e minimo

#define max(A, B) ((A) > (B) ? (A) : (B))
#define min(A, B) ((A) < (B) ? (A) : (B))

ponto primeiro_ponto;      //primeiro ponto no fecho;
ponto menor_x;
ponto maior_x; 
ponto menor_y;
ponto maior_y;

long int qtd_branco;
long int qtd_preto;

/**
 *  <#Description#>
 *
 *  @param f <#f description#>
 *  @param centroide <#centroide description#>
 */
void centroide(poligono *f, ponto centroide);

/**
 *  <#Description#>
 *
 *  @param p <#p description#>
 *	@param altura
 *	@param largura
 */
void pontos_extremo(poligono *p, int altura, int largura);
/**
 *  <#Description#>
 *
 *  @param f <#f description#>
 *
 *  @return <#return value description#>
 */
double area_do_fecho(poligono *f);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 */
void copia_ponto(ponto a, ponto b);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 */
void swap_ponto(ponto a, ponto b);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *
 *  @return <#return value description#>
 */
double distancia(ponto a, ponto b);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *  @param c <#c description#>
 *
 *  @return <#return value description#>
 */
int area_triangulo_com_sinal(ponto a, ponto b, ponto c);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *  @param c <#c description#>
 *
 *  @return <#return value description#>
 */
int triangulo_area(ponto a, ponto b, ponto c);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *  @param c <#c description#>
 *
 *  @return <#return value description#>
 */
bool sentido_anti_horario(ponto a, ponto b, ponto c);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *  @param c <#c description#>
 *
 *  @return <#return value description#>
 */
bool sentido_horario(ponto a, ponto b, ponto c);
/**
 *  <#Description#>
 *
 *  @param a <#a description#>
 *  @param b <#b description#>
 *  @param c <#c description#>
 *
 *  @return <#return value description#>
 */
bool colinear(ponto a, ponto b, ponto c);
/**
 *  <#Description#>
 *
 *  @param p <#p description#>
 */
void print_poligono(poligono *p);
/**
 *  <#Description#>
 *
 *  @param entrada <#entrada description#>
 *  @param n       <#n description#>
 */
void ordena_e_remove_duplicados(ponto entrada[], int *n);
/**
 *  <#Description#>
 *
 *  @param entrada <#entrada description#>
 *  @param n       <#n description#>
 *  @param fecho   <#fecho description#>
 */
void fecho_convexo(ponto entrada[], int n, poligono *fecho);
/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 *
 *  @return <#return value description#>
 */
poligono* fecho(unsigned char ***matriz, int altura, int largura);
/**
 *  <#Description#>
 *
 *  @param p1 <#p1 description#>
 *  @param p2 <#p2 description#>
 *
 *  @return <#return value description#>
 */
int mais_a_esquerda(ponto *p1, ponto *p2);
/**
 *  <#Description#>
 *
 *  @param p1 <#p1 description#>
 *  @param p2 <#p2 description#>
 *
 *  @return <#return value description#>
 */
int menor_angulo(ponto *p1, ponto *p2);

/**
 *  <#Description#>
 *
 *  @param centroide <#x description#>
 *	@param matriz_pb_cor <#matriz_pb_cor description#>
 
 *  @return <#return value description#>
 */
area* conta_pb(ponto centroide, unsigned char ***matriz_pb_cor);

#endif
