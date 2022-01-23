#pragma once

#include <iostream>
#include <vector>
#include "C:/Users/Derley/source/repos/openGL/openGL/glut-3.7.6-bin/glut.h"
#include "C:/Users/Derley/Downloads/eigen-3.4.0/eigen-3.4.0/Eigen/Dense"

using namespace std;
using namespace Eigen;

class Cubo {
public:
	Cubo() {

	}

	Cubo(double x, double y, double z, int d) : len(d), x(x), y(y), z(z) {
		len = d;
		points[0] = Vector4f(x,     y, z, 1);
		points[1] = Vector4f(x,     y - d, z, 1);
		points[2] = Vector4f(x + d, y - d, z, 1);
		points[3] = Vector4f(x + d, y, z, 1);

		points[4] = Vector4f(x,     y, z - d, 1);
		points[5] = Vector4f(x,     y - d, z - d, 1);
		points[6] = Vector4f(x + d, y - d, z - d, 1);
		points[7] = Vector4f(x + d, y, z - d, 1);
	}

	void desenhar() {
		desenhar_face(points[0], points[1], points[2], points[3], Vector3f(1, 0, 0));
		desenhar_face(points[4], points[5], points[6], points[7], Vector3f(0, 1, 0));
		desenhar_face(points[4], points[5], points[1], points[0], Vector3f(0, 0, 1));

		desenhar_face(points[4], points[0], points[3], points[7], Vector3f(1, 1, 0));
		desenhar_face(points[7], points[6], points[2], points[3], Vector3f(0, 1, 1));
		desenhar_face(points[5], points[1], points[2], points[6], Vector3f(1, 0, 1));
	}

	Vector4f points[8];
private:
	int len;
	float x, y, z;

	void desenhar_face(Vector4f p1, Vector4f p2, Vector4f p3, Vector4f p4, Vector3f color) {
		glBegin(GL_QUADS);
			glColor3f(color[0], color[1], color[2]);
			glVertex3f(p1[0], p1[1], p1[2]);
			glVertex3f(p2[0], p2[1], p2[2]);
			glVertex3f(p3[0], p3[1], p3[2]);
			glVertex3f(p4[0], p4[1], p4[2]);
		glEnd();
	}
};
