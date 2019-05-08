#include "./headers/child.h"

// Funkcija koja iscrtava dete.
void draw_child(int i){

	glPushMatrix();
		glShadeModel(GL_SMOOTH);
		glTranslatef(0, -HEIGHT/4, 0);
		glPushMatrix();
			// Bira se boja kose.
			if((i%10 == 2) | (i%10 == 6))
				red();
			else if((i%10 == 4) | (i%10 == 9))
				brunette();
			else if((i%10 == 0) | (i%10 == 5))
					blonde();
			else
				black();
			// Crta se kosa.
			glTranslatef(0, 2.2*SEAT_HALF, 0.2*SEAT_HALF);
			glutSolidSphere(0.6*SEAT_HALF, 10, 10);		// kraci deo kose
			glPushMatrix();
				glTranslatef(0, -0.67*SEAT_HALF, 0.35*SEAT_HALF);
				glScalef(3, 6, 1);
				glutSolidSphere(0.2*SEAT_HALF, 10, 10);	// duzi deo kose
			glPopMatrix();

			// glava
			tan_col();
			glTranslatef(0, -0.2*SEAT_HALF, -0.2*SEAT_HALF);
			glutSolidSphere(0.5*SEAT_HALF, 5*SEAT_HALF, 5*SEAT_HALF);

			// vrat
			tan_col();
			glTranslatef(0, -0.5*SEAT_HALF, 0);
			glScalef(1, 3, 1);
			glutSolidSphere(0.2*SEAT_HALF, 5, 5);
		glPopMatrix();

		// telo - gornji deo
		glPushMatrix();
			// Bira se boja majice.
			if(i%3==0)
				peach();
			else if(i%3==1)
				green();
			else
				cyan();
			glTranslatef(0, 0.7*SEAT_HALF, 0);
			glScalef(1.1, 1.5, 1.1);
			glutSolidSphere(0.5*SEAT_HALF, 10, 10);
		glPopMatrix();
		// telo - doji deo
		glPushMatrix();
			black();
			glTranslatef(0, -0.2*SEAT_HALF, -0.25*SEAT_HALF);
			glScalef(1.1, 1.3, 1.3);
			glutSolidSphere(0.6*SEAT_HALF, 5, 5);
		glPopMatrix();

		// noge
		// gornji deo desne noge
		glPushMatrix();
			tan_col();
			glTranslatef(0.3*SEAT_HALF, -0.2*SEAT_HALF, -1.25*SEAT_HALF);
			glScalef(0.3, 0.3, 1.6);
			glutSolidSphere(0.5*SEAT_HALF, 5, 5);
		glPopMatrix();

		// gornji deo leve noge
		glPushMatrix();
			tan_col();
			glTranslatef(-0.3*SEAT_HALF, -0.2*SEAT_HALF, -1.25*SEAT_HALF);
			glScalef(0.3, 0.3, 1.6);
			glutSolidSphere(0.5*SEAT_HALF, 5, 5);
		glPopMatrix();

		// donji deo desne noge
		glPushMatrix();
			tan_col();
			glTranslatef(0.3*SEAT_HALF, -0.8*SEAT_HALF, -1.9*SEAT_HALF);
			glScalef(0.3, 1.6, 0.3);
			glutSolidSphere(0.5*SEAT_HALF, 5, 5);
		glPopMatrix();
		// cipela desne noge
		glPushMatrix();
			black();
			glTranslatef(0.3*SEAT_HALF, -1.5*SEAT_HALF, -2.1*SEAT_HALF);
			glScalef(1, 1, 1.5);
			glutSolidSphere(0.3*SEAT_HALF, 5, 5);
		glPopMatrix();

		// donji deo leve noge
		glPushMatrix();
			tan_col();
			glTranslatef(-0.3, -0.8*SEAT_HALF, -1.9*SEAT_HALF);
			glScalef(0.3, 1.6, 0.3);
			glutSolidSphere(0.5*SEAT_HALF, 5, 5);
		glPopMatrix();

		// cipela leve noge
		glPushMatrix();
			black();
			glTranslatef(-0.3*SEAT_HALF, -1.5*SEAT_HALF, -2.1*SEAT_HALF);
			glScalef(1, 1, 1.5);
			glutSolidSphere(0.3*SEAT_HALF, 5, 5);
		glPopMatrix();

		// desna ruka
		glPushMatrix();
			tan_col();
			glTranslatef(0.4*SEAT_HALF, 1.1*SEAT_HALF, -SEAT_HALF);
			glScalef(0.3, 0.3, 2);
			glutSolidSphere(0.5*SEAT_HALF, 5, 5);

		glPopMatrix();

		// leva ruka
		glPushMatrix();
			tan_col();
			glTranslatef(-0.4*SEAT_HALF, 1.1*SEAT_HALF, -SEAT_HALF);
			glScalef(0.3, 0.3, 2);
			glutSolidSphere(0.5*SEAT_HALF, 5, 5);
		glPopMatrix();

		// Iscrtavanje lopte.
		if(i == ball_parameter/100){	// lopta je u rukama i-tog deteta
			glPushMatrix();
				blue();

				float x_pom = 0;
				float y_pom =  1.5*SEAT_HALF;
				float z_pom = -1.5*SEAT_HALF;

				// lopta je izmedju i-tog i narednog tj. (i+1)-og deteta
				if (((ball_parameter-i*100) > 30) & ((ball_parameter-i*100) < 70)){

					// Pomocni parametar koji ide od 0 do 1 u periodu u kom je lopta u vazduhu.
					float flying_ball_tmp = (float)(ball_parameter-i*100 -30)/39;

					// udaljenost izmedju dva sedista po z osi (preko sinusa ugla koji zaklapaju dva sedista)
					float dist_z = (WIDTH/2 -0.3 +(speed_up-1))*2*sin(PI/NUMBER_OF_SEATS)
													-3*SEAT_HALF; 	// 2*udaljenost od centra sedista do lopte u rukama

					// Vrednosti za koje se pomera lopta u odnosu na dete koje ju baca:
					x_pom += (float)(1.5 + (speed_up-1)/6)*flying_ball_tmp;	// u levo
					y_pom += sin(flying_ball_tmp*PI) + (speed_up-1)/5;		// u vis
					z_pom -= flying_ball_tmp*(dist_z);	// u dalj

					glTranslatef(x_pom, y_pom, z_pom);
				}

				// za ball_parameter < 30 lopa je u rukama i-tog deteta i ceka da se sediste okrene
				else
					glTranslatef(x_pom, y_pom, z_pom);

				// za parametar ball_parameter > 70 lopa nije u rukama i-tog deteta nego narednog
				if((ball_parameter-i*100) < 70)
					glutSolidSphere(0.5*SEAT_HALF, 15, 15);
			glPopMatrix();
		}

		if(i == (ball_parameter/100 + 1)){	// Lopta je u rukama narednog deteta.
			glPushMatrix();
				blue();
				glTranslatef(0, 1.5*SEAT_HALF, -1.5*SEAT_HALF);

				// Lopta se iscrtava samo za ball_parameter > 70.
				if((i*100-ball_parameter) <= 30)
					glutSolidSphere(0.5*SEAT_HALF, 15, 15);
			glPopMatrix();
		}

		// Lopta je u rukama narednog deteta (za i==NUMBER_OF_SEATS-1 naredno dete je i==0).
		if((ball_parameter/100==(NUMBER_OF_SEATS-1)) & (i==0)){
			glPushMatrix();
				blue();
				glTranslatef(0, 1.5*SEAT_HALF, -1.5*SEAT_HALF);

				if((ball_parameter - (NUMBER_OF_SEATS-1)*100) >= 70)
					glutSolidSphere(0.5*SEAT_HALF, 15, 15);
			glPopMatrix();
		}
	glPopMatrix();
}
