#include "./headers/colors.h"

// Parametri za crnu boju
GLfloat ambient_coeffs_black[]  = { 0.05, 0.05, 0.05, 1 };    // ambijentalna
GLfloat diffuse_coeffs_black[]  = { 0.00, 0.00, 0.00, 1 };    // difuzna
GLfloat specular_coeffs_black[] = { 0.20, 0.20, 0.20, 1 };    // spekularna

// Parametri za plavu boju kose
GLfloat ambient_coeffs_blonde[]  = { 0.10, 0.10, 0.00, 1 };    // ambijentalna
GLfloat diffuse_coeffs_blonde[]  = { 0.30, 0.20, 0.10, 1 };    // difuzna
GLfloat specular_coeffs_blonde[] = { 0.40, 0.40, 0.10, 1 };    // spekularna

// Parametri za smedju boju kose
GLfloat ambient_coeffs_brunette[]  = { 0.00, 0.00, 0.00, 1 };    // ambijentalna
GLfloat diffuse_coeffs_brunette[]  = { 0.20, 0.05, 0.00, 1 };    // difuzna
GLfloat specular_coeffs_brunette[] = { 0.40, 0.37, 0.17, 1 };    // spekularna

// Parametri za crvenu boju kose
GLfloat ambient_coeffs_red[]  = { 0.0, 0.0, 0.0, 1 };        // ambijentalna
GLfloat diffuse_coeffs_red[]  = { 0.2, 0.0, 0.0, 1 };        // difuzna
GLfloat specular_coeffs_red[] = { 0.4, 0.1, 0.1, 1 };        // spekularna

// Parametri za boju koze
GLfloat ambient_coeffs_tan[]  = { 0.30, 0.20, 0.10, 1 };     // ambijentalna
GLfloat diffuse_coeffs_tan[]  = { 0.82, 0.71, 0.55, 1 };     // difuzna
GLfloat specular_coeffs_tan[] = { 0.90, 0.80, 0.60, 1 };     // spekularna

// Parametri za zelenu boju
GLfloat ambient_coeffs_green[]  = { 0.3, 0.5, 0.3, 1 };         // ambijentalna
GLfloat diffuse_coeffs_green[]  = { 0.5, 1.0, 0.5, 1 };         // difuzna
GLfloat specular_coeffs_green[] = { 0.7, 1.0, 0.7, 1 };         // spekularna

// Parametri za plavo-zelenu boju
GLfloat ambient_coeffs_cyan[]  = { 0.2, 0.7, 0.7, 1 };          // ambijentalna
GLfloat diffuse_coeffs_cyan[]  = { 0.4, 1.0, 1.0, 1 };          // difuzna
GLfloat specular_coeffs_cyan[] = { 0.5, 1.0, 1.0, 1 };          // spekularna

// Parametri za boju kajsije
GLfloat ambient_coeffs_peach[]  = { 0.7, 0.7, 0.5, 1 };         // ambijentalna
GLfloat diffuse_coeffs_peach[]  = { 0.9, 0.8, 0.6, 1 };         // difuzna
GLfloat specular_coeffs_peach[] = { 1.0, 0.9, 0.7, 1 };         // spekularna

// Parametri za tamno plavu boju
GLfloat ambient_coeffs_blue[]  = { 0.0, 0.0, 0.2, 1 };         // ambijentalna
GLfloat diffuse_coeffs_blue[]  = { 0.2, 0.0, 0.4, 1 };         // difuzna
GLfloat specular_coeffs_blue[] = { 0.3, 0.5, 0.7, 1 };         // spekularna

// Parametri za sivu boju
GLfloat ambient_coeffs_gray[]  = { 0.4, 0.4, 0.4, 1 };       // ambijentalna
GLfloat diffuse_coeffs_gray[]  = { 0.6, 0.6, 0.6, 1 };       // difuzna
GLfloat specular_coeffs_gray[] = { 0.8, 0.8, 0.8, 1 };       // spekularna

// Parametri za sivu boju stuba
GLfloat ambient_coeffs_gray_c[]  = { 0.2, 0.2, 0.2, 1 };       // ambijentalna
GLfloat diffuse_coeffs_gray_c[]  = { 0.4, 0.4, 0.4, 1 };       // difuzna
GLfloat specular_coeffs_gray_c[] = { 0.4, 0.4, 0.4, 1 };       // spekularna

// Parametri za ljubicastu boju
GLfloat ambient_coeffs_purple[]  = { 0.4, 0.0, 0.4, 1 };        // ambijentalna
GLfloat diffuse_coeffs_purple[]  = { 0.5, 0.0, 0.5, 1 };        // difuzna
GLfloat specular_coeffs_purple[] = { 0.6, 0.0, 0.6, 1 };        // spekularna

// Parametri za boju neba
GLfloat ambient_coeffs_sky[]  = { 0.8, 0.9, 0.9, 1 };        // ambijentalna
GLfloat diffuse_coeffs_sky[]  = { 0.8, 0.3, 0.8, 1};        // difuzna
GLfloat specular_coeffs_sky[] = { 0.8, 0.1, 0.7, 1};        // spekularna

// Funkcija koja podesava koeficijente refleksije crnog materijala.
void black(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_black);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_black);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_black);

}

// Funkcija koja podesava koeficijente refleksije plave kose.
void blonde(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_blonde);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_blonde);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_blonde);

}

// Funkcija koja podesava koeficijente refleksije smedje kose.
void brunette(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_brunette);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_brunette);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_brunette);

}

// Funkcija koja podesava koeficijente refleksije tamno crvene kose.
void red(){
	glPushMatrix();
  	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_red);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_red);
  	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_red);
	glPopMatrix();
}

// Funkcija koja podesava koeficijente refleksije materijala boje koze.
void tan_col(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_tan);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_tan);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_tan);

}

// Funkcija koja podesava koeficijente refleksije zelenog materijala.
void green(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_green);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_green);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_green);

}

// Funkcija koja podesava koeficijente refleksije plavo zelenog materijala.
void cyan(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_cyan);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_cyan);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_cyan);

}

// Funkcija koja podesava koeficijente refleksije materijala boje kajsije.
void peach(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_peach);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_peach);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_peach);

}

// Funkcija koja podesava koeficijente refleksije tamno plavog materijala.
void blue(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_blue);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_blue);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_blue);

}

// Funkcija koja podesava koeficijente refleksije sivog materijala.
void gray(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_gray);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_gray);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_gray);

}

// Funkcija koja podesava koeficijente refleksije tamno sivog materijala.
void gray_c(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_gray_c);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_gray_c);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_gray_c);

}

// Funkcija koja podesava koeficijente refleksije ljubicastog materijala.
void purple(){
  glPushMatrix();
  	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_purple);
  	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_purple);
  	glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_purple);
	glPopMatrix();
}

// Funkcija koja podesava koeficijente refleksije materijala koji predstavlja nebo.
void sky(){
  glPushMatrix();
		glMaterialfv(GL_BACK, GL_AMBIENT, ambient_coeffs_sky);
		glMaterialfv(GL_BACK, GL_DIFFUSE, diffuse_coeffs_sky);
		glMaterialfv(GL_BACK, GL_SPECULAR, specular_coeffs_sky);
	glPopMatrix();
}

// Funkcija koja podesava osvetljenje.
void set_lighting(){

  glPushMatrix();
	  glLoadIdentity();

  	GLfloat light_position[] = { 0, 30, 50, 1 };			// pozicija svetla

  	GLfloat light_ambient[] = { 0.4, 0.4, 0.4, 1 };		// ambijentalna boja svetla
  	GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };		// difuzna boja svetla
  	GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };	// spekularna boja svetla
  	GLfloat shininess = 50;		// koeficijent glatkosti materijala

		//	Ukljucuje se osvjetljenje.
  	glEnable(GL_LIGHTING);
  	glEnable(GL_LIGHT0);

    glShadeModel(GL_SMOOTH);

    //	Podesava se pozicija svetla.
  	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		//	Podesavaju se boje svetla.
  	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

		// Podesava se koeficijent glatkosti materijala.
  	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

	glPopMatrix();
}

// Funkcija koja podesava osvetljenje za nebo.
void set_sky_lighting(){
	glPushMatrix();
		GLfloat light_position_sky[] = { 0, 0, 90, 0 };		// pozicija svetla

		GLfloat light_ambient_sky[] = { 0.5, 0.5, 0.9, 1 };		// ambijentalna boja svetla
		GLfloat light_diffuse_sky[] = { 0.5, 0.5, 0.9, 1};		// difuzna boja svetla
		GLfloat light_specular_sky[] = { 0.6, 0.2, 0.6, 1 };	// spekularna boja svetla

		GLfloat shininess_sky = 50; 	// koeficijent glatkosti materijala

		glEnable(GL_LIGHT1);
		glShadeModel(GL_SMOOTH);

		// Podesava se pozicija svetla.
		glLightfv(GL_LIGHT1, GL_POSITION, light_position_sky);
		//	Podesavaju se boje svetla.
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_sky);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse_sky);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular_sky);

		// Podesava se koeficijent glatkosti materijala
		glMaterialf(GL_BACK, GL_SHININESS, shininess_sky);
		sky();

	glPopMatrix();

}
