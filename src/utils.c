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

float string_para_float(char *string){
	float valor;

	sscanf(string, "%f", &valor);
	return valor;
}

int string_para_int(char *string){
	int valor;

	sscanf(string, "%d", &valor);
	return valor;
}
