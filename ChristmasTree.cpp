#include<glut.h>
#include<gl/GLU.h>
#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
bool Decorate = 1; int flag = 0; bool Light = 1;

GLfloat vertices[][3] = {
	{9,0.0,9.0},{11.0,0.0,9.0},{11.0,3.0,9.0},
	{9,3.0,9.0}, {9.0,0.0,11.0},{11.0,0.0,11.0},
	{11.0,3.0,11.0}, {9.0,3.0,11.0} };
GLfloat colors[][3] = { {1.0,1.0,1.0},{1.0,0.0,0.0},
{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };
GLfloat GREEN[] = { 0, 0.6, 0.07, 0.550000 };
GLfloat WHITE[] = { 1, 1, 1 ,1};
GLfloat RED[] = { 1, 0, 0 };
GLfloat REDD[] = { 0.8, 0, 0.2 };
GLfloat BLACK[] = { 0, 0, 0 };
class Ball {
	double radius;
	GLfloat* color;
	double x;
	double y;
	double z;
public:
	Ball(double r, GLfloat* c, double x, double y, double z) :
		radius(r), color(c), 
		y(y), x(x), z(z) {
	}
	void showball() {

		glPushMatrix();
		GLfloat mat_specular[] = { 0.633000, 0.727811, 0.633000, 0.550000 };
		GLfloat mat_shininess[] = { 76.800003 };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glTranslated(x, y, z);
		glutSolidSphere(radius, 30, 30);
		glPopMatrix();
	}
};
Ball balls[] = {
  Ball(0.35, RED, 13.8, 3, 13.5),
  Ball(0.35, RED, 13.8, 3, 6.5),
  Ball(0.35, RED, 6.2, 3, 13.5),
  Ball(0.35, RED, 6.2, 3, 6.5),

  Ball(0.3, WHITE, 13, 4.8, 13),
  Ball(0.3, WHITE, 7, 4.8, 13),
  Ball(0.3, WHITE, 13, 4.8, 7),
  Ball(0.3, WHITE, 7, 4.8, 7),

  Ball(0.25, RED, 12.5, 7, 12.5),
  Ball(0.25, RED, 7.5, 7, 12.5),
  Ball(0.25, RED, 12.5, 7, 7.5),
  Ball(0.25, RED, 7.5, 7, 7.5),

  Ball(0.25, WHITE, 13, 7, 10),
  Ball(0.25, WHITE, 10, 7, 13),
  Ball(0.25, WHITE, 7, 7, 10),
  Ball(0.25, WHITE, 10, 7, 7),

  Ball(0.3, REDD, 14, 4.9, 10),
  Ball(0.3, REDD, 10, 4.9, 14),
  Ball(0.3, REDD, 10, 4.9, 6),
  Ball(0.3, REDD, 6, 4.9, 10),

  Ball(0.35, WHITE, 14.8, 2.9, 10),
  Ball(0.35, WHITE, 10, 2.9, 14.8),
  Ball(0.35, WHITE, 10, 2.9, 5.2),
  Ball(0.35, WHITE, 5.2, 2.9, 10),
  //snow man
  Ball(2, WHITE, 3, 2, 4),
  Ball(1.4, WHITE, 3, 3.9,4),
};
GLfloat SHININESS[] = { 12 };
void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
	glMatrixMode(GL_MODELVIEW);
}
void root_line() {
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WHITE);
	glBegin(GL_LINES);
	glVertex3f(9, 3, 9);
	glVertex3f(9, 0, 9);
	glVertex3f(9, 3, 11);
	glVertex3f(9, 0, 11);
	glVertex3f(11, 3, 11);
	glVertex3f(11, 0, 11);
	glVertex3f(11, 3, 9);
	glVertex3f(11, 0, 9);
	glEnd();
}
void treeleaf(float x1, float y1, float z1, float x11, float y11, float z11, float h) {
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, GREEN);
	glMaterialfv(GL_FRONT, GL_SHININESS, SHININESS);
	int s = 10;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(-x1 + s, y1, 0 + s);// glColor3f(0, 1, 0);
	glVertex3f(0 + s, y1, -z1 + s);
	glVertex3f(x1 + s, y1, 0 + s);
	glVertex3f(0 + s, y1, x1 + s);
	glVertex3f(-x1 + s, y1, 0 + s);
	glEnd();
	glBegin(GL_TRIANGLE_FAN); glColor3f(0, 0, 1);
	glVertex3f(-x1 + s, y1, 0 + s);
	glVertex3f(0 + s, y1, z1 + s);

	glVertex3f(x1 + s, y1, 0 + s);
	glVertex3f(0 + s, y1, -z1 + s);
	glEnd();
	glBegin(GL_TRIANGLE_FAN); glColor3f(0, 1, 0);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(-x11 + s, y11, -z11 + s);// glColor3f(0, 1, 0);
	glVertex3f(x11 + s, y11, -z11 + s);
	glVertex3f(x11 + s, y11, z11 + s);
	glVertex3f(-x11 + s, y11, z11 + s);
	glVertex3f(-x11 + s, y11, -z11 + s);
	glEnd();
	glBegin(GL_TRIANGLE_FAN); glColor3f(0, 0, 1);
	glVertex3f(-x11 + s, y11, -z11 + s);
	glVertex3f(-x11 + s, y11, z11 + s);
	glVertex3f(x11 + s, y11, z11 + s);
	glVertex3f(-x11 + s, y11, -z11 + s);
	glEnd();

}
void treeline(float x1, float y1, float z1, float x11, float y11, float z11, float h) {
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WHITE);
	glBegin(GL_LINES);
	int s = 10;
	glColor3f(1, 1, 1);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(-x1 + s, y1, 0 + s);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(0 + s, y1, z1 + s);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(x1 + s, y1, 0 + s);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(0 + s, y1, -z1 + s);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(-x11 + s, y11, -z11 + s);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(-x11 + s, y11, z11 + s);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(x11 + s, y11, z11 + s);
	glVertex3f(0 + s, h, 0 + s);
	glVertex3f(x11 + s, y11, -z11 + s);
	glEnd();
}
void polygon(int a, int b, int c, int d)
{
	GLfloat Br[] = { 0.3, 0.23, 0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Br);
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}
void colorcube()
{
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);
	root_line();
}
class Camera {
	double theta;      // determines the x and z positions
	double y;          // the current y position
	double dTheta;     // increment in theta for swinging the camera around
	double dy;         // increment in y for moving the camera up/down
public:
	Camera() : theta(0), y(10), dTheta(0.04), dy(0.4) {}
	double getX() { return 25 * sin(theta); }
	double getY() { return y; }
	double getZ() { return 25 * cos(theta); }
	void moveRight() { theta += dTheta; }
	void moveLeft() { theta -= dTheta; }
	void moveUp() { y += dy; }
	void moveDown() { if (y > dy) y -= dy; }
};
class Checkerboard {
	int displayListId;
	int width;
	int depth;

public:
	Checkerboard(int width, int depth) : width(width), depth(depth) {};
	double centerx() { return width / 2; }
	double centerz() { return depth / 2; }
	void create() {
		displayListId = glGenLists(1);
		glNewList(displayListId, GL_COMPILE);
		GLfloat lightPosition[] = { 3, 15, 5, 1 }, lightPosition1[] = {30,20,0,0};
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);
		glNormal3d(0, 1, 0);
		colorcube();
		float x1 = 5, y1 = 3, z1 = 5, x11 = 3.8, y11 = 3, z11 = 3.5, h = 6;
		treeleaf(x1, y1, z1, x11, y11, z11, h);
		treeline(x1, y1, z1, x11, y11, z11, h);
		float x3 = 4, y3 = 5, z3 = 4, x33 = 3, y33 = 4.9, z33 = 3, h3 = 9;
		treeleaf(x3, y3, z3, x33, y33, z33, h3);
		treeline(x3, y3, z3, x33, y33, z33, h3);
		float x2 = 3, y2 = 7, z2 = 3, x22 = 2.5, y22 = 7, z22 = 2.5, h2 = 11;
		treeleaf(x2, y2, z2, x22, y22, z22, h2);
		treeline(x2, y2, z2, x22, y22, z22, h2);
		glBegin(GL_QUADS);
		for (int x = 0; x < width - 1; x++) {
			for (int z = 0; z < depth - 1; z++) {
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
					(x + z) % 2 == 0 ? RED : WHITE);
				glVertex3d(x, 0, z);
				glVertex3d(x + 1.0, 0, z);
				glVertex3d(x + 1.0, 0, z + 1.0);
				glVertex3d(x, 0, z + 1.0);
			}
		}
		glEnd();
		glEndList();
	}
	void draw() {
		glCallList(displayListId);
	}
};
void timer(int v) {
	glutPostRedisplay();
	glutTimerFunc(100 / 60, timer, v);
}
Checkerboard checkerboard(20, 20);
Camera camera;

void special(int key, int, int) {
	switch (key) {
	case GLUT_KEY_LEFT: camera.moveLeft(); break;
	case GLUT_KEY_RIGHT: camera.moveRight(); break;
	case GLUT_KEY_UP: camera.moveUp(); break;
	case GLUT_KEY_DOWN: camera.moveDown(); break;
	}
	glutPostRedisplay();
}
bool ctrl_light2 = 0, ctrl_light1 = 0;
void mainMenu(int id) {
	switch (id)
	{
	case 1:
		ctrl_light1 ^= 1;
		if (ctrl_light1) glEnable(GL_LIGHT0);//啟動 N 號 光源
		else glDisable(GL_LIGHT0);break;
	case 2:
		ctrl_light2 ^= 1;
		if (ctrl_light2) glEnable(GL_LIGHT1);
		else glDisable(GL_LIGHT1);break;
	case 3:
		Decorate ^= 1;break;
	default:
		break;
	}
}
void creatMenu() {
	
	int menu = glutCreateMenu(mainMenu);//主選單
	glutAddMenuEntry("Light1 on/off ", 1);
	glutAddMenuEntry("Light2 on/off ", 2);
	glutAddMenuEntry("Decorate", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);//右鍵開選單
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(camera.getX(), camera.getY(), camera.getZ(), checkerboard.centerx(), 0.0, checkerboard.centerz(), 0.0, 1.0, 0.0);
	checkerboard.draw();
	if (Decorate ==1)
	for (int i = 0; i < sizeof balls / sizeof(Ball); i++) {
		balls[i].showball();
	}
	glFlush();
	glutSwapBuffers();
}
void init() {
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);//建立光源 ( 光源代號 , 光源特性 , )
	glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);//特性: 鏡面反射
	glMaterialfv(GL_FRONT, GL_SPECULAR,WHITE); 
	glMaterialf(GL_FRONT, GL_SHININESS, 30);
	glEnable(GL_LIGHTING);//啟動光源

	GLfloat sun_mat_emission[] = { 0.0f, 0.0f, 0.8f, 0.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, sun_mat_emission);//建立光源 ( 光源代號 , 光源特性 , )
	glLightfv(GL_LIGHT1, GL_SPECULAR, sun_mat_emission);
	glLightfv(GL_LIGHT1, GL_CONSTANT_ATTENUATION, sun_mat_emission);// 光線按照熱衰減
	glLightf(GL_LIGHT1, GL_SPOT_DIRECTION,Light);
	glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);
	checkerboard.create();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("s10859047");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special);//回應鍵盤
	creatMenu();
	glutTimerFunc(100, timer, 0);
	init();
	glutMainLoop();
}