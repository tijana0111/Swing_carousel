#include "./headers/background.h"

GLuint texture_names[NUMBER_OF_TEXTURES];

// Funkcija koja iscrtava sferu u kojoj se sve nalazi i koja predstavlja nebo.
void draw_sky(){

  glPushMatrix();

    // Omogucava se osvetljavanje unutrasnjusti sfere u kojoj se sve nalazi.
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    // Isklucuje se staro osvetljenje i ukljucuje se posebno osvetljenje za nebo.
    glDisable(GL_LIGHT0);
    set_sky_lighting();

    // Iscrtava se nebo.
    glutSolidSphere(90, 30, 30);

    // Iskljucuje se osvetljenje za nebo i vraca se staro osvetljenje.
    glDisable(GL_LIGHT1);
    glEnable(GL_LIGHT0);

    // Vise nije potrebno osvetljavanje unutrasnjusti.
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  glPopMatrix();

}

void initialize_texture(void){
  // Objekat koji predstavlja teskturu ucitanu iz fajla.
  Image * image;

  // Ukljucuju se teksture.
  glEnable(GL_TEXTURE_2D);

  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

  // Inicijalizuje se objekat koji ce sadrzati teksture ucitane iz fajla.
  image = image_init(0, 0);

  // Kreira se prva (i jedina) tekstura.
  image_read(image, FILENAME0);

  // Generisu se identifikatori tekstura.
  glGenTextures(NUMBER_OF_TEXTURES, texture_names);

  glBindTexture(GL_TEXTURE_2D, texture_names[0]);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
               image->width, image->height, 0,
               GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, 0);

  // Unistava se objekat koji sadrzi teksture ucitane iz fajla.
  image_done(image);
}

// Funkcija koja crta travu.
void draw_grass(){
	glPushMatrix();
	  glTranslatef(0, -HEIGHT/2-2, 0);

		glBindTexture(GL_TEXTURE_2D, texture_names[0]);

	  glBegin(GL_QUADS);
		  glNormal3f(0, 1, 0);
		  glTexCoord2f(0, 0);
		  glVertex3f(100, 0, 100);
		  glTexCoord2f(15, 0);
		  glVertex3f(-100, 0, 100);
		  glTexCoord2f(15, 15);
		  glVertex3f(-100, 0, -100);
		  glTexCoord2f(0, 15);
		  glVertex3f(100, 0, -100);
	  glEnd ();

    glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}
