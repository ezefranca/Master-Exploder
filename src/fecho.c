#include "fecho.h"

void copia_ponto(ponto a, ponto b)
{
    for (int i=0; i<DIMENSAO; i++){
        b[i] = a[i];
    }
}

double area_do_fecho(poligono *f)
{
   int i,j;
   double area = 0;

   for (i=0; i < f->n ;i++) {
      j = (i + 1) % f->n;
      area += f->p[i][X] * f->p[j][Y];
      area -= f->p[i][Y] * f->p[j][X];
   }

   area /= 2;
   if (area < 0)
       area = area * -1;

   return area;
}

void pontos_extremo(poligono *p){
    ponto menor_x, maior_x, menor_y, maior_y;
    
    menor_x[X] = MAXIMO;
    menor_x[Y] = MAXIMO;

    maior_x[X] = 0;
    maior_x[Y] = 0;

    menor_y[X] = MAXIMO;
    menor_y[Y] = MAXIMO;

    maior_y[X] = 0;
    maior_y[Y] = 0;

    for(int i = 0; i < p->n; i++){
        if(p->p[i][X] < menor_x[X])
        {
            menor_x[X] = p->p[i][X];
            menor_x[Y] = p->p[i][Y];
        }

        if(p->p[i][X] > maior_x[X])
        {
            maior_x[X] = p->p[i][X];
            maior_x[Y] = p->p[i][Y];
        }

        if(p->p[i][Y] < menor_y[Y])
        {
            menor_y[X] = p->p[i][X];
            menor_y[Y] = p->p[i][Y];
        }

        if(p->p[i][X] > maior_y[Y])
        {
            maior_y[X] = p->p[i][X];
            maior_y[Y] = p->p[i][Y];
        }
    }
    //copia_ponto(menor_ponto,ponto_inicial);
    printf("menor ponto X(%d,%d)\n",menor_x[X], menor_x[Y]);
    printf("maior ponto X(%d,%d)\n",maior_x[X], maior_x[Y]);
    printf("menor ponto Y(%d,%d)\n",menor_y[X], menor_y[Y]);
    printf("maior ponto Y(%d,%d)\n",maior_y[X], maior_y[Y]);
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
    //printf("comecou\n");
    for (int k = 0; k < p->n ; k++)
        for (int j = k; j < p->n; j++)
            if (p->p[k][X] == p->p[j][X] && p->p[j][X] == p->p[j][Y])
            {
                //printf("ALERTA DE REPETIDO, ALERTA DE REPETIDO\n");
            }
    for (int i = 0; i < p->n ; i++){
        //for (int j = 0; j < p->n; j++){
        // d = distancia(p->p[i], p->p[j]);
        // if (d < menor_distancia)
        // {
        //     menor_distancia = d;
        //     copia_ponto(p->p[j], p->p[i+1]);
        
        // }
        //printf("(%lf,%lf)\n",p->p[i][X],p->p[i][Y]);
        
        int j = (i + 1) ;//% p->n;
        //al_draw_filled_circle(p->p[i+1][X], p->p[i+1][Y], 1, vermelho);
        al_draw_line(p->p[i][X], p->p[i][Y], p->p[j][X], p->p[j][Y], vermelho, 1);
        
        // al_draw_line(p->p[i][X], p->p[i][Y], p->p[j][X], p->p[j][Y], vermelho, 5);
        
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
    //al_draw_line(p->p[p->n][X], p->p[p->n][Y], primeiro_ponto[X], primeiro_ponto[Y], vermelho, 25);
}

void ordena_e_remove_duplicados(ponto entrada[], int *n)
{
    int old_n;               // numero n de pontos antes de deletar
    int del;                 // intervalo para deletar pontos
    int mais_a_esquerda();
    
    qsort(entrada, *n, sizeof(ponto), mais_a_esquerda);
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

    int h = 0;
    entrada[0][Z] = 1;
    copia_ponto(entrada[0], fecho->p[h]);
    copia_ponto(entrada[0], primeiro_ponto);
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
        entrada[i][Z] = 1; // "visitado"
    }while((fecho->p[0][X] != entrada[i][X] || fecho->p[0][Y] != entrada[i][Y]));
    //copia_ponto(fecho->p[0],fecho->p[h]);
    fecho->n = h;
}

poligono* fecho(unsigned char ***matriz, int altura, int largura){
    
    ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);
    ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
    ponto entrada[MAXIMO];
    poligono *fecho;
    fecho = malloc(sizeof(poligono));
    int n = 0;              //numero de pontos
    
    int _vizinhos = 100;
    for (int i = _vizinhos; i < altura - _vizinhos; i++)
        for (int j = _vizinhos; j < largura - _vizinhos; j++)
            if(matriz[i][j][0] == 255 && matriz[i][j][1] == 255 && matriz[i][j][2] == 255)
            {                
                entrada[n][X] = j;
                entrada[n][Y] = i;
                n++;
            }        
    if (n > MAXIMO) n = MAXIMO;

    //printf("Quantidade de pontos %d\n", n);
    fecho_convexo(entrada, n, fecho);
    //ponto_extremo(fecho, menor_x, maior_x, menor_y, maior_y);
    return fecho;
}


int mais_a_esquerda(ponto *p1, ponto *p2)
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
