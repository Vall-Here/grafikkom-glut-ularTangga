#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>


// const int BOARD_WIDTH = 7;
// int player1Position = 1;
// int player2Position = 1;
// int currentPlayer = 2;

// const int rows = 12;
// const int cols = 7;
// int diceResult = 0;

int jumlahlemparan = 1;
int jumlahlemparan2 = 1;

//Variabel untuk nilai dari player
int bidak_player1_X = 0;
int bidak_player1_Y = 0;

int bidak_player2_X = 0;
int bidak_player2_Y = 0;

//Variabel untuk pergantian pemain
bool giliran_player1 = true;

// Variabel untuk menggeser observer
float geser_oberver_X = 0.0;
float geser_oberver_Y = 0.0;

//Variabel untuk batas Observer
const float batas_observer_kiri = 0.0;
const float batas_observer_kanan = 3.7;
const float batas_observer_bawah = 0.0;
const float batas_observer_atas = 20.0;


// Variabel untuk rotasi papan permainan
float sudut_rotasi_X = 0.0f;
float sudut_rotasi_Y = 180.0f;
float sudut_rotasi_Z = 0.0f;

// Variabel untuk pusat rotasi
float pusat_rotasi_X = 3.5f;
float pusat_rotasi_Y = 6.0f;
float pusat_rotasi_Z = 0.0f;

// Variabel untuk menyimpan sudut rotasi terakhir
float sudut_rotasi_terakhir_x = 0.0f;
float sudut_rotasi_terakhir_Y = 0.0f;
float sudut_rotasi_terakhir_Z = 0.0f;


bool rotasi_diizinkan = false;
bool rotasi_awal_dilakukan = false;  

// Variabel global untuk mode warna
bool warna_transparan = false;

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


void drawKotak(bool warna_transparan) {
    glPushMatrix();
    
    if (warna_transparan) {
        glColor4f(0.5,1,0.5, 0.5);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}  
    glBegin(GL_POLYGON);
        // Sisi depan
        
        glVertex3f(0,0,0.5);
        glVertex3f(1,0,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(0,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(1,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
       
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(0,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
       
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        
        glVertex3f(0,0,0);
        glVertex3f(0,0,0.5);
        glVertex3f(1,0,0.5);
        glVertex3f(1,0,0);
    glEnd();
    glPopMatrix();

    //kotak 2
     glPushMatrix();
     
    if (warna_transparan) {
        glColor4f(1,1,0.5, 0.5);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}   
    glBegin(GL_POLYGON);
        // Sisi depan
        
        glVertex3f(1,0,0.5);
        glVertex3f(2,0,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(1,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5); 
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
        glColor3f(0.5,1,0.5); 
        glVertex3f(2,0,0.5);
        glVertex3f(3,0,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(2,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); 
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
        glColor3f(1,1,0.5); 
        glVertex3f(3,0,0.5);
        glVertex3f(4,0,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(3,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5); 
        glVertex3f(3,0,0);
        glVertex3f(3,1,0);
        glVertex3f(4,1,0);
        glVertex3f(4,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(4,0,0);
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(4,0,0.5);
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
            glColor3f(0.5,1,0.5); 
            glVertex3f(4,0,0.5);
            glVertex3f(5,0,0.5);
            glVertex3f(5,1,0.5);
            glVertex3f(4,1,0.5);
        glEnd();

        glBegin(GL_POLYGON);
            // Sisi belakang
            glColor3f(0.5,1,0.5); 
            glVertex3f(4,0,0);
            glVertex3f(4,1,0);
            glVertex3f(5,1,0);
            glVertex3f(5,0,0);
        glEnd();

        glBegin(GL_POLYGON);
            // Sisi kanan
            glColor3f(0.5,1,0.5);
            glVertex3f(5,0,0);
            glVertex3f(5,1,0);
            glVertex3f(5,1,0.5);
            glVertex3f(5,0,0.5);
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
            glVertex3f(5,1,0);
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
         glColor3f(1,1,0.5);  
        glVertex3f(5,1,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(6,0,0.5);
        glVertex3f(5,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);  
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
        glColor3f(0.5,1,0.5); 
        glVertex3f(6,0,0.5);
        glVertex3f(7,0,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(6,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); 
        glVertex3f(6,0,0);
        glVertex3f(6,1,0);
        glVertex3f(7,1,0);
        glVertex3f(7,0,0);
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
        glVertex3f(7,1,0);
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
        glColor3f(1,1,0.5); 
        glVertex3f(6,1,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(6,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5); 
        glVertex3f(6,1,0);
        glVertex3f(6,2,0);
        glVertex3f(7,2,0);
        glVertex3f(7,1,0);
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
        glVertex3f(7,2,0);
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
        glVertex3f(5,2,0);
        glVertex3f(5,2,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(6,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(5,1,0);
        glVertex3f(5,1,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(6,1,0);
    glEnd();
    glPopMatrix();

    //kotak 10
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(4,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(5,2,0);
        glVertex3f(5,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(5,1,0);
        glVertex3f(5,2,0);
        glVertex3f(5,2,0.5);
        glVertex3f(5,1,0.5);
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
        glVertex3f(5,2,0);
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
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(4,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(2,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,2,0);
        glVertex3f(3,2,0);
        glVertex3f(3,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(3,1,0);
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(3,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(0,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(0,1,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(1,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(1,1,0);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(1,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(0,2,0.5);
        glVertex3f(0,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(0.5,1,0.5); 
        glVertex3f(6,2,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(6,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(0.5,1,0.5); 
        glVertex3f(6,2,0);
        glVertex3f(6,3,0);
        glVertex3f(7,3,0);
        glVertex3f(7,2,0);
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
        glVertex3f(7,3,0);
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
         glColor3f(1,1,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(5,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);
        glVertex3f(5,3,0);
        glVertex3f(6,3,0);
        glVertex3f(6,2,0);
        glVertex3f(5,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,1,0.5);
        glVertex3f(6,2,0);
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(6,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,1,0.5);
        glVertex3f(5,2,0);
        glVertex3f(5,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,3,0);
        glVertex3f(5,3,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,3,0);
        glVertex3f(5,3,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,3,0);
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
        glVertex3f(5,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(5,2,0);
        glVertex3f(5,3,0);
        glVertex3f(5,3,0.5);
        glVertex3f(5,2,0.5);
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
        glVertex3f(5,3,0);
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
        glColor3f(1,1,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(3,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(3,2,0);
        glVertex3f(3,3,0);
        glVertex3f(4,3,0);
        glVertex3f(4,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(4,2,0);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(4,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(3,2,0);
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(3,2,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(1,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(1,2,0);
        glVertex3f(1,3,0);
        glVertex3f(2,3,0);
        glVertex3f(2,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(2,2,0);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(2,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(6,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(6,3,0);
        glVertex3f(6,4,0);
        glVertex3f(7,4,0);
        glVertex3f(7,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(7,3,0);
        glVertex3f(7,4,0);
        glVertex3f(7,4,0.5);
        glVertex3f(7,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(7,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(5,4,0);
        glVertex3f(5,4,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(5,4,0);
        glVertex3f(5,4,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,4,0);
    glEnd();
    glPopMatrix();

    //kotak 24
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(4,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,4,0);
        glVertex3f(5,4,0);
        glVertex3f(5,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(5,3,0);
        glVertex3f(5,4,0);
        glVertex3f(5,4,0.5);
        glVertex3f(5,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(4,3,0);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(4,3,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(2,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,4,0);
        glVertex3f(3,4,0);
        glVertex3f(3,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(3,3,0);
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(3,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(0,3,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(0,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(0,3,0);
        glVertex3f(0,4,0);
        glVertex3f(1,4,0);
        glVertex3f(1,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(1,3,0);
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(1,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(0,4,0.5);
        glVertex3f(0,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(0,4,0);
        glVertex3f(0,4,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(7,4,0);
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
        glVertex3f(7,5,0);
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
         glColor3f(1,1,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(5,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);
        glVertex3f(5,5,0);
        glVertex3f(6,5,0);
        glVertex3f(6,4,0);
        glVertex3f(5,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,1,0.5);
        glVertex3f(6,4,0);
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(6,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,1,0.5);
        glVertex3f(5,4,0);
        glVertex3f(5,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,5,0);
        glVertex3f(5,5,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,5,0);
        glVertex3f(5,5,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,5,0);
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
        glVertex3f(5,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(5,4,0);
        glVertex3f(5,5,0);
        glVertex3f(5,5,0.5);
        glVertex3f(5,4,0.5);
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
        glVertex3f(5,5,0);
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
        glColor3f(1,1,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(3,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(3,4,0);
        glVertex3f(3,5,0);
        glVertex3f(4,5,0);
        glVertex3f(4,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(4,4,0);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(4,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(3,4,0);
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(3,4,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(1,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(1,4,0);
        glVertex3f(1,5,0);
        glVertex3f(2,5,0);
        glVertex3f(2,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(2,4,0);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(2,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(6,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(6,5,0);
        glVertex3f(6,6,0);
        glVertex3f(7,6,0);
        glVertex3f(7,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(7,5,0);
        glVertex3f(7,6,0);
        glVertex3f(7,6,0.5);
        glVertex3f(7,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(7,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(5,6,0);
        glVertex3f(5,6,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(5,6,0);
        glVertex3f(5,6,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,6,0);
    glEnd();
    glPopMatrix();

    //kotak 38
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(4,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,6,0);
        glVertex3f(5,6,0);
        glVertex3f(5,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(5,5,0);
        glVertex3f(5,6,0);
        glVertex3f(5,6,0.5);
        glVertex3f(5,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(4,5,0);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(4,5,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(2,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,6,0);
        glVertex3f(3,6,0);
        glVertex3f(3,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(3,5,0);
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(3,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(0,5,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(0,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(0,5,0);
        glVertex3f(0,6,0);
        glVertex3f(1,6,0);
        glVertex3f(1,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(1,5,0);
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(1,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(0,5,0);
        glVertex3f(0,5,0.5);
        glVertex3f(0,6,0.5);
        glVertex3f(0,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(0,6,0);
        glVertex3f(0,6,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(7,6,0);
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
        glVertex3f(7,7,0);
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
         glColor3f(1,1,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(5,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);
        glVertex3f(5,7,0);
        glVertex3f(6,7,0);
        glVertex3f(6,6,0);
        glVertex3f(5,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,1,0.5);
        glVertex3f(6,6,0);
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(6,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,1,0.5);
        glVertex3f(5,6,0);
        glVertex3f(5,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,7,0);
        glVertex3f(5,7,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,7,0);
        glVertex3f(5,7,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,7,0);
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
        glVertex3f(5,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(5,6,0);
        glVertex3f(5,7,0);
        glVertex3f(5,7,0.5);
        glVertex3f(5,6,0.5);
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
        glVertex3f(5,7,0);
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
        glColor3f(1,1,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(3,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(3,6,0);
        glVertex3f(3,7,0);
        glVertex3f(4,7,0);
        glVertex3f(4,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(4,6,0);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(4,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(3,6,0);
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(3,6,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(1,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(1,6,0);
        glVertex3f(1,7,0);
        glVertex3f(2,7,0);
        glVertex3f(2,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(2,6,0);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(2,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(6,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(6,7,0);
        glVertex3f(6,8,0);
        glVertex3f(7,8,0);
        glVertex3f(7,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(7,7,0);
        glVertex3f(7,8,0);
        glVertex3f(7,8,0.5);
        glVertex3f(7,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(7,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(5,8,0);
        glVertex3f(5,8,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(5,8,0);
        glVertex3f(5,8,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,8,0);
    glEnd();
    glPopMatrix();

    //kotak 52
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(4,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,8,0);
        glVertex3f(5,8,0);
        glVertex3f(5,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(5,7,0);
        glVertex3f(5,8,0);
        glVertex3f(5,8,0.5);
        glVertex3f(5,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(4,7,0);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(4,7,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(2,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,8,0);
        glVertex3f(3,8,0);
        glVertex3f(3,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(3,7,0);
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(3,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(0,7,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(0,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(0,7,0);
        glVertex3f(0,8,0);
        glVertex3f(1,8,0);
        glVertex3f(1,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(1,7,0);
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(1,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(0,7,0);
        glVertex3f(0,7,0.5);
        glVertex3f(0,8,0.5);
        glVertex3f(0,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(0,8,0);
        glVertex3f(0,8,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(7,8,0);
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
        glVertex3f(7,9,0);
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
         glColor3f(1,1,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(5,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);
        glVertex3f(5,9,0);
        glVertex3f(6,9,0);
        glVertex3f(6,8,0);
        glVertex3f(5,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,1,0.5);
        glVertex3f(6,8,0);
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(6,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,1,0.5);
        glVertex3f(5,8,0);
        glVertex3f(5,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,9,0);
        glVertex3f(5,9,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,9,0);
        glVertex3f(5,9,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,9,0);
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
        glVertex3f(5,8,0);
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
        glVertex3f(5,9,0);
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
        glColor3f(1,1,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(3,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(3,8,0);
        glVertex3f(3,9,0);
        glVertex3f(4,9,0);
        glVertex3f(4,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(4,8,0);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(4,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(3,8,0);
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(3,8,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(1,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(1,8,0);
        glVertex3f(1,9,0);
        glVertex3f(2,9,0);
        glVertex3f(2,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(2,8,0);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(2,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(6,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(6,9,0);
        glVertex3f(6,10,0);
        glVertex3f(7,10,0);
        glVertex3f(7,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(7,9,0);
        glVertex3f(7,10,0);
        glVertex3f(7,10,0.5);
        glVertex3f(7,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(7,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(5,10,0);
        glVertex3f(5,10,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(5,10,0);
        glVertex3f(5,10,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
    glPopMatrix();

    //kotak 66
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(4,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,10,0);
        glVertex3f(5,10,0);
        glVertex3f(5,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(5,9,0);
        glVertex3f(5,10,0);
        glVertex3f(5,10,0.5);
        glVertex3f(5,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(4,9,0);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(4,9,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(2,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,10,0);
        glVertex3f(3,10,0);
        glVertex3f(3,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(3,9,0);
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(3,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(0,9,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(0,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(0,9,0);
        glVertex3f(0,10,0);
        glVertex3f(1,10,0);
        glVertex3f(1,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(1,9,0);
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(1,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(0,9,0);
        glVertex3f(0,9,0.5);
        glVertex3f(0,10,0.5);
        glVertex3f(0,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(0,10,0);
        glVertex3f(0,10,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(7,10,0);
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
        glVertex3f(7,11,0);
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
         glColor3f(1,1,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(5,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
         glColor3f(1,1,0.5);
        glVertex3f(5,11,0);
        glVertex3f(6,11,0);
        glVertex3f(6,10,0);
        glVertex3f(5,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
         glColor3f(1,1,0.5);
        glVertex3f(6,10,0);
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(6,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
         glColor3f(1,1,0.5);
        glVertex3f(5,10,0);
        glVertex3f(5,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,11,0);
        glVertex3f(5,11,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(1,1,0.5);
        glVertex3f(5,11,0);
        glVertex3f(5,11,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,11,0);
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
        glVertex3f(5,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(0.5,1,0.5);
        glVertex3f(5,10,0);
        glVertex3f(5,11,0);
        glVertex3f(5,11,0.5);
        glVertex3f(5,10,0.5);
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
        glVertex3f(5,11,0);
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
        glColor3f(1,1,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(3,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(3,10,0);
        glVertex3f(3,11,0);
        glVertex3f(4,11,0);
        glVertex3f(4,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(4,10,0);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(4,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(3,10,0);
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(3,10,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(1,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(1,10,0);
        glVertex3f(1,11,0);
        glVertex3f(2,11,0);
        glVertex3f(2,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(2,10,0);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(2,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(7,12,0.5);
        glVertex3f(6,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(6,11,0);
        glVertex3f(6,12,0);
        glVertex3f(7,12,0);
        glVertex3f(7,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(7,11,0);
        glVertex3f(7,12,0);
        glVertex3f(7,12,0.5);
        glVertex3f(7,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(6,12,0);
        glVertex3f(6,12,0.5);
        glVertex3f(7,12,0.5);
        glVertex3f(7,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(5,12,0);
        glVertex3f(5,12,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
         glColor3f(0.5,1,0.5);
        glVertex3f(5,12,0);
        glVertex3f(5,12,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,12,0);
    glEnd();
    glPopMatrix();

    //kotak 80
     glPushMatrix();
    glBegin(GL_POLYGON);
        // Sisi depan
        glColor3f(1,1,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(4,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,12,0);
        glVertex3f(5,12,0);
        glVertex3f(5,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(5,11,0);
        glVertex3f(5,12,0);
        glVertex3f(5,12,0.5);
        glVertex3f(5,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(4,12,0.5);
        glVertex3f(4,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(5,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glVertex3f(4,11,0);
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(4,11,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(2,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,12,0);
        glVertex3f(3,12,0);
        glVertex3f(3,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(3,11,0);
        glVertex3f(3,12,0);
        glVertex3f(3,12,0.5);
        glVertex3f(3,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(2,12,0.5);
        glVertex3f(2,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(2,12,0);
        glVertex3f(2,12,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(3,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
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
        glColor3f(1,1,0.5);
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(0,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glColor3f(1,1,0.5);
        glVertex3f(0,11,0);
        glVertex3f(0,12,0);
        glVertex3f(1,12,0);
        glVertex3f(1,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glColor3f(1,1,0.5);
        glVertex3f(1,11,0);
        glVertex3f(1,12,0);
        glVertex3f(1,12,0.5);
        glVertex3f(1,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glColor3f(1,1,0.5);
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(0,12,0.5);
        glVertex3f(0,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(0,12,0);
        glVertex3f(0,12,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(1,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glColor3f(1,1,0.5);
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
    glPopMatrix();
}

void drawPagar(){

    // BAWAH
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
     // Depan
        glVertex3f(0, 0, -0.5);
        glVertex3f(7, 0, -0.5);
        glVertex3f(7, 0.1, -0.5);
        glVertex3f(0, 0.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 0, 0);
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0.1, 0);
        glVertex3f(0, 0.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, -0.5);
        glVertex3f(0, 0.1, -0.5);
        glVertex3f(0, 0.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(7, 0.1, -0.5);
        glVertex3f(7, 0.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 0.1, 0);
        glVertex3f(7, 0.1, 0);
        glVertex3f(7, 0.1,-0.5);
        glVertex3f(0, 0.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();
    // ATAS
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 11.9, -0.5);
        glVertex3f(7, 11.9, -0.5);
        glVertex3f(7, 12, -0.5);
        glVertex3f(0, 12, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 11.9, 0);
        glVertex3f(7, 11.9, 0);
        glVertex3f(7, 12, 0);
        glVertex3f(0, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 11.9, 0);
        glVertex3f(0, 11.9, -0.5);
        glVertex3f(0, 12, -0.5);
        glVertex3f(0, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 11.9, 0);
        glVertex3f(7, 11.9, -0.5);
        glVertex3f(7, 12, -0.5);
        glVertex3f(7, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 12, 0);
        glVertex3f(7, 12, 0);
        glVertex3f(7, 12,-0.5);
        glVertex3f(0, 12, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 11.9, 0);
        glVertex3f(7, 11.9, 0);
        glVertex3f(7, 11.9, -0.5);
        glVertex3f(0, 11.9, -0.5);
    glEnd();

    // KIRI
    glBegin(GL_POLYGON);
     // Depan
        glVertex3f(0, 0, -0.5);
        glVertex3f(0.1, 0, -0.5);
        glVertex3f(0.1, 12, -0.5);
        glVertex3f(0, 12, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 0, 0);
        glVertex3f(0.1, 0, 0);
        glVertex3f(0.1, 12, 0);
        glVertex3f(0, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, -0.5);
        glVertex3f(0, 12, -0.5);
        glVertex3f(0, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(0.1, 0, 0);
        glVertex3f(0.1, 0, -0.5);
        glVertex3f(0.1, 12, -0.5);
        glVertex3f(0.1, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 12, 0);
        glVertex3f(0.1, 12, 0);
        glVertex3f(0.1, 12,-0.5);
        glVertex3f(0, 12, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(0.1, 0, 0);
        glVertex3f(0.1, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();

    // KIRI
    glBegin(GL_POLYGON);
     // Depan
        glVertex3f(7, 0, -0.5);
        glVertex3f(6.9, 0, -0.5);
        glVertex3f(6.9, 12, -0.5);
        glVertex3f(7, 12, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(7, 0, 0);
        glVertex3f(6.9, 0, 0);
        glVertex3f(6.9, 12, 0);
        glVertex3f(7, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(7, 12, -0.5);
        glVertex3f(7, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6.9, 0, 0);
        glVertex3f(6.9, 0, -0.5);
        glVertex3f(6.9, 12, -0.5);
        glVertex3f(6.9, 12, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(7, 12, 0);
        glVertex3f(6.9, 12, 0);
        glVertex3f(6.9, 12,-0.5);
        glVertex3f(7, 12, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(6.9, 0, 0);
        glVertex3f(6.9, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();


    // PAGAR TENGAH
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 0.9, -0.5);
        glVertex3f(6, 0.9, -0.5);
        glVertex3f(6, 1.1, -0.5);
        glVertex3f(0, 1.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 0.9, 0);
        glVertex3f(6, 0.9, 0);
        glVertex3f(6, 1.1, 0);
        glVertex3f(0, 1.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 0.9, 0);
        glVertex3f(0, 0.9, -0.5);
        glVertex3f(0, 1.1, -0.5);
        glVertex3f(0, 1.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 0.9, 0);
        glVertex3f(6, 0.9, -0.5);
        glVertex3f(6, 1.1, -0.5);
        glVertex3f(6, 1.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 1.1, 0);
        glVertex3f(6, 1.1, 0);
        glVertex3f(6, 1.1,-0.5);
        glVertex3f(0, 1.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(6, 0, 0);
        glVertex3f(6, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();
    // 2
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 1.9, -0.5);
        glVertex3f(7, 1.9, -0.5);
        glVertex3f(7, 2.1, -0.5);
        glVertex3f(1, 2.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 1.9, 0);
        glVertex3f(7, 1.9, 0);
        glVertex3f(7, 2.1, 0);
        glVertex3f(1, 2.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 1.9, 0);
        glVertex3f(1, 1.9, -0.5);
        glVertex3f(1, 2.1, -0.5);
        glVertex3f(1, 2.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 1.9, 0);
        glVertex3f(7, 1.9, -0.5);
        glVertex3f(7, 2.1, -0.5);
        glVertex3f(7, 2.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 2.1, 0);
        glVertex3f(7, 2.1, 0);
        glVertex3f(7, 2.1,-0.5);
        glVertex3f(1, 2.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0);
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(1, 0, -0.5);
    glEnd();
    //3
       glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 2.9, -0.5);
        glVertex3f(6, 2.9, -0.5);
        glVertex3f(6, 3.1, -0.5);
        glVertex3f(0, 3.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 2.9, 0);
        glVertex3f(6, 2.9, 0);
        glVertex3f(6, 3.1, 0);
        glVertex3f(0, 3.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 2.9, 0);
        glVertex3f(0, 2.9, -0.5);
        glVertex3f(0, 3.1, -0.5);
        glVertex3f(0, 3.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 2.9, 0);
        glVertex3f(6, 2.9, -0.5);
        glVertex3f(6, 3.1, -0.5);
        glVertex3f(6, 3.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 3.1, 0);
        glVertex3f(6, 3.1, 0);
        glVertex3f(6, 3.1,-0.5);
        glVertex3f(0, 3.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(6, 0, 0);
        glVertex3f(6, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();

       // 4
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 3.9, -0.5);
        glVertex3f(7, 3.9, -0.5);
        glVertex3f(7, 4.1, -0.5);
        glVertex3f(1, 4.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 3.9, 0);
        glVertex3f(7, 3.9, 0);
        glVertex3f(7, 4.1, 0);
        glVertex3f(1, 4.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 3.9, 0);
        glVertex3f(1, 3.9, -0.5);
        glVertex3f(1, 4.1, -0.5);
        glVertex3f(1, 4.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 3.9, 0);
        glVertex3f(7, 3.9, -0.5);
        glVertex3f(7, 4.1, -0.5);
        glVertex3f(7, 4.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 4.1, 0);
        glVertex3f(7, 4.1, 0);
        glVertex3f(7, 4.1,-0.5);
        glVertex3f(1, 4.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0);
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(1, 0, -0.5);
    glEnd();

      //5
       glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 4.9, -0.5);
        glVertex3f(6, 4.9, -0.5);
        glVertex3f(6, 5.1, -0.5);
        glVertex3f(0, 5.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 4.9, 0);
        glVertex3f(6, 4.9, 0);
        glVertex3f(6, 5.1, 0);
        glVertex3f(0, 5.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 4.9, 0);
        glVertex3f(0, 4.9, -0.5);
        glVertex3f(0, 5.1, -0.5);
        glVertex3f(0, 5.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 4.9, 0);
        glVertex3f(6, 4.9, -0.5);
        glVertex3f(6, 5.1, -0.5);
        glVertex3f(6, 5.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 5.1, 0);
        glVertex3f(6, 5.1, 0);
        glVertex3f(6, 5.1,-0.5);
        glVertex3f(0, 5.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(6, 0, 0);
        glVertex3f(6, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();

      // 6
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 5.9, -0.5);
        glVertex3f(7, 5.9, -0.5);
        glVertex3f(7, 6.1, -0.5);
        glVertex3f(1, 6.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 5.9, 0);
        glVertex3f(7, 5.9, 0);
        glVertex3f(7, 6.1, 0);
        glVertex3f(1, 6.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 5.9, 0);
        glVertex3f(1, 5.9, -0.5);
        glVertex3f(1, 6.1, -0.5);
        glVertex3f(1, 6.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 5.9, 0);
        glVertex3f(7, 5.9, -0.5);
        glVertex3f(7, 6.1, -0.5);
        glVertex3f(7, 6.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 6.1, 0);
        glVertex3f(7, 6.1, 0);
        glVertex3f(7, 6.1,-0.5);
        glVertex3f(1, 6.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0);
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(1, 0, -0.5);
    glEnd();

     //7
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 6.9, -0.5);
        glVertex3f(6, 6.9, -0.5);
        glVertex3f(6, 7.1, -0.5);
        glVertex3f(0, 7.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 6.9, 0);
        glVertex3f(6, 6.9, 0);
        glVertex3f(6, 7.1, 0);
        glVertex3f(0, 7.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 6.9, 0);
        glVertex3f(0, 6.9, -0.5);
        glVertex3f(0, 7.1, -0.5);
        glVertex3f(0, 7.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 6.9, 0);
        glVertex3f(6, 6.9, -0.5);
        glVertex3f(6, 7.1, -0.5);
        glVertex3f(6, 7.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 7.1, 0);
        glVertex3f(6, 7.1, 0);
        glVertex3f(6, 7.1,-0.5);
        glVertex3f(0, 7.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(6, 0, 0);
        glVertex3f(6, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();

      // 8
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 7.9, -0.5);
        glVertex3f(7, 7.9, -0.5);
        glVertex3f(7, 8.1, -0.5);
        glVertex3f(1, 8.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 7.9, 0);
        glVertex3f(7, 7.9, 0);
        glVertex3f(7, 8.1, 0);
        glVertex3f(1, 8.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 7.9, 0);
        glVertex3f(1, 7.9, -0.5);
        glVertex3f(1, 8.1, -0.5);
        glVertex3f(1, 8.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 7.9, 0);
        glVertex3f(7, 7.9, -0.5);
        glVertex3f(7, 8.1, -0.5);
        glVertex3f(7, 8.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 8.1, 0);
        glVertex3f(7, 8.1, 0);
        glVertex3f(7, 8.1,-0.5);
        glVertex3f(1, 8.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0);
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(1, 0, -0.5);
    glEnd();

      //9
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 8.9, -0.5);
        glVertex3f(6, 8.9, -0.5);
        glVertex3f(6, 9.1, -0.5);
        glVertex3f(0, 9.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 8.9, 0);
        glVertex3f(6, 8.9, 0);
        glVertex3f(6, 9.1, 0);
        glVertex3f(0, 9.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 8.9, 0);
        glVertex3f(0, 8.9, -0.5);
        glVertex3f(0, 9.1, -0.5);
        glVertex3f(0, 9.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 8.9, 0);
        glVertex3f(6, 8.9, -0.5);
        glVertex3f(6, 9.1, -0.5);
        glVertex3f(6, 9.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 9.1, 0);
        glVertex3f(6, 9.1, 0);
        glVertex3f(6, 9.1,-0.5);
        glVertex3f(0, 9.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(6, 0, 0);
        glVertex3f(6, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();

      // 10
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 9.9, -0.5);
        glVertex3f(7, 9.9, -0.5);
        glVertex3f(7, 10.1, -0.5);
        glVertex3f(1, 10.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 9.9, 0);
        glVertex3f(7, 9.9, 0);
        glVertex3f(7, 10.1, 0);
        glVertex3f(1, 10.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 9.9, 0);
        glVertex3f(1, 9.9, -0.5);
        glVertex3f(1, 10.1, -0.5);
        glVertex3f(1, 10.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 9.9, 0);
        glVertex3f(7, 9.9, -0.5);
        glVertex3f(7, 10.1, -0.5);
        glVertex3f(7, 10.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 10.1, 0);
        glVertex3f(7, 10.1, 0);
        glVertex3f(7, 10.1,-0.5);
        glVertex3f(1, 10.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0);
        glVertex3f(7, 0, 0);
        glVertex3f(7, 0, -0.5);
        glVertex3f(1, 0, -0.5);
    glEnd();
    //11
     glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 10.9, -0.5);
        glVertex3f(6, 10.9, -0.5);
        glVertex3f(6, 11.1, -0.5);
        glVertex3f(0, 11.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 10.9, 0);
        glVertex3f(6, 10.9, 0);
        glVertex3f(6, 11.1, 0);
        glVertex3f(0, 11.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 10.9, 0);
        glVertex3f(0, 10.9, -0.5);
        glVertex3f(0, 11.1, -0.5);
        glVertex3f(0, 11.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 10.9, 0);
        glVertex3f(6, 10.9, -0.5);
        glVertex3f(6, 11.1, -0.5);
        glVertex3f(6, 11.1, 0);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 11.1, 0);
        glVertex3f(6, 11.1, 0);
        glVertex3f(6, 11.1,-0.5);
        glVertex3f(0, 11.1, -0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0);
        glVertex3f(6, 0, 0);
        glVertex3f(6, 0, -0.5);
        glVertex3f(0, 0, -0.5);
    glEnd();
}


void drawBoard() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(pusat_rotasi_X, pusat_rotasi_Y, pusat_rotasi_Z);
    glRotatef(sudut_rotasi_X, 1.0f, 0.0f, 0.0f);
    glRotatef(sudut_rotasi_Y, 0.0f, 1.0f, 0.0f);
    glRotatef(sudut_rotasi_Z, 0.0f, 0.0f, 1.0f);
    glTranslatef(-pusat_rotasi_X, -pusat_rotasi_Y, -pusat_rotasi_Z);
	glPointSize(4);


    drawKotak(false);
    drawPagar();










glutSwapBuffers();
glFlush();
}




void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 10, -3, 14,-15,30);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glClearColor(0.0, 0.0, 0.0, 0.0);
	// glColor3f(96.0,96.0,96.0);

}
void input(unsigned char key, int x, int y) {
    key = tolower(key); //Agar bisa menginput keyboard huruf besar dan kecil

    if (rotasi_diizinkan) { //Percabangan untuk rotasi papan permainan
        switch (key) {
            case 'i': // Putar Atas
                sudut_rotasi_X -= 2.0f;
                break;
            case 'k': // Putar Bawah
                sudut_rotasi_X += 2.0f;
                break;
            case 'j': // Putar Kiri
                sudut_rotasi_Y -= 2.0f;
                break;
            case 'l': // Putar Kanan
                sudut_rotasi_Y += 2.0f;
                break;
            case 'u': // Putar Z Berlawanan Arah jarum Jam
                sudut_rotasi_Z -= 2.0f;
                break;
            case 'o': // Putar Z Berlawanan Arah jarum Jam
                sudut_rotasi_Z += 2.0f;
                break;
        }
    }

    switch (key) {
        case 'v':
            if (rotasi_diizinkan) {
                // Simpan sudut rotasi terakhir
                sudut_rotasi_terakhir_x = sudut_rotasi_X;
                sudut_rotasi_terakhir_Y = sudut_rotasi_Y;
                sudut_rotasi_terakhir_Z = sudut_rotasi_Z;
                // Reset sudut rotasi ke awal
                sudut_rotasi_X = 0.0f;
                sudut_rotasi_Y = 180.0f;
                sudut_rotasi_Z = 0.0f;
            } else {
                if (!rotasi_awal_dilakukan) {
                    sudut_rotasi_X = -20.0f; 
                    rotasi_awal_dilakukan = true;
                } else {
                    // Kembalikan sudut rotasi terakhir
                    sudut_rotasi_X = sudut_rotasi_terakhir_x;
                    sudut_rotasi_Y = sudut_rotasi_terakhir_Y;
                    sudut_rotasi_Z = sudut_rotasi_terakhir_Z;
                }
            }
            // Mengubah izin rotasi pada papan
            rotasi_diizinkan = !rotasi_diizinkan;
            // Mengubah mode warna pada papan
            warna_transparan = !warna_transparan;
            break;
        case 'w':
            if (geser_oberver_Y + 0.2 <= batas_observer_atas)
                geser_oberver_Y += 0.2; // Pergeseran ke atas
            break;
        case 'a':
            if (geser_oberver_X - 0.2 >= batas_observer_kiri)
                geser_oberver_X -= 0.2; // Pergeseran ke kiri
            break;
        case 's':
            if (geser_oberver_Y - 0.2 >= batas_observer_bawah)
                geser_oberver_Y -= 0.2; // Pergeseran ke bawah
            break;
        case 'd':
            if (geser_oberver_X + 0.2 <= batas_observer_kanan)
                geser_oberver_X += 0.2; // Pergeseran ke kanan
            break;
        case 27: // Keluar pakai tombol ESC
            exit(0);
    }
    glutPostRedisplay(); // Mengupdate dipslay atau tampilan

    //Fungsi Penggerak Bidak
    if (key == ' ') {
         srand (time(NULL));
         if(giliran_player1) {
            cout << "Letak Awal Player1 : " << jumlahlemparan << endl;
            int rand_player1 = rand() % 6 + 1;
            cout << "Player1 Mendapatkan : " << rand_player1 << " Nilai Dadu"<< endl;
            jumlahlemparan += rand_player1;
            cout << "Letak Player1 Setelah Dijumlah : " << jumlahlemparan << endl;
            cout <<"===========================================================" <<endl;
            if (jumlahlemparan == 1){
                bidak_player1_X = 0;
                bidak_player1_Y =0 ;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 2){
                bidak_player1_X = 1;
                bidak_player1_Y =0;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 3) {
                bidak_player1_X = 2;
                bidak_player1_Y =0;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 4){
                bidak_player1_X = 3;
                bidak_player1_Y = 0;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 5){
                bidak_player1_X = 3;
                bidak_player1_Y = 1;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 6){
                bidak_player1_X = 2;
                bidak_player1_Y = 1;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 7){
                bidak_player1_X = 1;
                bidak_player1_Y = 1;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 8){
                bidak_player1_X = 0;
                bidak_player1_Y = 1;
                giliran_player1 = false;
            }
            else if (jumlahlemparan== 9){
                bidak_player1_X = 0;
                bidak_player1_Y = 2;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 10){
                bidak_player1_X = 1;
                bidak_player1_Y = 2;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 11){
                bidak_player1_X = 2;
                bidak_player1_Y = 2;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 12){
                bidak_player1_X = 3;
                bidak_player1_Y = 2;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 13){
                bidak_player1_X = 3;
                bidak_player1_Y = 3;
                giliran_player1 = false;
            }
            //Tangga 1 (14-30)
            else if (jumlahlemparan == 14){
                bidak_player1_X = 2;
                bidak_player1_Y = 7;
                jumlahlemparan += 16;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 15){
                bidak_player1_X = 1;
                bidak_player1_Y = 3;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 16){
                bidak_player1_X = 0;
                bidak_player1_Y = 3;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 17){
                bidak_player1_X = 0;
                bidak_player1_Y = 4;
                giliran_player1 = false;
            }
            //Ular 1 (18-8)
            else if (jumlahlemparan == 18){
                bidak_player1_X = 0;
                bidak_player1_Y = 1;
                jumlahlemparan -= 10;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 19){
                bidak_player1_X = 2;
                bidak_player1_Y = 4;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 20){
                bidak_player1_X = 3;
                bidak_player1_Y = 4;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 21){
                bidak_player1_X = 3;
                bidak_player1_Y = 5;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 22){
                bidak_player1_X = 2;
                bidak_player1_Y = 5;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 23){
                bidak_player1_X = 1;
                bidak_player1_Y = 5;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 24){
                bidak_player1_X = 0;
                bidak_player1_Y = 5;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 25){
                bidak_player1_X = 0;
                bidak_player1_Y = 6;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 26){
                bidak_player1_X = 1;
                bidak_player1_Y = 6;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 27){
                bidak_player1_X = 2;
                bidak_player1_Y = 6;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 28){
                bidak_player1_X = 3;
                bidak_player1_Y = 6;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 29){
                bidak_player1_X = 3;
                bidak_player1_Y = 7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 30){
                bidak_player1_X = 2;
                bidak_player1_Y = 7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 31){
                bidak_player1_X = 1;
                bidak_player1_Y = 7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 32){
                bidak_player1_X = 0;
                bidak_player1_Y = 7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 33){
                bidak_player1_X = 0;
                bidak_player1_Y = 8;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 34){
                bidak_player1_X = 1;
                bidak_player1_Y = 8;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 35){
                bidak_player1_X = 2;
                bidak_player1_Y = 8;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 36){
                bidak_player1_X = 3;
                bidak_player1_Y = 8;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 37){
                bidak_player1_X = 3;
                bidak_player1_Y = 9;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 38){
                bidak_player1_X = 2;
                bidak_player1_Y = 9;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 39){
                bidak_player1_X = 1;
                bidak_player1_Y = 9;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 40){
                bidak_player1_X = 0;
                bidak_player1_Y = 9;
                giliran_player1 = false;
            }
            //Tangga 2 (41-44)
            else if (jumlahlemparan == 41){
                bidak_player1_X = 3;
                bidak_player1_Y = 10;
                jumlahlemparan += 3;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 42){
                bidak_player1_X = 1;
                bidak_player1_Y = 10;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 43){
                bidak_player1_X = 2;
                bidak_player1_Y = 10;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 44){
                bidak_player1_X = 3;
                bidak_player1_Y = 10;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 45){
                bidak_player1_X = 3;
                bidak_player1_Y = 11;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 46){
                bidak_player1_X = 2;
                bidak_player1_Y = 11;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 47){
                bidak_player1_X = 1;
                bidak_player1_Y = 11;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 48){
                bidak_player1_X = 0;
                bidak_player1_Y = 11;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 49){
                bidak_player1_X = 0;
                bidak_player1_Y = 12;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 50){
                bidak_player1_X = 1;
                bidak_player1_Y = 12;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 51){
                bidak_player1_X = 2;
                bidak_player1_Y = 12;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 52){
                bidak_player1_X = 3;
                bidak_player1_Y = 12;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 53){
                bidak_player1_X = 3;
                bidak_player1_Y = 13;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 54){
                bidak_player1_X = 2;
                bidak_player1_Y = 13;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 55){
                bidak_player1_X = 1;
                bidak_player1_Y = 13;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 56){
                bidak_player1_X = 0;
                bidak_player1_Y = 13;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 57){
                bidak_player1_X = 0;
                bidak_player1_Y = 14;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 58){
                bidak_player1_X = 1;
                bidak_player1_Y = 14;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 59){
                bidak_player1_X = 2;
                bidak_player1_Y = 14;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 60){
                bidak_player1_X = 3;
                bidak_player1_Y = 14;
                giliran_player1 = false;
            }
            //Ular 2 (61-45)
            else if (jumlahlemparan == 61){
                bidak_player1_X = 3;
                bidak_player1_Y = 11;
                jumlahlemparan -= 16;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 62){
                bidak_player1_X = 2;
                bidak_player1_Y = 15;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 63){
                bidak_player1_X = 1;
                bidak_player1_Y = 15;
                giliran_player1 = false;
            }
            //Tangga 3 (64-76)
            else if (jumlahlemparan == 64){
                bidak_player1_X = 3;
                bidak_player1_Y = 18;
                jumlahlemparan += 12;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 65){
                bidak_player1_X = 0;
                bidak_player1_Y = 16;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 66){
                bidak_player1_X = 1;
                bidak_player1_Y = 16;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 67){
                bidak_player1_X = 2;
                bidak_player1_Y = 16;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 68){
                bidak_player1_X = 3;
                bidak_player1_Y = 16;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 69){
                bidak_player1_X = 3;
                bidak_player1_Y = 17;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 70){
                bidak_player1_X = 2;
                bidak_player1_Y = 17;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 71){
                bidak_player1_X = 1;
                bidak_player1_Y = 17;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 72){
                bidak_player1_X = 0;
                bidak_player1_Y = 17;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 73){
                bidak_player1_X = 0;
                bidak_player1_Y = 18;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 74){
                bidak_player1_X = 1;
                bidak_player1_Y = 18;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 75){
                bidak_player1_X = 2;
                bidak_player1_Y = 18;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 76){
                bidak_player1_X = 3;
                bidak_player1_Y = 18;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 77){
                bidak_player1_X = 3;
                bidak_player1_Y = 19;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 78){
                bidak_player1_X = 2;
                bidak_player1_Y = 19;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 79){
                bidak_player1_X = 1;
                bidak_player1_Y = 19;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 80){
                bidak_player1_X = 0;
                bidak_player1_Y = 19;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 81){
                bidak_player1_X = 0;
                bidak_player1_Y = 20;
                giliran_player1 = false;
            }
            //Ular 3 (82-71)
            else if (jumlahlemparan == 82){
                bidak_player1_X = 1;
                bidak_player1_Y = 17;
                jumlahlemparan -= 11;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 83){
                bidak_player1_X = 2;
                bidak_player1_Y = 20;
                giliran_player1 = false;
            }
            else if (jumlahlemparan > 83){
                bidak_player1_X = 3;
                bidak_player1_Y = 20;
                cout << "Player1 Menang" << endl;
                exit(0);
            }
         }
         else {
            cout << "Letak Awal Player2 : " << jumlahlemparan2 << endl;
            int rand_player2 = rand() % 6 + 1;
            cout << "Player2 mendapatkan : " << rand_player2 <<" Nilai Dadu"<< endl;
            jumlahlemparan2 += rand_player2;
            cout << "Letak Player2 Setelah Dijumlah : " << jumlahlemparan2 << endl;
            cout <<"===========================================================" <<endl;
            if (jumlahlemparan2 == 1){
                bidak_player2_X = 0;
                bidak_player2_Y =0 ;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 2){
                bidak_player2_X = 1;
                bidak_player2_Y =0;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 3) {
                bidak_player2_X = 2;
                bidak_player2_Y =0;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 4){
                bidak_player2_X = 3;
                bidak_player2_Y = 0;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 5){
                bidak_player2_X = 3;
                bidak_player2_Y = 1;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 6){
                bidak_player2_X = 2;
                bidak_player2_Y = 1;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 7){
                bidak_player2_X = 1;
                bidak_player2_Y = 1;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 8){
                bidak_player2_X = 0;
                bidak_player2_Y = 1;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2== 9){
                bidak_player2_X = 0;
                bidak_player2_Y = 2;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 10){
                bidak_player2_X = 1;
                bidak_player2_Y = 2;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 11){
                bidak_player2_X = 2;
                bidak_player2_Y = 2;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 12){
                bidak_player2_X = 3;
                bidak_player2_Y = 2;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 13){
                bidak_player2_X = 3;
                bidak_player2_Y = 3;
                giliran_player1 = true;
            }
            //Tanggga 1 (14-30)
            else if (jumlahlemparan2 == 14){
                bidak_player2_X = 2;
                bidak_player2_Y = 7;
                jumlahlemparan2 += 16; //Typo
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 15){
                bidak_player2_X = 1;
                bidak_player2_Y = 3;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 16){
                bidak_player2_X = 0;
                bidak_player2_Y = 3;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 17){
                bidak_player2_X = 0;
                bidak_player2_Y = 4;
                giliran_player1 = true;
            }
            //Ular 1 (18-8)
            else if (jumlahlemparan2 == 18){
                bidak_player2_X = 0;
                bidak_player2_Y = 1;
                jumlahlemparan2 -= 10;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 19){
                bidak_player2_X = 2;
                bidak_player2_Y = 4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 20){
                bidak_player2_X = 3;
                bidak_player2_Y = 4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 21){
                bidak_player2_X = 3;
                bidak_player2_Y = 5;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 22){
                bidak_player2_X = 2;
                bidak_player2_Y = 5;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 23){
                bidak_player2_X = 1;
                bidak_player2_Y = 5;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 24){
                bidak_player2_X = 0;
                bidak_player2_Y = 5;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 25){
                bidak_player2_X = 0;
                bidak_player2_Y = 6;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 26){
                bidak_player2_X = 1;
                bidak_player2_Y = 6;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 27){
                bidak_player2_X = 2;
                bidak_player2_Y = 6;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 28){
                bidak_player2_X = 3;
                bidak_player2_Y = 6;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 29){
                bidak_player2_X = 3;
                bidak_player2_Y = 7;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 30){
                bidak_player2_X = 2;
                bidak_player2_Y = 7;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 31){
                bidak_player2_X = 1;
                bidak_player2_Y = 7;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 32){
                bidak_player2_X = 0;
                bidak_player2_Y = 7;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 33){
                bidak_player2_X = 0;
                bidak_player2_Y = 8;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 34){
                bidak_player2_X = 1;
                bidak_player2_Y = 8;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 35){
                bidak_player2_X = 2;
                bidak_player2_Y = 8;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 36){
                bidak_player2_X = 3;
                bidak_player2_Y = 8;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 37){
                bidak_player2_X = 3;
                bidak_player2_Y = 9;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 38){
                bidak_player2_X = 2;
                bidak_player2_Y = 9;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 39){
                bidak_player2_X = 1;
                bidak_player2_Y = 9;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 40){
                bidak_player2_X = 0;
                bidak_player2_Y = 9;
                giliran_player1 = true;
            }
            //Tangga 2 (41-44)
            else if (jumlahlemparan2 == 41){
                bidak_player2_X = 3;
                bidak_player2_Y = 10;
                jumlahlemparan2 += 3;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 42){
                bidak_player2_X = 1;
                bidak_player2_Y = 10;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 43){
                bidak_player2_X = 2;
                bidak_player2_Y = 10;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 44){
                bidak_player2_X = 3;
                bidak_player2_Y = 10;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 45){
                bidak_player2_X = 3;
                bidak_player2_Y = 11;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 46){
                bidak_player2_X = 2;
                bidak_player2_Y = 11;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 47){
                bidak_player2_X = 1;
                bidak_player2_Y = 11;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 48){
                bidak_player2_X = 0;
                bidak_player2_Y = 11;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 49){
                bidak_player2_X = 0;
                bidak_player2_Y = 12;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 50){
                bidak_player2_X = 1;
                bidak_player2_Y = 12;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 51){
                bidak_player2_X = 2;
                bidak_player2_Y = 12;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 52){
                bidak_player2_X = 3;
                bidak_player2_Y = 12;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 53){
                bidak_player2_X = 3;
                bidak_player2_Y = 13;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 54){
                bidak_player2_X = 2;
                bidak_player2_Y = 13;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 55){
                bidak_player2_X = 1;
                bidak_player2_Y = 13;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 56){
                bidak_player2_X = 0;
                bidak_player2_Y = 13;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 57){
                bidak_player2_X = 0;
                bidak_player2_Y = 14;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 58){
                bidak_player2_X = 1;
                bidak_player2_Y = 14;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 59){
                bidak_player2_X = 2;
                bidak_player2_Y = 14;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 60){
                bidak_player2_X = 3;
                bidak_player2_Y = 14;
                giliran_player1 = true;
            }
            //Ular 2 (61-45)
            else if (jumlahlemparan2 == 61){
                bidak_player2_X = 3;
                bidak_player2_Y = 11;
                jumlahlemparan2 -= 16;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 62){
                bidak_player2_X = 2;
                bidak_player2_Y = 15;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 63){
                bidak_player2_X = 1;
                bidak_player2_Y = 15;
                giliran_player1 = true;
            }
            //Tangga 2 (64-76)
            else if (jumlahlemparan2 == 64){
                bidak_player2_X = 3;
                bidak_player2_Y = 18;
                jumlahlemparan2 += 12;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 65){
                bidak_player2_X = 0;
                bidak_player2_Y = 16;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 66){
                bidak_player2_X = 1;
                bidak_player2_Y = 16;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 67){
                bidak_player2_X = 2;
                bidak_player2_Y = 16;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 68){
                bidak_player2_X = 3;
                bidak_player2_Y = 16;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 69){
                bidak_player2_X = 3;
                bidak_player2_Y = 17;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 70){
                bidak_player2_X = 2;
                bidak_player2_Y = 17;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 71){
                bidak_player2_X = 1;
                bidak_player2_Y = 17;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 72){
                bidak_player2_X = 0;
                bidak_player2_Y = 17;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 73){
                bidak_player2_X = 0;
                bidak_player2_Y = 18;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 74){
                bidak_player2_X = 1;
                bidak_player2_Y = 18;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 75){
                bidak_player2_X = 2;
                bidak_player2_Y = 18;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 76){
                bidak_player2_X = 3;
                bidak_player2_Y = 18;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 77){
                bidak_player2_X = 3;
                bidak_player2_Y = 19;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 78){
                bidak_player2_X = 2;
                bidak_player2_Y = 19;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 79){
                bidak_player2_X = 1;
                bidak_player2_Y = 19;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 80){
                bidak_player2_X = 0;
                bidak_player2_Y = 19;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 81){
                bidak_player2_X = 0;
                bidak_player2_Y = 20;
                giliran_player1 = true;
            }
            //Ular 3 (82-71)
            else if (jumlahlemparan2 == 82){
                bidak_player2_X = 1;
                bidak_player2_Y = 17;
                jumlahlemparan2 -= 11;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 83){
                bidak_player2_X = 2;
                bidak_player2_Y = 20;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 > 83){
                bidak_player2_X = 3;
                bidak_player2_Y = 20;
                cout << "Player2 Menang" << endl;
                exit(0);
            }
         }
    }

    drawBoard();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ular Tangga");
    glutDisplayFunc(drawBoard);
    glutKeyboardFunc(input);
    myinit();



    glClearColor(0, 0, 0, 0);
    glutMainLoop();
    return 0;
}
