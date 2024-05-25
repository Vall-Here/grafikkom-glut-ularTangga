#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>


const int BOARD_WIDTH = 7;
int player1Position = 1;
int player2Position = 1;
int currentPlayer = 2;

const int rows = 12;
const int cols = 7;
int diceResult = 0;

// void drawFour(float xAtas, float yBawah , float z) {
//     glColor3f(0.0,0.0,0.0);
//     glBegin(GL_POLYGON);
//     glVertex3f(0.9 + xAtas, 0.6 + yBawah, z);
//     glVertex3f(0.85 + xAtas, 0.6 + yBawah, z);
//     glVertex3f(0.85 + xAtas, 0.90 + yBawah, z);
//     glVertex3f(0.9 + xAtas, 0.90 + yBawah, z);
//     glEnd();

//     glBegin(GL_POLYGON);
//     glVertex3f(0.9 + xAtas, 0.90 + yBawah, z);
//     glVertex3f(0.85 + xAtas, 0.90 + yBawah, z);
//     glVertex3f(0.75 + xAtas, 0.72 + yBawah, z);
//     glVertex3f(0.78 + xAtas, 0.72 + yBawah, z);
//     glEnd();

//     glBegin(GL_POLYGON);
//     glVertex3f(0.78 + xAtas, 0.76 + yBawah, z);
//     glVertex3f(0.75 + xAtas, 0.71 + yBawah, z);
//     glVertex3f(0.9 + xAtas, 0.71 + yBawah, z);
//     glVertex3f(0.9 + xAtas, 0.76 + yBawah, z);
//     glEnd();
// }


// void drawSix(float xAtas, float yBawah, float z) {
//     glColor3f(0.0,0.0,0.0);
//     glBegin(GL_POLYGON);

//     glVertex3f(xAtas + 0.9f, yBawah + 0.9f, z);
//     glVertex3f(xAtas + 0.9f, yBawah + 0.85f, z);
//     glVertex3f(xAtas + 0.75f, yBawah + 0.85f, z);
//     glVertex3f(xAtas + 0.75f, yBawah + 0.9f, z);
//     glEnd();

//     glBegin(GL_POLYGON);
//     glVertex3f(xAtas + 0.75f, yBawah + 0.9f, z);
//     glVertex3f(xAtas + 0.75f, yBawah + 0.6f, z);
//     glVertex3f(xAtas + 0.8f, yBawah + 0.6f, z);
//     glVertex3f(xAtas + 0.8f, yBawah + 0.9f, z);
//     glEnd();

//     glBegin(GL_POLYGON);
//     glVertex3f(xAtas + 0.8f, yBawah + 0.6f, z);
//     glVertex3f(xAtas + 0.9f, yBawah + 0.6f, z);
//     glVertex3f(xAtas + 0.9f, yBawah + 0.65f, z);
//     glVertex3f(xAtas + 0.8f, yBawah + 0.65f,z);
//     glEnd();

//     glBegin(GL_POLYGON);
//     glVertex3f(xAtas + 0.9f, yBawah + 0.75f, z);
//     glVertex3f(xAtas + 0.9f, yBawah + 0.6f, z);
//     glVertex3f(xAtas + 0.85f, yBawah + 0.6f, z);
//     glVertex3f(xAtas + 0.85f, yBawah + 0.75f, z);
//     glEnd();

//     glBegin(GL_POLYGON);
//     glVertex3f(xAtas + 0.9f, yBawah + 0.75f, z);
//     glVertex3f(xAtas + 0.8f, yBawah + 0.75f, z);
//     glVertex3f(xAtas + 0.8f, yBawah + 0.7f, z);
//     glVertex3f(xAtas + 0.9f, yBawah + 0.7f, z);
//     glEnd();
// }






void drawBoard() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();


    //glRotatef(25, 1, 0, 0);

    //kotak 1
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5); // Merah
        glVertex3f(0,0,0.5);
        glVertex3f(1,0,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(0,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); // Hijau
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(1,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(0,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(1,0,0.5);
        glVertex3f(1,0,0);
    glEnd();
    glPopMatrix();

    //kotak 2
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5); // Merah
        glVertex3f(1,0,0.5);
        glVertex3f(2,0,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(1,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5); // Hijau
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(2,1,0);
        glVertex3f(2,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(2,0,0);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(2,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(1,0,0);
        glVertex3f(1,0,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(1,0,0);
        glVertex3f(1,0,0.5);
        glVertex3f(2,0,0.5);
        glVertex3f(2,0,0);
    glEnd();
    glPopMatrix();

    //kotak 3
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5); // Merah
        glVertex3f(2,0,0.5);
        glVertex3f(3,0,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(2,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); // Hijau
        glVertex3f(2,0,0);
        glVertex3f(2,1,0);
        glVertex3f(3,1,0);
        glVertex3f(3,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,0,0);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(2,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(2,0,0);
        glVertex3f(2,0,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,0,0);
        glVertex3f(2,0,0.5);
        glVertex3f(3,0,0.5);
        glVertex3f(3,0,0);
    glEnd();
    glPopMatrix();

    //kotak 4
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5); // Merah
        glVertex3f(3,0,0.5);
        glVertex3f(4,0,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(3,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5); // Hijau
        glVertex3f(3,0,0);
        glVertex3f(3,1,0);
        glVertex3f(4,1,0);
        glVertex3f(4,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(3,0,0);
        glVertex3f(3,1,0);
        glVertex3f(3,1,0.5);
        glVertex3f(3,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(3,0,0);
        glVertex3f(3,0,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(3,1,0);
        glVertex3f(3,1,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(4,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(3,0,0);
        glVertex3f(3,0,0.5);
        glVertex3f(4,0,0.5);
        glVertex3f(4,0,0);
    glEnd();
    glPopMatrix();

    //kotak 5
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5); // Merah
        glVertex3f(4,0,0.5);
        glVertex3f(5,0,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(4,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); // Hijau
        glVertex3f(4,0,0);
        glVertex3f(4,1,0);
        glVertex3f(5,1,0);
        glVertex3f(4,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,0,0);
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(4,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(4,0,0);
        glVertex3f(4,0,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(4,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(4,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,0,0);
        glVertex3f(4,0,0.5);
        glVertex3f(5,0,0.5);
        glVertex3f(5,0,0);
    glEnd();
    glPopMatrix();

    //kotak 8
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(1,1,0.5);  // Merah
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(4,2,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);  // Hijau
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(5,2,0);
        glVertex3f(4,1,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,1,0.5); 
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(4,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,1,0.5); 
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5); 
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5); 
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,1,0);
    glEnd();
    glPopMatrix();







    glFlush();
}



void reshape(int w, int h) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 12, -5, 17, 5, -5);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ular Tangga");
    glutReshapeFunc(reshape);
    glutDisplayFunc(drawBoard);


    glClearColor(0, 0, 0, 0);
    glutMainLoop();
    return 0;
}

