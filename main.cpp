#include "GL/freeglut.h"
#include "GL/gl.h"
#include "math.h"

float WinWid = 400.0;
float WinHei = 400.0;

float Angel[2] = { 0.0, 0.0 } ;

float WinWid2 = 300.0;
float WinHei2 = 300.0;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(Angel[0], 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    for(float i = -WinWid/2; i<= WinWid/2; i+=20.0) {
        glVertex2f(i, -WinHei/2);
        glVertex2f(i, WinHei/2);
    }
    for(float i = -WinHei/2; i<= WinHei/2; i+=20.0) {
        glVertex2f(-WinWid/2, i);
        glVertex2f(WinWid/2, i);
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void Draw2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(Angel[1], 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    for(float i = -WinWid2/2; i<= WinWid2/2; i+=20.0) {
        glVertex2f(i, -WinHei2/2);
        glVertex2f(i, WinHei2/2);
    }
    for(float i = -WinHei2/2; i<= WinHei2/2; i+=20.0) {
        glVertex2f(-WinWid2/2, i);
        glVertex2f(WinWid2/2, i);
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void Timer(int value) {
    glColor3f(1.0, 1.0, 1.0);
    ++Angel[value];
    glutPostRedisplay();
    glutTimerFunc(50, Timer, value);
}

void Init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

void Init2() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid2/2, WinWid2/2, -WinHei2/2, WinHei2/2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    
    int hwnd = glutCreateWindow("Lesson 15");
    glutDisplayFunc(Draw);
    glutTimerFunc(50, Timer, 0);
    Init();
    
    glutInitWindowSize(WinWid2, WinHei2);
    glutInitWindowPosition(150, 250);
    int hwnd2 = glutCreateWindow("Window");
    glutDisplayFunc(Draw2);
    glutTimerFunc(50, Timer, 1);

    glutSetWindow(hwnd);
    glutReshapeWindow(500, 300);
    glutPositionWindow(200, 100);
    glutSetWindow(hwnd2);
//    int f = glutGetWindow();
    Init2();
    
//    glutDestroyWindow(hwnd2);
    
    glutMainLoop();
    
    return 0;
}
