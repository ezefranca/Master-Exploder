#include "init.h"
#include "comum.h"

/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
int inicializar_allegro(){
	game = malloc(sizeof(GAME));
	game->pontos = malloc(sizeof(PONTUACAO));
	game->fontes = malloc(sizeof(FONTES));
	game->carrega = malloc(sizeof(CARREGAMENTO));
	game->telas = malloc(sizeof(TELAS));
	game->minions = malloc(sizeof(MINIONS));
	
	int pontos_perdidos;
	int pontos_vencidos;
	
	config = carregar_configuracao("configuration.conf");
    
	if(config == NULL){
        criar_configuracao("configuration.conf");
		config = carregar_configuracao("configuration.conf");
	}
	
	game->divisor_camera = string_para_double(pegar_configuracao("CAM_DIVISOR","camera", config));//1.5;
	game->luminus =  string_para_int(pegar_configuracao("LUMINUS","camera", config));//80;
	game->usa_fecho = string_para_boolean(pegar_configuracao("USAR_FECHO","camera", config));

	game->largura_tela = string_para_int(pegar_configuracao("LARGURA_TELA","system", config));//1280;
	game->altura_tela = string_para_int(pegar_configuracao("ALTURA_TELA","system", config));//720;
	game->divisor_tempo = string_para_double(pegar_configuracao("TIMER_DIVIDENDO","allegro", config));//1;
	
	game->_vizinhos = string_para_int(pegar_configuracao("VIZINHOS","system", config));//100;
	
	game->melhor_de = string_para_int(pegar_configuracao("MELHOR_DE","jogo", config));//5;
	game->calibragem = string_para_int(pegar_configuracao("MULTI_CALIBRAGEM","jogo", config));//3;
	game->tempo_jogada = string_para_int(pegar_configuracao("TEMPO_JOGADA","jogo", config));//5;
	game->tempo_antes_jogada = string_para_int(pegar_configuracao("TEMPO_ANTES_JOGADA","jogo", config));//5;
	game->tempo_exibicao_jogada = string_para_int(pegar_configuracao("TEMPO_EXIBICAO_JOGADA","jogo", config));//5;
	game->minions->qtd = string_para_int(pegar_configuracao("QTD_MINIONS","jogo", config));//5;
	
	game->maximo_respeito = string_para_int(pegar_configuracao("MAXIMO","points", config));//10; 
	game->pontos->respeito_jogador_1 = string_para_int(pegar_configuracao("INICIAL","points", config));//0;
	game->pontos->respeito_jogador_2 = game->pontos->respeito_jogador_1;//0;
	
	//Valor se altera durante o jogo:
	game->pontos->numero_partidas = 0;
	game->pontos->jogador_1 = 0;
	game->pontos->jogador_2 = 0;
	
	game->debug = string_para_boolean(pegar_configuracao("HABILITADO","debug", config));//false;
	
	game->carrega->musica = string_para_boolean(pegar_configuracao("HABILITADO","audio", config));//false;
	game->carrega->fonte = string_para_boolean(pegar_configuracao("HABILITADO","fonts", config));//false;
	
	game->carrega->display = string_para_boolean(pegar_configuracao("HABILITADO","tela", config));//false;
	game->telas->sprite = string_para_boolean(pegar_configuracao("SPRITE_HABILITADO","tela", config));//;
	game->telas->gameover = string_para_boolean(pegar_configuracao("GAMEOVER_HABILITADO","tela", config));//;
	game->telas->start = string_para_boolean(pegar_configuracao("START_HABILITADO","tela", config));//;
	game->telas->game = string_para_boolean(pegar_configuracao("GAME_HABILITADO","tela", config));//;
	
	/** Carregamento dos Minions **/
	game->minions->minion = malloc(game->minions->qtd * sizeof(MINION*));
	
	for(int i = 0; i < game->minions->qtd; i++){
		game->minions->minion[i] = malloc(sizeof(MINION));
	}
	
	game->minions->minion[0]->probabilidade = 0.4;
	game->minions->minion[0]->pontos_perdidos = 1;
	game->minions->minion[0]->pontos_vencidos = 1;
	game->minions->minion[0]->falas = malloc(sizeof(FALAS));
	game->minions->minion[0]->falas->n = 2;
	game->minions->minion[0]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[0]->falas->frase = malloc(game->minions->minion[0]->falas->n * sizeof(char*));
	game->minions->minion[0]->falas->frase[0] = "Now is my turn!";
	game->minions->minion[0]->falas->frase[1] = "I will make you burn!";
	//game->minions->minion[0]->falas->frase[2] = "teste";
	
	game->minions->minion[1]->probabilidade = 0.75;
	game->minions->minion[1]->pontos_perdidos = 2;
	game->minions->minion[1]->pontos_vencidos = 3;
	game->minions->minion[1]->falas = malloc(sizeof(FALAS));
	game->minions->minion[1]->falas->n = 1;
	game->minions->minion[1]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[1]->falas->frase = malloc(game->minions->minion[1]->falas->n * sizeof(char*));
	game->minions->minion[1]->falas->frase[0] = "You can try, but ya gona down";
	
	game->minions->minion[2]->probabilidade = 0.9;
	game->minions->minion[2]->pontos_perdidos = 3;
	game->minions->minion[2]->pontos_vencidos = 2;
	game->minions->minion[2]->falas = malloc(sizeof(FALAS));
	game->minions->minion[2]->falas->n = 3;
	game->minions->minion[2]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[2]->falas->frase = malloc(game->minions->minion[2]->falas->n * sizeof(char*));
	game->minions->minion[2]->falas->frase[0] = "I am not the minion Vinicius.";
	game->minions->minion[2]->falas->frase[1] = "I am the Vinicius Second.";
	game->minions->minion[2]->falas->frase[2] = "Lets play";
	
	game->minions->minion[3]->probabilidade = 0.95;
	game->minions->minion[3]->pontos_perdidos = 10;
	game->minions->minion[3]->pontos_vencidos = 0;
	game->minions->minion[3]->falas = malloc(sizeof(FALAS));
	game->minions->minion[3]->falas->n = 1;
	game->minions->minion[3]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[3]->falas->frase = malloc(game->minions->minion[3]->falas->n * sizeof(char*));
	game->minions->minion[3]->falas->frase[0] = "I am Vinicius!";
	game->minions->minion[3]->falas->frase[0] = "Kibe is not a crime!";
		
	game->minions->minion[4]->probabilidade = 1;
	game->minions->minion[4]->pontos_perdidos = 3;
	game->minions->minion[4]->pontos_vencidos = 2;
	game->minions->minion[4]->falas = malloc(sizeof(FALAS));
	game->minions->minion[4]->falas->n = 1;
	game->minions->minion[4]->imagem = "assets/image/minions/vinicius.png";
	game->minions->minion[4]->falas->frase = malloc(game->minions->minion[4]->falas->n * sizeof(char*));
	game->minions->minion[4]->falas->frase[0] = "A dica para o EP4 está no EP3!";
	
	
	cam = camera_inicializa(0);

	game->largura_camera = cam->largura;
	game->altura_camera = cam->altura;
	
    if(!cam)
        erro("erro na inicializacao da camera\n");

	if(!al_init())
        erro("erro na inicializacao do allegro\n");

    if(!al_init_image_addon())
        erro("erro na inicializacao do adicional de imagem\n");

    if(!al_init_primitives_addon())
        erro("erro na inicializacao do adicional de primitivas\n");

    if(!al_install_audio())
      	erro("failed to initialize audio!\n");
   
    if(!al_init_acodec_addon())
      erro("failed to initialize audio codecs!\n");
 
	al_init_font_addon();
	al_init_ttf_addon();
		
	if(!al_reserve_samples(1))
		erro("failed to reserve samples!\n");

    timer = al_create_timer(game->divisor_tempo/ FPS);
	
    if(!timer)
        erro("erro na criacao do relogio\n");

    display = al_create_display(game->largura_tela, game->altura_tela);
    if(!display)
        erro("erro na criacao da janela\n");

    queue = al_create_event_queue();
    if(!queue)
        erro("erro na criacao da fila\n");

	game->idioma_setado = pegar_configuracao("IDIOMA","system", config);
	
	game->fontes->super = al_load_font(pegar_configuracao("SUPER_FONTE","fonts", config), string_para_int(pegar_configuracao("SUPER_TAMANHO","fonts", config)), 10);
	game->fontes->h1 = al_load_font(pegar_configuracao("H1_FONTE","fonts", config), string_para_int(pegar_configuracao("H1_TAMANHO","fonts", config)), 10);
	game->fontes->h2 = al_load_font(pegar_configuracao("H2_FONTE","fonts", config), string_para_int(pegar_configuracao("H2_TAMANHO","fonts", config)), 10);
	game->fontes->h3 = al_load_font(pegar_configuracao("H3_FONTE","fonts", config), string_para_int(pegar_configuracao("H3_TAMANHO","fonts", config)), 10);
	game->fontes->h4 = al_load_font(pegar_configuracao("H4_FONTE","fonts", config), string_para_int(pegar_configuracao("H4_TAMANHO","fonts", config)), 10);
	game->fontes->h5 = al_load_font(pegar_configuracao("H5_FONTE","fonts", config), string_para_int(pegar_configuracao("H5_TAMANHO","fonts", config)), 10);
	game->fontes->h6 = al_load_font(pegar_configuracao("H6_FONTE","fonts", config), string_para_int(pegar_configuracao("H6_TAMANHO","fonts", config)), 10);
	game->fontes->p = al_load_font(pegar_configuracao("P_FONTE","fonts", config), string_para_int(pegar_configuracao("P_TAMANHO","fonts", config)), 10);
	
	if(game->idioma_setado != NULL)
        carregar_idioma(game->idioma_setado);
	else
		carregar_idioma("data/idiomas/pt_br.conf");
	
	char *test = pegar_idioma("test", linguagem);

	if(game->carrega->musica){
		game->musica = al_load_sample(pegar_configuracao("FUNDO","audio", config));
		
		if (!game->musica){
				erro("Nao carregou o arquivo de musica game->musica");
			}
		else
			al_play_sample(game->musica, string_para_double(pegar_configuracao("FUNDO_GAIN","audio", config)), string_para_double(pegar_configuracao("FUNDO_PAN","audio", config)), string_para_double(pegar_configuracao("FUNDO_SPEED","audio", config)), ALLEGRO_PLAYMODE_LOOP,NULL);
	}
	
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    al_start_timer(timer);
    return 1;
}