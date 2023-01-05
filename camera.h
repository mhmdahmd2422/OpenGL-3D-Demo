#define DEG2RAD(a) (a * 0.0174532925)
class Vector3f
{
public:
	float x, y, z;

	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3f operator+(Vector3f const &v)
	{
		return Vector3f(x + v.x, y + v.y, z + v.z);
	}

	Vector3f operator-(Vector3f &v)
	{
		return Vector3f(x - v.x, y - v.y, z - v.z);
	}

	Vector3f operator*(float n)
	{
		return Vector3f(x * n, y * n, z * n);
	}

	Vector3f operator/(float n)
	{
		return Vector3f(x / n, y / n, z / n);
	}

	Vector3f unit()
	{
		return *this / sqrt(x * x + y * y + z * z);
	}

	Vector3f cross(Vector3f v)
	{
		return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}
};

class Camera
{
public:
	Vector3f eye, center, up;

	Camera(float eyeX = 1.0f, float eyeY = 1.0f, float eyeZ = 1.0f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f)
	{
		eye = Vector3f(eyeX, eyeY, eyeZ);
		center = Vector3f(centerX, centerY, centerZ);
		up = Vector3f(upX, upY, upZ);
		Vector3f view = (center - eye).unit();
		eye = eye + view * -0.7;
		center = center + view * -0.7;
	}

	void moveX(float d)
	{
		Vector3f right = up.cross(center - eye).unit();
		eye = eye + right * d;
		center = center + right * d;
	}

	void moveY(float d)
	{
		eye = eye + up.unit() * d;
		center = center + up.unit() * d;
	}

	void moveZ(float d)
	{
		Vector3f view = (center - eye).unit();
		eye = eye + view * d;
		center = center + view * d;
	}

	void rotateX(float a)
	{
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
		up = view.cross(right);
		center = eye + view;
	}

	void rotateY(float a)
	{
		Vector3f view = (center - eye).unit();
		Vector3f right = up.cross(view).unit();
		view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
		right = view.cross(up);
		center = eye + view;
	}

	void look()
	{
		gluLookAt(
				eye.x, eye.y, eye.z,
				center.x, center.y, center.z,
				up.x, up.y, up.z);
	}
};

Camera camera;

void setupLights()
{
	GLfloat ambient[] = {0.7f, 0.7f, 0.7, 1.0f};
	GLfloat diffuse[] = {0.6f, 0.6f, 0.6, 1.0f};
	GLfloat specular[] = {1.0f, 1.0f, 1.0, 1.0f};
	GLfloat shininess[] = {50};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = {0.7f, 0.7f, 1, 1.0f};
	// GLfloat lightPosition[] = { -7.0f, 6.0f,3.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupCamera()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.look();
}


void setLeftView()
{
	camera.up.x = -0.00405836;
	camera.up.y = 0.999989;
	camera.up.z = 0.00230124;

	camera.center.x = -0.713009;
	camera.center.y = 0.448415;
	camera.center.z = 0.426624;

	camera.eye.x = -1.71246;
	camera.eye.y = 0.444435;
	camera.eye.z = 0.393797;
}

void setTopView()
{
	camera.up.x = 0.0226687;
	camera.up.y = -0.0143616;
	camera.up.z = -0.99964;

	camera.center.x = -0.00778855;
	camera.center.y = 1.79373;
	camera.center.z = 0.516674;

	camera.eye.x = -0.00758377;
	camera.eye.y = 2.79363;
	camera.eye.z = 0.502314;
}

void setRightView()
{
	camera.up.x = -0.108454;
	camera.up.y = 0.994058;
	camera.up.z = -0.00928754;

	camera.center.x = 0.952321;
	camera.center.y = 0.526236;
	camera.center.z = 0.454693;

	camera.eye.x = 1.94623;
	camera.eye.y = 0.634482;
	camera.eye.z = 0.434158;
}

void setFrontView()
{
	camera.up.x = -0.00171101;
	camera.up.y = 0.995962;
	camera.up.z = -0.0897583;

	camera.center.x = 0.0095462;
	camera.center.y = 0.491564;
	camera.center.z = 1.5339;

	camera.eye.x = 0.0304264;
	camera.eye.y = 0.590316;
	camera.eye.z = 2.62926;
}

