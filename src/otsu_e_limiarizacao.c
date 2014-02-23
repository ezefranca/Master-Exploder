#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include "camera.h"

#define FPS 60

void erro(char *mensagem) {
  fputs(mensagem, stderr);

  exit(EXIT_FAILURE);
}

int limiarizacao(unsigned char ***matriz, int altura, int largura){
	for(int i = 0; i < altura; i++) {
		for(int j = 0; j < largura; j++)
			for(int k = 0; k < 3; k++){
				if(matriz[i][j][k] < 128)
					matriz[i][j][k] = 0;
				else
					matriz[i][j][k] = 255;
			}
		}
		return 1;
}

void otsu_binarizacao(unsigned char ***matriz, unsigned char ***saida, int altura, int largura)
/* método de otsu - referencia teórica wiki.icmc.usp.br/images/b/bb/Otsu_e_derivadas.pdf‎ */
{
  int histograma[256];
  double probabilidade[256], omega[256]; /* probabilidade de ser cinza */
  double myu[256];
  double max_sigma, sigma[256];
  int i, x, y, z; /* variaveis para os loops for */
  int limiar; /* limiar para binarização */

  /* geração do histograma */
  for (i = 0; i < 256; i++) histograma[i] = 0;
  for (y = 0; y < altura; y++)
    for (x = 0; x < largura; x++) {
      for (z = 0; z < 3; z++)
      histograma[matriz[y][x][z]]++;
    }
  /* calculo da probabilidade */
  for ( i = 0; i < 256; i ++ ) {
    probabilidade[i] = (double)histograma[i] / (altura * largura);
  }

  /* omega e myu*/
  omega[0] = probabilidade[0];
  myu[0] = 0.0;
  for (i = 1; i < 256; i++) {
    omega[i] = omega[i-1] + probabilidade[i];
    myu[i] = myu[i-1] + i*probabilidade[i];
  }


/* Maximização do sigma, determina o valor de Limiar ideal */
  //Não entendi 100% a ideia aqui...
  limiar = 0;
  max_sigma = 0.0;
  for (i = 0; i < 255; i++) {
    if (omega[i] != 0.0 && omega[i] != 1.0)
      sigma[i] = pow(myu[255]*omega[i] - myu[i], 2) / (omega[i]*(1.0 - omega[i]));
    else
      sigma[i] = 0.0;
    if (sigma[i] > max_sigma) {
      max_sigma = sigma[i];
      limiar = i;
    }
  }

  /* saida da binarização */

  for (y = 0; y < altura; y++)
    for (x = 0; x < largura; x++)
      for(z = 0; z < 3; z++)
      if (matriz[y][x][z] > limiar)
	saida[y][x][z] = 255;
      else
	saida[y][x][z] = 0;

}

int main() {

  //Bloco de variaveis
  int euclidiana = 0;
  int soma = 0, soma_r =0, soma_g = 0, soma_b = 0;
  int quadrado = 0;
  int raiz = 0;
  int max_x = 0, max_y = 0, min_x = 0, min_y = 0;
  camera *cam = camera_inicializa(0);
  //Fim do bloco de variaveis

  if(!cam)
    erro("erro na inicializacao da camera\n");

  int largura = cam->largura;
  int altura = cam->altura;

  if(!al_init())
    erro("erro na inicializacao do allegro\n");

  if(!al_init_image_addon())
    erro("erro na inicializacao do adicional de imagem\n");

  if(!al_init_primitives_addon())
    erro("erro na inicializacao do adicional de primitivas\n");

  ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
  if(!timer)
    erro("erro na criacao do relogio\n");

  ALLEGRO_DISPLAY *display = al_create_display(2 * largura, altura);
  if(!display)
    erro("erro na criacao da janela\n");

  ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
  if(!queue)
    erro("erro na criacao da fila\n");

  al_register_event_source(queue, al_get_timer_event_source(timer));
  al_register_event_source(queue, al_get_display_event_source(display));

  al_start_timer(timer);

  /**********/

  unsigned char ***matriz = camera_aloca_matriz(cam);
  unsigned char ***fundo = camera_aloca_matriz(cam);
  unsigned char ***matriz_mao = camera_aloca_matriz(cam);

  ALLEGRO_COLOR cor = al_map_rgb_f(0, 0, 1);

  ALLEGRO_BITMAP *buffer = al_get_backbuffer(display);

  ALLEGRO_BITMAP *esquerda = al_create_sub_bitmap(buffer, 0, 0, largura, altura);

  ALLEGRO_BITMAP *direita = al_create_sub_bitmap(buffer, largura, 0, largura, altura);

  /**********/

  int desenhar = 0;
  int terminar = 0;

     for (int i = 0; i < altura; i++)
    {
      for (int j = 0; j < largura; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          fundo[i][j][k] = cam->quadro[i][j][k];
        }
      }
    }
    otsu_binarizacao(fundo, fundo, altura, largura);
    //limiarizacao(fundo, altura, largura);

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

      float cy = 0;
      float cx = 0;
      int cn = 0;

      //limiarizacao(cam->quadro, altura, largura);
      //otsu_binarizacao(cam->quadro, cam->quadro, altura, largura);

      for (int i = 0; i < altura; i++)
      {
        for (int j = 0; j < largura; j++)
        {


          soma_r = fundo[i][j][0] - cam->quadro[i][j][0];
          soma_g = fundo[i][j][1] - cam->quadro[i][j][1];
          soma_b = fundo[i][j][2] - cam->quadro[i][j][2];

          quadrado = (soma_r * soma_r) + (soma_g * soma_g) + (soma_b * soma_b) ;

          euclidiana = sqrt(quadrado);

          if(euclidiana > 200) {
           max_x = i;
           max_y = j;
           matriz[i][j][0] = 0;
           matriz[i][j][1] = 0;
           matriz[i][j][2] = 0;

         }

         else {
           matriz[i][j][0] = 255;
           matriz[i][j][1] = 255;
           matriz[i][j][2] = 255;
         }


       }

     }
      /**********/
     camera_copia(cam, cam->quadro, esquerda);
     camera_copia(cam, matriz, direita);
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
