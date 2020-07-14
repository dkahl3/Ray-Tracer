#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <vector>
#include "Geometry.h"
#include "Vector3n.h"
#include "Scene.h"

// Window width/height
extern GLint width = 600;
extern GLint height = 400;

// Define virtual space coordinate system
float xMin = -10.0;
float xMax = 10.0;
float yMin = -10.0 * height / width;
float yMax = 10.0 * height / width;
float xRange = xMax - xMin;
float yRange = yMax - yMin;
float deltaX = xRange / width;
float deltaY = yRange / height;

// Scene Object
Scene* s;

// Function declarations
void display();
void reshape(GLint, GLint);

int main(int argc, char* argv[]) {
	// Initialize Scene
	std::vector <Object*> objects;
	
	Sphere* s0 = new Sphere(MathEng::Vector3n(0, 0, 10), MathEng::Vector3n(0.0, 0.0, 0.5), 2);
	Sphere* s1 = new Sphere(MathEng::Vector3n(2, -2, 12), MathEng::Vector3n(0.5, 0.0, 0.0), 2);
	Sphere* s2 = new Sphere(MathEng::Vector3n(-2, 2, 9), MathEng::Vector3n(0.0, 0.5, 0.0), 2);
	objects.push_back(s0);
	objects.push_back(s1);
	objects.push_back(s2);
	
	s = new Scene(objects);

	// Initialize Window 
	glutInit(&argc, argv);
 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(0, 0);

	glutInitWindowSize(width, height);

	glutCreateWindow("Ray Tracer");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	
	// Loop through display function
	glutMainLoop();

	return 0;
}

void display() {
	// Variables for background and object colors
	GLfloat background[] = { 0.5f, 0.5f, 0.5f };
	GLfloat color[] = { 0.6f, 0.6f, 0.6f };

	// Clear the screen to the clear colour. No depth buffer in this example.
	glClearColor(0.8, 0.8, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	float x, y;

	for (int row = 0; row < height; row++) {
		y = yMin + row * deltaY;
		for (int col = 0; col < width; col++) {	
			x = xMin + col * deltaX;

			// Create ray using camera position and pixel (x,y)
			MathEng::Vector3n rayEnd(x, y, 10);
			rayEnd.normalize();
			Ray out(MathEng::Vector3n(0.0, 0.0, 0.0), rayEnd);

			// Cast ray
			Color c = s->getIntersection(out);

			// Draw pixel color
			color[0] = c.R;
			color[1] = c.G;
			color[2] = c.B;
			glRasterPos2i(col, row);
			glDrawPixels(1, 1, GL_RGB, GL_FLOAT, color);

		}
	}

	glutSwapBuffers();
}

void reshape(GLint w, GLint h) {
	width = w;
	height = h;

	glutPostRedisplay();
}