#include <GL/glut.h>
#include <stdio.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

float angle = 0.0f;

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -5.0f);
  glRotatef(angle, 1.0f, 1.0f, 1.0f);

  glutSolidCube(2.0f);

  glFlush();
  glutSwapBuffers();
}

void idle() {
  angle += 0.1f;
  if (angle > 360.0f) {
    angle -= 360.0f;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow("Animated Cube");
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;
}
