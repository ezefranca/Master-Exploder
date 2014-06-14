#include "utils.h"
/**
 *  <#Description#>
 *
 *  @param mensagem <#mensagem description#>
 */
void erro(char *mensagem) {
  fputs(mensagem, stderr);

  exit(EXIT_FAILURE);
}
/**
 *  <#Description#>
 *
 *  @param mensagem <#mensagem description#>
 */
void aviso(char *mensagem){
	fputs(mensagem, stderr);
}
/**
 *  <#Description#>
 *
 *  @param string <#string description#>
 *
 *  @return <#return value description#>
 */
double string_para_double(char *string){
	if(string == NULL) {
		aviso("Não pegou a configuração correta.");
		return 1;
	}
	return strtod(string, NULL);
}
/**
 *  <#Description#>
 *
 *  @param string <#string description#>
 *
 *  @return <#return value description#>
 */
int string_para_int(char *string){
	if(string == NULL) {
		aviso("Não pegou a configuração correta.");
		return 1;
	}
	return atoi(string);
}

/**
 *  <#Description#>
 *
 *  @param string <#string description#>
 *
 *  @return <#return value description#>
 */
int string_para_boolean(char *string){
	return (strcmp(string, "TRUE") == 0 || strcmp(string, "true") == 0 || strcmp(string, "True") == 0);
}