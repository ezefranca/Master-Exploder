#include "idioma.h"

#define TRUE 1
#define FALSE 0
#define NUMERO_ALFABETO 24
/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
IDIOMA *aloca_idioma(){
	IDIOMA *language = malloc(sizeof(IDIOMA));
    language->hash = malloc(NUMERO_ALFABETO * sizeof(elemento_string*));
	
	for(int n = 0; n < NUMERO_ALFABETO; n++){
		language->hash[n] = NULL;
	}
    return language;
}
/**
 *  <#Description#>
 *
 *  @param entrada <#entrada description#>
 *
 *  @return <#return value description#>
 */
int conta_linhas(ALLEGRO_FILE *entrada) {
    int linhas;
    char caractere, ultimo_caractere;
    linhas = 1;

    while ((caractere = al_fgetc(entrada)) != EOF) {
        if (caractere == '\n')
            linhas++;
        ultimo_caractere = caractere;
    }
    if (ultimo_caractere == '\n') --linhas;

    //Retorna o ponteiro para inicio do arquivo. Similar to rewind.
    al_fseek(entrada, 0, ALLEGRO_SEEK_SET);
    return linhas;
}
/**
 *  <#Description#>
 *
 *  @param entrada <#entrada description#>
 *  @param ate     <#ate description#>
 *
 *  @return <#return value description#>
 */
int conta_ate(ALLEGRO_FILE *entrada, char ate) {
    int n;
    char caractere;

    for (n = 0; (caractere = al_fgetc(entrada)) != ate && caractere != EOF; n++);
    
	return n;
}
/**
 *  <#Description#>
 *
 *  @param idi    <#idi description#>
 *  @param var    <#var description#>
 *  @param string <#string description#>
 */
void insere_idioma(IDIOMA *idi, char *var, char *string) {
    int hash_numero;
	
	elemento_string *e = malloc(sizeof(elemento_string));
    e->var = var;
    e->string = string;
	
    hash_numero = (int) var[0] % NUMERO_ALFABETO;
	
	if (idi->hash[hash_numero] == NULL) {
        idi->hash[hash_numero] = e;
        e->proximo = NULL;
    } else {
        e->proximo = idi->hash[hash_numero];
        idi->hash[hash_numero] = e;
    }
}

/* Fun;'oes visiveis no .h */
/**
 *  <#Description#>
 *
 *  @param arquivo <#arquivo description#>
 */
void carregar_idioma(const char *arquivo){
	ALLEGRO_FILE *entrada;
	char **string, **var, c;
	int i, linhas;
	int *tvar, *tstring;
	
	linguagem = aloca_idioma();
	
	entrada = al_fopen(arquivo, "r");

    if (!entrada) {
		aviso("erro na leitura do arquivo de idioma. idioma in code será usado.\n");
		return;
    }
	
    linhas = conta_linhas(entrada);
    var = malloc(linhas * sizeof (char *));
    string = malloc(linhas * sizeof (char *));
    tvar = malloc(linhas * sizeof (int));
    tstring = malloc(linhas * sizeof (int));

    for (i = 0; i < linhas; i++) {
		tvar[i] = conta_ate(entrada, '=');
        tstring[i] = conta_ate(entrada, '\n');

        var[i] = malloc(tvar[i] * sizeof (char));
        string[i] = malloc(tstring[i] * sizeof (char));
		
    }

    al_fseek(entrada, 0, ALLEGRO_SEEK_SET);

	
    for (i = 0; i < linhas; i++){
		al_fgets(entrada, var[i], tvar[i] + 1);
        al_fgetc(entrada);
        al_fgets(entrada, string[i], tstring[i] + 1);
		
		do {
			al_fgets(entrada, &c, 2);
        } while (c != '\n');

		printf("chegou %s = %s\n", var[i], string[i]);
        if(strlen(var[i]) > 0 && strlen(string[i]) > 0)
			insere_idioma(linguagem, var[i], string[i]);
	}
    
	al_fclose(entrada);

    free(string);
    free(var);

    free(tstring);
    free(tvar);

    return;
}
/**
 *  <#Description#>
 *
 *  @param key    <#key description#>
 *  @param idioma <#idioma description#>
 *
 *  @return <#return value description#>
 */
const char *pegar_idioma(const char *key, IDIOMA *idioma){
	elemento_string *anterior, *atual;

    anterior = idioma->hash[key[0] % NUMERO_ALFABETO];
		
	if (anterior == NULL) {
        //if(game->debug)
			//aviso("lista de idioma vazio\n");
        return key;
    } else if (strcmp(key, anterior->var) == 0) {
        return (anterior->string);
    } else {
        atual = anterior->proximo;
        while (atual != NULL && strcmp(key, atual->var) != 0) {
            anterior = atual;
            atual = anterior->proximo;
        }

        if (atual != NULL) {
            return (atual->string);
        }
    }
	return key;
}

/**
 *  <#Description#>
 *
 *  @param language <#language description#>
 */
void destroi_idioma(IDIOMA *language){
	if(language->hash != NULL)
		free(language->hash);
	if(language != NULL)
		free(language);
}