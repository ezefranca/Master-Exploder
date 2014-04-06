#include "init.h"

int inicializar_allegro(){

    cam = camera_inicializa(0);


    if(!cam)
        erro("erro na inicializacao da camera\n");

    largura = cam->largura;
    altura = cam->altura;


  if(!al_init())
        erro("erro na inicializacao do allegro\n");

    if(!al_init_image_addon())
        erro("erro na inicializacao do adicional de imagem\n");

    if(!al_init_primitives_addon())
        erro("erro na inicializacao do adicional de primitivas\n");

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
        erro("erro na criacao do relogio\n");

    display = al_create_display(2 * largura, altura);
    if(!display)
        erro("erro na criacao da janela\n");

    queue = al_create_event_queue();
    if(!queue)
        erro("erro na criacao da fila\n");

    config = carregar_configuracao("configuration.conf");
    if(!config)
        criar_configuracao("configuration.conf");

    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    al_start_timer(timer);
    return 1;
}
