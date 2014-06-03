#include "init.h"
#include "comum.h"
#include "terminate.h"

<<<<<<< HEAD

void teste_erosao(unsigned char ***imagem, int altura, int largura){
    unsigned char mascara[9] = {0,255,0,255,255,0,0,255,0};
    int ok = 1;
   for (int i = 2; i < altura - 2; i++)
   {
       for (int j = 2; j < largura - 2; j++)
       {

               if(imagem[i][j][0]     != 255 && imagem[i][j][1]     != 255 && imagem[i][j][2]     != 255) 
                    ok = 0;
               if(imagem[i][j+1][0]   != 255 && imagem[i][j+1][1]   != 255 && imagem[i][j+1][2]   != 255)
                    ok = 0;
               if(imagem[i][j-1][0]   != 255 && imagem[i][j-1][1]   != 255 && imagem[i][j-1][2]   != 255)
                    ok = 0;
               if(imagem[i+1][j][0]   != 255 && imagem[i+1][j][1]   != 255 && imagem[i+1][j][2]   != 255)
                    ok = 0;
               if(imagem[i-1][j+1][0] != 255 && imagem[i-1][j+1][1] != 255 && imagem[i-1][j+1][2] != 255)
                    ok = 0;

                if(!ok)
                {
                  imagem[i][j][0] = imagem[i][j][0];
                  imagem[i][j][1] = imagem[i][j][1];
                  imagem[i][j][1] = imagem[i][j][2];

                  imagem[i+1][j][0] = 0;  
                  imagem[i+1][j][1] = 0;  
                  imagem[i+1][j][2] = 0;

                  imagem[i][j+1][0] = 0;  
                  imagem[i][j+1][1] = 0;  
                  imagem[i][j+1][2] = 0;

                  imagem[i+1][j+1][0] = 0;  
                  imagem[i+1][j+1][1] = 0;  
                  imagem[i+1][j+1][2] = 0;
                }
                else
                {
                    printf("MORFOU MORFOU MORFOU\n");
                  imagem[i][j][0] = 255;  
                  imagem[i][j][1] = 255;  
                  imagem[i][j][2] = 255;  

                  imagem[i+1][j][0] = 0;  
                  imagem[i+1][j][1] = 0;  
                  imagem[i+1][j][2] = 0;

                  imagem[i][j+1][0] = 0;  
                  imagem[i][j+1][1] = 0;  
                  imagem[i][j+1][2] = 0;

                  imagem[i+1][j+1][0] = 0;  
                  imagem[i+1][j+1][1] = 0;  
                  imagem[i+1][j+1][2] = 0;
                }
                ok = 1;
        }
    }
=======
void testeRGB(Rgb *cores){
  cores->r = 200;
   // printf("---------------------------------%d\n",cores->r);
>>>>>>> master-ezequiel
}

void remove_fundo(unsigned char ***atual, unsigned char ***primeiro, unsigned char ***matriz){

  int r , g , b;

  for(int y = 0; y < altura; y++){
    for(int x = 0; x < largura; x++) {
      r = abs(atual[y][x][0] -  primeiro[y][x][0]);
      g = abs(atual[y][x][1] -  primeiro[y][x][1]);
      b = abs(atual[y][x][2] -  primeiro[y][x][2]);

      if ((r + g + b) > 50)
      {
        matriz[y][x][0] = 255;
        matriz[y][x][1] = 255;
        matriz[y][x][2] = 255;
      }

      else
      {
        matriz[y][x][0] = 0;
        matriz[y][x][1] = 0;
        matriz[y][x][2] = 0;
      }   
    }
  }
}

int main() {

  inicializar_allegro();

<<<<<<< HEAD
    unsigned char ***p = camera_aloca_matriz(cam);

    unsigned char ***matriz = camera_aloca_matriz(cam);
    unsigned char ***matriz_pb = camera_aloca_matriz(cam);
    unsigned char ***matriz_verde = camera_aloca_matriz(cam);
=======
  unsigned char ***matriz = camera_aloca_matriz(cam);
  unsigned char ***matriz_pb = camera_aloca_matriz(cam);
  unsigned char ***matriz_verde = camera_aloca_matriz(cam);

  unsigned char ***primeiro = camera_aloca_matriz(cam);
>>>>>>> master-ezequiel
    //unsigned char ***matriz2 = camera_aloca_matriz(cam);
    //ALLEGRO_COLOR cor = al_map_rgb_f(0, 0, 1);

  ALLEGRO_BITMAP *buffer = al_get_backbuffer(display);
  ALLEGRO_BITMAP *esquerda = al_create_sub_bitmap(buffer, 0, 0, largura, altura);
  ALLEGRO_BITMAP *direita = al_create_sub_bitmap(buffer, largura, 0, largura, altura);

    //ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);

  Rgb *cores_rgb = malloc(sizeof(Rgb));
  Hsv *cores_hsv = malloc(sizeof(Hsv));

<<<<<<< HEAD
    
    int desenhar = 0;
    int terminar = 0;
    //int atualiza = 0;
    //  guarda o p quadro para usar na sobreposição de frames

    int y , x;
    camera_atualiza(cam);
    for(y = 0; y < altura; y++) {
        for(x = 0; x < largura; x++) {
            p[y][x][0] = cam->quadro[y][x][0];
            p[y][x][1] = cam->quadro[y][x][1];
            p[y][x][2] = cam->quadro[y][x][2];
        }
    }
    normalizacao_preto_e_branco(p, altura, largura);
    otsu_binarizacao(p, p, altura, largura);


    while(1) {

        
        



        // for(y = 0; y < altura; y++) {
        //     for(x = 0; x < largura; x++) {
        //         p[y][x][0] = cam->quadro[y][x][0];
        //         p[y][x][1] = cam->quadro[y][x][1];
        //         p[y][x][2] = cam->quadro[y][x][2];

        //         cores_rgb->r = cam->quadro[y][x][0];
        //         cores_rgb->g = cam->quadro[y][x][1];
        //         cores_rgb->b = cam->quadro[y][x][2];

        //         rgb_para_hsv(cores_rgb, cores_hsv);
        //     }
        // }

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
                for(y = 0; y < altura; y++) {
                    for(x = 0; x < largura; x++) {
                        //euclidiana();
                    }
                }

                // Normaliza o frame atual e o p frame salvo para preto e branco (tons de cinza)
                normalizacao_preto_e_branco(cam->quadro, altura, largura);

                // copia o frame normalizado para o matriz_pb
                matriz_copia(cam->quadro, matriz_pb, altura, largura);

                // binariza a matriz_pb e a primeira matriz
                otsu_binarizacao(matriz_pb, matriz_pb, altura, largura);
               

                //filtro_mediana(matriz_pb, matriz_pb, altura, largura);
                
                // aplica um filtro de sobel para detcção de bordas
                filtro_borda(matriz_pb, matriz_pb, (altura - 10), (largura - 10));

                // copia a matriz_pb para matriz_verde, a matriz_verde eh utilizada em diversas operacoes
                matriz_copia(matriz_pb, matriz_verde, altura, largura);
                teste_erosao(matriz_pb, altura, largura);
                poligono *f = fecho(matriz_verde,altura, largura);
                camera_copia(cam, matriz_pb, esquerda);
                camera_copia(cam, matriz_pb, direita);

            //------------------
                int _vizinhos = 10;
=======

  int desenhar = 0;
  int terminar = 0;
    //int atualiza = 0;

  camera_atualiza(cam);

  for(int y = 0; y < altura; y++){
    for(int x = 0; x < largura; x++) {
      primeiro[y][x][0] = cam->quadro[y][x][0];
      primeiro[y][x][1] = cam->quadro[y][x][1];
      primeiro[y][x][2] = cam->quadro[y][x][2];
    }
  }

  while(1) {

    testeRGB(cores_rgb);
    for(int y = 0; y < altura; y++)
      for(int x = 0; x < largura; x++) {
        cores_rgb->r = cam->quadro[y][x][0];
        cores_rgb->g = cam->quadro[y][x][1];
        cores_rgb->b = cam->quadro[y][x][2];

        rgb_para_hsv(cores_rgb, cores_hsv);
               // printf("R:%d G:%d B:%d ----- H:%f S:%f V:%f\n",cores_rgb->r, cores_rgb->g, cores_rgb->b, cores_hsv->h, cores_hsv->s, cores_hsv->v );
      }

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
        remove_fundo(cam->quadro, primeiro, matriz);
            /**********/
            /**********/
            //limiarizacao(fundo, altura, largura);
            //otsu_binarizacao(fundo, fundo, altura, largura);
        normalizacao_preto_e_branco(matriz, altura, largura);
        otsu_binarizacao(matriz, matriz_pb, altura, largura);
            //filtro_borda(cam->quadro, matriz_pb, altura, largura);
            //filtro_laplaciano(cam->quadro, matriz, altura, largura);
        filtro_borda(matriz_pb, matriz_pb, altura, largura);
            //limiarizacao(matriz_pb, altura, largura);
            //filtro_mediana(matriz, matriz, altura, largura);
            //filtro_mediana(matriz, matriz, altura, largura);
            // laplaciano(matriz, matriz, altura, largura);
            //filtro_media(matriz, matriz, altura, largura);
        matriz_copia(matriz_pb, matriz_verde, altura, largura);
        poligono *f = fecho(matriz_verde,altura, largura);
        camera_copia(cam, matriz_pb, esquerda);
        camera_copia(cam, matriz_verde, direita);
            //al_draw_circle(300, 300, 10, vermelho, 10);
            //fecho(matriz_pb, altura, largura);
            //------------------
        int _vizinhos = 100;
>>>>>>> master-ezequiel
            //Teste
        ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
        ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);
        ALLEGRO_COLOR preto = al_map_rgb_f(0, 0, 0);

        al_draw_filled_rectangle(1, 1, largura, altura, verde);
        al_draw_rectangle(_vizinhos, _vizinhos, (largura - _vizinhos),(altura - _vizinhos) , preto, 3);

<<<<<<< HEAD
                for (int i = _vizinhos; i < altura - _vizinhos; i++){
                    for (int j = _vizinhos; j < largura - _vizinhos; j++){
                        //removedor_ruidos(matriz_verde, 2, i, j);
                        if(matriz_verde[i][j][0] == 255 && matriz_verde[i][j][1] == 255 && matriz_verde[i][j][2] == 255)
                        {
                            al_draw_filled_circle(j, i, 2, azul);
=======
        for (int i = _vizinhos; i < altura - _vizinhos; i++){
          for (int j = _vizinhos; j < largura - _vizinhos; j++){
                    // removedor_ruidos(matriz, _vizinhos, i, j);
            if(matriz_verde[i][j][0] == 255 && matriz_verde[i][j][1] == 255 && matriz_verde[i][j][2] == 255)
            {
              al_draw_filled_circle(j, i, 2, azul);
>>>>>>> master-ezequiel

            }
          }
        }

                //pontos_extremo(f, menor_x, maior_x, menor_y, maior_y);
        printf("\nArea do fecho: %2f Pontos %d\n", area_do_fecho(f), f->n);
        print_poligono(f);
            //camera_copia(cam, fundo, direita);
            /**********/

        al_flip_display();
        free(f);
      }
    }

	/**********/

    al_destroy_bitmap(direita);

    al_destroy_bitmap(esquerda);

    camera_libera_matriz(cam, matriz);

    /**********/

    finalizar_allegro();

    return EXIT_SUCCESS;
  }
