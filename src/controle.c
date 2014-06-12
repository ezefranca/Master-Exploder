#include "controle.h"
#include <math.h>
#include "fecho.h"

int calcula_padrao(poligono *f, area *b){


	c = malloc(sizeof(controle));

	c->razao = abs(area_do_fecho(f) / b->qtd_branco);
	if(contador_global < 10){
		verificacoes[contador_global] = c->razao;
	}else{

		for(int i = 0; i < 10; i++){
			for (int j = i+1; j < 9; j++)
			{
				if (verificacoes[i] == verificacoes[j])
				{
					padrao++;
				}
			}
		}
		contador_global = -1;
	}
	contador_global++;

	if(padrao >= 5){
		printf("encontrado um padrao\n");

		for(int i = 0; i < 10; i++){
			printf("%d\n", verificacoes[i]);
			verificacoes[i] == 1;

		}

		padrao = 0;
	}

	//printf("razao: %.1f\n", razao);
  	free(c);
	return 0;
}