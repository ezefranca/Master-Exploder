#include "comum.h"

void fadeout(int velocidade) {
    ALLEGRO_BITMAP *buffer = NULL;
    buffer = al_create_bitmap(800, 600);
    al_set_target_bitmap(buffer);
	
    al_draw_bitmap(al_get_backbuffer(display), 0, 0, 0);
    al_set_target_bitmap(al_get_backbuffer(display));

    if (velocidade <= 0)
        velocidade = 1;
    else if (velocidade > 15)
		velocidade = 15;
  

    int alfa;
    for (alfa = 0; alfa <= 255; alfa += velocidade)
    {
        al_clear_to_color(al_map_rgba(0, 0, 0, 0));
        al_draw_tinted_bitmap(buffer, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 0);
        al_flip_display();
        al_rest(0.005); // Não é necessário caso haja controle de FPS
    }

    al_destroy_bitmap(buffer);
}

void fadein(ALLEGRO_BITMAP *imagem, int velocidade)
{
    if (velocidade < 0)
    {
        velocidade = 1;
    }
    else if (velocidade > 15)
    {
        velocidade = 15;
    }

    int alfa;
    for (alfa = 0; alfa <= 255; alfa += velocidade)
    {
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_tinted_bitmap(imagem, al_map_rgba(alfa, alfa, alfa, alfa), 80, 100, 0);
        al_flip_display();
        al_rest(0.005); // Não é necessário caso haja controle de FPS
    }
}

void tela_sprite(){

	ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/senac.png");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);

    tela = al_load_bitmap("assets/image/intro/pi.png");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);

    tela = al_load_bitmap("assets/image/intro/allegro.png");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);

    tela = al_load_bitmap("assets/image/intro/github.png");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);
	
	tela = al_load_bitmap("assets/image/intro/logo2.jpg");
    fadein(tela, 7);
    al_rest(2.0);
}

