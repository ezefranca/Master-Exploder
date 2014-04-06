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
#include "utils.h"
#include "limiarizacao.h"
#include "normalizacaorgb.h"
#include "normalizacao.h"
#include "filtros.h"
#include "matrizes.h"
#include "ezequiel.h"

/*Constantes*/
#define FPS 60

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
ALLEGRO_COLOR vermelho;// = al_map_rgb_f(255, 0, 0);
#endif
