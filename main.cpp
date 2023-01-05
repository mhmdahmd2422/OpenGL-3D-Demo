#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include "camera.h"
#include "shape.h"

#define GLUT_KEY_ESCAPE 27

bool shouldChangeColor = false;

double monsterX, monsterY, monsterZ;

float randomFloat()
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}


void resetColors()
{
	redShade = 0;
	greenShade = 0;
	blueShade = 0;
	extraRedShade = 0;
	extraGreenShade = 0;
	extraBlueShade = 0;
}


void Display()
{
	setupCamera();
	setupLights();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		glTranslated(monsterX, monsterY, monsterZ);
		glScaled(0.1, 0.1, 0.1);
		drawMonster();
		glPopMatrix();

	glPushMatrix();
	glScaled(1, 1, 1);
	drawRoom();
	glPopMatrix();

	glFlush();
}

void onKeyPress(unsigned char key, int x, int y)
{
	float d = 0.01 * 10;

	switch (key)
	{
	case 'c':
		shouldChangeColor = !shouldChangeColor;
		if (!shouldChangeColor)
			resetColors();
		break;
	case 'w':
		camera.moveY(d);
		break;
	case 's':
		camera.moveY(-d);
		break;
	case 'a':
		camera.moveX(d);
		break;
	case 'd':
		camera.moveX(-d);
		break;
	case 'q':
		camera.moveZ(d);
		break;
	case 'e':
		camera.moveZ(-d);
		break;
	case 'h':
		setRightView();
		break;
	case 'g':
		setLeftView();
		break;
	case 'y':
		setTopView();
		break;
	case 'f':
		setFrontView();
		break;
    case 'p' : glutFullScreen();
        break;
	case GLUT_KEY_ESCAPE:
		exit(EXIT_SUCCESS);
	}

	glutPostRedisplay();
}


void colorDurationHandler(int x)
{
	if (shouldChangeColor)
	{
		redShade = randomFloat();
		greenShade = randomFloat();
		blueShade = randomFloat();

		extraRedShade = randomFloat();
		extraGreenShade = randomFloat();
		extraBlueShade = randomFloat();
	}
	glutPostRedisplay();
	glutTimerFunc(500, colorDurationHandler, 0);
}


void MonsterAnimationHandler()
{
	if (monsterY >= 0.4){
		monsterY -= 0.001;
	}
}


void idleCallback()
{
    MonsterAnimationHandler();

	if (clockRotation < 0)
	{
		clockRotation = 360;
	}
	clockRotation -= 0.05;


	glutPostRedisplay();
}

void initializeAnimation()
{
	monsterX = 0.2;
	monsterY = 1.75;
	monsterZ = 0.1;
}

void monsterDurationHandler(int value)
{
	int randomPeriod = 5000 + (5 * (rand() % 1000));
    initializeAnimation();
	glutTimerFunc(randomPeriod, monsterDurationHandler, 0);
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("19109957");
	glutDisplayFunc(Display);
	glutKeyboardFunc(onKeyPress);
	colorDurationHandler(0);
	monsterDurationHandler(0);
	glutIdleFunc(idleCallback);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
	return 0;
}
