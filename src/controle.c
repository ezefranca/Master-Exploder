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
 int calcula_padrao(poligono *f, area *b, mao *pedra_inicial){

 	c = malloc(sizeof(controle));
 	c->razao = abs(area_do_fecho(f) / pedra_inicial->area_fecho);

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
		//printf("razao: %.3f\n", c->razao);
 		int 
 		padrao = 0;

 		pontos_extremo(f, altura, largura);
 		//printf("%.2f\n", c->razao);

 		if (c->razao < 1)
 		{
 			printf("PEDRA\n");
 			return 2;
 		}
 		else{
 			printf("TESOURA ou PAPEL\n");
 			//printf("%d\n", (maior_x[X] - menor_x[X]));
 			int x = area_do_fecho(f) - b->qtd_branco;
 			if(x > 10000){
 				return 1;
 				//tesoura 
 			//printf("%d\n", x);
 			}else{
 				//papel
 				return 0;
 			}
 		}

 		


 		free(c);
 		return -1;
 	}
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
 	pedra_inicial->area_fecho = area_do_fecho(fecho);
 	pontos_extremo(fecho, altura, largura);
 	pedra_inicial->maior_x[X] = maior_x[X];
 	pedra_inicial->maior_x[Y] = maior_x[Y];
 	pedra_inicial->menor_y[X] = menor_y[X];
 	pedra_inicial->menor_y[Y] = menor_y[Y];

 	return;

 }
