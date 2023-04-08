#include <gl/glew.h> // A cross-platform open-source C/C++ extension loading library
#include <stdlib.h>
#include <gl/freeglut.h> // Handle the window-managing operations
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int windowWidth = 1000;
int windowHeight = 800;
float angle = 30.0;
float Y = 0;
float transValue;
int type = 0;

GLuint myTexture1;
GLuint myTexture2;
GLuint myTexture3;


char image1Path[] = "C:/Users/USER/OneDrive/”ÿÕ «·„ﬂ »/earth1.bmp";
char image2Path[] = "C:/Users/USER/OneDrive/”ÿÕ «·„ﬂ »/sun.bmp"; //Change path with your path
char image3Path[] = "C:/Users/USER/OneDrive/”ÿÕ «·„ﬂ »/Stars.bmp";


GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };


GLfloat lightX = -2, lightY = 1.5, lightZ = -2;
GLfloat light_position[] = { lightX,lightY, lightZ, 0.0 };

GLfloat shininess[] = { 24 };

//http://stackoverflow.com/questions/12518111/how-to-load-a-bmp-on-glut-to-use-it-as-a-texture

GLuint LoadTexture(const char* filename, int width, int height)
{
	GLuint texture;
	unsigned char* data;
	FILE* file;

	//The following code will read in our RAW file
	file = fopen(filename, "rb");

	if (file == NULL)
	{
		cout << "Unable to open the image file" << endl << "Program will exit :(" << endl;
		exit(0);
		return 0;
	}

	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);

	fclose(file);


	// reorder the image colors to RGB not BGR
	for (int i = 0; i < width * height; ++i)
	{
		int index = i * 3;
		unsigned char B, R;
		B = data[index];
		R = data[index + 2];

		data[index] = R;
		data[index + 2] = B;

	}
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	free(data);
	if (glGetError() != GL_NO_ERROR)
		printf("GLError in genTexture()\n");
	return texture;
}

//This code is taken from google
void circle(float x, float y, float n1, float n2) {
	glBegin(GL_POLYGON);
	GLfloat angle;
	for (int i = 0; i <= 360; i++) {
		angle = i * 3.14 * 2 / 180;
		glVertex2f(x + cos(angle) * n1, y + sin(angle) * n2);
	}
	glEnd();
}

void Rocket() {
	glBegin(GL_TRIANGLES);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(0.3, 1.0);
	glVertex2f(-0.3, 1.0);
	glVertex2f(0, 2.3);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-0.3f, 1.0f);
	glVertex2f(0.3f, 1.0f);
	glVertex2f(0.3f, -1.5f);
	glVertex2f(-0.3f, -1.5f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.5f, -2.0f);
	glVertex2f(-1.0f, -2.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.5f, -0.9f);
	glVertex2f(0.5f, -0.4f);
	glVertex2f(0.3f, -0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.1f);
	glVertex2f(-0.5f, -2.4f);
	glVertex2f(-1.0f, -2.4f);
	glVertex2f(-0.75, -3.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.8f, 0.4f);
	glVertex2f(-0.6f, -2.4f);
	glVertex2f(-0.9f, -2.4f);
	glVertex2f(-0.75, -3.0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.1f);
	glVertex2f(0.5f, -2.4f);
	glVertex2f(1.0f, -2.4f);
	glVertex2f(0.75, -3.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.8f, 0.4f);
	glVertex2f(0.6f, -2.4f);
	glVertex2f(0.9f, -2.4f);
	glVertex2f(0.75, -3.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.5f, -0.9f);
	glVertex2f(-0.5f, -0.4f);
	glVertex2f(-0.3f, -0.4);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(-1.0f, -2.4f);
	glVertex2f(-0.5f, -2.4f);
	glVertex2f(-0.6f, -2.0f);
	glVertex2f(-0.9f, -2.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(-0.75, 1.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.5f, -2.0f);
	glVertex2f(1.0f, -2.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(1.0f, -2.4f);
	glVertex2f(0.5f, -2.4f);
	glVertex2f(0.6f, -2.0f);
	glVertex2f(0.9f, -2.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.75, 1.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(-0.2f, -1.5f);
	glVertex2f(0.2f, -1.5f);
	glVertex2f(0.4f, -2.0f);
	glVertex2f(-0.4f, -2.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.1f);
	glVertex2f(0.3f, -2.0f);
	glVertex2f(-0.3f, -2.0f);
	glVertex2f(0, -4.0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.8f, 0.4f);
	glVertex2f(0.2f, -2.0f);
	glVertex2f(-0.2f, -2.0f);
	glVertex2f(0, -3);
	glEnd();
	glColor3f(1.0f, 1.0f, 0.9f);
	circle(0.0f, 0.0f, 0.20f, 0.15f);
	circle(0.0f, 0.5f, 0.20f, 0.15f);
	circle(0.0f, -0.5f, 0.20f, 0.15f);
	circle(-0.75f, -1.0f, 0.15f, 0.40f);
	circle(0.75f, -1.0f, 0.15f, 0.40f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);// «·‘›«›ÌÂ „À·À
	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 0.0, 0.1);
	glVertex2f(-0.3f, -1.4f);
	glColor4f(0.0, 1.0, 0.0, 0.5);
	glVertex2f(-0.3f, -0.5f);
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glVertex2f(-0.7, -1.7);
	glEnd();
	glDisable(GL_BLEND);
	glFlush();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);// «·‘›«›ÌÂ „À·À
	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 0.0, 0.1);
	glVertex2f(0.3f, -1.4f);
	glColor4f(0.0, 1.0, 0.0, 0.5);
	glVertex2f(0.3f, -0.5f);
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glVertex2f(0.7, -1.7);
	glEnd();
	glDisable(GL_BLEND);
	glFlush();
}

void satellite1() {
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.5f, -2.0f);
	glVertex2f(-1.0f, -2.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.5f, -0.9f);
	glVertex2f(0.5f, -0.4f);
	glVertex2f(0.3f, -0.4);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.1f);
	glVertex2f(-0.5f, -2.4f);
	glVertex2f(-1.0f, -2.4f);
	glVertex2f(-0.75, -3.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.8f, 0.4f);
	glVertex2f(-0.6f, -2.4f);
	glVertex2f(-0.9f, -2.4f);
	glVertex2f(-0.75, -3.0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.1f);
	glVertex2f(0.5f, -2.4f);
	glVertex2f(1.0f, -2.4f);
	glVertex2f(0.75, -3.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.8f, 0.4f);
	glVertex2f(0.6f, -2.4f);
	glVertex2f(0.9f, -2.4f);
	glVertex2f(0.75, -3.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.5f, -0.9f);
	glVertex2f(-0.5f, -0.4f);
	glVertex2f(-0.3f, -0.4);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(-1.0f, -2.4f);
	glVertex2f(-0.5f, -2.4f);
	glVertex2f(-0.6f, -2.0f);
	glVertex2f(-0.9f, -2.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(-0.75, 1.0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.5f, -2.0f);
	glVertex2f(1.0f, -2.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(1.0f, -2.4f);
	glVertex2f(0.5f, -2.4f);
	glVertex2f(0.6f, -2.0f);
	glVertex2f(0.9f, -2.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.75, 1.0);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.9f);
	circle(-0.75f, -1.0f, 0.15f, 0.40f);
	circle(0.75f, -1.0f, 0.15f, 0.40f);

	glFlush();
}

void satellite2() {
	glBegin(GL_QUADS);//«·Œÿ «·«“—ﬁ
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(-0.1f, -1.5f);
	glVertex2f(0.1f, -1.5f);
	glVertex2f(0.1f, -2.0f);
	glVertex2f(-0.1f, -2.0f);
	glEnd();
	glBegin(GL_TRIANGLES);//«·„À·À
	glColor3f(0.3, 0.6, 0.8);
	glVertex2f(0.3, 1.0);
	glVertex2f(-0.3, 1.0);
	glVertex2f(0, 2.3);
	glEnd();
	glBegin(GL_QUADS);//«·„” ÿÌ· «··Ì ›«·‰’
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-0.3f, 1.0f);
	glVertex2f(0.3f, 1.0f);
	glVertex2f(0.3f, -1.5f);
	glVertex2f(-0.3f, -1.5f);
	glEnd();

	
	glBegin(GL_QUADS);//«·Ê’·Â ⁄ «·Ì„Ì‰
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.5f, -0.7f);
	glVertex2f(0.5f, -0.4f);
	glVertex2f(0.3f, -0.4);
	glEnd();
	glBegin(GL_QUADS);//«·„” ÿÌ· ⁄ «·Ì„Ì‰
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(0.5f, -0.2f);
	glVertex2f(0.5f, -1.0f);
	glVertex2f(3.0f, -1.0f);
	glVertex2f(3.0f, -0.2f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.5, -0.55);
	glVertex2f(3, -0.55);
	glVertex2f(1.0, -0.2f);
	glVertex2f(1, -1.0f);
	glVertex2f(1.5, -0.2f);
	glVertex2f(1.5, -1.0f);
	glVertex2f(2.0, -0.2f);
	glVertex2f(2.0, -1.0f);
	glVertex2f(2.5, -0.2f);
	glVertex2f(2.5, -1.0f);
	glEnd();
	

	glBegin(GL_QUADS);//«·Ê’·Â ⁄ «·Ì”«—
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.5f, -0.7f);
	glVertex2f(-0.5f, -0.4f);
	glVertex2f(-0.3f, -0.4);
	glEnd();
	glBegin(GL_QUADS);//„” ÿÌ· «·Ì”«—
	glColor3f(0.4, 0.2, 0.6);
	glVertex2f(-0.5f, -0.2f);
	glVertex2f(-0.5f, -1.0f);
	glVertex2f(-3.0f, -1.0f);
	glVertex2f(-3.0f, -0.2f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.5, -0.55);
	glVertex2f(-3, -0.55);
	glVertex2f(-1.0, -0.2f);
	glVertex2f(-1, -1.0f);
	glVertex2f(-1.5, -0.2f);
	glVertex2f(-1.5, -1.0f);
	glVertex2f(-2.0, -0.2f);
	glVertex2f(-2.0, -1.0f);
	glVertex2f(-2.5, -0.2f);
	glVertex2f(-2.5, -1.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.9f);
	circle(0.0f, 0.0f, 0.20f, 0.15f);
	circle(0.0f, 0.5f, 0.20f, 0.15f);
	circle(0.0f, -0.5f, 0.20f, 0.15f);
	circle(0.0f, -1.9f, 0.60f, 0.15f);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0, -1.9);
	glVertex2f(0.0, -2.2);
	glVertex2f(-0.3, -1.9);
	glVertex2f(0.0, -2.2);
	glVertex2f(0.3, -1.9);
	glVertex2f(0.0, -2.2);
	glEnd();
	circle(0.0f, -2.2f, 0.09f, 0.08f); //red  circle

	glFlush();

}

void earth() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture1);
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 1.0);
	GLUquadric* qobj = gluNewQuadric();
	gluQuadricTexture(qobj, GL_TRUE);
	gluSphere(qobj, 10, 100, 100);
	gluDeleteQuadric(qobj);
	glDisable(GL_TEXTURE_2D);
	glEnd();


}



void sun() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture2);
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 1.0, 1.0);
	GLUquadric* qobj = gluNewQuadric();
	gluQuadricTexture(qobj, GL_TRUE);
	gluSphere(qobj, 3, 100, 100);
	gluDeleteQuadric(qobj);
	glDisable(GL_TEXTURE_2D);
	glEnd();
}

void background() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myTexture3);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-10, 10);
	glTexCoord2f(1, 0); glVertex2f(10, 10);
	glTexCoord2f(1, 1); glVertex2f(10, -10);
	glTexCoord2f(0, 1); glVertex2f(-10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

static
void key(unsigned char keyPressed, int x, int y) // key handling
{
	switch (keyPressed) {

	case 'x':
		if (lightX >= 5) {
			lightX = 0;
		}
		else {
			lightX += 0.1;
		}
		cout << "light translate on x axis : " << lightX << endl;
		break;
	case 'y':
		if (lightY >= 5) {
			lightY = 0;
		}
		else {
			lightY += 0.1;
		}
		cout << "light translate on y axis : " << lightY << endl;
		break;
	case 'z':
		if (lightZ >= 5) {
			lightZ = 0;
		}
		else {
			lightZ += 0.1;
		}
		cout << "light translate on z axis : " << lightY << endl;
		break;

	case 't':
		std::cout << "print rocket\n";
		type = 1;
		if (transValue >= 11) {
			std::cout << "print satellite\n";
			type = 2;
			if (transValue >= 22) {
				transValue = 3;
				transValue = transValue + 0.1;//increment the value of transValue by 0.1
				cout << "The new translate value is: " << transValue << endl;

			}
			else {
				transValue = transValue + 0.1;//increment the value of transValue by 0.1
				cout << "The new translate value is: " << transValue << endl; //show the change
			}
		}
		else {
			transValue = transValue + 0.1;//increment the value of transValue by 0.1
			cout << "The new translate value is: " << transValue << endl; //show the change
		}
		break;
	case 'q':
	case 27:
		exit(0);
		break;

	default:
		fprintf(stderr, "\nKeyboard commands:\n\n"
			"q, <esc> - Quit\n");
		break;

	}
}

void update(int value) {

	angle += 1.0f;
	if (angle > 360) {
		angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

//This code is taken from google
void textt(float x, float y, void* font, string str)
{
	glRasterPos2f(x, y);
	for (string::iterator c = (&str)->begin(); c != (&str)->end(); ++c)
	{
		glutBitmapCharacter(font, *c);
	}
}

void init() {
	myTexture1 = LoadTexture(image1Path, 600, 360);
	myTexture2 = LoadTexture(image2Path, 512, 512);
	myTexture3 = LoadTexture(image3Path, 1000, 800);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
								  // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);

	glMatrixMode(GL_MODELVIEW);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
}

void display() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glLoadIdentity();

	GLfloat light_position[] = { lightX,lightY, lightZ, 0.0 };
	glOrtho(-10, 10, -10, 10, -10, 10);
	background();

	if (type > 0) {
		switch (type)
		{
		case 1:
		{
			glPushMatrix();
			glTranslatef(0.0, transValue, 0.0);
			glTranslatef(0.0, -7.5, 0.0);
			glColor3f(0.0f, 1.0f, 0.0f);
			glScalef(0.60, 1.0, 0.60);
			Rocket();
			glPopMatrix();
			break;
		}
		case 2:
		{
			glPushMatrix();
			glTranslatef(0.0, transValue, 0.0);
			glTranslatef(0.0, -8, 0.0);
			glScalef(0.60, 1.0, 0.60);
			satellite1();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(0.0, 3, 0.0);
			glScalef(0.60, 1.0, 0.60);
			satellite2();
			glPopMatrix();
			break;
		}
		}
	}

	glPushMatrix();
	glTranslatef(-9.0, 7.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	sun();
	glPopMatrix();

	string a("How to send satellites into space");
	textt(3, 8, GLUT_BITMAP_TIMES_ROMAN_24, const_cast<char*>(a.c_str()));
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/////////////////////////////////////////

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, light_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	glColor3f(1.0f, 0.6f, 0.1f);
	glEnable(GL_DEPTH_TEST);

	glTranslatef(0.0, -15, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	earth();
	glPopMatrix();


	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glFlush();
	glutSwapBuffers();
}


static void play(void)
{
	glutPostRedisplay();
}

void reshape(int windowWidth, int windowHeight) {
	glViewport(0, 0, 1000, 800);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1, 1, -1, 1);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(50, 50);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(" pp ");
	init();
	transValue = 0.0;//ﬁÌ„Â «› —«÷ÌÂ ⁄·Ï ‘«‰  »œ√ „‰ „ﬂ«‰Â«
	glutIdleFunc(play);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}