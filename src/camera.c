#include "camera.h"

/**
 *  Converte uma IplImage do openCV para tipo cam (Hashimoto)
 *
 *  @param cam   recebe um tipo camera
 *  @param image recebe um tipo IplImage (OpenCV)
 */
void camera_converte(camera *cam, IplImage *image) {
  char *row = image->imageData;

  for(int y = 0; y < cam->altura; y++) {
    char *pixel = row;

    for(int x = cam->largura - 1; x >= 0; x--) {
      cam->quadro[y][x][2] = *pixel;
      pixel++;

      cam->quadro[y][x][1] = *pixel;
      pixel++;

      cam->quadro[y][x][0] = *pixel;
      pixel++;
    }

    row += image->widthStep;
  }
}

/**
 *  Inicializa a camera
 *
 *  @param i  numero da camera, voce pode inicializar diversas cameras
 *
 *  @return returna cam, um tipo camera (Hashimoto)
 */
camera *camera_inicializa(int i) {
	camera *cam = NULL;
	double proporcao_h,proporcao_x;
	CvCapture *capture = cvCaptureFromCAM(i);

	if(capture) {
		IplImage *image = cvQueryFrame(capture);

		if(image) {
			cam = malloc(sizeof(camera));

			cam->capture = capture;
			//Manter a proporcao da camera, mas com a resolução de 640 de largura.
			proporcao_h = (double) image->height/image->width;
			proporcao_x = (double) image->width/image->height;
			
			cam->altura = (int) (game->largura_tela / 2) * proporcao_h;
			printf("%d", cam->altura);
			
			cam->largura = (int) cam->altura * proporcao_x;
			printf("%d %f", cam->largura, proporcao_x);
			
			cam->quadro = camera_aloca_matriz(cam);
		  camera_converte(cam, image);
		}
		else
		  cvReleaseCapture(&capture);
  }

  return cam;
}

/**
 *  Finaliza camera
 *
 *  @param cam cam para ser liberado da memória
 */
void camera_finaliza(camera *cam) {
  camera_libera_matriz(cam, cam->quadro);

  cvReleaseCapture(&cam->capture);

  free(cam);
}

/**
 *  Atualiza o frame da camera
 *
 *  @param cam recebe um tipo camera, ao qual atribui a imagem da camera
 */
void camera_atualiza(camera *cam) {
  IplImage *image = cvQueryFrame(cam->capture);

  camera_converte(cam, image);
}

/**
 *  Copia imagem da camera para um allegro bitmap
 *
 *  @param cam    tipo camera que vai contem a imagem
 *  @param matriz matrix tridimensional sem sinal
 *  @param bitmap allegro bitmap
 */
void camera_copia(camera *cam, unsigned char ***matriz, ALLEGRO_BITMAP *bitmap) {
  ALLEGRO_LOCKED_REGION *region = al_lock_bitmap(bitmap, ALLEGRO_PIXEL_FORMAT_ARGB_8888, ALLEGRO_LOCK_WRITEONLY);

  char *row = region->data;

  for(int y = 0; y < cam->altura; y++) {
    char *pixel = row;

    for(int x = 0; x < cam->largura; x++) {
      *pixel = matriz[y][x][2];
      pixel++;

      *pixel = matriz[y][x][1];
      pixel++;

      *pixel = matriz[y][x][0];
      pixel += 2;
    }

    row += region->pitch;
  }

  al_unlock_bitmap(bitmap);
}

/**
 *  Aloca uma matriz com o conteudo da camera
 *
 *  @param cam ponteiro de camera que vai ser alocado
 *
 *  @return matriz com conteudo da camera
 */
unsigned char ***camera_aloca_matriz(camera *cam) {
  unsigned char ***matriz = malloc(cam->altura * sizeof(unsigned char **));

  for(int y = 0; y < cam->altura; y++) {
    matriz[y] = malloc(cam->largura * sizeof(unsigned char *));

    for(int x = 0; x < cam->largura; x++)
      matriz[y][x] = malloc(4 * sizeof(unsigned char));
  }

  return matriz;
}

/**
 *  Desaloca a matriz
 *
 *  @param cam    tipo camera a ser desalocado
 *  @param matriz matriz a ser desalocada
 */
void camera_libera_matriz(camera *cam, unsigned char ***matriz) {
	for(int y = 0; y < cam->altura; y++) {
		for(int x = 0; x < cam->largura; x++)
			free(matriz[y][x]);
		free(matriz[y]);
	}
	free(matriz);
}
