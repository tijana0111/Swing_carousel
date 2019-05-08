#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "swing_carousel.h"
#include <GL/glut.h>
#include "image.h"

#define NUMBER_OF_TEXTURES 1

#define FILENAME0 "grass.bmp"

// Funkcija koja iscrtava sferu u kojoj se sve nalazi i koja predstavlja nebo.
void draw_sky();

// Funkcija koja crta travu.
void draw_grass();

void initialize_texture(void);

#endif
