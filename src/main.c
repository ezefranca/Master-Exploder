#include "init.h"
#include "comum.h"
#include "jogabilidade.h"
#include "terminate.h"

#define TELA_OPCAO 0
#define TELA_ABERTURA 1
#define TELA_JOGO 2
#define TELA_VENCEDOR 3
#define TELA_PERDEDOR 4

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
	int tela = 3;
    double x[10]; 
    double fx[10];

    //int atualiza = 0;

	//Configuracoes da jogabilidade
	bool chefe = false;
	bool sair = false;
	bool introducao = true;
	introducao = false;
	bool fim_introducao = false;
	bool reinicio = false;
	bool minion_4_usado = FALSE;
	int rodada = 0;
	int controle =- 1;
	int mao_adversario = -1;
	int pontos_jogador_1 = 0;
	int pontos_jogador_2 = 0;
	int pontos_respeito = 1;
	int contador = 0;
	int primeira = 0;
	Minion *minion_adversario;
	
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

		
	
	//Seleção do minion inicial.
	minion_adversario = rand_boss(&minion_4_usado);
	
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
		
			/********** Exibição de tela ***********/ 
			switch(tela){
				case TELA_OPCAO:
					//printf("Tela %d\n", tela);
					tela_abertura();
					break;
				case TELA_ABERTURA:
					if(introducao){
						tela_introducao();
						if(controle == PEDRA){
							//Sai da primeira introducao e vai para a abertura de inicio dos minions.
							introducao = false;
							primeira = TRUE;
							controle =-1;
							}
						}
					else {
							//tela de introducao do Minion.
							tela_minion(minion_adversario, primeira);
							if(controle == PEDRA){
								//Sai da introducao e comeca o jogo no proximo loop.
								tela = TELA_JOGO;
								//Próximo loop não é a primeira introdução e não é a primeira frase de minion.
								primeira = FALSE;
								controle =-1;
							}
						}
					break;
				case TELA_JOGO:
					printf("Tela %d", tela);
					
					for(contador = 1; contador <= 5; contador++)
						tela_jogo(pontos_jogador_1, pontos_jogador_2, minion_adversario, contador);
					//if()
					//Se venceu contra chefe vai para tela vencedor. Se não vai para a próxima partida contra outro minion.
					/*if()
					else {
						tela = TELA_ABERTURA;
						introducao = false;
						controle = -1;
					}*/
					break;
				case TELA_VENCEDOR:
					tela_vencedor();
					if(controle == PEDRA){
						tela = TELA_OPCAO;
						//Reinicia jogo
						chefe = false;
						introducao = true;
						rodada = 0;
						controle =-1;
						pontos_jogador_1 = 0;
						pontos_jogador_2 = 0;
						pontos_respeito = 1;
					}
					else if(controle == TESOURA) {
						sair = true;
					}
					break;
				case TELA_PERDEDOR:
					//printf("Tela %d", tela);
					tela_perdedor(chefe);
					if(controle == PEDRA) {
						tela = TELA_OPCAO;
						//Reinicia jogo
						chefe = false;
						introducao = true;
						rodada = 0;
						controle =-1;
						pontos_jogador_1 = 0;
						pontos_jogador_2 = 0;
						pontos_respeito = 1;
					}
					else if(controle == TESOURA) {
						sair = true;
					}
					break;
			}
		
			if(sair)
				break;
			
			desenhar = 0;
			camera_atualiza(cam);
			//Antigo remove fundo
			subtrai_matriz(cam->quadro, primeiro, matriz);
			
			normalizacao_preto_e_branco(matriz, altura, largura);
			otsu_binarizacao(matriz, matriz_pb, altura, largura);
			
			filtro_borda(matriz_pb, matriz_pb, altura, largura);
			
			matriz_copia(matriz_pb, matriz_verde, altura, largura);
			poligono *f = fecho(matriz_verde, altura, largura);
			
			if(game->debug) {
				camera_copia(cam, matriz, esquerda);
			}
			
			matriz_copia(matriz, matriz_contagem, altura, largura);

			//camera_copia(cam, matriz_verde, direita);
			
			ALLEGRO_COLOR azul = al_map_rgb_f(0, 0, 255);
			ALLEGRO_COLOR verde = al_map_rgb_f(0, 255, 0);
			ALLEGRO_COLOR preto = al_map_rgb_f(0, 0, 0);
			
			
			/*
			Tesoura, 20000 - 36000

			Pedra,   15000 - 45000

			Papel, 40000 - 120000
			*/
			ponto laranja;
			centroide(f, laranja);
			
			//printf("PB %d %d %d %d %d %d\n", laranja[X], laranja[Y], menor_x[X], maior_x[X], menor_y[Y], maior_y[Y]);
			print_poligono(f);
			
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
			
			area *b = conta_pb(laranja, matriz_contagem);

			calcula_padrao(f, b);

			if(game->debug)
				camera_copia(cam, matriz_contagem, direita);
			
			al_flip_display();
			free(b);
			free(f);
			

			/*********** Ações do jogo. ************/
			
			//Tela de Abertura rodando.
			if(tela == TELA_OPCAO){
				if(reinicio){
					reinicio = false;
				}
				else {
					if(controle == TESOURA){
						break;
					}
					else if(controle == PEDRA){
						//Comeca introducao do chefe no inicio do jogo.
						tela = TELA_ABERTURA;	
						introducao = true;
					}
				}
			} 
			else if(tela == TELA_JOGO){
				
				if(ganhador_rodada(controle, mao_adversario) == JOGADOR_1){
						pontos_jogador_1++;
					}
					else {
						pontos_jogador_2++;
					}
					
				if(fim_jogada(pontos_jogador_1, pontos_jogador_2, game->melhor_de)){
					if(chefe){
						//Chefe ganhou
						if(ganhador_jogo(pontos_jogador_1, pontos_jogador_2) == JOGADOR_2){
							tela = TELA_PERDEDOR;
						}
						else {
							tela = TELA_VENCEDOR;
						}
					}
					else {
						//Jogo contra minion.
						
						//Ganhador do jogo atual.
						if(ganhador_jogo(pontos_jogador_1, pontos_jogador_2) == EMPATE) {
							//Tela empate reinicia a partida. Possui al_rest de 4 segundos.
							tela_empate();
							
							//Reinicia a partida.
							pontos_jogador_1 = 0;
							pontos_jogador_2 = 0;
						}
						else if(ganhador_jogo(pontos_jogador_1, pontos_jogador_2) == JOGADOR_1){
							//Adiciona pontos de respeito.
							pontos_respeito += minion_adversario->pontos_vencidos;
							//Se acabou pontos de respeito exibe tela 4.
							if(fim_de_jogo(pontos_respeito)){
								//Jogo acabou contra minions, agora tem respeito suficiente para jogar contra o chefe. É tudo ou nada contra o chefe.
								if(pontos_respeito >= 10){
									chefe = true;
								}
							}
							else {
								//Selecao do próximo minion.
								minion_adversario = rand_boss(&minion_4_usado);
							}
						}
						else {
							//Remove pontos de respeito.
							pontos_respeito -= minion_adversario->pontos_perdidos;
							if(fim_de_jogo(pontos_respeito)){
								tela = TELA_PERDEDOR;
							}
						}
					}
				}
			}
			
			/******************** Controle e escolha da mão adversária ****************************/
		
			//controle = ;
			//mao_adversaria = ;
		}
		
		
		
	}
	
	al_destroy_bitmap(direita);
	al_destroy_bitmap(esquerda);
	
    camera_libera_matriz(cam, matriz);

	/**********/

	finalizar_allegro();

    return EXIT_SUCCESS;
}