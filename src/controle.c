#include "controle.h"
#include <math.h>
#include "fecho.h"

// Como para dar play ele terá na primeira tela usar pedra, contabiliza a quantidade de brancos no fecho (deveria ser muito maior que preto) e registra a informação de minimo e maximo da primeira detecção com maioria branco como pedra, usa essa informação para diferenciar papel, e tesoura é a diferença de preto e branco (mesmo tendo o mesmo minimo e maximo do papel - eixo Y).

// Bom essa é minha sugestão, talvez você já a tenha tentado.

/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
int calcula_padrao(poligono *f, area *b){

	pontos_extremo(f, altura, largura);

	if ((pedra_inicial->maior_y[Y] - pedra_inicial->menor_y[Y]) < maior_y[Y] - menor_y[Y])
	{
		printf("nao eh pedra\n");
	}


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
		//printf("encontrado um padrao\n");

		for(int i = 0; i < 10; i++){
			//printf("%d\n", verificacoes[i]);
			verificacoes[i] == 1;

		}

		padrao = 0;
	}

	//printf("razao: %.1f\n", razao);
  	free(c);
	return 0;
}


/**
 *  <#Description#>
 *
 *  @param matriz  <#matriz description#>
 *  @param saida   <#saida description#>
 *  @param altura  <#altura description#>
 *  @param largura <#largura description#>
 */
void captura_pedra(mao *pedra_inicial, poligono *fecho, area *b){

	pedra_inicial->qtd_branco = b->qtd_branco;
	pontos_extremo(fecho, altura, largura);
	pedra_inicial->maior_x[X] = maior_x[X];
	pedra_inicial->maior_x[Y] = maior_x[Y];
	pedra_inicial->menor_y[X] = menor_y[X];
	pedra_inicial->menor_y[Y] = menor_y[Y];

	return;

}
