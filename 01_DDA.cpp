#include <cmath>
#include <stdio.h>
#include <GL/glut.h>
//int x1, x2, y1, y2;
void setpixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void lineDDA(int x1, int x2, int y1, int y2) {
	int dx = x2 - x1, dy = y2 - y1, steps, k;
	float xinc, yinc, x = x1, y = y1;

	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else steps = fabs(dy);

	xinc = float(dx) / float(steps);
	yinc = float(dy) / float(steps);
	setpixel(round(x), round(y));
	for (k = 0; k < steps; k++) {
		x += xinc;
		y += yinc;
		setpixel(round(x), round(y));
	}
}


void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

void disp1() {
//	x1 = 50; x2 = 200; y1 = 100; y2 = 400;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(5);
	lineDDA(10,410,10,400);
}


int main() {
	//	printf("Enter the input :");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("PDA");
	myinit();
	glutDisplayFunc(disp1);
	glutMainLoop();
	return 0;
}
