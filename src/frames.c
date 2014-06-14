#include "frames.h"
#include "comum.h"

//Funcoes exibe_ são funções não acessíveis pelo .h

/**
 *  <#Description#>
 *
 *  @param velocidade <#velocidade description#>
 */
void exibe_fade_out(int velocidade) {
    ALLEGRO_BITMAP *buffer = NULL;
	int alfa;
	
    buffer = al_create_bitmap(game->largura_tela, game->altura_tela);
    al_set_target_bitmap(buffer);
	
    al_draw_bitmap(al_get_backbuffer(display), 1, 1, 0);
    al_set_target_bitmap(al_get_backbuffer(display));

    if (velocidade <= 0)
        velocidade = 1;
    else if (velocidade > 15)
		velocidade = 15;
  
    
    for (alfa = 0; alfa <= 255; alfa += velocidade)
    {
        al_clear_to_color(al_map_rgba(0, 0, 0, 0));
        al_draw_tinted_bitmap(buffer, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 1, 1, 0);
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
void exibe_fade_in(ALLEGRO_BITMAP *imagem, int velocidade){
	int alfa;
	
    if (velocidade < 0)
        velocidade = 1;
    else if (velocidade > 15)
        velocidade = 15;

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
void exibe_opcoes_rodape(int final){
	ALLEGRO_BITMAP *tela;
	const char *play;
	int x;
	
	if(final) {
		play = pegar_idioma("Options", linguagem);
		x = 820;
	}
	else {
		play = pegar_idioma("Play", linguagem);
		x = 900;
		}
		
	tela = al_load_bitmap("assets/image/icones/papel_small.png");
	al_draw_bitmap(tela, x, 650, 0);
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap("assets/image/icones/tesoura_small.png");
	al_draw_bitmap(tela, 1080, 650, 0);
	al_destroy_bitmap(tela);
	
	al_draw_text(game->fontes->h2, al_map_rgb(255, 255, 255), 1040, 650, ALLEGRO_ALIGN_RIGHT, play);
	al_draw_text(game->fontes->h2, al_map_rgb(255, 255, 255), 1245, 650, ALLEGRO_ALIGN_RIGHT, pegar_idioma("Exit", linguagem));
}

/**
 *  <#Description#>
 *
 *  @param arquivo     <#arquivo description#>
 *  @param efeito <#efeito description#>
 *  @param rest <#rest description#>
 */
void exibe_com_efeito(const char *arquivo, int efeito, double rest){
	ALLEGRO_BITMAP *tela = al_load_bitmap(arquivo);
	switch(efeito){
		case 0:
			//Fade in.
			exibe_fade_in(tela, 7);
			al_rest(rest);
		case 1:
			//Fade out 
			al_draw_bitmap(tela, 1, 1, 0);
			al_rest(rest);
			exibe_fade_out(8);
		case 3:
			//Fade in e out
			exibe_fade_in(tela, 7);
			al_rest(rest);
			exibe_fade_out(8);
	}
	al_destroy_bitmap(tela);
	return;
}

void exibe_sem_efeito(const char *arquivo){
	ALLEGRO_BITMAP *tela = al_load_bitmap(arquivo);
	al_draw_bitmap(tela, 1, 1, 0);
	al_destroy_bitmap(tela);
}

void exibe_pontos(int pontos){
	ALLEGRO_BITMAP *ponto = al_load_bitmap("assets/image/partida/ponto.png");
	int i;
	
	for(i = 650; i < 650 + (pontos * 60); i+=60){
		al_draw_bitmap(ponto, i, 650, 0);
	}
	
	al_destroy_bitmap(ponto);
	ponto = al_load_bitmap("assets/image/partida/ponto_gasto.png");
	
	for(i; i < 650 + 600; i+=60){
		al_draw_bitmap(ponto, i, 650, 0);
	}
	
	al_destroy_bitmap(ponto);
	al_draw_text(game->fontes->h2, al_map_rgb(200, 200, 200), 650, 550, ALLEGRO_ALIGN_LEFT, pegar_idioma("Respect points", linguagem));
}

/**
 *  <#Description#>
 */
void tela_logo(){
	exibe_com_efeito("assets/image/intro/logo2.jpg", 3, 2);
}
/**
 *  <#Description#>
 */
void tela_sprite(){
	exibe_com_efeito("assets/image/intro/senac.jpg", 3, 2);
	exibe_com_efeito("assets/image/intro/pi.jpg", 3, 2);
	exibe_com_efeito("assets/image/intro/allegro.jpg", 3, 2);
	exibe_com_efeito("assets/image/intro/github.jpg", 3, 2);
    return;
}

/* Funções para single player */
/**
 *  <#Description#>
 */
void tela_vencedor(){
	exibe_sem_efeito("assets/image/final/win.jpg");
	
	al_draw_textf(game->fontes->h1, al_map_rgb(255, 255, 255), 640, 40, ALLEGRO_ALIGN_CENTRE, pegar_idioma("DAMNED FUCK BAGS FRAK demon code!", linguagem));
	al_draw_textf(game->fontes->h1, al_map_rgb(255, 255, 255), 640, 130, ALLEGRO_ALIGN_CENTRE, pegar_idioma("You can have this victory!", linguagem));
	
	exibe_opcoes_rodape(1);	
}

/**
 *  <#Description#>
 */
void tela_perdedor(int chefe){
	const char *tela, *frase, *frase2;
	if(chefe) {
		tela = "assets/image/final/perdeu_chefe.jpg";
		frase = pegar_idioma("You are a loser. You think that can defeat me?!", linguagem);
		frase2 = pegar_idioma("Now you are dead bitch. HaHAHA", linguagem);
		}
	else {
		tela = "assets/image/final/perdeu.jpg";
		frase = pegar_idioma("Ya 're a loser. Ya re not even worth suck my master cock!", linguagem);
		frase2 = pegar_idioma("Hwua Hwia Hwia", linguagem);
	}
	exibe_sem_efeito(tela);
	
	al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 640, 40, ALLEGRO_ALIGN_CENTRE, frase);
	al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 640, 130, ALLEGRO_ALIGN_CENTRE, frase2);
	
	exibe_opcoes_rodape(1);
}

/**
 *  <#Description#>
 */
void tela_abertura(){
	exibe_sem_efeito("assets/image/intro/menu.jpg");
	exibe_sem_efeito("assets/image/icones/papel_small.png");
	exibe_sem_efeito("assets/image/icones/tesoura_small.png");
	
	al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 902, 200, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Play", linguagem));
	al_draw_text(game->fontes->h1, al_map_rgb(255, 255, 255), 902, 294, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Exit", linguagem));
}

/**
 *  <#Description#>
 */
void tela_introducao(){
	exibe_sem_efeito("assets/image/intro/falas.jpg");
	exibe_sem_efeito("assets/image/logo/logo.png");
	
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 100, ALLEGRO_ALIGN_LEFT, pegar_idioma("Beelzeboss: - I am complete", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 160, ALLEGRO_ALIGN_LEFT, pegar_idioma("Player: - Fuck!", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 220, ALLEGRO_ALIGN_LEFT, pegar_idioma("Beelzeboss: - Yes you are fucked, shit out of luck.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 280, ALLEGRO_ALIGN_LEFT, pegar_idioma("Now I'm complete and my cock you will suck. This world will be mine and you're first in line.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 340, ALLEGRO_ALIGN_LEFT, pegar_idioma("You brought me the pick and now you shall both die.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 400, ALLEGRO_ALIGN_LEFT, pegar_idioma("Tenacious D: - Wait wait waait you mother-fucker. We challenge you to a Rock-paper-scissors off,", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 460, ALLEGRO_ALIGN_LEFT, pegar_idioma("give us one chance to rock your socks off.", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 520, ALLEGRO_ALIGN_LEFT, pegar_idioma("Beelzeboss: - Fuck, fuck, Fuck the demon code prevents me from declining a", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 10, 580, ALLEGRO_ALIGN_LEFT, pegar_idioma(" Rock-paper-scissors off challenge.", linguagem));
	
	exibe_opcoes_rodape(0);
}

/**
 *  <#Description#>
 */
void tela_minion(MINION *minion_adversario, int primeira_frase){
	ALLEGRO_BITMAP *tela;
	int y = 40;
	exibe_sem_efeito("assets/image/intro/falas.jpg");
	
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
	exibe_opcoes_rodape(0);
}

/**
 *  <#Description#>
 */
void tela_empate(){
	exibe_sem_efeito("assets/image/intro/falas.jpg");
	
	al_draw_text(game->fontes->h2, al_map_rgb(255, 255, 255), 640, 100, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Tie", linguagem));
	al_draw_text(game->fontes->h3, al_map_rgb(255, 255, 255), 640, 250, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Restarting match!", linguagem));
	al_flip_display();
	al_rest(2.0);
}



void tela_carregando(unsigned char ***matriz){
	al_draw_text(game->fontes->h2, al_map_rgb(200, 200, 200), 640, 30, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Calibration in progress...", linguagem));
	al_draw_text(game->fontes->h2, al_map_rgb(200, 200, 200), 640, 600, ALLEGRO_ALIGN_CENTRE, pegar_idioma("Please, put your hand on rock format on the center of screen.", linguagem));
}

/**
 *  <#Description#>
 *
 *  @param pontos_jogador_1 <#pontos_jogador_1 description#>
 *  @param pontos_jogador_2 <#pontos_jogador_2 description#>
 *  @param contador         <#contador description#>
 */
void tela_jogo(int pontos_jogador_1, int pontos_jogador_2, int pontos_respeito, MINION *minion_adversario, int contador, int mostra_contador){
	ALLEGRO_BITMAP *tela;
	
	exibe_sem_efeito("assets/image/intro/jogada.jpg");
	
	tela = al_load_bitmap("assets/image/partida/standby.png");
	al_draw_bitmap(tela, 10, 340, 0);
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap("assets/image/partida/standby_adversario.png");
	al_draw_bitmap(tela, 900, 40, 0);
	al_destroy_bitmap(tela);
	
	if(mostra_contador)
		al_draw_textf(game->fontes->super, al_map_rgb(255, 255, 255), 50, -30, ALLEGRO_ALIGN_LEFT, "%d", contador);
	
	al_draw_textf(game->fontes->super, al_map_rgb(255, 255, 255), 250, -40, ALLEGRO_ALIGN_LEFT, "%d", pontos_jogador_1);
	al_draw_textf(game->fontes->super, al_map_rgb(255, 255, 255), 450, -40, ALLEGRO_ALIGN_LEFT, "%d", pontos_jogador_2);
	
	exibe_pontos(pontos_respeito);
	
	al_flip_display();
}

void tela_jogo_maos(int pontos_jogador_1, int pontos_jogador_2, int pontos_respeito, int mao_jogador, int mao_adversaria){
	ALLEGRO_BITMAP *tela;
	exibe_sem_efeito("assets/image/intro/jogada.jpg");
	
	switch(mao_jogador){
		case PEDRA:
			tela = al_load_bitmap("assets/image/partida/pedra.png");
			break;
		case PAPEL:
			tela = al_load_bitmap("assets/image/partida/papel.png");
			break;
		default:
			tela = al_load_bitmap("assets/image/partida/tesoura.png");
			break;
	}
	
	al_draw_bitmap(tela, 10, 340, 0);
	al_destroy_bitmap(tela);
	
	switch(mao_jogador){
		case PEDRA:
			tela = al_load_bitmap("assets/image/partida/pedra_adversario.png");
			break;
		case PAPEL:
			tela = al_load_bitmap("assets/image/partida/papel_adversario.png");
			break;
		default:
			tela = al_load_bitmap("assets/image/partida/tesoura_adversario.png");
			break;
	}
	al_draw_bitmap(tela, 900, 40, 0);
	al_destroy_bitmap(tela);
	
	al_draw_textf(game->fontes->super, al_map_rgb(255, 255, 255), 250, -40, ALLEGRO_ALIGN_LEFT, "%d", pontos_jogador_1);
	al_draw_textf(game->fontes->super, al_map_rgb(255, 255, 255), 450, -40, ALLEGRO_ALIGN_LEFT, "%d", pontos_jogador_2);
	
	exibe_pontos(pontos_respeito);
	
	al_flip_display();
	al_rest(2);
}

/**
 *  <#Description#>
 */
void tela_chefe(){
	ALLEGRO_BITMAP *tela;
	exibe_sem_efeito("assets/image/chefe/fundo.png");
	
	tela = al_load_bitmap("assets/image/logo/logo.png");
	al_draw_bitmap(tela, 460, 10, 0);
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap("assets/image/chefe/chefe.png");
	al_draw_bitmap(tela, 400, 140, 0);
	al_destroy_bitmap(tela);
	
	tela = al_load_bitmap("assets/image/chefe/fogo.png");
	al_draw_bitmap(tela, 1, 530, 0);
	al_destroy_bitmap(tela);
	
	exibe_opcoes_rodape(0);
}