#include "frames.h"
#include "comum.h"

/**
 *  <#Description#>
 *
 *  @param velocidade <#velocidade description#>
 */
void fadeout(int velocidade) {
    ALLEGRO_BITMAP *buffer = NULL;
    buffer = al_create_bitmap(game->largura_tela, game->altura_tela);
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
/**
 *  <#Description#>
 *
 *  @param imagem     <#imagem description#>
 *  @param velocidade <#velocidade description#>
 */
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
        al_draw_tinted_bitmap(imagem, al_map_rgba(alfa, alfa, alfa, alfa), 0, 0, 0);
        al_flip_display();
        al_rest(0.005); // Não é necessário caso haja controle de FPS
    }
}

/**
 *  <#Description#>
 */
void opcoes_rodape(){
	ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/falas.jpg");
	
	tela = al_load_bitmap("assets/image/icones/pedra_small.png");
	al_draw_bitmap(tela, 900, 650, 0);
	
	al_destroy_bitmap(tela);
	
	//tela = al_load_bitmap("assets/image/icones/papel_small.png");
	//al_draw_bitmap(tela, 1, 294, 0);
	
	tela = al_load_bitmap("assets/image/icones/tesoura_small.png");
	al_draw_bitmap(tela, 1080, 650, 0);
	
	al_destroy_bitmap(tela);
	
	al_draw_text(game->fontes->h2, al_map_rgb(255, 255, 255), 1040, 650, ALLEGRO_ALIGN_RIGHT, pegar_idioma("Play", linguagem));
	//al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 862, 294, ALLEGRO_ALIGN_RIGHT, pegar_idioma("Ranking", linguagem));
	al_draw_text(game->fontes->h2, al_map_rgb(255, 255, 255), 1245, 650, ALLEGRO_ALIGN_RIGHT, pegar_idioma("Exit", linguagem));
}

/**
 *  <#Description#>
 */
void tela_sprite(){

	ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/senac.jpg");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);

    tela = al_load_bitmap("assets/image/intro/pi.jpg");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);

    tela = al_load_bitmap("assets/image/intro/allegro.jpg");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);

    tela = al_load_bitmap("assets/image/intro/github.jpg");
    fadein(tela, 7);
    al_rest(2.0);
    fadeout(8);
	
	tela = al_load_bitmap("assets/image/intro/logo2.jpg");
    fadein(tela, 7);
    al_rest(2.0);

    return;
}

/* Funções para single player */
/**
 *  <#Description#>
 */
void tela_vencedor(int minion){
	//ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/win.jpg");
	
	//al_draw_textf(game.fonte_menu, al_map_rgb(0, 0, 0), 200, 570, ALLEGRO_ALIGN_CENTRE, get_idioma("Level: %d"), game.level);
		
}
/**
 *  <#Description#>
 */
void tela_perdedor(){
	//ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/perdeu.jpg");
	
}

/**
 *  <#Description#>
 */
void tela_abertura(){
	ALLEGRO_BITMAP *tela;
	tela = al_load_bitmap("assets/image/intro/menu.jpg");
	al_draw_bitmap(tela, 1, 1, 0);
	
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap("assets/image/icones/pedra_small.png");
	al_draw_bitmap(tela, 790, 204, 0);
	
	al_destroy_bitmap(tela);
	
	//tela = al_load_bitmap("assets/image/icones/papel_small.png");
	//al_draw_bitmap(tela, 1, 294, 0);
	
	tela = al_load_bitmap("assets/image/icones/tesoura_small.png");
	al_draw_bitmap(tela, 780, 298, 0);
	
	al_destroy_bitmap(tela);
	
	al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 902, 200, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Play", linguagem));
	//al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 862, 294, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Ranking", linguagem));
	al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 902, 294, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Exit", linguagem));
	
}

/**
 *  <#Description#>
 */
void tela_introducao(){
	ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/falas.jpg");
	al_draw_bitmap(tela, 1, 1, 0);
	
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap("assets/image/logo/logo.png");
	al_draw_bitmap(tela, 460, 10, 0);
	
	al_destroy_bitmap(tela);
	
	
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 100, ALLEGRO_ALIGN_LEFT, pegar_idioma("Beelzeboss: - I am complete", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 160, ALLEGRO_ALIGN_LEFT, pegar_idioma("Player: - Fuck!", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 220, ALLEGRO_ALIGN_LEFT, pegar_idioma("Beelzeboss: - Yes you are fucked, shit out of luck.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 280, ALLEGRO_ALIGN_LEFT, pegar_idioma("Now I'm complete and my cock you will suck. This world will be mine and you're first in line.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 340, ALLEGRO_ALIGN_LEFT, pegar_idioma("You brought me the pick and now you shall both die.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 400, ALLEGRO_ALIGN_LEFT, pegar_idioma("Tenacious D: - Wait wait waait you mother-fucker. We challenge you to a Rock-paper-scissors off,", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 460, ALLEGRO_ALIGN_LEFT, pegar_idioma("give us one chance to rock your socks off.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 520, ALLEGRO_ALIGN_LEFT, pegar_idioma("Beelzeboss: - Fuck, fuck, Fuck the demon code prevents me from declining a", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 580, ALLEGRO_ALIGN_LEFT, pegar_idioma(" Rock-paper-scissors off challenge.", linguagem));
	
	opcoes_rodape();
}

/**
 *  <#Description#>
 */
void tela_minion(Minion *minion_adversario, int primeira_frase){
	int y = 40;
	ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/falas.jpg");
	al_draw_bitmap(tela, 1, 1, 0);
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap("assets/image/logo/logo.png");
	al_draw_bitmap(tela, 460, 10, 0);
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap(minion_adversario->imagem);
	al_draw_bitmap(tela, 950, 80, 0);
	al_destroy_bitmap(tela);
	
	if(primeira_frase) {
		al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 100, ALLEGRO_ALIGN_LEFT, pegar_idioma("Minion - So ya want to challenge my master. We 're not going let'ya.", linguagem));
		al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 160, ALLEGRO_ALIGN_LEFT, pegar_idioma("Ya have to earn our respect!! Ten of it.", linguagem));
		al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 220, ALLEGRO_ALIGN_LEFT, pegar_idioma("Only then can you fight our master!!", linguagem));
	}
	else {
		for(int i = 0; i < minion_adversario->falas->n; i++){
			y+=60;
			al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, y, ALLEGRO_ALIGN_LEFT, minion_adversario->falas->frase[i]);
		}
	}
	opcoes_rodape();
}

/**
 *  <#Description#>
 */
void tela_vencedor_chefe(){

}

/**
 *  <#Description#>
 */
void tela_empate(){

}

/**
 *  <#Description#>
 *
 *  @param pontos_jogador_1 <#pontos_jogador_1 description#>
 *  @param pontos_jogador_2 <#pontos_jogador_2 description#>
 *  @param contador         <#contador description#>
 */
void tela_jogo(int pontos_jogador_1, int pontos_jogador_2, Minion *minion_adversario, int contador){
	//ALLEGRO_BITMAP *tela = al_load_bitmap("assets/image/intro/jogada.jpg");

}