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
float string_para_float(char *string){
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
