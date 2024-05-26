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

float rotateX = 0.0f;
float rotateY = 0.0f;

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


void drawKotak(){
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

    //kotak 6
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(1,1,0.5);  // Merah
        glVertex3f(5,1,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(6,0,0.5);
        glVertex3f(5,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);  // Merah
        glVertex3f(5,1,0);
        glVertex3f(6,1,0);
        glVertex3f(6,0,0);
        glVertex3f(5,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,1,0.5);
        glVertex3f(6,0,0);
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(6,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,1,0.5);
        glVertex3f(5,0,0);
        glVertex3f(5,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,0,0);
    glEnd();
     glBegin(GL_POLYGON);
            // Sisi atas
            glColor3f(1,1,0.5);
            glVertex3f(5,1,0);
            glVertex3f(5,1,0.5);
            glVertex3f(6,1,0.5);
            glVertex3f(6,1,0);
        glEnd();
         glBegin(GL_POLYGON);
            // Sisi atas
            glColor3f( 1 ,1,0.5);
            glVertex3f(5,0,0);
            glVertex3f(5,0,0.5);
            glVertex3f(6,0,0.5);
            glVertex3f(6,0,0);
        glEnd();
    glPopMatrix();

    //kotak 7
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5); // Merah
        glVertex3f(6,0,0.5);
        glVertex3f(7,0,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(6,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); // Hijau
        glVertex3f(6,0,0);
        glVertex3f(6,1,0);
        glVertex3f(7,1,0);
        glVertex3f(6,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(7,0,0);
        glVertex3f(7,1,0);
        glVertex3f(7,1,0.5);
        glVertex3f(7,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(6,0,0);
        glVertex3f(6,0,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(6,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(6,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,0,0);
        glVertex3f(6,0,0.5);
        glVertex3f(7,0,0.5);
        glVertex3f(7,0,0);
    glEnd();
    glPopMatrix();
    //kotak 8
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5); // Merah
        glVertex3f(6,1,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(6,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5); // Hijau
        glVertex3f(6,1,0);
        glVertex3f(6,2,0);
        glVertex3f(7,2,0);
        glVertex3f(6,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(7,1,0);
        glVertex3f(7,2,0);
        glVertex3f(7,2,0.5);
        glVertex3f(7,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(6,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(6,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(7,1,0);
    glEnd();
    glPopMatrix();

    //kotak 9
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(0.5,1,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(5,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(0.5,1,0.5);
        glVertex3f(5,2,0);
        glVertex3f(6,2,0);
        glVertex3f(6,1,0);
        glVertex3f(5,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(0.5,1,0.5);
        glVertex3f(6,1,0);
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(6,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(0.5,1,0.5);
        glVertex3f(5,1,0);
        glVertex3f(5,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,2,0);
    glEnd();
    glPopMatrix();

    //kotak 10
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(4,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(5,2,0);
        glVertex3f(4,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(4,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,1,0);
    glEnd();
    glPopMatrix();

    //kotak 11
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(3,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(3,1,0);
        glVertex3f(3,2,0);
        glVertex3f(4,2,0);
        glVertex3f(4,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,1,0);
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(3,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(3,1,0);
        glVertex3f(3,1,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,1,0);
        glVertex3f(3,1,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(4,1,0);
    glEnd();
    glPopMatrix();

    //kotak 12
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(2,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,2,0);
        glVertex3f(3,2,0);
        glVertex3f(3,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(2,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,1,0);
    glEnd();
    glPopMatrix();

    //kotak 13
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(1,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(1,1,0);
        glVertex3f(1,2,0);
        glVertex3f(2,2,0);
        glVertex3f(2,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(2,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,1,0);
    glEnd();
    glPopMatrix();

    //kotak 14
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(0,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(0,1,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(1,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(1,1,0);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(1,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(0,2,0.5);
        glVertex3f(0,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,1,0);
    glEnd();
    glPopMatrix();

    //kotak 21
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5); // Merah
        glVertex3f(6,2,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(6,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); // Hijau
        glVertex3f(6,2,0);
        glVertex3f(6,3,0);
        glVertex3f(7,3,0);
        glVertex3f(6,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(7,2,0);
        glVertex3f(7,3,0);
        glVertex3f(7,3,0.5);
        glVertex3f(7,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(6,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(7,2,0);
    glEnd();
    glPopMatrix();

    //kotak 20
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(1,2,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(5,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,2,0.5);
        glVertex3f(5,3,0);
        glVertex3f(6,3,0);
        glVertex3f(6,2,0);
        glVertex3f(5,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,2,0.5);
        glVertex3f(6,2,0);
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(6,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,2,0.5);
        glVertex3f(5,2,0);
        glVertex3f(5,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,3,0);
    glEnd();
    glPopMatrix();

    //kotak 19
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(4,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,3,0);
        glVertex3f(5,3,0);
        glVertex3f(4,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(4,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,2,0);
    glEnd();
    glPopMatrix();

    //kotak 18
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(3,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(3,2,0);
        glVertex3f(3,3,0);
        glVertex3f(4,3,0);
        glVertex3f(4,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(3,2,0);
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(3,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
    glPopMatrix();

    //kotak 17
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(2,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,3,0);
        glVertex3f(3,3,0);
        glVertex3f(3,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(2,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,2,0);
    glEnd();
    glPopMatrix();

    //kotak 16
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(1,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(1,2,0);
        glVertex3f(1,3,0);
        glVertex3f(2,3,0);
        glVertex3f(2,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(2,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,2,0);
    glEnd();
    glPopMatrix();

    //kotak 15
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(0,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(0,2,0);
        glVertex3f(0,3,0);
        glVertex3f(1,3,0);
        glVertex3f(1,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,2,0);
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(1,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(0,3,0.5);
        glVertex3f(0,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,2,0);
    glEnd();
    glPopMatrix();

    //kotak 22
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(6,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(6,3,0);
        glVertex3f(6,4,0);
        glVertex3f(7,4,0);
        glVertex3f(6,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(7,3,0);
        glVertex3f(7,4,0);
        glVertex3f(7,4,0.5);
        glVertex3f(7,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(6,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(7,3,0);
    glEnd();
    glPopMatrix();

    //kotak 23
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(0.5,1,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(5,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(0.5,1,0.5);
        glVertex3f(5,4,0);
        glVertex3f(6,4,0);
        glVertex3f(6,3,0);
        glVertex3f(5,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(0.5,1,0.5);
        glVertex3f(6,3,0);
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(6,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(0.5,1,0.5);
        glVertex3f(5,3,0);
        glVertex3f(5,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,4,0);
    glEnd();
    glPopMatrix();

    //kotak 24
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(4,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,4,0);
        glVertex3f(5,4,0);
        glVertex3f(4,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(4,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,3,0);
    glEnd();
    glPopMatrix();

    //kotak 25
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(3,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(3,3,0);
        glVertex3f(3,4,0);
        glVertex3f(4,4,0);
        glVertex3f(4,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,3,0);
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(3,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
    glPopMatrix();

    //kotak 26
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(2,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,4,0);
        glVertex3f(3,4,0);
        glVertex3f(3,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(2,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,3,0);
    glEnd();
    glPopMatrix();

    //kotak 27
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(1,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(1,3,0);
        glVertex3f(1,4,0);
        glVertex3f(2,4,0);
        glVertex3f(2,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(2,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,3,0);
    glEnd();
    glPopMatrix();

    //kotak 28
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(0,3,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(0,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(0,3,0);
        glVertex3f(0,4,0);
        glVertex3f(1,4,0);
        glVertex3f(1,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(1,3,0);
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(1,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(0,4,0.5);
        glVertex3f(0,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,4,0);
        glVertex3f(0,4,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,3,0);
    glEnd();
    glPopMatrix();

    //kotak 35
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(6,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(6,4,0);
        glVertex3f(6,5,0);
        glVertex3f(7,5,0);
        glVertex3f(6,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(7,4,0);
        glVertex3f(7,5,0);
        glVertex3f(7,5,0.5);
        glVertex3f(7,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(6,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(7,4,0);
    glEnd();
    glPopMatrix();

    //kotak 34
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(1,2,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(5,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,2,0.5);
        glVertex3f(5,5,0);
        glVertex3f(6,5,0);
        glVertex3f(6,4,0);
        glVertex3f(5,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,2,0.5);
        glVertex3f(6,4,0);
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(6,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,2,0.5);
        glVertex3f(5,4,0);
        glVertex3f(5,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,5,0);
    glEnd();
    glPopMatrix();

    //kotak 33
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(4,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,5,0);
        glVertex3f(5,5,0);
        glVertex3f(4,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(4,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,4,0);
    glEnd();
    glPopMatrix();

    //kotak 32
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(3,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(3,4,0);
        glVertex3f(3,5,0);
        glVertex3f(4,5,0);
        glVertex3f(4,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(3,4,0);
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(3,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
    glPopMatrix();

    //kotak 31
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(2,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,5,0);
        glVertex3f(3,5,0);
        glVertex3f(3,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(2,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,4,0);
    glEnd();
    glPopMatrix();

    //kotak 30
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(1,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(1,4,0);
        glVertex3f(1,5,0);
        glVertex3f(2,5,0);
        glVertex3f(2,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(2,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,4,0);
    glEnd();
    glPopMatrix();

    //kotak 29
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(0,4,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(0,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(0,4,0);
        glVertex3f(0,5,0);
        glVertex3f(1,5,0);
        glVertex3f(1,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,4,0);
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(1,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(0,4,0);
        glVertex3f(0,4,0.5);
        glVertex3f(0,5,0.5);
        glVertex3f(0,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,5,0);
        glVertex3f(0,5,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,4,0);
        glVertex3f(0,4,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,4,0);
    glEnd();
    glPopMatrix();

    //kotak 36
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(6,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(6,5,0);
        glVertex3f(6,6,0);
        glVertex3f(7,6,0);
        glVertex3f(6,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(7,5,0);
        glVertex3f(7,6,0);
        glVertex3f(7,6,0.5);
        glVertex3f(7,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(6,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(7,5,0);
    glEnd();
    glPopMatrix();

    //kotak 37
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(0.5,1,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(5,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(0.5,1,0.5);
        glVertex3f(5,6,0);
        glVertex3f(6,6,0);
        glVertex3f(6,5,0);
        glVertex3f(5,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(0.5,1,0.5);
        glVertex3f(6,5,0);
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(6,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(0.5,1,0.5);
        glVertex3f(5,5,0);
        glVertex3f(5,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,6,0);
    glEnd();
    glPopMatrix();

    //kotak 38
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(4,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,6,0);
        glVertex3f(5,6,0);
        glVertex3f(4,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(4,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,5,0);
    glEnd();
    glPopMatrix();

    //kotak 39
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(3,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(3,5,0);
        glVertex3f(3,6,0);
        glVertex3f(4,6,0);
        glVertex3f(4,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,5,0);
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(3,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
    glPopMatrix();

    //kotak 40
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(2,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,6,0);
        glVertex3f(3,6,0);
        glVertex3f(3,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(2,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,5,0);
    glEnd();
    glPopMatrix();

    //kotak 41
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(1,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(1,5,0);
        glVertex3f(1,6,0);
        glVertex3f(2,6,0);
        glVertex3f(2,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(2,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,5,0);
    glEnd();
    glPopMatrix();

    //kotak 42
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(0,5,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(0,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(0,5,0);
        glVertex3f(0,6,0);
        glVertex3f(1,6,0);
        glVertex3f(1,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(1,5,0);
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(1,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(0,5,0);
        glVertex3f(0,5,0.5);
        glVertex3f(0,6,0.5);
        glVertex3f(0,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,6,0);
        glVertex3f(0,6,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,5,0);
        glVertex3f(0,5,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,5,0);
    glEnd();
    glPopMatrix();

    //kotak 49
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(6,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(6,6,0);
        glVertex3f(6,7,0);
        glVertex3f(7,7,0);
        glVertex3f(6,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(7,6,0);
        glVertex3f(7,7,0);
        glVertex3f(7,7,0.5);
        glVertex3f(7,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(6,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(7,6,0);
    glEnd();
    glPopMatrix();

    //kotak 48
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(1,2,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(5,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,2,0.5);
        glVertex3f(5,7,0);
        glVertex3f(6,7,0);
        glVertex3f(6,6,0);
        glVertex3f(5,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,2,0.5);
        glVertex3f(6,6,0);
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(6,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,2,0.5);
        glVertex3f(5,6,0);
        glVertex3f(5,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,7,0);
    glEnd();
    glPopMatrix();

    //kotak 47
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(4,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,7,0);
        glVertex3f(5,7,0);
        glVertex3f(4,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(4,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,6,0);
    glEnd();
    glPopMatrix();

    //kotak 46
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(3,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(3,6,0);
        glVertex3f(3,7,0);
        glVertex3f(4,7,0);
        glVertex3f(4,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(3,6,0);
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(3,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
    glPopMatrix();

    //kotak 45
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(2,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,7,0);
        glVertex3f(3,7,0);
        glVertex3f(3,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(2,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,6,0);
    glEnd();
    glPopMatrix();

    //kotak 44
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(1,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(1,6,0);
        glVertex3f(1,7,0);
        glVertex3f(2,7,0);
        glVertex3f(2,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(2,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,6,0);
    glEnd();
    glPopMatrix();

    //kotak 43
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(0,6,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(0,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(0,6,0);
        glVertex3f(0,7,0);
        glVertex3f(1,7,0);
        glVertex3f(1,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,6,0);
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(1,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(0,6,0);
        glVertex3f(0,6,0.5);
        glVertex3f(0,7,0.5);
        glVertex3f(0,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,7,0);
        glVertex3f(0,7,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,6,0);
        glVertex3f(0,6,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,6,0);
    glEnd();
    glPopMatrix();

//kotak 50
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(6,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(6,7,0);
        glVertex3f(6,8,0);
        glVertex3f(7,8,0);
        glVertex3f(6,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(7,7,0);
        glVertex3f(7,8,0);
        glVertex3f(7,8,0.5);
        glVertex3f(7,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(6,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(7,7,0);
    glEnd();
    glPopMatrix();

    //kotak 51
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(0.5,1,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(5,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(0.5,1,0.5);
        glVertex3f(5,8,0);
        glVertex3f(6,8,0);
        glVertex3f(6,7,0);
        glVertex3f(5,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(0.5,1,0.5);
        glVertex3f(6,7,0);
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(6,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(0.5,1,0.5);
        glVertex3f(5,7,0);
        glVertex3f(5,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,8,0);
    glEnd();
    glPopMatrix();

    //kotak 52
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(4,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,8,0);
        glVertex3f(5,8,0);
        glVertex3f(4,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(4,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,7,0);
    glEnd();
    glPopMatrix();

    //kotak 53
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(3,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(3,7,0);
        glVertex3f(3,8,0);
        glVertex3f(4,8,0);
        glVertex3f(4,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,7,0);
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(3,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
    glPopMatrix();

    //kotak 54
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(2,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,8,0);
        glVertex3f(3,8,0);
        glVertex3f(3,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(2,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,7,0);
    glEnd();
    glPopMatrix();

    //kotak 55
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(1,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(1,7,0);
        glVertex3f(1,8,0);
        glVertex3f(2,8,0);
        glVertex3f(2,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(2,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,7,0);
    glEnd();
    glPopMatrix();

    //kotak 56
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(0,7,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(0,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(0,7,0);
        glVertex3f(0,8,0);
        glVertex3f(1,8,0);
        glVertex3f(1,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(1,7,0);
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(1,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(0,7,0);
        glVertex3f(0,7,0.5);
        glVertex3f(0,8,0.5);
        glVertex3f(0,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,8,0);
        glVertex3f(0,8,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,7,0);
        glVertex3f(0,7,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,7,0);
    glEnd();
    glPopMatrix();

    //kotak 63
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(6,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(6,8,0);
        glVertex3f(6,9,0);
        glVertex3f(7,9,0);
        glVertex3f(6,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(7,8,0);
        glVertex3f(7,9,0);
        glVertex3f(7,9,0.5);
        glVertex3f(7,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(6,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(7,8,0);
    glEnd();
    glPopMatrix();

    //kotak 62
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(1,2,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(5,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,2,0.5);
        glVertex3f(5,9,0);
        glVertex3f(6,9,0);
        glVertex3f(6,8,0);
        glVertex3f(5,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,2,0.5);
        glVertex3f(6,8,0);
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(6,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,2,0.5);
        glVertex3f(5,8,0);
        glVertex3f(5,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,9,0);
    glEnd();
    glPopMatrix();

    //kotak 61
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(4,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,9,0);
        glVertex3f(5,9,0);
        glVertex3f(4,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(4,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,8,0);
    glEnd();
    glPopMatrix();

    //kotak 60
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(3,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(3,8,0);
        glVertex3f(3,9,0);
        glVertex3f(4,9,0);
        glVertex3f(4,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(3,8,0);
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(3,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
    glPopMatrix();

    //kotak 59
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(2,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,9,0);
        glVertex3f(3,9,0);
        glVertex3f(3,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(2,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,8,0);
    glEnd();
    glPopMatrix();

    //kotak 58
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(1,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(1,8,0);
        glVertex3f(1,9,0);
        glVertex3f(2,9,0);
        glVertex3f(2,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(2,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,8,0);
    glEnd();
    glPopMatrix();

    //kotak 57
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(0,8,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(0,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(0,8,0);
        glVertex3f(0,9,0);
        glVertex3f(1,9,0);
        glVertex3f(1,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,8,0);
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(1,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(0,8,0);
        glVertex3f(0,8,0.5);
        glVertex3f(0,9,0.5);
        glVertex3f(0,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,9,0);
        glVertex3f(0,9,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,8,0);
        glVertex3f(0,8,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,8,0);
    glEnd();
    glPopMatrix();

    //kotak 64
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(6,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(6,9,0);
        glVertex3f(6,10,0);
        glVertex3f(7,10,0);
        glVertex3f(6,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(7,9,0);
        glVertex3f(7,10,0);
        glVertex3f(7,10,0.5);
        glVertex3f(7,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(7,9,0);
    glEnd();
    glPopMatrix();

    //kotak 65
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(0.5,1,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(5,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(0.5,1,0.5);
        glVertex3f(5,10,0);
        glVertex3f(6,10,0);
        glVertex3f(6,9,0);
        glVertex3f(5,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(0.5,1,0.5);
        glVertex3f(6,9,0);
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(6,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(0.5,1,0.5);
        glVertex3f(5,9,0);
        glVertex3f(5,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,10,0);
    glEnd();
    glPopMatrix();

    //kotak 66
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(4,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,10,0);
        glVertex3f(5,10,0);
        glVertex3f(4,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(4,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,9,0);
    glEnd();
    glPopMatrix();

    //kotak 67
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(3,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(3,9,0);
        glVertex3f(3,10,0);
        glVertex3f(4,10,0);
        glVertex3f(4,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,9,0);
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(3,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
    glPopMatrix();

    //kotak 68
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(2,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,10,0);
        glVertex3f(3,10,0);
        glVertex3f(3,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(2,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,9,0);
    glEnd();
    glPopMatrix();

    //kotak 69
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(1,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(1,9,0);
        glVertex3f(1,10,0);
        glVertex3f(2,10,0);
        glVertex3f(2,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(2,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,9,0);
    glEnd();
    glPopMatrix();

    //kotak 70
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(0,9,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(0,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(0,9,0);
        glVertex3f(0,10,0);
        glVertex3f(1,10,0);
        glVertex3f(1,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(1,9,0);
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(1,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(0,9,0);
        glVertex3f(0,9,0.5);
        glVertex3f(0,10,0.5);
        glVertex3f(0,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,10,0);
        glVertex3f(0,10,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,9,0);
        glVertex3f(0,9,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,9,0);
    glEnd();
    glPopMatrix();


    //kotak 77
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(6,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(6,10,0);
        glVertex3f(6,11,0);
        glVertex3f(7,11,0);
        glVertex3f(6,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(7,10,0);
        glVertex3f(7,11,0);
        glVertex3f(7,11,0.5);
        glVertex3f(7,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(6,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(7,10,0);
    glEnd();
    glPopMatrix();

    //kotak 76
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(1,2,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(5,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,2,0.5);
        glVertex3f(5,11,0);
        glVertex3f(6,11,0);
        glVertex3f(6,10,0);
        glVertex3f(5,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,2,0.5);
        glVertex3f(6,10,0);
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(6,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,2,0.5);
        glVertex3f(5,10,0);
        glVertex3f(5,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,2,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,11,0);
    glEnd();
    glPopMatrix();

    //kotak 75
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(4,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,11,0);
        glVertex3f(5,11,0);
        glVertex3f(4,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(4,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,10,0);
    glEnd();
    glPopMatrix();

    //kotak 74
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(3,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(3,10,0);
        glVertex3f(3,11,0);
        glVertex3f(4,11,0);
        glVertex3f(4,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(3,10,0);
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(3,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
    glPopMatrix();

    //kotak 73
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(2,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,11,0);
        glVertex3f(3,11,0);
        glVertex3f(3,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(2,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,10,0);
    glEnd();
    glPopMatrix();

    //kotak 72
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(1,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(1,10,0);
        glVertex3f(1,11,0);
        glVertex3f(2,11,0);
        glVertex3f(2,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(2,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,10,0);
    glEnd();
    glPopMatrix();

    //kotak 71
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(0,10,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(0,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(0,10,0);
        glVertex3f(0,11,0);
        glVertex3f(1,11,0);
        glVertex3f(1,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,10,0);
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(1,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(0,10,0);
        glVertex3f(0,10,0.5);
        glVertex3f(0,11,0.5);
        glVertex3f(0,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(0,10,0);
        glVertex3f(0,10,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,10,0);
    glEnd();
    glPopMatrix();


    //kotak 78
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(7,12,0.5);
        glVertex3f(6,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(6,11,0);
        glVertex3f(6,12,0);
        glVertex3f(7,12,0);
        glVertex3f(6,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(7,11,0);
        glVertex3f(7,12,0);
        glVertex3f(7,12,0.5);
        glVertex3f(7,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,12,0);
        glVertex3f(6,12,0.5);
        glVertex3f(7,12,0.5);
        glVertex3f(6,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(7,11,0);
    glEnd();
    glPopMatrix();

    //kotak 79
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
         glColor3f(0.5,1,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(5,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(0.5,1,0.5);
        glVertex3f(5,12,0);
        glVertex3f(6,12,0);
        glVertex3f(6,11,0);
        glVertex3f(5,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(0.5,1,0.5);
        glVertex3f(6,11,0);
        glVertex3f(6,12,0);
        glVertex3f(6,12,0.5);
        glVertex3f(6,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(0.5,1,0.5);
        glVertex3f(5,11,0);
        glVertex3f(5,12,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(5,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(4,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(5,12,0);
    glEnd();
    glPopMatrix();

    //kotak 80
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(4,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,12,0);
        glVertex3f(5,12,0);
        glVertex3f(4,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(4,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(4,12,0.5);
        glVertex3f(4,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(4,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,11,0);
    glEnd();
    glPopMatrix();

    //kotak 81
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,12,0.5);
        glVertex3f(3,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(3,11,0);
        glVertex3f(3,12,0);
        glVertex3f(4,12,0);
        glVertex3f(4,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(3,11,0);
        glVertex3f(3,12,0);
        glVertex3f(3,12,0.5);
        glVertex3f(3,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(3,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,12,0);
        glVertex3f(3,12,0.5);
        glVertex3f(4,12,0.5);
        glVertex3f(4,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
    glPopMatrix();

    //kotak 82
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(2,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,12,0);
        glVertex3f(3,12,0);
        glVertex3f(3,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,12,0);
        glVertex3f(2,12,0.5);
        glVertex3f(2,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(2,12,0.5);
        glVertex3f(2,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,12,0);
        glVertex3f(2,12,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(3,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,11,0);
    glEnd();
    glPopMatrix();

    //kotak 83
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(0.5,1,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,12,0.5);
        glVertex3f(1,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5);
        glVertex3f(1,11,0);
        glVertex3f(1,12,0);
        glVertex3f(2,12,0);
        glVertex3f(2,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,12,0);
        glVertex3f(2,12,0.5);
        glVertex3f(2,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(0.5,1,0.5);
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(1,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,12,0);
        glVertex3f(1,12,0.5);
        glVertex3f(2,12,0.5);
        glVertex3f(2,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(0.5,1,0.5);
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,11,0);
    glEnd();
    glPopMatrix();

    //kotak 84
    glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,2,0.5);
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(0,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,2,0.5);
        glVertex3f(0,11,0);
        glVertex3f(0,12,0);
        glVertex3f(1,12,0);
        glVertex3f(1,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,2,0.5);
        glVertex3f(1,11,0);
        glVertex3f(1,12,0);
        glVertex3f(1,12,0.5);
        glVertex3f(1,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,2,0.5);
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(0,12,0.5);
        glVertex3f(0,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,12,0);
        glVertex3f(0,12,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(1,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,2,0.5);
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
    glPopMatrix();
}





void drawBoard() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();
    drawKotak();

    glFlush();
}



void reshape(int w, int h) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 12, -5, 17, 5, -5);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glutSwapBuffers();
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
