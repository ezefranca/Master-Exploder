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

void aviso(char *mensagem){
	fputs(mensagem, stderr);
}

float string_para_float(char *string){
	if(string == NULL) {
		aviso("Não pegou a configuração correta.");
		return 1;
	}
	return strtod(string, NULL);
}

int string_para_int(char *string){
	if(string == NULL) {
		aviso("Não pegou a configuração correta.");
		return 1;
	}
	return atoi(string);
}
