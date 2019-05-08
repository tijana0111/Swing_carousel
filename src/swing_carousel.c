#include "./headers/swing_carousel.h"

void draw_swing_carousel(){
	draw_base();
	draw_top();
	draw_seats();
}

// Funkcija koja iscrtava osnovu ringispila - deo koji se ne krece.
void draw_base()
{
	// glavni stub
	glPushMatrix();
		glLineWidth(2);

		// stub
		glPushMatrix();
			gray_c();
			GLfloat shininess = 10;
			glMaterialf(GL_FRONT, GL_SHININESS, shininess);
			glTranslatef(0, -HEIGHT/2, 0);
			draw_cylinder();
			shininess = 60;
			glMaterialf(GL_FRONT, GL_SHININESS, shininess);
		glPopMatrix();

		// okrugli vrh stuba
		glPushMatrix();
			glTranslatef(0, HEIGHT/4 + lifting*HEIGHT_EXPANSION+0.8, 0);
			glRotatef(90, 1, 0, 0);
			glShadeModel(GL_FLAT);
			black();
			glutSolidTorus(1, 1.5, 4, NUMBER_OF_SEATS-1);
			purple();
			glutWireTorus(1, 1.5, 4, NUMBER_OF_SEATS-1);
		glPopMatrix();
	glPopMatrix();

	// postolje
	glPushMatrix();
		glTranslatef(0, -HEIGHT/2, 0);
		glRotatef(90, -1, 0, 0);

		// postolje - sredina
		glPushMatrix();
			gray();
			glutSolidCone(WIDTH/2+ EXPANSION_BY_STEP, HEIGHT/10, NUMBER_OF_SEATS, 1);
			black();
			glutWireCone(WIDTH/2+ EXPANSION_BY_STEP, HEIGHT/10, NUMBER_OF_SEATS, 1);
		glPopMatrix();

		// postolje - prvi stepenik
		glPushMatrix();
			glTranslatef(0, 0, -1);
			glShadeModel(GL_FLAT);
			gray();
			glutSolidTorus(0.5, WIDTH/2 + 0.5 + EXPANSION_BY_STEP, 4, NUMBER_OF_SEATS);
			purple();
			glutWireTorus(0.5, WIDTH/2 + 0.5 + EXPANSION_BY_STEP, 4, NUMBER_OF_SEATS);
		glPopMatrix();

		// postolje - drugi stepenik
		glPushMatrix();
			glTranslatef(0, 0, -0.5);
			glShadeModel(GL_FLAT);
			gray();
			glutSolidTorus(0.5, WIDTH/2 + EXPANSION_BY_STEP, 4, NUMBER_OF_SEATS);
			purple();
			glutWireTorus(0.5, WIDTH/2 + EXPANSION_BY_STEP, 4, NUMBER_OF_SEATS);
		glPopMatrix();

	glPopMatrix();

}

// Funkcija koja iscrtava gornji deo ringispila.
void draw_top()
{
	glPushMatrix();
		glTranslatef(0, lifting*HEIGHT_EXPANSION, 0);
		glRotatef(rotation_degree, 0, 1 ,0);
		glLineWidth(2);

		// gornji deo krova
		glPushMatrix();
			glTranslatef(0, HEIGHT/2, 0);
			glRotatef(-90, 1, 0, 0);

			glPushMatrix();
				glShadeModel(GL_FLAT);
				gray();
				glutSolidCone(WIDTH/2, HEIGHT/8, NUMBER_OF_SEATS, 1);
				black();
				glutWireCone(WIDTH/2, HEIGHT/8, NUMBER_OF_SEATS, 1);
			glPopMatrix();

			// ivica krova
			glPushMatrix();
				glShadeModel(GL_FLAT);
				black();
				glutSolidTorus(0.5, WIDTH/2, 4, NUMBER_OF_SEATS);
				purple();
				glutWireTorus(0.5, WIDTH/2, 4, NUMBER_OF_SEATS);
			glPopMatrix();

			// vrh - lopta
			glPushMatrix();
				//set_lighting();
				purple();
				glTranslatef(0, 0, HEIGHT/8);
				glutSolidSphere(0.5, 20, 20);
			glPopMatrix();
		glPopMatrix();

		// donji deo krova
		glPushMatrix();
			glTranslatef(0, HEIGHT/2, 0);
			glRotatef(90, 1, 0, 0);

			glPushMatrix();
				glShadeModel(GL_FLAT);
				gray();
				glutSolidCone(WIDTH/2, HEIGHT/4, NUMBER_OF_SEATS, 1);
				black();
				glutWireCone(WIDTH/2, HEIGHT/4, NUMBER_OF_SEATS, 1);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
}

// Funkcija koja ukrug iscrtava lance i sedista koja na njima vise.
void draw_seats(){
	glPushMatrix();
	glLineWidth(2);
	int i;
	for (i = 0; i < NUMBER_OF_SEATS; i++) {
		glPushMatrix();
			glRotatef(rotation_degree, 0, 1 ,0);
			// Sedista se redjaju u krug.
			glTranslatef(
				cos(2* i * PI / NUMBER_OF_SEATS) * (WIDTH/2 -0.3),
				0 + lifting*HEIGHT_EXPANSION,
				sin(2* i * PI / NUMBER_OF_SEATS) * (WIDTH/2 -0.3));

			// Rotacija koja omogucava da sedista budu okrenuta ka sedistu isped sebe.
			glRotatef(360* i / NUMBER_OF_SEATS, 0, -1 ,0);

			// Rotacija koja omogucava da se sedista postepeno nakrive i uzdignu pri ubrzanju.
			glTranslatef(0, +HEIGHT/2, 0);	// Sedista se pomeraju tako da im kraj bude u centru.
			glRotatef(5*(speed_up - 1), 0, 0, 1);	// Rotiraju se oko z ose samo ako se speed_up uvecao.
			glTranslatef(0, -HEIGHT/2, 0);	// Sedista se vracaju na svoje mesto.

			glPushMatrix();

				if ((i) == (ball_parameter/100)){		//	Ako je lopta kod sedista:
					if((ball_parameter - i*100) <30)	// Sediste se okrece ka sedistu iza sebe.
						glRotatef(180*((float)(ball_parameter-i*100)/30) , 0, -1 ,0);
					else if ((ball_parameter - i*100) <70)		//	Sediste se ne rotira dodatno.
						glRotatef(180, 0, -1 ,0);
					else	// Sediste se vraca da bude okrenuto ka sedistu isped sebe.
						glRotatef(180 + 180*((float)(ball_parameter-i*100 - 70)/30) , 0, 1 ,0);
				}
				// Iscratava se sediste sa lancima.
				draw_seat_in_center(i);
			glPopMatrix();
		glPopMatrix();
	}
	glPopMatrix();
}

// Funkcija koja iscrtava cetiri lanca i jedno sediste koje visi na njima.
void draw_seat_in_center(int i){
	// dete
	draw_child(i);

	// lanci na kojima vise sedista
	glPushMatrix();
		black();
		glBegin(GL_LINES);
			// lanac do levog zadnjeg ugla sedista
			glVertex3f(0, HEIGHT/2, 0);
			glVertex3f( -SEAT_HALF, -HEIGHT/4,  SEAT_HALF);
			// lanac do desnog zadnjeg ugla sedista
			glVertex3f(0, HEIGHT/2, 0);
			glVertex3f(  SEAT_HALF, -HEIGHT/4,  SEAT_HALF);
			// lanac do levog prednjeg ugla sedista
			glVertex3f(0, HEIGHT/2, 0);
			glVertex3f( -SEAT_HALF, -HEIGHT/4, -SEAT_HALF);
			// lanac do desnog prednjeg ugla sedista
			glVertex3f(0, HEIGHT/2, 0);
			glVertex3f( +SEAT_HALF, -HEIGHT/4, -SEAT_HALF);
		glEnd();
	glPopMatrix();

	// sediste - donji deo
	glPushMatrix();
		purple();
		glTranslatef(0, -SEAT_HALF-HEIGHT/4, 0);
		glScalef(1, 0.05, 1);
		glutSolidCube(SEAT_HALF*2-0.2);
	glPopMatrix();

	// sediste - naslon
	glPushMatrix();
		purple();
		glTranslatef(0, -HEIGHT/4,  SEAT_HALF);
		glScalef(1, 1, 0.1);
		glutSolidCube(SEAT_HALF*2-0.2);
	glPopMatrix();

	// sediste - sipke
	glPushMatrix();
		black();
		glTranslatef(0, -HEIGHT/4, 0);
		glutWireCube(SEAT_HALF*2+0.01);
		glutWireCube(SEAT_HALF*2-0.05);
	glPopMatrix();

}

// Funkcija koja postavlja koordinate i normale temena valjka u zavisnosti od parametara u i v.
void set_normal_and_vertex(float u, float v)
{
	glNormal3f(sin(v), 0, cos(v));
	glVertex3f(sin(v), u, cos(v));
}

// Funkcija koja iscrtava valjak cija visina zavisi od HEIGHT i HEIGHT_EXPANSION.
void draw_cylinder()
{
	float u, v;

	glPushMatrix();
		for (u = 0; u < PI * (HEIGHT/4 + HEIGHT_EXPANSION); u += PI / 20) {
			glBegin(GL_TRIANGLE_STRIP);
			for (v = 0; v <= PI*2 + EPSILON; v += PI / 20) {
				set_normal_and_vertex(u, v);
				set_normal_and_vertex(u + PI / 20, v);
			}
			glEnd();
		}
	glPopMatrix();
}
