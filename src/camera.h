#ifndef CAMERA_H
#define CAMERA_H

#include <opencv/highgui.h>
#include <allegro5/allegro.h>
#include "config.h"

/**
 *  <#Description#>
 */
typedef struct {
  unsigned char ***quadro;
  int largura, altura;
  CvCapture *capture;
} camera;


/**
 *  <#Description#>
 *
 *  @param i <#i description#>
 *
 *  @return <#return value description#>
 */
camera *camera_inicializa(int i);
/**
 *  <#Description#>
 *
 *  @param cam <#cam description#>
 */
void camera_finaliza(camera *cam);
/**
 *  <#Description#>
 *
 *  @param cam <#cam description#>
 */
void camera_atualiza(camera *cam);
/**
 *  <#Description#>
 *
 *  @param cam    <#cam description#>
 *  @param matriz <#matriz description#>
 *  @param bitmap <#bitmap description#>
 */
void camera_copia(camera *cam, unsigned char ***matriz, ALLEGRO_BITMAP *bitmap);
/**
 *  <#Description#>
 *
 *  @param cam <#cam description#>
 *
 *  @return <#return value description#>
 */
unsigned char ***camera_aloca_matriz(camera *cam);
/**
 *  <#Description#>
 *
 *  @param cam    <#cam description#>
 *  @param matriz <#matriz description#>
 */
void camera_libera_matriz(camera *cam, unsigned char ***matriz);

#endif
