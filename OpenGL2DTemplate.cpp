#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <glut.h>
using namespace std;
#include <Windows.h>
#include<mmsystem.h>

int p0[2];
int p1[2];
int p2[2];
int p3[2];

int p01[2];
int p11[2];
int p21[2];
int p31[2];

int p02[2];
int p12[2];
int p22[2];
int p32[2];

int p03[2];
int p13[2];
int p23[2];
int p33[2];

int p001[2];
int p002[2];
int p003[2];
int p004[2];


int p0011[2];
int p0021[2];
int p0031[2];
int p0041[2];

int p0012[2];
int p0022[2];
int p0032[2];
int p0042[2];

int p0013[2];
int p0023[2];
int p0033[2];
int p0043[2];

int tar = 4;
int power = 0;
int power2 = 0;
int a = 0;
int b = 0;
int d = 0;
int e = 0;
int xm = 0;
int xy = 0;


float t = 0;

float c = 0.5;

float ap1 = 600;
const float DEG2RAD = 3.14159 / 180;

float cloud1x = 0;

bool in1 = true;
bool in2 = false;

bool out1 = false;
bool out2 = false;
bool health = true;

bool motion = true;
bool motion2 = true;
float t1 = 0;
bool red = false;
bool blue = false;

float poy = 225;
float pox = 225;
bool org = false;
bool org2 = false;
bool color = false;
bool color2 = false;
bool dis = false;
bool dis2 = false;
float h1 = 149;
float h2 = 759;
float s = 0;
bool ok = false;
bool wall1 = true;
bool wall2 = false;

bool lose = false;


int* bezier(float t, int* p0, int* p1, int* p2, int* p3)
{
	int res[2];
	res[0] = pow((1 - t), 3) * p0[0] + 3 * t * pow((1 - t), 2) * p1[0] + 3 * pow(t, 2) * (1 - t) * p2[0] + pow(t, 3) * p3[0];
	res[1] = pow((1 - t), 3) * p0[1] + 3 * t * pow((1 - t), 2) * p1[1] + 3 * pow(t, 2) * (1 - t) * p2[1] + pow(t, 3) * p3[1];
	return res;
}

void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void Display() {






	glClear(GL_COLOR_BUFFER_BIT);


	if (lose == true) {



		if (red == true) {
			glColor3f(1,0 , 0);

			print(200, 400, "RED PLAYER YOU LOST");
		}

		if (blue == true) {
			glColor3f(0,0, 1);

			print(200, 400, "BLUE PLAYER YOU LOST");
		}

		glutPostRedisplay();


		glFlush();
	}

	else{
	//glBegin(GL_TRIANGLES);
		//glColor3f(c, c, c);

		//glVertex3f(150.0f, 200.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		//glVertex3f(100.0f, 100.0f, 0.0f);
		//glColor3f(0.0f, 0.0f, 1.0f);
		//glVertex3f(200.0f, 100.0f, 0.0f);
	//glEnd();


	glBegin(GL_LINE_LOOP);    //el mal3ab

	glColor3f(1, 1, 1);

	glVertex3f(5, 20, 0);

	glVertex3f(5, 520, 0);

	glVertex3f(800, 520, 0);

	glVertex3f(800, 20, 0);

	glEnd();















	glBegin(GL_POLYGON);
	// 1st stripe
	glColor3f(0.5, 1, 0.5);

	glVertex3f(6, 22, 0);

	glVertex3f(6, 518, 0);

	glVertex3f(160, 518, 0);

	glVertex3f(160, 22, 0);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0);    // 2nd stripe

	glVertex3f(150, 22, 0);

	glVertex3f(150, 518, 0);

	glVertex3f(320, 518, 0);

	glVertex3f(320, 22, 0);

	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0.5, 1, 0.5);

	glVertex3f(320, 22, 0);      //3rd stripe

	glVertex3f(320, 518, 0);

	glVertex3f(480, 518, 0);

	glVertex3f(480, 22, 0);

	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(0, 0.5, 0);

	glVertex3f(480, 22, 0);      // 4th stripe

	glVertex3f(480, 518, 0);

	glVertex3f(640, 518, 0);

	glVertex3f(640, 22, 0);

	glEnd();






	glBegin(GL_POLYGON);
	glColor3f(0.5, 1, 0.5);

	glVertex3f(640, 22, 0);      //5rd stripe

	glVertex3f(640, 518, 0);

	glVertex3f(800, 518, 0);

	glVertex3f(800, 22, 0);

	glEnd();





	glBegin(GL_LINE_LOOP);    //inner line fel mal3ab

	glColor3f(1, 1, 1);

	glVertex3f(30, 50, 0);

	glVertex3f(30, 470, 0);

	glVertex3f(770, 470, 0);

	glVertex3f(770, 50, 0);

	glEnd();























	glBegin(GL_POLYGON);    //el sdat

	glColor3f(0.4, 0.4, 0.4);

	glVertex3f(5, 521, 0);

	glVertex3f(5, 680, 0);

	glVertex3f(800, 680, 0);

	glVertex3f(800, 521, 0);

	glEnd();


	glBegin(GL_POLYGON);    //sky

	glColor3f(0.2, 0.7, 0.9);

	glVertex3f(5, 680, 0);

	glVertex3f(5, 800, 0);

	glVertex3f(800, 800, 0);

	glVertex3f(800, 680, 0);

	glEnd();






	glPushMatrix();
	glTranslated(cloud1x, 0, 0);

	glBegin(GL_TRIANGLE_FAN);    //cloud 1
	glColor3f(1, 1, 1);
	glVertex3f(100, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(100 + cos(degInRad) * 30,
			750 + sin(degInRad) * 30);

	}

	glEnd();




	glBegin(GL_TRIANGLE_FAN);    //cloud 1
	glColor3f(1, 1, 1);
	glVertex3f(130, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(130 + cos(degInRad) * 30,
			750 + sin(degInRad) * 30);

	}

	glEnd();



	glBegin(GL_TRIANGLE_FAN);    //cloud 1
	glColor3f(1, 1, 1);
	glVertex3f(160, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(160 + cos(degInRad) * 30,
			750 + sin(degInRad) * 30);

	}

	glEnd();




	glBegin(GL_TRIANGLE_FAN);    //cloud 1
	glColor3f(1, 1, 1);
	glVertex3f(190, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(190 + cos(degInRad) * 30,
			750 + sin(degInRad) * 30);

	}

	glEnd();







	glPopMatrix();



	glPushMatrix();
	glTranslated(cloud1x, 0, 0);

	glBegin(GL_TRIANGLE_FAN);    //cloud 2
	glColor3f(1, 1, 1);
	glVertex3f(350, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(350 + cos(degInRad) * 30,
			750 + sin(degInRad) * 30);

	}

	glEnd();




	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(380, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(380 + cos(degInRad) * 32,
			750 + sin(degInRad) * 32);

	}

	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(410, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(410 + cos(degInRad) * 31,
			750 + sin(degInRad) * 31);

	}

	glEnd();




	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(440, 750, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(440 + cos(degInRad) * 30,
			750 + sin(degInRad) * 30);

	}

	glEnd();







	glPopMatrix();



















	glBegin(GL_QUADS);    //gomhor #1

	glColor3f(0, 0, 0);

	glVertex3f(0, 650, 0);

	glVertex3f(40, 535, 0);

	glVertex3f(180, 535, 0);

	glVertex3f(140, 650, 0);



	glEnd();



	glBegin(GL_QUADS);    //gomhor #2

	glColor3f(0, 0, 0);

	glVertex3f(200, 650, 0);

	glVertex3f(240, 535, 0);

	glVertex3f(380, 535, 0);

	glVertex3f(340, 650, 0);

	glEnd();


	glBegin(GL_QUADS);    //gomhor #3

	glColor3f(0, 0, 0);

	glVertex3f(420, 650, 0);

	glVertex3f(460, 535, 0);

	glVertex3f(600, 535, 0);

	glVertex3f(560, 650, 0);

	glEnd();



	glBegin(GL_QUADS);    //gomhor #4

	glColor3f(0, 0, 0);

	glVertex3f(620, 650, 0);

	glVertex3f(660, 535, 0);

	glVertex3f(800, 535, 0);

	glVertex3f(760, 650, 0);

	glEnd();




	glBegin(GL_POLYGON);    //el banners#1

	glColor3f(1, 0.8, 0.1);

	glVertex3f(5, 521, 0);

	glVertex3f(5, 535, 0);

	glVertex3f(180, 535, 0);

	glVertex3f(180, 521, 0);

	glEnd();


	glBegin(GL_POLYGON);    //el banners#1

	glColor3f(1, 0.9, 0.1);

	glVertex3f(5, 535, 0);

	glVertex3f(5, 550, 0);

	glVertex3f(180, 550, 0);

	glVertex3f(180, 535, 0);

	glEnd();

	



	glBegin(GL_POLYGON);    //el banners#2

	glColor3f(0.7, 0, 0);

	glVertex3f(182, 521, 0);

	glVertex3f(182, 535, 0);

	glVertex3f(355, 535, 0);

	glVertex3f(355, 521, 0);

	glEnd();


	glBegin(GL_POLYGON);    //el banners#2

	glColor3f(0.8, 0, 0);

	glVertex3f(182, 535, 0);

	glVertex3f(182, 550, 0);

	glVertex3f(355, 550, 0);

	glVertex3f(355, 535, 0);

	glEnd();




	glBegin(GL_POLYGON);    //el banners#3

	glColor3f(0.1, 0.6, 0.8);

	glVertex3f(357, 521, 0);

	glVertex3f(357, 535, 0);

	glVertex3f(525, 535, 0);

	glVertex3f(525, 521, 0);

	glEnd();


	glBegin(GL_POLYGON);    //el banners#3

	glColor3f(0.1, 0.6, 1);

	glVertex3f(357, 535, 0);

	glVertex3f(357, 550, 0);

	glVertex3f(525, 550, 0);

	glVertex3f(525, 535, 0);

	glEnd();


	glBegin(GL_POLYGON);    //el banners#4

	glColor3f(0.2, 0.9, 0.4);

	glVertex3f(527, 521, 0);

	glVertex3f(527, 535, 0);

	glVertex3f(700, 535, 0);

	glVertex3f(700, 521, 0);

	glEnd();


	glBegin(GL_POLYGON);    //el banners#4

	glColor3f(0.2, 1, 0.4);

	glVertex3f(527, 535, 0);

	glVertex3f(527, 550, 0);

	glVertex3f(700, 550, 0);

	glVertex3f(700, 535, 0);

	glEnd();



	glBegin(GL_POLYGON);    //el banners#5

	glColor3f(0.7, 0.3, 0.8);

	glVertex3f(702, 521, 0);

	glVertex3f(702, 535, 0);

	glVertex3f(800, 535, 0);

	glVertex3f(800, 521, 0);

	glEnd();


	glBegin(GL_POLYGON);    //el banners#5

	glColor3f(0.7, 0.3, 0.9);

	glVertex3f(702, 535, 0);

	glVertex3f(702, 550, 0);

	glVertex3f(800, 550, 0);

	glVertex3f(800, 535, 0);

	glEnd();


	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(181, 521, 0);
	glVertex3f(181, 550, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(356, 521, 0);
	glVertex3f(356, 550, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(701, 521, 0);
	glVertex3f(701, 550, 0);
	glEnd();



	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(526, 521, 0);
	glVertex3f(526, 550, 0);
	glEnd();
	glLineWidth(1);

	glDisable(GL_LINE_SMOOTH);









	glBegin(GL_POLYGON);    //el noor  1

	glColor3f(0, 0, 0);

	glVertex3f(680, 680, 0);

	glVertex3f(680, 720, 0);

	glVertex3f(800, 720, 0);

	glVertex3f(800, 680, 0);

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(700, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(700 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(740, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(740 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(780, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(780 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();




	glBegin(GL_POLYGON);    //el noor  2

	glColor3f(0, 0, 0);

	glVertex3f(2, 680, 0);

	glVertex3f(2, 720, 0);

	glVertex3f(120, 720, 0);

	glVertex3f(120, 680, 0);

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(20, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(20 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(60, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(60 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(100, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(100 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();




	glBegin(GL_POLYGON);    //el noor  3

	glColor3f(0, 0, 0);

	glVertex3f(250, 680, 0);

	glVertex3f(250, 720, 0);

	glVertex3f(570, 720, 0);

	glVertex3f(570, 680, 0);

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(270, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(270 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(310, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(310 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(350, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(350 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(390, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(390 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(430, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(430 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(470, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(470 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(510, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(510 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(550, 700, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(550 + cos(degInRad) * 12,
			700 + sin(degInRad) * 12);

	}

	glEnd();












	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);

	for (int i = 0; i < 360; i++) {                 // circle kebera
		float degInRad = i * DEG2RAD;
		glVertex2d(400 + cos(degInRad) * 100,
			250 + sin(degInRad) * 100);
	}
	glEnd();







	glPushMatrix();
	glTranslated(0, t1, 0);
	int j;

	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);                                                           //////////// gomhor 1
		glColor3f(1, 0, 0);
		glVertex3f(30 + j, 600, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((30 + j) + cos(degInRad) * 7,
				600 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 3; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);    // gomhor 1
		glColor3f(1, 0, 0);
		glVertex3f(15 + j, 620, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((15 + j) + cos(degInRad) * 7,
				620 + sin(degInRad) * 7);

		}

		glEnd();

	}



	for (j = 5; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);    // gomhor 1
		glColor3f(1, 0, 0);
		glVertex3f(30 + j, 580, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((30 + j) + cos(degInRad) * 7,
				580 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 14; j < 130; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);    // gomhor 1
		glColor3f(1, 0, 0);
		glVertex3f(30 + j, 560, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((30 + j) + cos(degInRad) * 7,
				560 + sin(degInRad) * 7);

		}

		glEnd();

	}
	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);    // gomhor 1
		glColor3f(1, 0, 0);
		glVertex3f(15 + j, 640, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((15 + j) + cos(degInRad) * 7,
				640 + sin(degInRad) * 7);

		}

		glEnd();

	}





	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);                                                           //////////// gomhor 2
		glColor3f(1, 0, 0);
		glVertex3f(230 + j, 600, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((230 + j) + cos(degInRad) * 7,
				600 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 3; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 0, 0);
		glVertex3f(215 + j, 620, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((215 + j) + cos(degInRad) * 7,
				620 + sin(degInRad) * 7);

		}

		glEnd();

	}



	for (j = 5; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 0, 0);
		glVertex3f(230 + j, 580, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((230 + j) + cos(degInRad) * 7,
				580 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 14; j < 130; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 0, 0);
		glVertex3f(230 + j, 560, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((230 + j) + cos(degInRad) * 7,
				560 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);    // gomhor 1
		glColor3f(1, 0, 0);
		glVertex3f(215 + j, 640, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((215 + j) + cos(degInRad) * 7,
				640 + sin(degInRad) * 7);

		}

		glEnd();

	}







	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);                                                           //////////// gomhor 3
		glColor3f(0, 0, 1);
		glVertex3f(450 + j, 600, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((450 + j) + cos(degInRad) * 7,
				600 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 3; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 1);
		glVertex3f(435 + j, 620, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((435 + j) + cos(degInRad) * 7,
				620 + sin(degInRad) * 7);

		}

		glEnd();

	}



	for (j = 5; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 1);
		glVertex3f(450 + j, 580, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((450 + j) + cos(degInRad) * 7,
				580 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 14; j < 130; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 1);
		glVertex3f(450 + j, 560, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((450 + j) + cos(degInRad) * 7,
				560 + sin(degInRad) * 7);

		}

		glEnd();

	}

	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);    // gomhor 1
		glColor3f(0, 0, 1);
		glVertex3f(435 + j, 640, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((435 + j) + cos(degInRad) * 7,
				640 + sin(degInRad) * 7);

		}

		glEnd();

	}




	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);                                                           //////////// gomhor 4
		glColor3f(0, 0, 1);
		glVertex3f(650 + j, 600, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((650 + j) + cos(degInRad) * 7,
				600 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 3; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 1);
		glVertex3f(635 + j, 620, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((635 + j) + cos(degInRad) * 7,
				620 + sin(degInRad) * 7);

		}

		glEnd();

	}



	for (j = 5; j < 120; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 1);
		glVertex3f(650 + j, 580, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((650 + j) + cos(degInRad) * 7,
				580 + sin(degInRad) * 7);

		}

		glEnd();

	}


	for (j = 14; j < 130; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 1);
		glVertex3f(650 + j, 560, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((650 + j) + cos(degInRad) * 7,
				560 + sin(degInRad) * 7);

		}

		glEnd();

	}

	for (j = 0; j < 115; j = j + 14) {


		glBegin(GL_TRIANGLE_FAN);    // gomhor 1
		glColor3f(0, 0, 1);
		glVertex3f(635 + j, 640, 0);

		for (int i = -1; i < 360; i++) {
			float degInRad = i * DEG2RAD;
			glVertex2d((635 + j) + cos(degInRad) * 7,
				640 + sin(degInRad) * 7);

		}

		glEnd();

	}






















































	glPopMatrix();




	                                                                         // player 1

	glPushMatrix();
	glTranslated(xy, 0, 0);



	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	glVertex3f(690, 238, 0);

	glVertex3f(690, 250, 0);

	glVertex3f(760, 250, 0);

	glVertex3f(760, 238, 0);

	glEnd();






	glBegin(GL_POLYGON);

	glColor3f(0, 0, 1);

	glVertex3f(690, 250, 0);

	glVertex3f(690, 260, 0);

	glVertex3f(760, 260, 0);
	//player 2
	glVertex3f(760, 250, 0);

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 1);
	glVertex3f(690, 253, 0);
	glVertex3f(750, 270, 0);
	glVertex3f(750, 250, 0);

	glEnd();





	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(690, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(690 + cos(degInRad) * 11,
			250 + sin(degInRad) * 11);

	}

	glEnd();


	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(700, 253, 0);
	glVertex3f(750, 265, 0);
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(720, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(720 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(740, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(740 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(690, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(690 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(700, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(700 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(710, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(710 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(730, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(730 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(750, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(750 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();


	glutPostRedisplay();

	glPopMatrix();





	glPushMatrix();
	glTranslated(xm, 0, 0);



	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);

	glVertex3f(40, 238, 0);

	glVertex3f(40, 250, 0);

	glVertex3f(110, 250, 0);

	glVertex3f(110, 238, 0);

	glEnd();






	glBegin(GL_POLYGON);

	glColor3f(1, 0, 0);

	glVertex3f(40, 250, 0);

	glVertex3f(40, 260, 0);

	glVertex3f(110, 260, 0);
	                                                      //player 2
	glVertex3f(110, 250, 0);

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 0, 0);
	glVertex3f(110, 253, 0);
	glVertex3f(50, 270, 0);
	glVertex3f(50, 250, 0);

	glEnd();





	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(110, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(110 + cos(degInRad) * 11,
			250 + sin(degInRad) * 11);

	}

	glEnd();


	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(110, 253, 0);
	glVertex3f(50, 265, 0);
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(60, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(60 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(70, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(70 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(80, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(80 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(50, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(50 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(90, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(90 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(100, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(100 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(110, 235, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(110 + cos(degInRad) * 2,
			235 + sin(degInRad) * 2);

	}

	glEnd();


	glutPostRedisplay();

	glPopMatrix();




















	                                                                                 //ball 1



	glPushMatrix();
	glTranslated(d, e, 0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(650, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(650 + cos(degInRad) * 18,
			250 + sin(degInRad) * 18);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(650, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(650 + cos(degInRad) * 4,
			250 + sin(degInRad) * 4);

	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(636, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(636 + cos(degInRad) * 4,
			250 + sin(degInRad) * 4);

	}







	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(642, 262, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(642 + cos(degInRad) * 4,
			262 + sin(degInRad) * 4);

	}







	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(658, 262, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(658 + cos(degInRad) * 4,
			262 + sin(degInRad) * 4);

	}







	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(659, 240, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(659 + cos(degInRad) * 4,
			240 + sin(degInRad) * 4);

	}







	glEnd();






	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(643, 236, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(643 + cos(degInRad) * 4,
			236 + sin(degInRad) * 4);

	}







	glEnd();

	glPopMatrix();







































	glPushMatrix();
	glTranslated(a, b, 0);
	                                                                        //ball 2
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(150, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(150 + cos(degInRad) * 18,
			250 + sin(degInRad) * 18);

	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(150, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(150 + cos(degInRad) * 4,
			250 + sin(degInRad) * 4);

	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(136, 250, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(136 + cos(degInRad) * 4,
			250 + sin(degInRad) * 4);

	}







	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(142, 262, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(142 + cos(degInRad) * 4,
			262 + sin(degInRad) * 4);

	}







	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(158, 262, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(158 + cos(degInRad) * 4,
			262 + sin(degInRad) * 4);

	}







	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(159, 240, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(159 + cos(degInRad) * 4,
			240 + sin(degInRad) * 4);

	}







	glEnd();






	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(143, 236, 0);

	for (int i = -1; i < 360; i++) {
		float degInRad = i * DEG2RAD;
		glVertex2d(143 + cos(degInRad) * 4,
			236 + sin(degInRad) * 4);

	}







	glEnd();

	glPopMatrix();


	glBegin(GL_POLYGON);
	                                                     // wall
	glColor3f(1, 1, 1);

	glVertex3f(395, 180, 0);

	glVertex3f(395, 400, 0);

	glVertex3f(405, 400, 0);

	glVertex3f(405, 180, 0);

	glEnd();



	if (wall1 == true) {


		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);

		glVertex3f(395, 180, 0);

		glVertex3f(395, 190, 0);

		glVertex3f(500, 190, 0);

		glVertex3f(500, 180, 0);

		glEnd();



		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);

		glVertex3f(395, 390, 0);

		glVertex3f(405, 395, 0);

		glVertex3f(500, 190, 0);
		glVertex3f(495, 180, 0);



		glEnd();



		glBegin(GL_LINES);

		glColor3f(1, 1, 1);

		glVertex3f(405, 200, 0);
		glVertex3f(490, 200, 0);


		glVertex3f(405, 220, 0);
		glVertex3f(485, 220, 0);

		glVertex3f(405, 240, 0);
		glVertex3f(475, 240, 0);


		glVertex3f(405, 260, 0);
		glVertex3f(465, 260, 0);

		glVertex3f(405, 280, 0);
		glVertex3f(457, 280, 0);

		glVertex3f(405, 300, 0);
		glVertex3f(447, 300, 0);
		 
		glVertex3f(405, 320, 0);
		glVertex3f(440, 320, 0);

		glVertex3f(405, 340, 0);
		glVertex3f(430, 340, 0);

		glVertex3f(405, 360, 0);
		glVertex3f(420, 360, 0);

		glVertex3f(405, 380, 0);
		glVertex3f(410, 380, 0);





		glVertex3f(450, 300, 0);
		glVertex3f(450, 180, 0);

		glVertex3f(410, 370, 0);
		glVertex3f(410, 180, 0);

		glVertex3f(430, 340, 0);
		glVertex3f(430, 180, 0);

		glVertex3f(420, 350, 0);
		glVertex3f(420, 180, 0);


		glVertex3f(460, 250, 0);
		glVertex3f(460, 180, 0);

		glVertex3f(470, 240, 0);
		glVertex3f(470, 180, 0);

		glVertex3f(480, 230, 0);
		glVertex3f(480, 180, 0);

		glEnd();


	}


	if (wall2 == true) {


		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);

		glVertex3f(405, 180, 0);

		glVertex3f(405, 190, 0);

		glVertex3f(310, 190, 0);

		glVertex3f(310, 180, 0);

		glEnd();



		glBegin(GL_POLYGON);

		glColor3f(1, 1, 1);

		glVertex3f(395, 390, 0);

		glVertex3f(405, 395, 0);

		glVertex3f(315, 180, 0);
		glVertex3f(310, 190, 0);



		glEnd();



		glBegin(GL_LINES);

		glColor3f(1, 1, 1);

		glVertex3f(405, 200, 0);
		glVertex3f(315, 200, 0);


		glVertex3f(405, 220, 0);
		glVertex3f(320, 220, 0);

		glVertex3f(405, 240, 0);
		glVertex3f(335, 240, 0);


		glVertex3f(405, 260, 0);
		glVertex3f(340, 260, 0);

		glVertex3f(405, 280, 0);
		glVertex3f(350, 280, 0);

		glVertex3f(405, 300, 0);
		glVertex3f(360, 300, 0);

		glVertex3f(405, 320, 0);
		glVertex3f(370, 320, 0);

		glVertex3f(405, 340, 0);
		glVertex3f(380, 340, 0);

		glVertex3f(405, 360, 0);
		glVertex3f(385, 360, 0);

		






		glVertex3f(350, 260, 0);
		glVertex3f(350, 180, 0);

		glVertex3f(390, 370, 0);
		glVertex3f(390, 180, 0);

		glVertex3f(330, 230, 0);
		glVertex3f(330, 180, 0);

		glVertex3f(320, 185, 0);
		glVertex3f(320, 180, 0);


		glVertex3f(360, 300, 0);
		glVertex3f(360, 180, 0);

		glVertex3f(370, 335, 0);
		glVertex3f(370, 180, 0);

		glVertex3f(380, 355, 0);
		glVertex3f(380, 180, 0);

		


		glEnd();


















	}

















	                                                              // power bar 1
	glBegin(GL_LINE_LOOP);

	glColor3f(1, 1, 1);

	glVertex3f(10, 225, 0);

	glVertex3f(10, 325, 0);

	glVertex3f(20, 325, 0);

	glVertex3f(20, 225, 0);

	glEnd();


	glBegin(GL_LINE_LOOP);

	glColor3f(1, 1, 1);

	glVertex3f(780, 225, 0);
	                                                              //power bar 2 
	glVertex3f(780, 325, 0);

	glVertex3f(790, 325, 0);

	glVertex3f(790, 225, 0);

	glEnd();


	glPushMatrix();
	glBegin(GL_POLYGON);

	glColor3f(1, 0, 0);

	glVertex3f(780, 225, 0);

	glVertex3f(780, pox, 0);

	glVertex3f(790, pox, 0);

	glVertex3f(790, 225, 0);

	glEnd();
	glutPostRedisplay();
	glPopMatrix();











	glPushMatrix();
	glBegin(GL_POLYGON);

	glColor3f(1, 0, 0);

	glVertex3f(10, 225, 0);

	glVertex3f(10, poy, 0);

	glVertex3f(20, poy, 0);

	glVertex3f(20, 225, 0);

	glEnd();
	glutPostRedisplay();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_POLYGON);

	glColor3f(0, 0, 0);
	                                                                   //health bar 1
	glVertex3f(40, 225, 0);

	glVertex3f(40, 220, 0);

	glVertex3f(150, 220, 0);

	glVertex3f(150, 225, 0);

	glEnd();


	glBegin(GL_POLYGON);

	glColor3f(0, 1, 0);
	if (color2 == true) {
		glColor3f(1, 0, 0);
	}
	glVertex3f(41, 224, 0);

	glVertex3f(41, 221, 0);

	glVertex3f(h1, 221, 0);

	glVertex3f(h1, 224, 0);

	glEnd();
	glutPostRedisplay();
	glPopMatrix();



	glPushMatrix();

	glBegin(GL_POLYGON);

	glColor3f(0, 0, 0);
	                                                               //health bar 2
	glVertex3f(650, 225, 0);

	glVertex3f(650, 220, 0);

	glVertex3f(760, 220, 0);

	glVertex3f(760, 225, 0);

	glEnd();



	glBegin(GL_POLYGON);

	glColor3f(0, 1, 0);
	if (color == true) {
		glColor3f(1, 0, 0);
	}

	glVertex3f(651, 224, 0);

	glVertex3f(651, 221, 0);

	glVertex3f(h2, 221, 0);

	glVertex3f(h2, 224, 0);

	glEnd();
	glutPostRedisplay();
	glPopMatrix();


	glPushMatrix();


	glTranslated(s, 0, 0);

	glBegin(GL_POLYGON);

	glColor3f(1, 1, 0);

	glVertex3f(21, 500, 0);

	glVertex3f(21, 440, 0);

	glVertex3f(149, 440, 0);

	glVertex3f(149, 500, 0);

	glEnd();
	glColor3f(0, 0, 0);

	print(30, 460, "OFF-SIDE");

	glBegin(GL_LINE_LOOP);

	glColor3f(0, 0, 0);

	glVertex3f(20, 500, 0);                               //defender

	glVertex3f(20, 440, 0);

	glVertex3f(150, 440, 0);

	glVertex3f(150, 500, 0);

	glEnd();







	glutPostRedisplay();
	glPopMatrix();



	if (dis == true) {
		glColor3f(1, 0, 0);
		print(680, 280, "OUCH!");

	}


	if (dis2 == true) {
		glColor3f(1, 0, 0);
		print(50, 280, "OUCH!");

	}












	glutPostRedisplay();


	glFlush();

	}
}



void Anim()                              /////////////////////////////////////






{



	s = s + 0.5;

	if (motion == true)
	{
		cloud1x = cloud1x + 0.008;
		if (cloud1x > 210) {
			motion = false;
		}
	}
	else
	{
		cloud1x = cloud1x - 0.008;
		if (cloud1x <= 0) {
			motion = true;
		}
	}




	if (motion2 == true)
	{
		t1 = t1 + 0.03;
		if (t1 > 3) {
			motion2 = false;
		}
	}
	else
	{
		t1 = t1 - 0.03;
		if (t1 <= 0) {
			motion2 = true;
		}
	}



	if (power == 1 && t < 1) {
		wall1 = true;
		wall2 = false;

		dis2 = false;
		int* pr = bezier(t, p0, p1, p2, p3);

		a = pr[0] - 150;
		b = pr[1] - 250;
		t = t + 0.003;
		xm = 25;
		org = true;





	}


	if (power == 1 && org == true && t >= 1) {
		wall2 = true;
		wall1 = false;
		a = -0;
		b = -0;
		t = 0;
		xm = 0;

		power = 0;
		org = false;
	}






	if (power == 2 && t < 1) {
		wall1 = true;
		wall2 = false;
		dis2 = false;
		int* pr = bezier(t, p01, p11, p21, p31);

		a = pr[0] - 150;
		b = pr[1] - 250;
		t = t + 0.003;
		xm = 25;
		org = true;
	}


	if (power == 2 && org == true && t >= 1) {
		sndPlaySound(TEXT("wall"), SND_ASYNC);
		wall2 = true;
		wall1 = false;
		a = -0;
		b = -0;
		t = 0;
		xm = 0;
		power = 0;
		org = false;
	}






	if (power == 3 && t < 1) {
		wall1 = true;
		wall2 = false;
		dis2 = false;
		int* pr = bezier(t, p02, p12, p22, p32);

		a = pr[0] - 150;
		b = pr[1] - 250;
		t = t + 0.003;
		xm = 25;
		org = true;

		if (20 + s <= pr[0] && pr[0] <= 150 + s && pr[1] >= 440 && pr[1] <= 500) {
			t = 1;


		}



	}

	if (power == 3 && org == true && t >= 1) {
		wall2 = true;
		wall1 = false;
		a = -0;
		b = -0;
		t = 0;
		xm = 0;
		power = 0;
		org = false;
	}




	if (power == 4 && t < 1) {
		wall1 = true;
		wall2 = false;
		health = true;
		dis2 = false;
		int* pr = bezier(t, p03, p13, p23, p33);

		a = pr[0] - 150;
		b = pr[1] - 250;
		t = t + 0.003;
		xm = 25;
		org = true;

		 


		if (20 + s <= pr[0] && pr[0] <= 150 + s && pr[1] >= 440 && pr[1] <= 500) {
			t = 1;
			health = false;

		}
		




	}


	if (power == 4 && org == true && t >= 1) {
		wall2 = true;
		wall1 = false;
		a = 0;
		b = 0;
		t = 0;

		

		if (health == true) {
			sndPlaySound(TEXT("hit"), SND_ASYNC);
			if (h2 < 760 && h2>659) {
				h2 = h2 - 12;
			}
			if (h2 >659 && h2 < 700) {
				color = true;
			}

			if (h2 <= 659) {
				blue = true;
				lose = true;
				
			}

			dis = true;
		}

		xm = 0;

		power = 0;
		org = false;
	}



	//                                     ////////

	if (power2 == 1 && t < 1) {
		wall2 = true;
		wall1 = false;

		dis = false;
		int* pr = bezier(t, p0011, p0021, p0031, p0041);

		d = pr[0] - 650;
		e = pr[1] - 250;
		t = t + 0.003;
		xy = -25;
		org2 = true;

	}


	if (power2 == 1 && org2 == true && t >= 1) {
		wall1 = true;
		wall2 = false;
		xy = 0;
		d = 0;
		e = 0;
		t = 0;
		power2 = 0;
		org2 = false;
	}






	if (power2 == 2 && t < 1) {
		wall2 = true;
		wall1 = false;
		dis = false;
		int* pr = bezier(t, p0012, p0022, p0032, p0042);

		d = pr[0] - 650;
		e = pr[1] - 250;
		t = t + 0.003;
		xy = -25;
		org2 = true;
		if (20 + s <= pr[0] && pr[0] <= 150 + s && pr[1] >= 440 && pr[1] <= 500) {
			t = 1;

		}
	}


	if (power2 == 2 && org2 == true && t >= 1) {
		sndPlaySound(TEXT("wall"), SND_ASYNC);
		wall1 = true;
		wall2 = false;
		xy = 0;
		d = -0;
		e = -0;
		t = 0;
		power2 = 0;
		org2 = false;
	}






	if (power2 == 3 && t < 1) {
		wall2 = true;
		wall1 = false;
		dis = false;
		int* pr = bezier(t, p0013, p0023, p0033, p0043);

		d = pr[0] - 650;
		e = pr[1] - 250;
		t = t + 0.003;
		xy = -25;
		org2 = true;

		if (20 + s <= pr[0] && pr[0] <= 150 + s && pr[1] >= 440 && pr[1] <= 500) {
			t = 1;

		}

	}


	if (power2 == 3 && org2 == true && t >= 1) {
		wall1 = true;
		wall2 = false;
		d = -0;
		e = -0;
		t = 0;
		xy = 0;
		power2 = 0;
		org2 = false;
	}




	if (power2 == 4 && t < 1) {
		wall2 = true;
		wall1 = false;
		health = true;
		dis = false;
		int* pr = bezier(t, p001, p002, p003, p004);
		xy = -25;

		d = pr[0] - 650;
		e = pr[1] - 250;
		t = t + 0.003;
		org2 = true;

		

		if (20 + s <= pr[0] && pr[0] <= 150 + s && pr[1] >= 440 && pr[1] <= 500) {
			t = 1;
			health = false;

		}
	}


	if (power2 == 4 && org2 == true && t >= 1) {

		wall1 = true;
		wall2 = false;
		xy = 0;
		d = 0;
		e = 0;
		t = 0;
		if (health == true) {
			sndPlaySound(TEXT("hit"), SND_ASYNC);
			if (h1 < 150 && h1>48) {
				h1 = h1 - 12;
			}

			if (h1 > 50 && h1 < 90) {
				color2 = true;
			}

			if (h1 <= 50) {
				
				red = true;
				lose = true;
			}
			dis2 = true;

		}
		power2 = 0;
		org2 = false;
	}






	glutPostRedisplay();
}







void Key(unsigned char key, int x, int y) {

	y = 800 - y;




	if (key == 'r' && x < 120 && x>30 && y > 225 && y < 275) {

		if (in1 == true && in2 == false) {
			if (poy < 325) {
				poy = poy + 25;
			}


			//in1 = false;
			//in2 = true;


		}

	}


	if (key == 'l' && x < 760 && x>680 && y > 225 && y < 275) {
		if (in2 == true && in1 == false) {

			if (pox < 325) {
				pox = pox + 25;
			}
			//in2 = false;
			//in1 = true;





		}

	}





	glutPostRedisplay();





}

void KeyUp(unsigned char key, int x, int y) {

	y = 800 - y;


	if (key == 'r' && x < 120 && x>30 && y > 225 && y < 275) {

		if (poy == 250) {
			power = 1;
		}
		if (poy == 275) {
			power = 2;
		}

		if (poy == 300) {
			power = 3;
		}
		if (poy == 325) {
			power = 4;


		

		}

		if (in1 == true && in2 == false) {
			sndPlaySound(TEXT("kick"), SND_ASYNC);
		}


		in1 = false;
		in2 = true;



		poy = 225;

	


	}



	if (key == 'l' && x < 760 && x>680 && y > 225 && y < 275) {

		if (pox == 250) {
			power2 = 1;
		}
		if (pox == 275) {
			power2 = 2;
		}

		if (pox == 300) {
			power2 = 3;
		}
		if (pox == 325) {
			power2 = 4;
		}

		if (in2 == true && in1 == false) {
			sndPlaySound(TEXT("kick"), SND_ASYNC);
		}

		in2 = false;
		in1 = true;
		pox = 225;
		
	}

	

	glutPostRedisplay();





}



void timer(int a) {

	s = 0;


	glutPostRedisplay();

	glutTimerFunc(20 * 1000, timer, 0);


}





//void timer2(int a) {
//
//	ap1 = ap1 - 15;
//
//
//	glutPostRedisplay();
//
//	glutTimerFunc(2 * 1000, timer, 0);
//
//
//
//}




void main(int argc, char** argr) {
	glutInit(&argc, argr);








	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);

	p0[0] = 150;
	p0[1] = 250;

	p1[0] = 86;
	p1[1] = 401;

	p2[0] = 242;
	p2[1] = 401;

	p3[0] = 250;
	p3[1] = 260;




	p01[0] = 150;
	p01[1] = 250;

	p11[0] = 113;
	p11[1] = 410;

	p21[0] = 347;
	p21[1] = 455;

	p31[0] = 390;
	p31[1] = 400;




	p02[0] = 150;
	p02[1] = 250;

	p12[0] = 238;
	p12[1] = 600;

	p22[0] = 530;
	p22[1] = 568;

	p32[0] = 550;
	p32[1] = 250;




	p03[0] = 150;
	p03[1] = 250;

	p13[0] = 131;
	p13[1] = 486;

	p23[0] = 671;
	p23[1] = 591;

	p33[0] = 720;
	p33[1] = 280;




















	p004[0] = 90;
	p004[1] = 250;

	p003[0] = 131;
	p003[1] = 486;

	p002[0] = 671;
	p002[1] = 591;

	p001[0] = 650;
	p001[1] = 250;




	p0041[0] = 500;
	p0041[1] = 262;

	p0031[0] = 491;
	p0031[1] = 290;

	p0021[0] = 682;
	p0021[1] = 566;

	p0011[0] = 650;
	p0011[1] = 250;




	p0042[0] = 389;
	p0042[1] = 400;

	p0032[0] = 458;
	p0032[1] = 497;

	p0022[0] = 657;
	p0022[1] = 505;

	p0012[0] = 650;
	p0012[1] = 250;



	p0043[0] = 300;
	p0043[1] = 250;

	p0033[0] = 290;
	p0033[1] = 600;

	p0023[0] = 700;
	p0023[1] = 600;

	p0013[0] = 650;
	p0013[1] = 250;














	glutCreateWindow("OpenGL - 2D Template");



	glutDisplayFunc(Display);



	glutIdleFunc(Anim);



	glutKeyboardUpFunc(KeyUp);

	//glutMouseFunc(Mouse);

	glutTimerFunc(20 * 1000, timer, 0); //time in ms
	//glutTimerFunc(2 * 1000, timer2, 0); //time in ms




	glutKeyboardFunc(Key);
	//glutKeyboardUpFunc(keyUp);
	//glutMouseFunc(Mouse);
	//sndPlaySound(TEXT("crowd"), SND_LOOP | SND_ASYNC);    //ashel el loop


	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 800, 0.0, 800);

	glutMainLoop();
}
