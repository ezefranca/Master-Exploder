#include "init.h"
#include "comum.h"
#include "terminate.h"
/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
  int main() {

    inicializar_allegro();

    contador_global = 0;
    padrao = 0;

    unsigned char ***matriz = camera_aloca_matriz(cam);
    unsigned char ***matriz_pb = camera_aloca_matriz(cam);
    unsigned char ***matriz_verde = camera_aloca_matriz(cam);
	unsigned char ***matriz_contagem = camera_aloca_matriz(cam);
    unsigned char ***primeiro = camera_aloca_matriz(cam);
    
    ALLEGRO_BITMAP *buffer = al_get_backbuffer(display);
    ALLEGRO_BITMAP *esquerda = al_create_sub_bitmap(buffer, 0, 0, largura, altura);
    ALLEGRO_BITMAP *direita = al_create_sub_bitmap(buffer, largura, 0, largura, altura);

    //ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);

    int desenhar = 0;
    int terminar = 0;
    int amostragem = 0;
	int tela = 0;
    double x[10]; 
    double fx[10];

    //int atualiza = 0;

    camera_atualiza(cam);

    for(int y = 0; y < altura; y++){
      for(int x = 0; x < largura; x++) {
        primeiro[y][x][0] = cam->quadro[y][x][0];
        primeiro[y][x][1] = cam->quadro[y][x][1];
        primeiro[y][x][2] = cam->quadro[y][x][2];
      }
    }

	if(game->telas->sprite)
		tela_sprite();

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
		
		//Selecao de frames.
		switch(tela){
			case 0:
				
				break;
			case 1:
			
				break;
			case 2:
			
				break;
			case 3:
			
				break;
		}
		
        desenhar = 0;
        camera_atualiza(cam);
		//Antigo remove fundo
        subtrai_matriz(cam->quadro, primeiro, matriz);
        
		normalizacao_preto_e_branco(matriz, altura, largura);
        otsu_binarizacao(matriz, matriz_pb, altura, largura);
        
		filtro_borda(matriz_pb, matriz_pb, altura, largura);
        
		matriz_copia(matriz_pb, matriz_verde, altura, largura);
        poligono *f = fecho(matriz_verde, altura, largura);
		camera_copia(cam, matriz, esquerda);
		
		matriz_copia(matriz, matriz_contagem, altura, largura);

		//camera_copia(cam, matriz_verde, direita);
		
		ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
        ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);
        ALLEGRO_COLOR preto = al_map_rgb_f(0, 0, 0);

        //al_draw_filled_rectangle(1, 1, largura, altura, verde);
		
		/*
        for (int i = game->_vizinhos; i < altura - game->_vizinhos; i++){
          for (int j = game->_vizinhos; j < largura - game->_vizinhos; j++){
                    // removedor_ruidos(matriz, _vizinhos, i, j);
            if(matriz_verde[i][j][0] == 255 && matriz_verde[i][j][1] == 255 && matriz_verde[i][j][2] == 255)
            {
			
              al_draw_filled_circle(j, i, 2, azul);

            }
          }
        }*/
		
		
		
        /*
        Tesoura, 20000 - 36000

        Pedra,   15000 - 45000

        Papel, 40000 - 120000
        */
		ponto laranja;
        centroide(f, laranja);
		
		//printf("PB %d %d %d %d %d %d\n", laranja[X], laranja[Y], menor_x[X], maior_x[X], menor_y[Y], maior_y[Y]);
		print_poligono(f);

		
		//bitmap_para_matriz(esquerda, matriz_contagem);
		
		//conta_pb(laranja[X], laranja[Y], matriz_contagem);
		
		//printf("PB %d, %d", qtd_branco, qtd_preto);
		//al_draw_filled_rectangle(menor_x[X], maior_y[Y], maior_x[X], menor_y[Y], azul);

   
		//al_draw_filled_rectangle(laranja[X], laranja[Y], laranja[X] + 5, laranja[Y] + 5, azul);
        
		
		
		
		// printf("PB %d %d\n", qtd_branco, qtd_preto);
		//camera_copia(cam, matriz_contagem, direita);
		
		//bitmap_para_matriz(esquerda, matriz_contagem);
		
		
		for(int i = 0; i < f->n; i++){
			ponto b;
			
			if(i + 1 == f->n){
				b[X] = f->p[0][X];
				b[Y] = f->p[0][Y];
			}
			else {
				b[X] = f->p[i+1][X];
				b[Y] = f->p[i+1][Y];
			}
			//printf("Ponto A (%d, %d) Ponto B (%d, %d)", f->p[i][X], f->p[i][Y], b[X], b[Y]);
			desenha_reta(f->p[i], b, matriz_contagem);
		}
		//area *b = malloc(sizeof(area));
		
		//conta_pb_recursivo(laranja[X], laranja[Y], matriz_contagem, b);
		area *b = conta_pb(laranja, matriz_contagem);
<<<<<<< HEAD
		calcula_padrao(f, b);
=======
		
		printf("Centro [%d,%d]\n", laranja[X], laranja[Y]);
		printf("Brancos %d Pretos %d\n", b->qtd_branco, b->qtd_preto);
		
>>>>>>> FETCH_HEAD
		camera_copia(cam, matriz_contagem, direita);
		
		//printf("Somada: %li, Preto: %li, Branco: %li, Fecho: %2f\n", (b->qtd_branco + b->qtd_preto),b->qtd_preto, b->qtd_branco, area_do_fecho(f));
		al_flip_display();
		free(b);
        free(f);
      }
    }

    al_destroy_bitmap(direita);

    al_destroy_bitmap(esquerda);

    camera_libera_matriz(cam, matriz);

	/**********/

    finalizar_allegro();

    return EXIT_SUCCESS;
}