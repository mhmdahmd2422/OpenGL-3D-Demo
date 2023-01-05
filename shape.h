double redShade = 0;
double greenShade = 0;
double blueShade = 0;

double extraRedShade = 0;
double extraGreenShade = 0;
double extraBlueShade = 0;

double clockRotation = 0;

void setDefaultColor()
{
	glColor3f(0.8, 0.8, 0.8);
}


void drawWall(double thickness)
{
	glPushMatrix();
	glTranslated(0.5, 0.5 * thickness, 0.5);
	glScaled(1.0, thickness, 1.0);
	glColor3f(0.9 + redShade, 0.9 + extraGreenShade, 1 - blueShade);
	glutSolidCube(1);
	glPopMatrix();
	setDefaultColor();
}

void drawTableLeg(double thick, double len)
{
	glPushMatrix();
	glTranslated(0, len / 2, 0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

void drawTable(double topWid, double topThick, double legThick, double legLen)
{
	glPushMatrix();
	glTranslated(0, legLen, 0);
	glScaled(topWid, topThick, topWid);
	glutSolidCube(1.0);
	glPopMatrix();

	double dist = 0.95 * topWid / 2.0 - legThick / 2.0;
	glPushMatrix();
	glTranslated(dist, 0, dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(-2 * dist, 0, 2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glPopMatrix();
}

void drawChair()
{
	glPushMatrix();

	// CHAIR BACK
	glPushMatrix();
	glColor3f(0.6 + greenShade, 0 + blueShade, 0.8 - extraRedShade);
	glTranslated(-.25, 1.03, -0.1);
	glScaled(0.8, 1.1, 0.08);
	glutSolidCube(1);
	glPopMatrix();
	// CHAIR BACK

	// CHAIR BOTTOM
	glPushMatrix();
	glColor3f(0.6 + blueShade, 0.8 - extraGreenShade, 0 + redShade + extraBlueShade);
	glTranslated(-.25, 0.5, 0.25);
	glScaled(0.8, 0.08, 0.8);
	glutSolidCube(1);
	glPopMatrix();
	// CHAIR BOTTOM

	// 4 LEGS
	glPushMatrix();
	glScaled(0.1, 1, 0.1);
	glColor3f(0.6 + extraGreenShade, 0.3 + extraRedShade - blueShade, 0.1 + greenShade + redShade);
	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-5, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-5, 0, 5);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, 5);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	// 4 LEGS

	glPopMatrix();
}


void drawRoom()
{

	// CHAIR
	glPushMatrix();
	glTranslated(0.25, 0.13, 0.7);
	glScaled(0.15, 0.15, 0.15);
	glRotated(45, 0, 1, 0);
	drawChair();
	glPopMatrix();
	// CHAIR

	// CLOCK
	glPushMatrix();
	glColor3f(0 + redShade, 0 + greenShade, 0 + extraBlueShade);
	glTranslated(0.4, 0.55, 0);
	glScaled(0.15, 0.15, 0.15);
	// CLOCK ARM
	glPushMatrix();
	glRotated(clockRotation, 0, 0, 1);
	glTranslated(0.5, 0.1, 0);
	glScaled(1, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	// CLOCK ARM

	glutSolidTorus(0.1, 1, 25, 25);
	glPopMatrix();
	// CLOCK

	glPushMatrix();
	setDefaultColor();
	glScaled(0.8, 0.8, 0.8);
	glTranslated(0.4, 0, 0.4);

	glPushMatrix();
	glTranslated(0.6, 0.38, 0.5);
	glRotated(30, 0, 1, 0);
	glColor3f(0.3 + extraRedShade, 0.5 - greenShade + extraGreenShade, 0.5 - extraBlueShade);
	glutSolidTeapot(0.08);
	glPopMatrix();

	// ORANGE
	glPushMatrix();
	glTranslated(0.25, 0.35, 0.35);
	// ROOT
	glPushMatrix();
	glColor3f(0 + redShade + extraRedShade, 1 - greenShade, 0 + extraBlueShade);
	glScaled(0.4, 1.3, 0.4);
	glTranslated(0, 0.04, 0);
	glRotated(-90, 1, 0, 0);
	glutSolidCube(0.01);
	glPopMatrix();
	// ROOT
	glColor3f(1 - redShade, 0.6 + greenShade - extraGreenShade, 0 + blueShade);
	glutSolidSphere(0.05, 15, 15);
	glPopMatrix();
	// ORANGE

	setDefaultColor();

	glPushMatrix();
	glTranslated(0.4, 0.0, 0.4);
	glColor3f(1 - extraRedShade, 1 - greenShade, 0.7 + extraBlueShade - blueShade);
	drawTable(0.6, 0.02, 0.02, 0.3);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	// ============ WALLS ============ //
	drawWall(0.02);
	glPushMatrix();
	glRotated(90, 0, 0, 1.0);
	drawWall(0.02);
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 1.0, 0.0, 0.0);
	drawWall(0.02);
	glPopMatrix();
	// ============ WALLS ============ //
}



void drawMonster()
{
	glPushMatrix();
	glScaled(1, 2, 0.65);

	// TEETH THING
	glPushMatrix();
	glColor3f(1, 1, 1); // Both teeth color
	glRotated(30, 0, 0, 1);
	glTranslated(-0.1, -0.2, 0.6);
	glScaled(0.7, 0.7, 0.7);
	glutSolidTetrahedron();
	glPopMatrix();
	// NOSE/TEETH

	// ARMS
	glPushMatrix();
	glColor3f(0, 0, 0); // Arms color
	// ARM RIGHT
	glPushMatrix();
	glTranslated(1, 0, 0);
	glScaled(1, 10, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	// ARM RIGHT

	// ARM LEFT
	glPushMatrix();
	glTranslated(-1, 0, 0);
	glScaled(1, 10, 1);
	glutSolidCube(0.1);
	glPopMatrix();
	// ARM LEFT
	glPopMatrix();
	// ARMS

	// LEG
	glPushMatrix();
	glColor3f(0, 0, 1); // Leg color
	glTranslated(0, -0.65, 0);
	glRotated(90, 1, 0, 0);
	glScaled(0.5, 1, 0.5);
	gluCylinder(gluNewQuadric(), 0.75, 0.3, 2, 15, 15);
	glPopMatrix();
	// LEG

	// 2 EYES
	glPushMatrix();
	glColor3f(1, 0, 0); // Eyes color
	glTranslated(0, 0.4, 0);
	glPushMatrix();
	glTranslated(0.3, 0, 0);
	glutSolidCone(0.5, 1.5, 15, 15);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-0.3, 0, 0);
	glutSolidCone(0.5, 1.5, 15, 15);
	glPopMatrix();
	glPopMatrix();
	// 2 EYES

	// THE ACTUAL THING
	glColor3f(0.7, 0.3, 1); // Main body color
	glutSolidSphere(1, 15, 15);
	glPopMatrix();
}
