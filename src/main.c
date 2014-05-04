#include "init.h"
#include "comum.h"

int main() {

    inicializar_allegro();

    unsigned char ***matriz = camera_aloca_matriz(cam);
    unsigned char ***matriz_pb = camera_aloca_matriz(cam);
    unsigned char ***matriz_verde = camera_aloca_matriz(cam);
    //unsigned char ***matriz2 = camera_aloca_matriz(cam);
    //ALLEGRO_COLOR cor = al_map_rgb_f(0, 0, 1);

    ALLEGRO_BITMAP *buffer = al_get_backbuffer(display);
    ALLEGRO_BITMAP *esquerda = al_create_sub_bitmap(buffer, 0, 0, largura, altura);
  //  ALLEGRO_BITMAP *direita = al_create_sub_bitmap(buffer, largura, 0, largura, altura);

    // Variável para a imagem da mao
    ALLEGRO_BITMAP *imagem = NULL;// al_create_sub_bitmap(buffer, largura, 0, largura, altura);

//    ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);

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
            //filtro_laplaciano(cam->quadro, matriz, altura, largura);
            filtro_borda(matriz_pb, matriz_pb, altura, largura);
            //limiarizacao(matriz_pb, altura, largura);
            //filtro_mediana(matriz, matriz, altura, largura);
            //filtro_mediana(matriz, matriz, altura, largura);
            // laplaciano(matriz, matriz, altura, largura);
            //filtro_media(matriz, matriz, altura, largura);
            //
            matriz_copia(matriz_pb, matriz_verde, altura, largura);
            poligono *f = fecho(matriz_verde,altura, largura);
            camera_copia(cam, matriz_pb, esquerda);
            //camera_copia(cam, matriz_verde, imagem);
            //al_draw_circle(300, 300, 10, vermelho, 10);
            //fecho(matriz_pb, altura, largura);
            //------------------
            int _vizinhos = 100;
            //Teste
            ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
            ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);

            al_draw_filled_rectangle(_vizinhos, _vizinhos, (largura - _vizinhos),(altura - _vizinhos) , verde);
            for (int i = _vizinhos; i < altura - _vizinhos; i++)
            {
            for (int j = _vizinhos; j < largura - _vizinhos; j++)
                {
                   // removedor_ruidos(matriz, _vizinhos, i, j);
                    if(matriz_verde[i][j][0] == 255 && matriz_verde[i][j][1] == 255 && matriz_verde[i][j][2] == 255)
                    {
                        al_draw_filled_circle(j, i, 5, azul);

                    }
                }
            }


            print_poligono(f);
            //camera_copia(cam, fundo, direita);
            /**********/
            
            /*Por enquanto somente uma imagem, mas aqui vai ficar
             a analise do fecho pra saber o que eh.
            
            */
            imagem = al_load_bitmap("assets/mao.png");
            al_draw_bitmap(imagem, largura/2, altura/2, 0);
            al_flip_display();
            free(f);
        }
    }

    /**********/

    //al_destroy_bitmap(direita);

    al_destroy_bitmap(esquerda);

    al_destroy_bitmap(imagem);

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
