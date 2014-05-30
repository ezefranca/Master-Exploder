#ifndef COMUM_H
#define COMUM_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include "camera.h"
#include "otsu.h"
#include "config.h"
#include "idioma.h"
#include "utils.h"
#include "limiarizacao.h"
#include "normalizacaorgb.h"
#include "normalizacao.h"
#include "filtros.h"
#include "matrizes.h"
#include "ezequiel.h"
#include "fecho.h"

/*Constantes*/
#define FPS 60
#define PEDRA 2
#define TESOURA 1
#define PAPEL 0
#define EMPATE 0
#define JOGADOR_2 2
#define JOGADOR_1 1


//Bloco de variaveis
int euclidiana;
camera *cam;

//Fim do bloco de variaveis

int largura;
int altura;


ALLEGRO_TIMER *timer;
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_CONFIG *config;
IDIOMA *idioma;

#endif
