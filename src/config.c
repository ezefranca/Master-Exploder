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

	//Setar item de configuracao.
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
	/** Colocar a lista de configuracoes padroes aqui. */
	ALLEGRO_CONFIG *new_config;

	new_config = al_create_config();

	setar_configuracao("CAM_DIVISOR", "1.5", "camera", new_config);
	setar_configuracao("LUMINUS", "80", "camera", new_config);
	setar_configuracao("TIMER_DIVIDENDO", "1.0", "allegro", new_config);
	setar_configuracao("LARGURA", "1280", "allegro", new_config);
	setar_configuracao("ALTURA", "720", "allegro", new_config);
	setar_configuracao("IDIOMA", "data/idiomas/pt_br.conf", "system", new_config);
	setar_configuracao("DEBUG", "false", "system", new_config);
	
	
	
	
	
	if(!al_save_config_file(name, new_config)) {
		free(new_config);
		erro("Erro na criacao do arquivo de configuracao inicial\n");
		}
	free(new_config);
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
