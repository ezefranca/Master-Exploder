#ifndef CONFIG_H
#define CONFIG_H
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
bool setar_configuracao(const char *conf_key, const char *conf_value, const char *section, ALLEGRO_CONFIG *config);

/**
 *  <#Description#>
 *
 *  @param name <#name description#>
 *
 *  @return <#return value description#>
 */
bool criar_configuracao(char *name);
/**
 *  <#Description#>
 *
 *  @param name   <#name description#>
 *  @param config <#config description#>
 *
 *  @return <#return value description#>
 */
bool salvar_configuracao(char *name, ALLEGRO_CONFIG *config);
/**
 *  <#Description#>
 *
 *  @param name <#name description#>
 *
 *  @return <#return value description#>
 */
ALLEGRO_CONFIG *carregar_configuracao(const char *name);
/**
 *  <#Description#>
 *
 *  @param conf_key <#conf_key description#>
 *  @param section  <#section description#>
 *  @param config   <#config description#>
 *
 *  @return <#return value description#>
 */
const char *pegar_configuracao(const char *conf_key, const char *section, const ALLEGRO_CONFIG *config);
#endif
