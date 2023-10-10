#include <GL/glut.h>
#include <windows.h>
#include <cmath>
#include <cstdlib>
#include <ctime>


void myWireSphere(GLfloat radius, int slices, int stacks) {
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glutWireSphere(radius, slices, stacks);
  glPopMatrix();
}

double year = 0, day = 0;

void drawSun() {
// Draw the core of the Sun as a red wireframe sphere.
glColor3f(1.0, 0.0, 0.0);
glutSolidSphere(0.2, 30, 30);

// Draw the radiative zone as a orange wireframe sphere.
glColor3f(1.0, 0.5, 0.0);
myWireSphere(0.4, 30, 30);

// Draw the convective zone as an yellow wireframe sphere.
glColor3f(1.0, 1.0, 0.0);
myWireSphere(0.6, 30, 30);

// Draw the photosphere as a white wireframe sphere.
glColor3f(1.0, 1.0, 1.0);
myWireSphere(0.8, 30, 30);

// Draw the chromosphere as a yellow wireframe sphere.
glColor3f(1.0, 1.0, 0.0);
myWireSphere(1.0, 30, 30);

// Draw the corona as a orange wireframe sphere.
glColor3f(1.0, 0.5, 0.0);
myWireSphere(1.2, 30, 30);
}

float getRandomPosition() {
    return (float)rand() / (float)RAND_MAX * 100.0f - 50.0f;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

srand(time(NULL));

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);

    for (int i = 0; i < 5000; i++) {
        float x = getRandomPosition();
        float y = getRandomPosition();
        float z = getRandomPosition();
        glVertex3f(x, y, z);

    }

    glEnd();

    // Draw the sun
    drawSun();

    // Set parameters for the planet Mercury
    glRotatef((GLfloat)year, 0.0, 10.0, 0.0);
    glTranslatef(4, 0.0, 0.0);
    glColor3f(0.5, 0.5, 0.5); // gray-brown or beige color
    glutSolidSphere(0.1, 30, 30);
glEnd();
    // Set parameters for the planet Venus
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(5, 0.0, 0.0);
    glColor3f(1.0f, 0.5f, 0.0f); // yellow-pale or orange color
    glutSolidSphere(0.12, 30, 30);
glEnd();
    // Set parameters for the planet Earth
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(8, 0.0, 0.0);
    glColor3f(0.0f, 0.5f, 0.5f); // blue-green color
    glutSolidSphere(0.5, 30, 30);
glEnd();
    // Set parameters for the planet Mars
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(9, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f); // red color
    glutSolidSphere(0.27, 30, 30);
glEnd();
    // Set parameters for the planet Jupiter
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(10.5, 0.0, 0.0);
    glColor3f(0.5f, 0.5f, 0.5f); // gray-brown or beige color
    glutSolidSphere(1, 30, 30);
glEnd();
    // Set parameters for the planet Saturn
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(15.5, 0.0, 0.0);
    glColor3f(0.8f, 0.7f, 0.6f); // pale yellow or beige color
    glutSolidSphere(0.65, 30, 30);
    glColor3f(250, 250, 250);
        glBegin(GL_LINES);
            glVertex3f(0, -1.2, 0);
            glVertex3f(0, 1.2, 0);
glEnd();

    // Set parameters for the planet Uranus
    glRotatef((GLfloat)year , 0.0, 1.0, 0.0);
    glTranslatef(20.5, 0.0, 0.0);
    glColor3f(0.5f, 0.8f, 0.8f); // pale blue or green-blue color
    glutSolidSphere(0.9, 30, 30);
glEnd();
    // Set parameters for the planet Neptune
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef(23.5, 0.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.5f); // dark blue color
    glutSolidSphere(0.8, 30, 30);
glEnd();
    // Draw the planet Pluto
    glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
    glTranslatef (25, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.1, 30, 30);
glEnd();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

static GLfloat u = 0.01;
static GLfloat du = 0.03;

void timer(int v) {
  u += du;
  day = fmod(day + 0.2, 360.0);
  year = fmod(year + 0.2, 360.0);
  glLoadIdentity();
  gluLookAt(20*cos(u/8.0)+12,5*sin(u/8.0)+1,10*cos(u/8.0)+2, 0,1,0, 0,1,0);
  glutPostRedisplay();
  glutTimerFunc(20, timer, v);
}

void reshape(GLint w, GLint h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
GLfloat aspect = (GLfloat) w / (GLfloat) h;
GLfloat fov = 120.0f;
GLfloat neaar = 1.0f;
GLfloat right = tan(fov / 2.0f) * neaar;
GLfloat top = right / aspect;
glFrustum(-right, right, -top, top, neaar, 100.0f);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1366,768);
  glutCreateWindow("Sistemul solar");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(1, timer, 1000);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
}
