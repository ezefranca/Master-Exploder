#include "fecho.h"

void copia_ponto(ponto a, ponto b)
{
    for (int i=0; i<DIMENSAO; i++){
        b[i] = a[i];
    }
}

void ponto_extremo(ponto entrada[], ponto ponto_inicial, int n){
    int menor_X = MAXIMO;
    int menor_Y = MAXIMO;
    ponto menor_ponto;
    for(int i = 0; i < n-1; i++){
        if(entrada[i][X] < menor_X && entrada[i][Y] < menor_Y)
        {
            menor_X = entrada[i][X];
            menor_Y = entrada[i][Y];
            //menor_ponto = entrada[i];
            copia_ponto(menor_ponto, entrada[i]);
        }
    }
    copia_ponto(menor_ponto,ponto_inicial);
    return;
}

void swap_ponto(ponto a, ponto b)
{
    ponto c;
    copia_ponto(a,c);
    copia_ponto(b,a);
    copia_ponto(c,b);
}

double distancia(ponto a, ponto b)
{
        double d=0.0;       // distancia  acumulada

        for (int i=0; i<DIMENSAO; i++)
                d = d + (a[i]-b[i]) * (a[i]-b[i]);

        return( sqrt(d) );
}

double area_triangulo_com_sinal(ponto a, ponto b, ponto c)
{
    float area = ((a[X]*b[Y] - a[Y]*b[X] + a[Y]*c[X]
        - a[X]*c[Y] + b[X]*c[Y] - c[X]*b[Y]) / 2.0 );
    return area ;
}

double triangulo_area(ponto a, ponto b, ponto c)
{
    return( fabs(area_triangulo_com_sinal(a,b,c)) );
}

bool sentido_anti_horario(ponto a, ponto b, ponto c)
{
    double area_triangulo_com_sinal();

    return (area_triangulo_com_sinal(a,b,c) > EPSILON);
}

bool sentido_horario(ponto a, ponto b, ponto c)
{
    double area_triangulo_com_sinal();

    return (area_triangulo_com_sinal(a,b,c) < - EPSILON);
}

bool colinear(ponto a, ponto b, ponto c)
{
    double area_triangulo_com_sinal();

    return (fabs(area_triangulo_com_sinal(a,b,c)) <= EPSILON);
}

void print_poligono(poligono *p)
{
    ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);
    int d = 500, menor_distancia = 0;
//    ponto temp;
    printf("%d\n", p->n);
    for (int i = 0; i < p->n - 1; i++){
        for (int j = 0; j < p->n - 1; j++){
               d = distancia(p->p[i], p->p[j]);
               if (d < menor_distancia)
               {
                   menor_distancia = d;
                   copia_ponto(p->p[j], p->p[i+1]);

               }
              // printf("(%lf,%lf)\n",p->p[i][X],p->p[i][Y]);


                //al_draw_filled_circle(p->p[i+1][X], p->p[i+1][Y], 1, vermelho);
                al_draw_line(p->p[i][X], p->p[i][Y], p->p[i+1][X], p->p[i+1][Y], vermelho, 10);

            }
            // if(d > 300){
            //     printf("Naruto\n");
            // if (i == 0 || i == 1)
            // {
            //     al_draw_filled_circle(p->p[i][X], p->p[i][Y], 10, vermelho);
            // }else
            // al_draw_filled_circle(p->p[i+1][X], p->p[i+1][Y], 1, vermelho);
            // //al_draw_line(p->p[i][X], p->p[i][Y], p->p[i+1][X], p->p[i+1][Y], vermelho, 1);
            // }
        }
}

void ordena_e_remove_duplicados(ponto entrada[], int *n)
{
    int old_n;               // numero n de pontos antes de deletar
    int del;                 // intervalo para deletar pontos
    bool mais_a_esquerda();

    qsort(entrada, *n, sizeof(ponto), mais_a_esquerda);

    old_n = *n;
    del = 1;
        for (int i=1; i<old_n; i++) {
        if ((entrada[del-1][X] == entrada[i][X]) && (entrada[del-1][Y] == entrada[i][Y]))
                        (*n)--;
                else {
                        copia_ponto(entrada[i],entrada[del]);
                        del = del + 1;
                }
        }
        copia_ponto(entrada[old_n-1],entrada[del]);
}

void fecho_convexo(ponto entrada[], int n, poligono *fecho)
{

    int k;          //outro contador
    int i;
    int top;        // tamanho (qtd de pontos) atual do fecho
    int menor_angulo();

    if (n <= 3) {       // todos os pontos no fecho, ou seja fecho eh uma linha ou triangulo
        for (i=0; i<n; i++)
            copia_ponto(entrada[i],fecho->p[i]);
        fecho->n = n;
        return;
    }

    ordena_e_remove_duplicados(entrada,&n);
    copia_ponto(entrada[0],&primeiro_ponto);

    //printf("primeiro ponto %d, %d\n", primeiro_ponto[X], primeiro_ponto[Y]);

    qsort(&entrada[1], n-1, sizeof(ponto), menor_angulo);

    copia_ponto(primeiro_ponto,fecho->p[0]);
    copia_ponto(entrada[1],fecho->p[1]);

    copia_ponto(primeiro_ponto,entrada[n]);  //
    top = 1;
    i = 2;
    k = 2;

    while (i <= n && k <= n) {
        if (!sentido_anti_horario(fecho->p[top-1], fecho->p[top], entrada[i])){
            if(top >= 2){
            top = top-1;
            }
        }else {
            top = top+1;
                        copia_ponto(entrada[i],fecho->p[top]);
            i++;
        }
        k++;
    }

    fecho->n = top;
}

poligono* fecho(unsigned char ***matriz, int altura, int largura){

    ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);
    ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
    ponto entrada[MAXIMO];
    poligono *fecho;
    fecho = malloc(sizeof(poligono));
    int n = 0;              //numero de pontos

    int _vizinhos = 100;
    al_draw_filled_rectangle(_vizinhos, _vizinhos, (largura - _vizinhos),(altura - _vizinhos) , verde);
    for (int i = _vizinhos; i < altura - _vizinhos; i++)
    {
    for (int j = _vizinhos; j < largura - _vizinhos; j++)
        {
           // removedor_ruidos(matriz, _vizinhos, i, j);
            if(matriz[i][j][0] == 255 && matriz[i][j][1] == 255 && matriz[i][j][2] == 255)
            {
                al_draw_filled_circle(j, i, 5, azul);
                // printf("pinta de verde\n");
                // matriz[i][j][0] = 255;
                // matriz[i][j][1] = 0;
                // matriz[i][j][2] = 0;

                entrada[i+j][X] = j;
                entrada[i+j][Y] = i;
                n++;
            }
        }
    }


    // //pintar de preto o resto
    // for (int i = 1; i < altura; i++)
    // {
    // for (int j = 1; j < largura; j++)
    //     {
    //        // removedor_ruidos(matriz, _vizinhos, i, j);
    //         if(matriz[i][j][1] != 255){
    //
    //             matriz[i][j][0] = 0;
    //             matriz[i][j][1] = 0;
    //             matriz[i][j][2] = 0;
    //
    //         }
    //     }
    // }

    if (n > MAXIMO)
    {
        n = MAXIMO;
    }
    //printf("Quantidade de pontos %d\n", n);
    fecho_convexo(entrada, n, fecho);
    //print_poligono(fecho);
    return fecho;
}


bool mais_a_esquerda(ponto *p1, ponto *p2)
{
    if ((*p1)[X] < (*p2)[X]) return (-1);
    if ((*p1)[X] > (*p2)[X]) return (1);

        if ((*p1)[Y] < (*p2)[Y]) return (-1);
        if ((*p1)[Y] > (*p2)[Y]) return (1);

    return(0);
}

int menor_angulo(ponto *p1, ponto *p2)
{
    if (colinear(primeiro_ponto,*p1,*p2)) {
        if (distancia(primeiro_ponto,*p1) <= distancia(primeiro_ponto,*p2))
            return -1;
        else
            return 1;
    }

    if (sentido_anti_horario(primeiro_ponto,*p1,*p2))
        return -1;
    else
        return 1;
}
