#include <stdio.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include "utils.h"

void erro(char *mensagem) {
  fputs(mensagem, stderr);

  exit(EXIT_FAILURE);
}

<<<<<<< HEAD
float string_para_float(char *string){
=======
float string2float(char *string){
>>>>>>> 007b205307e56e74bb3c93cada309cccc554a52a
	float valor;

	sscanf(string, "%f", &valor);
	return valor;	
<<<<<<< HEAD
}

int string_para_int(char *string){
	int valor;

	sscanf(string, "%d", &valor);
	return valor;	
=======
>>>>>>> 007b205307e56e74bb3c93cada309cccc554a52a
}