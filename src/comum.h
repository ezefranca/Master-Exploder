#ifndef COMUM_H
#define COMUM_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <stdlib.h>
#include "camera.h"
#include "otsu.h"
#include "config.h"
#include "frames.h"
#include "idioma.h"
#include "utils.h"
#include "limiarizacao.h"
#include "normalizacaorgb.h"
#include "normalizacao.h"
#include "filtros.h"
#include "matrizes.h"
#include "ezequiel.h"
#include "fecho.h"
#include "controle.h"

/*Constantes*/
#define FPS 60



//Bloco de variaveis
int euclidiana;
camera *cam;

//Fim do bloco de variaveis

int largura;
int altura;

ALLEGRO_FONT *fonte;
ALLEGRO_TIMER *timer;
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_CONFIG *config;
IDIOMA *idioma;

/**
 *  <#Description#>
 */
typedef struct _pontos {
	int numero_partidas;
	int jogador_1;
	int jogador_2;
} Pontuacao;

/**
 *  <#Description#>
 */
typedef struct _game {
	int largura_camera;
	int altura_camera;
	int largura_tela;
	int altura_tela;
	
	float divisor_tempo;
	float divisor_camera;
	int luminus;
	bool debug;
	
	const char *idioma_setado;
	Pontuacao *pontos;
} Game;

Game *game;
  
#endif
