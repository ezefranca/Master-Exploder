#include "fecho.h"

/**
 *  Calcula o centroide do fecho convexo
 *
 *  @param f recebe um fecho convexo
 *  @param centroide recebe um ponto, onde será atribuido a coordenada centroide
 */
void centroide(poligono *f, ponto centroide){
    int x = 0, y = 0;
    int n = f->n;

    if (n == 0)
        n = 1;

    for (int i=0; i < f->n ;i++) {
        x += f->p[i][X];
        y += f->p[i][Y]; 
	}
	centroide[X] = x / n;
	centroide[Y] = y / n;
}
/**
 *  Copia pontos
 *
 *  @param a ponto a ser copiado
 *  @param b ponto a ser escrito
 */
void copia_ponto(ponto a, ponto b){
    for (int i=0; i<DIMENSAO; i++){
        b[i] = a[i];
    }
}
/**
 *  Calcula área do fecho convexo pelo método shoelace
 *
 *  @param f recebe um fecho convexo
 *
 *  @return retorna um double com o valor da área
 */
double area_do_fecho(poligono *f){
   int i,j;
   double area = 0;

   for (i=0; i < f->n ;i++) {
      j = (i + 1) % f->n;
      area += f->p[i][X] * f->p[j][Y];
      area -= f->p[i][Y] * f->p[j][X];
   }

   area /= 2;
   if (area < 0)
       area *= -1;

   return area;
}
/**
 *  Encontra os pontos extremos do fecho convexo
 *
 *  @param p recebe um tipo poligono (fecho convexo)
 *  @param largura largura da matriz/imagem
 *  @param altura  altura da matriz/imagem
 */
void pontos_extremo(poligono *p, int largura, int altura){
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

        if(p->p[i][Y] > maior_y[Y])
        {
            maior_y[X] = p->p[i][X];
            maior_y[Y] = p->p[i][Y];
        }
    }
    //copia_ponto(menor_ponto,ponto_inicial);
    //printf("menor ponto X(%d,%d)\n",menor_x[X], menor_x[Y]);
    //printf("maior ponto X(%d,%d)\n",maior_x[X], maior_x[Y]);
    //printf("menor ponto Y(%d,%d)\n",menor_y[X], menor_y[Y]);
    //printf("maior ponto Y(%d,%d)\n",maior_y[X], maior_y[Y]);
	printf("ponto teste (%d,%d) (%d,%d)", menor_x[X], maior_y[Y], maior_x[X], menor_y[Y]);
    return;
}
/**
 *  Troca a posicões dos pontos
 *
 *  @param a ponto a
 *  @param b ponto b
 */
void swap_ponto(ponto a, ponto b)
{
    ponto c;
    copia_ponto(a,c);
    copia_ponto(b,a);
    copia_ponto(c,b);
}
/**
 *  Calcula a distancia entre dois pontos
 *
 *  @param a ponto a
 *  @param b ponto b
 *
 *  @return retorna a distancia entre os dois pontos
 */
double distancia(ponto a, ponto b)
{
    double d = 0.0;       // distancia  acumulada
    
    for (int i=0; i<DIMENSAO; i++)
        d = d + (a[i]-b[i]) * (a[i]-b[i]);
    
    return(sqrt(d));
}
/**
 *  Calcula a área do triangulo
 *
 *  @param a ponto da coordenada 1
 *  @param b ponto da coordenada 2
 *  @param c ponto da coordenada 3
 *
 *  @return retorna o valor da área
 */
int area_triangulo_com_sinal(ponto a, ponto b, ponto c)
{
    int area = ((a[X]*b[Y] - a[Y]*b[X] + a[Y]*c[X]
                 - a[X]*c[Y] + b[X]*c[Y] - c[X]*b[Y]));
    return area;
}
/**
 *  Calcula a área total (sem sinal) do triangulo
 *
 *  @param a ponto da coordenada 1
 *  @param b ponto da coordenada 2
 *  @param c ponto da coordenada 3
 *
 *  @return retorna o valor da área
 */
int triangulo_area(ponto a, ponto b, ponto c){
    return(abs(area_triangulo_com_sinal(a,b,c)));
}
/**
 *  Verifica a tendencia dos pontos estarem anti-horarios
 *
 *  @param a ponto da coordenada 1
 *  @param b ponto da coordenada 2
 *  @param c ponto da coordenada 3
 *
 *  @return boleano 0 ou 1
 */
bool sentido_anti_horario(ponto a, ponto b, ponto c){
    int area_triangulo_com_sinal();
    
    return (area_triangulo_com_sinal(a,b,c) > 0);
}
/**
 *  Verifica a tendencia dos pontos estarem sentido horario.
 *
 *  @param a ponto da coordenada 1
 *  @param b ponto da coordenada 2
 *  @param c ponto da coordenada 3
 *
 *  @return boleano 0 ou 1
 */
bool sentido_horario(ponto a, ponto b, ponto c){
    int area_triangulo_com_sinal();
    
    return (area_triangulo_com_sinal(a,b,c) < 0);
}

/**
 *  Verifica se tres pontos estão colineares
 *
 *  @param a ponto da coordenada 1
 *  @param b ponto da coordenada 2
 *  @param c ponto da coordenada 3
 *
 *  @return boleano 0 ou 1 se estiverem ou não
 */
bool colinear(ponto a, ponto b, ponto c){
    int area_triangulo_com_sinal();
    
    return (fabs(area_triangulo_com_sinal(a,b,c)) <= 0);
}

/**
 *  Desenha na tela o fecho convexo
 *
 *  @param p recebe como parametro um fecho convexo.
 */
void print_poligono(poligono *p){
    ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);

    for (int i = 0; i < p->n ; i++){       
        int j = (i + 1) ;//% p->n;
        al_draw_line(p->p[i][X], p->p[i][Y], p->p[j][X], p->p[j][Y], vermelho, 5);
    }
}
/**
 *  Ordena os vertices do fecho convexo
 *
 *  @param entrada array de pontos do fecho
 *  @param n       numero de pontos do fecho
 */
void ordena_e_remove_duplicados(ponto entrada[], int *n){
    int old_n;               // numero n de pontos antes de deletar
    int del;                 // intervalo para deletar pontos
    int mais_a_esquerda();
    
    qsort(entrada, *n, sizeof(ponto), mais_a_esquerda);
}
/**
 *  Função que calcula o fecho convexo
 *
 *  @param entrada array de pontos possiveis no fecho
 *  @param n       quantidade do array acima
 *  @param fecho   um tipo poligono, fecho
 */
void fecho_convexo(ponto entrada[], int n, poligono *fecho){
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
        h++;
        copia_ponto(entrada[i], fecho->p[h]);
        entrada[i][Z] = 1; // "visitado"
    }while((fecho->p[0][X] != entrada[i][X] || fecho->p[0][Y] != entrada[i][Y]));
    fecho->n = h;
}
/**
 *  Função principal do fecho, prepara a execução do fecho
 *
 *  @param matriz  matriz com da tela
 *  @param altura  altura da tela
 *  @param largura largura da tela
 *
 *  @return ponteiro de poligono, ponteiro para um fecho convexo.
 */
poligono* fecho(unsigned char ***matriz, int altura, int largura){
    
    ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);
    ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
    ponto entrada[MAXIMO];
    poligono *fecho;
    fecho = malloc(sizeof(poligono));
    int n = 0; //numero de pontos
    //int _vizinhos = 100;
    for (int i = game->_vizinhos; i < altura - game->_vizinhos; i++)
        for (int j = game->_vizinhos; j < largura - game->_vizinhos; j++)
            if(matriz[i][j][0] == 255 && matriz[i][j][1] == 255 && matriz[i][j][2] == 255)
            {                
                entrada[n][X] = j;
                entrada[n][Y] = i;
                n++;
            }        
    if (n > MAXIMO) n = MAXIMO;
    fecho_convexo(entrada, n, fecho);
    return fecho;
}

/**
 *  <#Description#>
 *
 *  @param p1 <#p1 description#>
 *  @param p2 <#p2 description#>
 *
 *  @return <#return value description#>
 */
int mais_a_esquerda(ponto *p1, ponto *p2)
{
    if ((*p1)[X] < (*p2)[X]) return (-1);
    if ((*p1)[X] > (*p2)[X]) return (1);
    
    if ((*p1)[Y] < (*p2)[Y]) return (-1);
    if ((*p1)[Y] > (*p2)[Y]) return (1);
    
    return(0);
}
/**
 *  <#Description#>
 *
 *  @param p1 <#p1 description#>
 *  @param p2 <#p2 description#>
 *
 *  @return <#return value description#>
 */
int menor_angulo(ponto *p1, ponto *p2){
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

/**
 *  Retorna área dos pontos brancos e pretos recursivamente.
 *
 *  @param x <#x description#>
 *  @param y <#y description#>
 *	@param matriz_pb_cor <#matriz_pb_cor description#>
 *	@param a <#a description#>
 *
 *  @return <#return value description#>
 */

void conta_pb_recursivo(int x, int y, unsigned char ***matriz_pb_cor, area *a) {
	bool verificacao;
	
	if(x >= (largura - 10) || y >= (altura - 10) || x < 10 || y < 10)
		return;
	
	if(game->usa_fecho)
		verificacao = (matriz_pb_cor[y][x][0] != 0 || matriz_pb_cor[y][x][1] != 0 || matriz_pb_cor[y][x][2] != 255);//Usa limite do fecho
	else 
		verificacao = (x > menor_x[X] && x < maior_x[X] && y > menor_y[Y] && y < maior_y[Y]);//Usa quadrado.
	if(verificacao) {
		
	 	if(matriz_pb_cor[y][x][0] != 255 || matriz_pb_cor[y][x][1] != 0 || matriz_pb_cor[y][x][2] != 0){
	 		if(matriz_pb_cor[y][x][0] == 255 && matriz_pb_cor[y][x][1] == 255 && matriz_pb_cor[y][x][2] == 255) 
	 			a->qtd_branco++;
	 		else 
	 			a->qtd_preto++;
			
	 		matriz_pb_cor[y][x][0] = 255;
	 		matriz_pb_cor[y][x][1] = 0;
	 		matriz_pb_cor[y][x][2] = 0;
			
	 		conta_pb_recursivo(x - 1, y, matriz_pb_cor, a);
	 		conta_pb_recursivo(x + 1, y, matriz_pb_cor, a);
	 		conta_pb_recursivo(x, y - 1, matriz_pb_cor, a);
	 		conta_pb_recursivo(x, y + 1, matriz_pb_cor, a);
	 	}
	}
	return;
}

/**
 *  Retorna área dos pontos brancos e pretos.
 *
 *  @param centroide <#centroide description#>
 *	@param matriz_pb_cor <#matriz_pb_cor description#>
 *
 *  @return <#return value description#>
 */
area* conta_pb(ponto centroide, unsigned char ***matriz_pb_cor) {
    area *a;
    a->qtd_branco = 0;
    a->qtd_preto = 0;

    /******************************** Marca todos como não visitados ********************************/
    for(int y = 0; y < altura; y++){
      for(int x = 0; x < largura; x++) {
        matriz_pb_cor[y][x][3] = 0;
      }
    }

    /* Vamos pensar no fecho convexo como um plano cartesiano X, Y

    //Verificar o quadrante 1, 2, 3, 4 atrás de pontos brancos e pretos
    /********************
         | C  D |
         | B  A |
    /*******************/


    /************************************ Verificação para frente + baixo ***********************************/
    //Verifica o quadrante A
    /********************
         | X  X |
         | X  A |
    /*******************/
    for(int y = centroide[Y]; y < altura; y++){
      for(int x = centroide[X]; x < largura; x++) {
        //se encontra parede do fecho
        if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 255){
            break;
        }    
        else if(matriz_pb_cor[y][x][0] == 255 && matriz_pb_cor[y][x][1] == 255 && matriz_pb_cor[y][x][2] == 255 && matriz_pb_cor[y][x][3] == 0){
            printf("branco\n");
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_branco++;
        }
        else if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 0 && matriz_pb_cor[y][x][3] == 0){
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_preto++;
        }
      }
    }

    /************************************ Verificação para trás + cima ***********************************/
    //Verifica o quadrante C
    /********************
         | C  X |
         | X  X |
    /*******************/
    for(int y = centroide[Y]; y > 1; y--){
      for(int x = centroide[X]; x > 1; x--) {
        //se encontra parede do fecho
        if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 255){
            break;
        }    
        else if(matriz_pb_cor[y][x][0] == 255 && matriz_pb_cor[y][x][1] == 255 && matriz_pb_cor[y][x][2] == 255 && matriz_pb_cor[y][x][3] == 0){
            printf("%d\n", a->qtd_branco);
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_branco++;
        }
        else if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 0 && matriz_pb_cor[y][x][3] == 0){
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_preto++;
        }
      }
    }

    /************************************ Verificação para trás + baixo ***********************************/
    //Verifica o quadrante B
    /********************
         | X  X |
         | B  X |
    /*******************/
    for(int y = centroide[Y]; y < altura; y++){
      for(int x = centroide[X]; x > 1; x--) {
        //se encontra parede do fecho
        if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 255){
            break;
        }    
        else if(matriz_pb_cor[y][x][0] == 255 && matriz_pb_cor[y][x][1] == 255 && matriz_pb_cor[y][x][2] == 255 && matriz_pb_cor[y][x][3] == 0){
            printf("%d\n", a->qtd_branco);
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_branco++;
        }
        else if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 0 && matriz_pb_cor[y][x][3] == 0){
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_preto++;
        }
      }
    }
    /************************************ Verificação para frente + cima ***********************************/
    //Verifica o quadrante A
    /********************
         | X  D |
         | X  X |
    /*******************/
    for(int y = centroide[Y]; y > 1; y--){
      for(int x = centroide[X]; x < largura; x++) {
        //se encontra parede do fecho
        if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 255){
            break;
        }    
        else if(matriz_pb_cor[y][x][0] == 255 && matriz_pb_cor[y][x][1] == 255 && matriz_pb_cor[y][x][2] == 255 && matriz_pb_cor[y][x][3] == 0){
            printf("%d\n", a->qtd_branco);
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_branco++;
        }
        else if(matriz_pb_cor[y][x][0] == 0 && matriz_pb_cor[y][x][1] == 0 && matriz_pb_cor[y][x][2] == 0 && matriz_pb_cor[y][x][3] == 0){
            matriz_pb_cor[y][x][3] = 1;
            a->qtd_preto++;
        }
      }
    }
return a;
}


