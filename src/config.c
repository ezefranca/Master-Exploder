#include "config.h"

/**
 *  <#Description#>
 *
 *  @param conf_key   <#conf_key description#>
 *  @param conf_value <#conf_value description#>
 *  @param section    <#section description#>
 *  @param config     <#config description#>
 *
 *  @return <#return value description#>
 */
bool setar_configuracao(const char *conf_key, const char *conf_value, const char *section, ALLEGRO_CONFIG *config) {
	const char *value;

	al_add_config_section(config, section);

	//Seta item de configuracao.
	al_set_config_value(config, section, conf_key, conf_value);

	value = al_get_config_value(config, section, conf_key);
	if(strcmp(value, conf_value)){
		return TRUE;
	}
	return FALSE;
}
/**
 *  <#Description#>
 *
 *  @param name <#name description#>
 *
 *  @return <#return value description#>
 */
bool criar_configuracao(char *name){
	ALLEGRO_CONFIG *new_config;

	new_config = al_create_config();

	/** Configurações da camera e ambiente **/
	setar_configuracao("CAM_DIVISOR", "1.5", "camera", new_config);
	setar_configuracao("LUMINUS", "80", "camera", new_config);
	setar_configuracao("USAR_FECHO", "true", "camera", new_config);
	
	
	/** Configurações do Allegro **/
	setar_configuracao("TIMER_DIVIDENDO", "1.0", "allegro", new_config);
	setar_configuracao("LARGURA", "1280", "allegro", new_config);
	setar_configuracao("ALTURA", "720", "allegro", new_config);
	
	/** Configurações do Sistema do Jogo **/
	setar_configuracao("IDIOMA", "data/idiomas/pt_br.conf", "system", new_config);
	setar_configuracao("LARGURA_TELA", "1280", "system", new_config);
	setar_configuracao("ALTURA_TELA", "720", "system", new_config);
	setar_configuracao("VIZINHOS", "100", "system", new_config);
	
	
	/** Configurações de Jogabilidade **/
	setar_configuracao("QTD_MINIONS", "5", "jogo", new_config);
	setar_configuracao("PONTOS_RESPEITO_MAXIMO", "10", "jogo", new_config);
	setar_configuracao("PONTOS_RESPEITO_INICIAL", "1", "jogo", new_config);
	setar_configuracao("MELHOR_DE", "5", "jogo", new_config);
	setar_configuracao("MULTI_CALIBRAGEM", "2", "jogo", new_config);
	setar_configuracao("TEMPO_ANTES_JOGADA", "2", "jogo", new_config);
	setar_configuracao("TEMPO_JOGADA", "5", "jogo", new_config);
	setar_configuracao("TEMPO_EXIBICAO_JOGADA", "3", "jogo", new_config);
	
	
	/** Configurações de pontuação **/
	setar_configuracao("IDIOMA", "data/idiomas/pt_br.conf", "points", new_config);
	
	/** Configurações de Fonte **/
	setar_configuracao("HABILITADO", "false", "fonts", new_config);
	setar_configuracao("H1_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	setar_configuracao("H2_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	setar_configuracao("H3_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	setar_configuracao("H4_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	setar_configuracao("H5_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	setar_configuracao("H6_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	setar_configuracao("SUPER_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	setar_configuracao("P_FONTE", "assets/font/PAPYRUS.TTF", "fonts", new_config);
	
	setar_configuracao("H1_TAMANHO", "50", "fonts", new_config);
	setar_configuracao("H2_TAMANHO", "40", "fonts", new_config);
	setar_configuracao("H3_TAMANHO", "30", "fonts", new_config);
	setar_configuracao("H4_TAMANHO", "25", "fonts", new_config);
	setar_configuracao("H5_TAMANHO", "20", "fonts", new_config);
	setar_configuracao("H6_TAMANHO", "15", "fonts", new_config);
	setar_configuracao("SUPER_TAMANHO", "150", "fonts", new_config);
	setar_configuracao("P_TAMANHO", "12", "fonts", new_config);
	
	
	/** Configurações de Audio **/
	setar_configuracao("HABILITADO", "true", "audio", new_config);
	setar_configuracao("FUNDO", "assets/sound/one.wav", "audio", new_config);
	
	/** Configurações de Telas **/
	setar_configuracao("HABILITADO", "true", "tela", new_config);
	setar_configuracao("SPRITE_HABILITADO", "true", "tela", new_config);
	setar_configuracao("GAMEOVER_HABILITADO", "true", "tela", new_config);
	setar_configuracao("START_HABILITADO", "true", "tela", new_config);
	setar_configuracao("GAME_HABILITADO", "true", "tela", new_config);
	
	/** Configurações de Debug **/
	setar_configuracao("HABILITADO", "false", "debug", new_config);
	
	if(!al_save_config_file(name, new_config)){
		free(new_config);
		erro("Erro na criacao do arquivo de configuracao inicial\n");
		}
	free(new_config);
	//Sleep thread atual enquanto o sistema operacional cria o arquivo. 
	al_rest(1);
	return TRUE;
}
/**
 *  <#Description#>
 *
 *  @param name   <#name description#>
 *  @param config <#config description#>
 *
 *  @return <#return value description#>
 */
bool salvar_configuracao(char *name, ALLEGRO_CONFIG *config){
	return al_save_config_file(name, config);
}
/**
 *  <#Description#>
 *
 *  @param name <#name description#>
 *
 *  @return <#return value description#>
 */
ALLEGRO_CONFIG *carregar_configuracao(const char *name) {
	return al_load_config_file(name);
}
/**
 *  <#Description#>
 *
 *  @param conf_key <#conf_key description#>
 *  @param section  <#section description#>
 *  @param config   <#config description#>
 *
 *  @return <#return value description#>
 */
const char *pegar_configuracao(const char *conf_key, const char *section, const ALLEGRO_CONFIG *config){
	return al_get_config_value(config, section, conf_key);
}