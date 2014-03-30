#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include "camera.h"
#include "otsu.h"
#include "config.h"
#include "utils.h"
#include "limiarizacao.h"
#include "normalizacaorgb.h"

#define FPS 60

ALLEGRO_BITMAP *fundo_teste;

int distancia_euclidiana(unsigned char r_velho, unsigned char g_velho, unsigned char b_velho, unsigned char r_atual, unsigned char g_atual, unsigned char b_atual){

    int soma_r = r_velho - r_atual;
    int soma_g = g_velho - g_atual;
    int soma_b = b_velho - b_atual;

    int quadrado = (soma_r * soma_r) + (soma_g * soma_g) + (soma_b * soma_b) ;
    int euclidiana = sqrt(quadrado);

    return euclidiana;
}

void removedor_ruidos(unsigned char ***matriz, int vizinhos, int localX, int localY){

    for (int k = 0; k < 3; k++)
    {
        if ((matriz [localX][localY][k] == 255) &&
            (matriz [localX - vizinhos][localY - vizinhos][k] != 255) &&
            (matriz [localX + vizinhos][localY + vizinhos][k] != 255))
        {
            matriz[localX][localY][k] = 0;
               // printf("vizinho FDP");
        }
    }
    return;
}

void valorizador_de_bordas(unsigned char ***matriz, int vizinhos, int localX, int localY){

    for (int i = 1; i < vizinhos; ++i)
    {
        for (int k = 0; k < 2; k++)
        {
            if ((matriz [localX][localY][k] == 255) &&
                (matriz [localX - i][localY - i][k] == 255) &&
                (matriz [localX + i][localY + i][k] == 255))
            {
                matriz[localX][localY][k] = 255;
                matriz[localX][localY][k] = 255;
                matriz[localX + 5][localY][k] = 255;
                matriz[localX][localY + 5][k] = 255;
                matriz[localX + 6][localY][k] = 0;
                matriz[localX][localY + 6][k] = 0;
                matriz[localX + 7][localY][k] = 0;
                matriz[localX][localY + 7][k] = 0;
                   // printf("vizinho FDP");
            }
        }
    }
    return;
}
// void extremamente_rudimentar_fecho_convexo(unsigned char ***matriz, int vizinhos, int localX, int localY){
//     int teste = 0;
//      ALLEGRO_COLOR vermelho = al_map_rgb_f(255, 0, 0);
//     for (int k = 0; k < 3; k++)
//         {

//             if ((matriz [localX][localY][k] == 255) && (matriz [localX + 1][localY + 1][k] == 255))
//             {
//                 teste++;
//                 //printf("somando");
//             }
//             if (teste == 3)
//             {
//                 //printf("carajo");
//                 al_draw_line(localX, localY, (localX + 3), localY, vermelho, 5);
//                 //printf("%d, %d e %d, %d\n", localX, localY, localX+1, localY);
//                 al_draw_triangle(localX, localY, localX+1, localY+1, localX+2, localY+2, vermelho, 5);
//             }
//         }
//     return;
// }


int main() {

    //Bloco de variaveis
    int euclidiana = 0;
    float max_x = 0, max_y = 0, min_x = 0, min_y = 0;
    fundo_teste = al_load_bitmap("teste.png");
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

    if (!al_init_ttf_addon())
        erro("erro ao inicializar add-on allegro_ttf.\n");

    if (!al_install_keyboard())
        erro("erro ao inicializar o teclado.\n");

    if(!al_install_audio())
        erro("erro ao inicializar o audio.\n");

    if(!al_init_acodec_addon())
        erro("erro ao iniciar o audio codec.!\n");

    if(!al_reserve_samples(1))
        erro("Falha ao alocar canais de audio.\n");

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    if(!timer)
        erro("erro na criacao do relogio\n");

    ALLEGRO_DISPLAY *display = al_create_display(2 * largura, altura);
    if(!display)
        erro("erro na criacao da janela\n");

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if(!queue)
        erro("erro na criacao da fila\n");

    ALLEGRO_CONFIG *config = carregar_configuracao("configuration.conf");
    if(!config)
        criar_configuracao("configuration.conf");

    ALLEGRO_FONT *fonte = al_load_font("fonte.ttf", 50, 10);
    if(!fonte)
        erro("erro no carregamento da fonte\n");



    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    al_start_timer(timer);

    /**********/

    unsigned char ***matriz = camera_aloca_matriz(cam);
    unsigned char ***fundo = camera_aloca_matriz(cam);
    unsigned char ***matriz_mao = camera_aloca_matriz(cam);

    ALLEGRO_COLOR cor = al_map_rgb_f(0, 0, 1);

    ALLEGRO_BITMAP *buffer = al_get_backbuffer(display);

    //ALLEGRO_BITMAP *esquerda = al_create_sub_bitmap(buffer, 0, 0, largura, altura);

    ALLEGRO_BITMAP *direita = al_create_sub_bitmap(buffer, largura, 0, largura, altura);

    ALLEGRO_BITMAP *esquerda = al_create_sub_bitmap(fundo_teste, 0, 0, largura, altura);


    /**********/

    int desenhar = 0;
    int terminar = 0;
    int atualiza = 0;

    while(1) {

        if((atualiza % 2) == 0){
            atualiza = 0;
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
        }
        //normalizacaorgb(fundo, altura, largura);
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

            max_x = 0;
            max_y = 0;
            min_x = altura;
            min_y = largura;
            atualiza ++;

            int r, g ,b, media;

            for (int i = 0; i < altura; i++)
            {
                for (int j = 0; j < largura; j++)
                {

                    euclidiana = distancia_euclidiana(fundo[i][j][0], fundo[i][j][1], fundo[i][j][2],
                      cam->quadro[i][j][0], cam->quadro[i][j][1], cam->quadro[i][j][2]);
                    if(euclidiana > 50) {

                        matriz[i][j][0] = 255;
                        matriz[i][j][1] = 255;
                        matriz[i][j][2] = 255;

                        r = matriz[i][j][0];
                        g = matriz[i][j][1];
                        b = matriz[i][j][2];

                        if(r > g + b) {
                            if (i > cy && j > cx)
                            {
                                cy += i;
                                cx += j;
                                cn++;
                            }
                        }

                    }

                    else {
                        media = r + g + b;
                        /*
                         matriz[i][j][0] = cam->quadro[i][j][0] / media;
                         matriz[i][j][1] = cam->quadro[i][j][1] / media;
                         matriz[i][j][2] = cam->quadro[i][j][2] / media;
                         */
                         if (media != 0) {
                            matriz[i][j][0] = r / media;
                            matriz[i][j][1] = g / media;
                            matriz[i][j][2] = b / media;
                        }
                        else {
                            matriz[i][j][0] = 10;
                            matriz[i][j][1] = 10;
                            matriz[i][j][2] = 10;

                        }

                    }



                }

            }

            for (int i = 5; i < altura - 5; i++)
            {
                for (int j = 5; j < largura - 5; j++)
                {
                    removedor_ruidos(matriz, 5, i, j);
                }
            }

            // for (int i = 5; i < altura - 7; i++)
            // {
            //     for (int j = 5; j < largura - 7; j++)
            //     {
            //         valorizador_de_bordas(matriz, 5, i, j);
            //     }
            // }

            //   for (int i = 0; i < altura - 1; i++)
            // {
            //     for (int j = 0; j < largura - 1; j++)
            //     {
            //         extremamente_rudimentar_fecho_convexo(matriz, 5, i, j);
            //     }
            // }


            /**********/
            //limiarizacao(fundo, altura, largura);
            //otsu_binarizacao(fundo, fundo, altura, largura);
            camera_copia(cam, matriz, direita);
            camera_copia(cam, cam->quadro, esquerda);
            //camera_copia(cam, cam->quadro, fundo_teste);
           // al_draw_bitmap(fundo_teste, 2, 2, 0);
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
