#include <windows.h>
#include <iostream>
#include "C:/Users/Derley/source/repos/openGL/openGL/glut-3.7.6-bin/glut.h"
#include "cubo.h"

#pragma comment(lib, "C:/Users/Derley/source/repos/openGL/openGL/glut-3.7.6-bin/glut32.lib")

using namespace std;

void changeSize(int w, int h) {
	cout << "changeSize function was called" << endl;

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, ratio, 0.1f, 500.f);

	glMatrixMode(GL_MODELVIEW);
}

double angle = 45;

double d = 4;

float x_start_position = 100;
float y_start_position = 100;

float H = 1300;
float W = 1200;

POINT p;

#define N_CUBOS 40   // NÚMERO DE CUBOS

bool is_rotate;

Cubo cubos[N_CUBOS];

//Cubo cubo1(-0.2, 0.2, 0, 4);
//Cubo cubo2(-0.5, 0.7, 0.2, 4);

int contador;

#define PI 3.1415

HWND hWnd;

float center_screen_x = x_start_position + H / 2;
float center_screen_y = y_start_position + W / 2;

float grad_x = H / 180;
float grad_y = W / 180;

void renderScene(void) {
	if (GetKeyState('W') & 0x8000) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = translationpt(0, 0, 0.3) * cubos[i].points[j];
			}
		}
	}

	if (GetKeyState('S') & 0x8000) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = translationpt(0, 0, -0.3) * cubos[i].points[j];
			}
		}
	}

	if (GetKeyState('A') & 0x8000) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = translationpt(0.3, 0, 0) * cubos[i].points[j];
			}
		}
	}

	if (GetKeyState('D') & 0x8000) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = translationpt(-0.3, 0, 0) * cubos[i].points[j];
			}
		}
	}

	if (GetKeyState(VK_ESCAPE) & 0x8000) {
		exit(0);
	}

	GetCursorPos(&p);

	ScreenToClient(hWnd, &p);

	if (p.x != x_start_position + H / 2 || p.y != y_start_position + W / 2);
		SetCursorPos(x_start_position + H / 2, y_start_position + W / 2);

	// INICIO: MOVIMENTAR A CÂMERA ROTACIONALMENTE ///////////////////////////////////////////////////////////////////////////////

	// movo todos os objetos pra esquerda
	if (p.x > center_screen_x) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = rotationYpt(abs(p.x - center_screen_x) / (grad_x * 100)) * cubos[i].points[j];
			}
		}
	} else

	// movo todos os objetos pra direita
	if (p.x < center_screen_x) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = rotationYpt(-(abs(p.x - center_screen_x) / (grad_x * 100))) * cubos[i].points[j];
			}
		}
	}

	// movo todos os objetos pra baixo
	if (p.y > center_screen_y) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = rotationXpt((abs(p.y - center_screen_y) / (grad_y * 100))) * cubos[i].points[j];
			}
		}
	} else

	// movo todos os objetos pra cima
	if (p.y < center_screen_y) {
		for (int i = 0; i < N_CUBOS; i++) {
			for (int j = 0; j < 8; j++) {
				cubos[i].points[j] = rotationXpt(-(abs(p.y - center_screen_y) / (grad_y * 100))) * cubos[i].points[j];
			}
		}
	}
		
	// FIM: MOVER CAMERA ///////////////////////////////////////////////////////////////////////////////////////////

	// Limpar o buffer de cor e de profundidade
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < N_CUBOS; i++) {
		cubos[i].desenhar();
	}

	//angle += 0.1;

	glutSwapBuffers();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char** argv) {

;	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glClearColor(0, 0, 0, 0);
	glutInitWindowPosition(x_start_position, y_start_position);
	glutInitWindowSize(H, W);
	glutCreateWindow("CUBO");

	// register callbacks
	glutDisplayFunc(renderScene);
	// callback functions
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glEnable(GL_DEPTH_TEST);

	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

	srand(0);

	//for (int i = 0; i < 10; i++) {
	//	cout << rand() << endl;
	//}

	//exit(0);
		
	for (int i = 0; i < N_CUBOS; i++) {
		cubos[i] = Cubo((rand() % 70) / 1.f, (rand() % 70) / 1.f, -(rand() % 70) / 1.f, rand() % 10);
		for (int j = 0; j < 8; j++) {
			cubos[i].points[j] = translationpt(0, 0, -50) * cubos[i].points[j];
		}
	}

	ShowCursor(FALSE);

	hWnd = GetActiveWindow();

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}