#ifndef IDIOMA_H
#define IDIOMA_H
/**
 *  <#Description#>
 */
typedef struct _elemento_string {
 	char *string;
 	char *var;
 	struct _elemento_string *proximo;
} elemento_string;

typedef struct {
	elemento_string **hash;
} IDIOMA;
/**
 *  <#Description#>
 *
 *  @param arquivo <#arquivo description#>
 */
void carregar_idioma(const char *arquivo);
/**
 *  <#Description#>
 *
 *  @param key    <#key description#>
 *  @param idioma <#idioma description#>
 *
 *  @return <#return value description#>
 */
const char *pegar_idioma(const char *key, IDIOMA *idioma);
/**
 *  <#Description#>
 *
 *  @param language <#language description#>
 */
void destroi_idioma(IDIOMA *language);

#endif