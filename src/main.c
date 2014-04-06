#include "init.h"
#include "comum.h"
//////////////////////////////////////////////
#define TRUE    1
#define FALSE   0
#define PI  3.1415926   /* ratio of circumference to diameter */
#define EPSILON 0.000001    /* a quantity small enough to be zero */

#define MAXPOLY     10000 /* maximum numero of pontos in a poligono */

// typedef int bool;

typedef struct {
    double a;       /* x-coefficient */
    double b;       /* y-coefficient */
    double c;       /* constant term */
} line;

#define DIMENSION   2   /* dimension of points */
#define X       0   /* x-coordinate index */
#define Y       1   /* y-coordinate index */

typedef double point[DIMENSION];

typedef struct {
    int n;          /* number of points in polygon */
    point p[MAXPOLY];   /* array of points in polygon */
} polygon;

/*  Comparison macros   */

#define max(A, B)       ((A) > (B) ? (A) : (B))
#define min(A, B)       ((A) < (B) ? (A) : (B))

/********************************/


points_to_line(point p1, point p2, line *l)
{
    if (p1[X] == p2[X]) {
        l->a = 1;
        l->b = 0;
        l->c = -p1[X];
    } else {
            l->b = 1;
        l->a = -(p1[Y]-p2[Y])/(p1[X]-p2[X]);
        l->c = -(l->a * p1[X]) - (l->b * p1[Y]);
    }
}

point_and_slope_to_line(point p, double m, line *l)
{
    l->a = -m;
    l->b = 1;
    l->c = -((l->a*p[X]) + (l->b*p[Y]));
}

bool parallelQ(line l1, line l2)
{
    return ( (fabs(l1.a-l2.a) <= EPSILON) &&
         (fabs(l1.b-l2.b) <= EPSILON) );
}

bool same_lineQ(line l1, line l2)
{
    return ( parallelQ(l1,l2) && (fabs(l1.c-l2.c) <= EPSILON) );
}


void intersection_point(line l1, line l2, point p)
{
    if (same_lineQ(l1,l2)) {
        printf("Warning: Identical lines, all points intersect.\n");
        p[X] = p[Y] = 0.0;
        return;
    }

    if (parallelQ(l1,l2) == TRUE) {
        printf("Error: Distinct parallel lines do not intersect.\n");
        return;
    }

    p[X] = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);

    if (fabs(l1.b) > EPSILON)   /* test for vertical line */
        p[Y] = - (l1.a * (p[X]) + l1.c) / l1.b;
    else
        p[Y] = - (l2.a * (p[X]) + l2.c) / l2.b;
}

void closest_point(point p_in, line l, point p_c)
{
    line perp;      /* perpendicular to l through (x,y) */

    if (fabs(l.b) <= EPSILON) { /* vertical line */
        p_c[X] = -(l.c);
        p_c[Y] = p_in[Y];
        return;
    }

    if (fabs(l.a) <= EPSILON) { /* horizontal line */
        p_c[X] = p_in[X];
        p_c[Y] = -(l.c);
        return;
    }

    point_and_slope_to_line(p_in,1/l.a,&perp); /* non-degenerate line */
/*printf("perpendicular bisector "); print_line(perp);*/
    intersection_point(l,perp,p_c);
/*printf("closest point "); print_point(p_c);*/
}

double distance(point a, point b)
{
        int i;          /* counter */
        double d=0.0;       /* accumulated distance */

        for (i=0; i<DIMENSION; i++)
                d = d + (a[i]-b[i]) * (a[i]-b[i]);

        return( sqrt(d) );
}

/***********************************************************************/

copy_point(point a, point b)
{
    int i;          /* counter */

    for (i=0; i<DIMENSION; i++) b[i] = a[i];
}

swap_point(point a, point b)
{
    point c;        /* temporary point */

    copy_point(a,c);
    copy_point(b,a);
    copy_point(c,b);
}

bool point_in_box(point p, point b1, point b2)
{
    return( (p[X] >= min(b1[X],b2[X])) && (p[X] <= max(b1[X],b2[X]))
        && (p[Y] >= min(b1[Y],b2[Y])) && (p[Y] <= max(b1[Y],b2[Y])) );
}

double signed_triangle_area(point a, point b, point c)
{
    return( (a[X]*b[Y] - a[Y]*b[X] + a[Y]*c[X] 
        - a[X]*c[Y] + b[X]*c[Y] - c[X]*b[Y]) / 2.0 );
}

double triangle_area(point a, point b, point c)
{
    return( fabs(signed_triangle_area(a,b,c)) );
}

bool ccw(point a, point b, point c)
{
    double signed_triangle_area();

    return (signed_triangle_area(a,b,c) > EPSILON);
}

bool cw(point a, point b, point c)
{
    double signed_triangle_area();

    return (signed_triangle_area(a,b,c) < - EPSILON);
}

bool collinear(point a, point b, point c)
{
    double signed_triangle_area();

    return (fabs(signed_triangle_area(a,b,c)) <= EPSILON);
}

print_points(point p[], int n)
{
        int i;                  /* counter */

        for (i=0; i<n; i++)
                printf("(%lf,%lf)\n",p[i][X],p[i][Y]);
}

print_polygon(polygon *p)
{
    ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);
    
          /* counter */

        for (int i=0; i<p->n - 1; i++){
               //printf("(%lf,%lf)\n",p->p[i][X],p->p[i][Y]);

                al_draw_filled_circle(p->p[i][X], p->p[i][Y], 1, vermelho);
                //al_draw_line(p->p[i][X], p->p[i][Y], p->p[i+1][X], p->p[i+1][Y], vermelho, 10);

            }
}

print_point(point p)
{
    printf("%7.3lf %7.3lf\n",p[X],p[Y]);
}

print_line(line l)
{
    printf("(a=%7.3lf,b=%7.3lf,c=%7.3lf)\n",l.a,l.b,l.c);
}

point first_point;      /* first hull point */

void convex_hull(point in[], int n, polygon *hull)
{

    int k; //outro contador
    int i;          /* input counter */
    int top;        /* current hull size */
    bool smaller_angle();

    if (n <= 3) {       /* all points on hull! */
        for (i=0; i<n; i++)
                        copy_point(in[i],hull->p[i]);
        hull->n = n;
        return;
    }

    sort_and_remove_duplicates(in,&n);
    copy_point(in[0],&first_point);

    qsort(&in[1], n-1, sizeof(point), smaller_angle);

    copy_point(first_point,hull->p[0]);
    copy_point(in[1],hull->p[1]);

    copy_point(first_point,in[n]);  /* sentinel to avoid special case */
    top = 1;
    i = 2;
    k = 2;

    while (i <= n && k <= n) {
        if (!ccw(hull->p[top-1], hull->p[top], in[i])){
            if(top >= 2){ 
            top = top-1; 
            }   /* top not on hull */
        }else {
            top = top+1;
                        copy_point(in[i],hull->p[top]);
                        print_point(in[i]);
            i++;
        }
        k++;
    }

    hull->n = top;
}


sort_and_remove_duplicates(point in[], int *n)
{
        int i;                  /* counter */
        int oldn;               /* number of points before deletion */
        int hole;               /* index marked for potential deletion */
    bool leftlower();

    qsort(in, *n, sizeof(point), leftlower);

        oldn = *n;
    hole = 1;
        for (i=1; i<oldn; i++) {
        if ((in[hole-1][X] == in[i][X]) && (in[hole-1][Y] == in[i][Y])) 
                        (*n)--;
                else {
                        copy_point(in[i],in[hole]);
                        hole = hole + 1;
                }
        }
        copy_point(in[oldn-1],in[hole]);
}


int FECHO(unsigned char ***matriz, int altura, int largura){
    point in[MAXPOLY];      /* input points */
    polygon hull;           /* convex hull */
    int n = 0;              /* number of points */
    int i;              /* counter */

    int _vizinhos = 10;
    // scanf("%d",&n);
    // for (i=0; i<n; i++)
    //     scanf("%lf %lf",&in[i][X],&in[i][Y]);
    for (int i = 10; i < altura - _vizinhos; i++)
    {
    for (int j = 10; j < largura - _vizinhos; j++)
        {
           // removedor_ruidos(matriz, _vizinhos, i, j);
            if(matriz[i][j][0] != 0 && matriz[i][j][1] != 0 && matriz[i][j][2] != 0)
            {
                in[i+j][X] = j;
                in[i+j][Y] = i;
                n++;
            }
        }
    }

    if (n > MAXPOLY)
    {
        n = MAXPOLY;
    }
    //printf("Quantidade de pontos %d\n", n);

    convex_hull(in,n,&hull);

    print_polygon(&hull);
    return 0;
}


bool leftlower(point *p1, point *p2)
{
    if ((*p1)[X] < (*p2)[X]) return (-1);
    if ((*p1)[X] > (*p2)[X]) return (1);

        if ((*p1)[Y] < (*p2)[Y]) return (-1);
        if ((*p1)[Y] > (*p2)[Y]) return (1);

    return(0);
}

bool smaller_angle(point *p1, point *p2)
{
    if (collinear(first_point,*p1,*p2)) {
        if (distance(first_point,*p1) <= distance(first_point,*p2))
            return(-1);
        else
            return(1);
    }

    if (ccw(first_point,*p1,*p2))
        return(-1);
    else
        return(1);
}








/////////////////////////////////////////////
int main() {

    inicializar_allegro();

    unsigned char ***matriz = camera_aloca_matriz(cam);
    unsigned char ***matriz_pb = camera_aloca_matriz(cam);
    unsigned char ***matriz2 = camera_aloca_matriz(cam);
    //ALLEGRO_COLOR cor = al_map_rgb_f(0, 0, 1);

    ALLEGRO_BITMAP *buffer = al_get_backbuffer(display);
    ALLEGRO_BITMAP *esquerda = al_create_sub_bitmap(buffer, 0, 0, largura, altura);
    ALLEGRO_BITMAP *direita = al_create_sub_bitmap(buffer, largura, 0, largura, altura);

    ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);

    int desenhar = 0;
    int terminar = 0;
    //int atualiza = 0;

    while(1) {

        ALLEGRO_EVENT event;

        al_wait_for_event(queue, &event);

        switch(event.type) {
            case ALLEGRO_EVENT_TIMER:
            desenhar = 1;
            break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            terminar = 1;
            break;
            default:
            printf("evento desconhecido\n");
        }

        if(terminar)
            break;

        if(desenhar && al_is_event_queue_empty(queue)) {
            desenhar = 0;
            camera_atualiza(cam);
            /**********/
            /**********/
            //limiarizacao(fundo, altura, largura);
            //otsu_binarizacao(fundo, fundo, altura, largura);
            normalizacao_preto_e_branco(cam->quadro, altura, largura);
            matriz_copia(cam->quadro, matriz_pb, altura, largura);
            otsu_binarizacao(matriz_pb, matriz_pb, altura, largura);
            //filtro_borda(cam->quadro, matriz_pb, altura, largura);
           // laplaciano(cam->quadro, matriz, altura, largura);
            filtro_borda(matriz_pb, matriz, altura, largura);
            //limiarizacao(matriz_pb, altura, largura);
            //filtro_mediana(matriz, matriz, altura, largura);
            //filtro_mediana(matriz, matriz, altura, largura);
            // laplaciano(matriz, matriz, altura, largura);
            //filtro_media(matriz, matriz, altura, largura);
            //
            camera_copia(cam, matriz, esquerda);
            camera_copia(cam, matriz_pb, direita);
            //al_draw_circle(300, 300, 10, vermelho, 10);
            //FECHO(matriz_pb, altura, largura);
            
            //camera_copia(cam, fundo, direita);
            /**********/
            
            al_flip_display();
        }
    }

    /**********/

    al_destroy_bitmap(direita);

    al_destroy_bitmap(esquerda);

    camera_libera_matriz(cam, matriz);

    /**********/

    al_stop_timer(timer);

    al_unregister_event_source(queue, al_get_display_event_source(display));
    al_unregister_event_source(queue, al_get_timer_event_source(timer));

    al_destroy_event_queue(queue);
    al_destroy_display(display);
    al_destroy_timer(timer);

    al_shutdown_primitives_addon();
    al_shutdown_image_addon();
    al_uninstall_system();

    camera_finaliza(cam);

    return EXIT_SUCCESS;
}
