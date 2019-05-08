#ifndef KEYBOARD_AND_TIMER_H
#define KEYBOARD_AND_TIMER_H

#define TIMER_ID 0
#define TIMER_INTERVAL 20

#include "swing_carousel.h"

// Deklaracije callback funkcija.
void on_timer(int value);
void on_keyboard(unsigned char key, int x, int y);
void SpecialInput(int key, int x, int y);

// ugao za koje se kamera pomera nagore
extern float up;
// ugao za koje se kamera pomera ulevo
extern float right;
// inkrement uglova za rotaciju kamere
extern float delta;

#endif
