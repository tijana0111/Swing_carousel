#include "./headers/keyboard_and_timer.h"


// parametar koji pokazuje da li je animacija u toku
int animation_ongoing;
// parametar koji pokazuje da li je u toku zaustavljanje animacije
int stop = 0;

// ugao za koji se rotira ringispil
float rotation_degree = 0;
// ubrzanje
float speed_up = 1;
// pomocni parametar za podizanje gornjeg dela ringispila
float lifting = 0;

// parametar za pokretanje dobacivanja loptom
int start_ball = 0;
// pomocni parametar za kretanje lopte
int ball_parameter = 0;
// parametar za zaustavljanje dobacivanja loptom
int stop_ball = 0;


void SpecialInput(int key, int x, int y){

  switch(key){

    case GLUT_KEY_UP:   // Kamera se pomera nagore za parametar delta.

      // Inkrementira se ugao up i ponovo iscrtava scena.
      up += delta;
      // Ugao se odrzava u intervalu [0°,36°].
      if (up > PI / 5) {
        up = PI / 5;
      }
      glutPostRedisplay();
      break;

    case GLUT_KEY_DOWN:   // Kamera se pomera nadole za parametar delta.

      // Dekrementira se ugao up i ponovo se iscrtava scena.
      up -= delta;
      // Ugao se odrzava u intervalu [0°,36°].
      if (up < 0) {
        up = 0;
      }
      glutPostRedisplay();
      break;

    case GLUT_KEY_LEFT:   // Kamera se pomera ulevo za parametar delta.

  		// Dekrementira se ugao right i ponovo se iscrtava scena.
  		right -= delta;
  		if (right > 2 * PI) {
  			right -= 2 * PI;
  		}
  		glutPostRedisplay();
  		break;

    case GLUT_KEY_RIGHT:    // Kamera se pomera udesno za parametar delta.

		// Inkrementira se ugao right i ponovo se iscrtava scena.
		right += delta;
		if (right > 2 * PI) {
			right -= 2 * PI;
		}
		glutPostRedisplay();
		break;
  }
}

void on_keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 27:
		// Zavrsava se program.
		exit(0);
		break;
	case 'g':
	case 'G':
		// Pokrece se animacija.
		if (!animation_ongoing) {
			if(!start_ball)
				glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
			animation_ongoing = 1;
		}
		else if(stop == 1) {
			stop = 0;
		}
		break;

	case 's':
	case 'S':
		// Zaustavlja se animacija polako.
		if (animation_ongoing) {
			stop = 1;
		}
		break;

	case 'R':
		// Uglovi za rotaciju kamere se vracaju na pocetne vrednosti.
		right = 0;
		up = PI/9;
		// Zaustavlja se animacija.
		animation_ongoing = 0;
		// Ugao za rotaciju ringispila se vraca na pocetnu vrednost.
		rotation_degree = 0;
		stop = 0;
		speed_up = 1;
		lifting = 0;

		start_ball = 0;
		ball_parameter = 0;

		glutPostRedisplay();
		break;

		case 'b':
			if (!start_ball) {

				if (!animation_ongoing){
					glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
				}

				start_ball = 1;
			}
		break;


		case 'B':
				if (start_ball)
					stop_ball = 1;
		break;

    }
}


void on_timer(int value){
	if(animation_ongoing){
	// Proverava se da li callback dolazi od odgovarajuceg tajmera.
	if (value != TIMER_ID)
		return;

	// U toku je zaustavljanje animacije.
	if (stop == 1){
		if(speed_up <= 1){		// Ako se ubrzanje smanjilo zaustavlja se animacija.
			animation_ongoing = 0;
			speed_up = 1;
			lifting = 0;
			stop = 0;
		}else
			speed_up -= 0.02;	// U suprotnom se smanjuje ubrzanje.

 		if(lifting > 0) 		// Spusta se gornji deo ringispila.
 			lifting -= 0.005;

	}
	// Ako nije u toku zaustavljanje povecava se ubrzanje.
	else if (speed_up < 5)
		speed_up += 0.02;
	// Ako nije u toku zaustavljanje i ubrzanje je dostiglo maksimum izdize se gornji deo.
 	else if((speed_up >= 5) & (lifting <1)){
 		lifting += 0.005;
 	}

	// Azurira se ugao rotacije ringispila.
	if (rotation_degree < 360)
		rotation_degree += 0.2*speed_up;
	else
		rotation_degree = 0;
	}

	if(stop_ball == 1)	// ako je u toku zaustavljanje dobacivanja
		if((ball_parameter%100) == 0){	 //ako je lopta uhvacena i sedista su okrenuta
			start_ball = 0;						// zaustavlja se dobacivanje
			stop_ball = 0;			// nije vise u toku zaustavljanje
		}
	// Ako je u toku dobacivanje loptom povecava se parametar za loptu.
	if(start_ball){
		if(ball_parameter < NUMBER_OF_SEATS*100)
			ball_parameter += 1;
		else
			ball_parameter = 0;
	}
	// Ponovo se iscrtava prozor i po potrebi se ponovo postavlja tajmer.
	glutPostRedisplay();
	if (animation_ongoing | start_ball) {
		glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
	}
}
