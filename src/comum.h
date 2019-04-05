#ifndef COMUM_H
#define COMUM_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
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
CAMERA *cam;

//Fim do bloco de variaveis

IDIOMA *linguagem;
ALLEGRO_TIMER *timer;
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_CONFIG *config;

  
#endif
