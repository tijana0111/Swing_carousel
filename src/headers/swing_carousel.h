#ifndef SWING_CAROUSEL_H
#define SWING_CAROUSEL_H

#include <GL/glut.h>
#include <math.h>

#include "child.h"
#include "colors.h"
#include "background.h"

#define PI 3.1415926535
#define EPSILON 0.01

#define NUMBER_OF_SEATS (10)	 // broj sedista
#define HEIGHT (20)		// visina ringispila
#define WIDTH (25)		// sirina ringispila
#define EXPANSION_BY_STEP (2)	  // prosirenje za stepenik
#define SEAT_HALF (1)	  // polovina velicine sedista
#define HEIGHT_EXPANSION (HEIGHT/10 - 0.1)	 // visina za koju se ringispil podigne

// ugao za koji se rotira ringispil
extern float rotation_degree;
// ubrzanje
extern float speed_up;
// pomocni parametar za podizanje gornjeg dela ringispila
extern float lifting;

// Funkcija koja iscrtava ringispil.
void draw_swing_carousel();

// Funkcija koja iscrtava osnovu ringispila - deo koji se ne krece.
void draw_base();

// Funkcija koja iscrtava gornji deo ringispila.
void draw_top();

// Funkcija koja ukrug iscrtava lance i sedista koja na njima vise.
void draw_seats();

// Funkcija koja iscrtava cetiri lanca i jedno sediste koje visi na njima.
void draw_seat_in_center(int i);

// Funkcija koja postavlja koordinate i normale temena valjka u zavisnosti od parametara u i v.
void set_normal_and_vertex(float u, float v);

// Funkcija koja iscrtava valjak.
void draw_cylinder();

#endif
