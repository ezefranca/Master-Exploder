#include "terminate.h"
/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
int finalizar_allegro(){

    al_stop_timer(timer);

    al_unregister_event_source(queue, al_get_display_event_source(display));
    al_unregister_event_source(queue, al_get_timer_event_source(timer));

    al_destroy_event_queue(queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
	al_destroy_config(config);
	
    al_shutdown_primitives_addon();
    al_shutdown_image_addon();
	al_shutdown_font_addon();
	al_shutdown_ttf_addon();
    al_uninstall_system();

    camera_finaliza(cam);
	
	destroi_idioma(linguagem);
	
	
	/*al_destroy_font(game->fontes->super);
	al_destroy_font(game->fontes->h1);
	al_destroy_font(game->fontes->h2);
	al_destroy_font(game->fontes->h3);
	al_destroy_font(game->fontes->h4);
	al_destroy_font(game->fontes->h5);
	al_destroy_font(game->fontes->h6);
	al_destroy_font(game->fontes->p);*/
	
	free(game->fontes);
	free(game->telas);
	free(game->carrega);
	free(game->fontes);
	free(game->pontos);
	
	for(int i = 0; i < 5; i++){
		free(game->minions->minion[i]->falas->frase);
		free(game->minions->minion[i]->falas);
		free(game->minions->minion[i]);
	}
	free(game->minions->minion);
	free(game->minions);
	
	free(game);
	
	return 1;
}
