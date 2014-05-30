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
        double d = 0.0;       // distancia  acumulada

        for (int i=0; i<DIMENSAO; i++)
                d = d + (a[i]-b[i]) * (a[i]-b[i]);

        return(sqrt(d));
}

int area_triangulo_com_sinal(ponto a, ponto b, ponto c)
{
    int area = ((a[X]*b[Y] - a[Y]*b[X] + a[Y]*c[X]
        - a[X]*c[Y] + b[X]*c[Y] - c[X]*b[Y]));
    return area ;
}

int triangulo_area(ponto a, ponto b, ponto c)
{
    return(abs(area_triangulo_com_sinal(a,b,c)));
}

bool sentido_anti_horario(ponto a, ponto b, ponto c)
{
    int area_triangulo_com_sinal();

    return (area_triangulo_com_sinal(a,b,c) > 0);
}

bool sentido_horario(ponto a, ponto b, ponto c)
{
    int area_triangulo_com_sinal();

    return (area_triangulo_com_sinal(a,b,c) < 0);
}

bool colinear(ponto a, ponto b, ponto c)
{
    int area_triangulo_com_sinal();

    return (fabs(area_triangulo_com_sinal(a,b,c)) <= 0);
}

void print_poligono(poligono *p)
{
    ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);
    printf("comecou\n");
    for (int k = 0; k < p->n ; k++)
        for (int j = k; j < p->n; j++)
            if (p->p[k][X] == p->p[j][X] && p->p[j][X] == p->p[j][Y])
            {
                printf("ALERTA DE REPETIDO, ALERTA DE REPETIDO\n");
            }
    for (int i = 0; i < p->n -1 ; i++){
        //for (int j = 0; j < p->n; j++){
               // d = distancia(p->p[i], p->p[j]);
               // if (d < menor_distancia)
               // {
               //     menor_distancia = d;
               //     copia_ponto(p->p[j], p->p[i+1]);

               // }
              //printf("(%lf,%lf)\n",p->p[i][X],p->p[i][Y]);

                int j = (i + 1); // % p->n;
                //al_draw_filled_circle(p->p[i+1][X], p->p[i+1][Y], 1, vermelho);
                al_draw_line(p->p[i][X], p->p[i][Y], p->p[j][X], p->p[j][Y], vermelho, 10);

                al_draw_line(p->p[i][X], p->p[i][Y], p->p[j][X], p->p[j][Y], vermelho, 5);

            //}
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
    printf("terminou\n");
}

void ordena_e_remove_duplicados(ponto entrada[], int *n)
{
    int old_n;               // numero n de pontos antes de deletar
    int del;                 // intervalo para deletar pontos
    int mais_a_esquerda();

    qsort(entrada, *n, sizeof(ponto), mais_a_esquerda);

    /*
	for (int i=*n-1; i>0; i--)
        for (int j=0; j<i; j++) {
            int resp;
            if(entrada[j][X] < entrada[j+1][X])
                resp = -1;
            else if(entrada[j][X] > entrada[j+1][X])
                resp = 1;
            else if(entrada[j][Y] < entrada[j+1][Y])
                resp = -1;
            else if(entrada[j][Y] > entrada[j+1][Y])
                resp = 1;
            else
                resp = 0;

            if(resp > 0) {
                int aux;
                aux = entrada[j][X];
                entrada[j][X] = entrada[j+1][X];
                entrada[j+1][X] = aux;

                aux = entrada[j][Y];
                entrada[j][Y] = entrada[j+1][Y];
                entrada[j+1][Y] = aux;
            }
        }
	*/
	
    // old_n = *n;
    // del = 1;
    //     for (int i=1; i<old_n; i++) {
    //     if ((entrada[del-1][X] == entrada[i][X]) && (entrada[del-1][Y] == entrada[i][Y]))
    //                     (*n)--;
    //             else {
    //                     copia_ponto(entrada[i],entrada[del]);
    //                     del = del + 1;
    //             }
    //     }
    //     copia_ponto(entrada[old_n-1],entrada[del]);
}

void fecho_convexo(ponto entrada[], int n, poligono *fecho)
{

    int k;          //outro contador
    int i, j;
    int top;        // tamanho (qtd de pontos) atual do fecho
    int menor_angulo(); // forward declaration

    if (n <= 3) {       // todos os pontos no fecho, ou seja fecho eh uma linha ou triangulo
        for (i=0; i<n; i++)
            copia_ponto(entrada[i],fecho->p[i]);
        fecho->n = n;
        return;
    }

    for(i = 0; i < n; i++)
      entrada[i][Z] = 0;

    ordena_e_remove_duplicados(entrada,&n);
    // printf("imprimindo\n");
    // for(i = 0; i < n; i++)
    //     printf("(%d, %d) \n", entrada[i][X], entrada[i][Y]);
    // printf("\n");
    int h = 0;
    copia_ponto(entrada[0], fecho->p[h]);
    entrada[0][Z] = 1;
    //printf("comecou\n");
    do {
        for(i = 0; i < n; i++)
      if((i == 0 || entrada[i][Z] == 0) && (fecho->p[h][X] != entrada[i][X] || fecho->p[h][Y] != entrada[i][Y]))
                break;

        for(j = 0; j < n; j++)
      if((j == 0 || entrada[j][Z] == 0) && (fecho->p[h][X] != entrada[j][X] || fecho->p[h][Y] != entrada[j][Y])) {
            if(entrada[i][X] != entrada[j][X] || entrada[i][Y] != entrada[j][Y]) {
                if(area_triangulo_com_sinal(fecho->p[h], entrada[i], entrada[j]) > 0)
                   i = j;
                else {
                    if(area_triangulo_com_sinal(fecho->p[h], entrada[i], entrada[j]) == 0) {
              double dhi = distancia(fecho->p[h], entrada[i]);
              double dhj = distancia(fecho->p[h], entrada[j]);
              double dij = distancia(entrada[i], entrada[j]);
              if(dij > dhi && dij > dhj)
            i = j;
              else
            if(dhi > dhj)
              i = j;
                    }
                }
            }
            }
                //if(!sentido_anti_horario(fecho->p[h], entrada[i], entrada[j]))
        //printf("adicionar %d\n", i);
        h++;
        //printf("H:%d N:%d\n",h, n );
        copia_ponto(entrada[i], fecho->p[h]);
    entrada[i][Z] = 1;
    }while((fecho->p[0][X] != entrada[i][X] || fecho->p[0][Y] != entrada[i][Y]));
    //printf("terminou\n");
    fecho->n = h;
    printf("imprimindo fecho\n");
    for(i = 0; i < fecho->n; i++)
        printf("(%d, %d) \n", fecho->p[i][X], fecho->p[i][Y]);
    printf("\n");
/*
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
*/
}

poligono* fecho(unsigned char ***matriz, int altura, int largura){

    ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);
    ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
    ponto entrada[MAXIMO];
    poligono *fecho;
    fecho = malloc(sizeof(poligono));
    int n = 0;              //numero de pontos

    int _vizinhos = 1;
    al_draw_filled_rectangle(_vizinhos, _vizinhos, (largura - _vizinhos),(altura - _vizinhos) , verde);
    for (int i = _vizinhos; i < altura - _vizinhos; i++)
    {
    for (int j = _vizinhos; j < largura - _vizinhos; j++)
        {
           // removedor_ruidos(matriz, _vizinhos, i, j);
            if(matriz[i][j][0] == 255 && matriz[i][j][1] == 255 && matriz[i][j][2] == 255)
            {
             //   al_draw_filled_circle(j, i, 5, azul);
                // printf("pinta de verde\n");
                // matriz[i][j][0] = 255;
                // matriz[i][j][1] = 0;
                // matriz[i][j][2] = 0;

                entrada[n][X] = j;
                entrada[n][Y] = i;
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


int mais_a_esquerda(ponto *p1, ponto *p2)
{
    if ((*p1)[X] < (*p2)[X]) return (-1);
    if ((*p1)[X] > (*p2)[X]) return (1);

        if ((*p1)[Y] < (*p2)[Y]) return (-1);
        if ((*p1)[Y] > (*p2)[Y]) return (1);

    return(0);

  //     if ( Area2(a,b,c) > 0 )
  //   return (1);
  // return (0);
}

int menor_angulo(ponto *p1, ponto *p2)
{
    if (colinear(primeiro_ponto,*p1,*p2)) {
        if (distancia(primeiro_ponto,*p1) < distancia(primeiro_ponto,*p2))
            return -1;
        else
            return 1;
    }

    if (sentido_anti_horario(primeiro_ponto,*p1,*p2))
        return -1;
    else
        return 1;
}
