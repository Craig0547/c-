
#include <GL/glut.h>

float player_x = 0.0f;
float player_y = 0.0f;
float player_angle = 0.0f;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 0.1, 100);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // set camera position and orientation
    gluLookAt(player_x, player_y, 0,
              player_x + cos(player_angle), player_y + sin(player_angle), 0,
              0, 0, 1);

    // draw floor and ceiling
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-10.0f, -10.0f, 0.0f);
    glVertex3f(10.0f, -10.0f, 0.0f);
    glVertex3f(10.0f, 10.0f, 0.0f);
    glVertex3f(-10.0f, 10.0f, 0.0f);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0f, -10.0f, 3.0f);
    glVertex3f(10.0f, -10.0f, 3.0f);
    glVertex3f(10.0f, 10.0f, 3.0f);
    glVertex3f(-10.0f, 10.0f, 3.0f);
    glEnd();

    // draw walls
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, -5.0f, 0.0f);
    glVertex3f(-5.0f, 5.0f, 0.0f);
    glVertex3f(-5.0f, 5.0f, 3.0f);
    glVertex3f(-5.0f, -5.0f, 3.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(5.0f, -5.0f, 0.0f);
    glVertex3f(5.0f, 5.0f, 0.0f);
    glVertex3f(5.0f, 5.0f, 3.0f);
    glVertex3f(5.0f, -5.0f, 3.0f);
    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            player_x += 0.1f * cos(player_angle);
            player_y += 0.1f * sin(player_angle);
            break;
        case 's':
            player_x -= 0.1f *cos(player_angle);
            player_y -= 0.1f * sin(player_angle);
break;
case 'a':
player_angle -= 0.1f;
break;
case 'd':
player_angle += 0.1f;
break;
case ' ':
// shoot
break;
}
glutPostRedisplay();
}

int main(int argc, char **argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(640, 640);
glutCreateWindow("Doom clone");
glutDisplayFunc(draw);
glutKeyboardFunc(keyboard);

glEnable(GL_DEPTH_TEST);

init();

glutMainLoop();
return 0;
}

