#ifndef FRAME_H
#define FRAME_H
#define PEDRA 2
#define TESOURA 1
#define PAPEL 0
#define EMPATE 0

typedef struct _idioma IDIOMA;
typedef struct _game Game;
typedef struct _minion Minion;


/**
 *  <#Description#>
 */
void tela_sprite();
/**
 *  <#Description#>
 */
void tela_vencedor();
/**
 *  <#Description#>
 */
void tela_perdedor();
/**
 *  <#Description#>
 */
void tela_abertura();

/**
 *  <#Description#>
 */
void tela_introducao();

/**
 *  <#Description#>
 */
void tela_minion(Minion *minion_adversario, int primeira_frase);

/**
 *  <#Description#>
 */
void tela_empate();

/**
 *  <#Description#>
 */
void tela_carregando(unsigned char ***matriz);

/**
 *  <#Description#>
 */
void tela_chefe();

/**
 *  <#Description#>
 *
 *  @param pontos_jogador_1 <#pontos_jogador_1 description#>
 *  @param pontos_jogador_2 <#pontos_jogador_2 description#>
 *  @param contador         <#contador description#>
 */
void tela_jogo(int pontos_jogador_1, int pontos_jogador_2, int pontos_respeito, Minion *minion_adversario, int contador, int mostra_contador);

void tela_jogo_maos(int pontos_jogador_1, int pontos_jogador_2, int pontos_respeito, int mao_jogador, int mao_adversaria);

#endif