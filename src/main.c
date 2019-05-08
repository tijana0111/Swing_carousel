#include "./headers/keyboard_and_timer.h"
#include "./headers/swing_carousel.h"


// Deklaracije callback funkcija.
static void on_display(void);
static void on_reshape(int window_width, int window_height);
//funkcije on_timer, on_keyboard i SpecialInput su izdvojene u zasebni fajl

// ugao za koje se kamera pomera nagore
float up = PI/9;
// ugao za koje se kamera pomera ulevo
float right = 0;
// inkrement uglova za rotaciju kamere
float delta = PI/90;

int main(int argc, char **argv){

	// Inicijalizuje se GLUT.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	// Kreira se prozor.
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Ringispil");

	// Registruju se callback funkcije.
	glutDisplayFunc(on_display);
	glutKeyboardFunc(on_keyboard);
	glutSpecialFunc(SpecialInput);
	glutReshapeFunc(on_reshape);
	glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);

	// Obavlja se OpenGL inicijalizacija.
	glClearColor(0.6, 0.7, 0.8, 0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	// Omogucava se koriscenje teksture.
	initialize_texture();

	// Ulazi se u glavnu petlju.
	glutMainLoop();

	return 0;
}

static void on_reshape(int window_width, int window_height){

	// Podesava se viewport.
	glViewport(0, 0, window_width, window_height);

	// Podesava se projekcija.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float) window_width / window_height, 1, 150);
}

static void on_display(void){

  // Brise se prethodni sadrzaj prozora.
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Podesava se vidna tacka.
  glMatrixMode(GL_MODELVIEW);

	// Podesava se osvetljenje.
	set_lighting();

	// Postavlja se vidna tacka.
	glLoadIdentity();
  gluLookAt(
		50 * cos(up) * sin(right),
		50 * sin(up),
		50 * cos(up) * cos(right),
		0, 0, 0,
		0, 1, 0
	);

	// Iscrtava se nebo.
	draw_sky();

	// Iscrtava se trava.
	draw_grass();

  // Iscrtava se ringispil.
  draw_swing_carousel();

  // Nova slika se postavlja na ekran.
  glutSwapBuffers();
}
