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


int rollDice() {
    return (rand() % 6) + 1;
}

int jumlahlemparan = 1;
int jumlahlemparan2 = 1;

int pemenang = 0;

//Variabel untuk nilai dari player
float bidak_player1_X = 0.4;
float bidak_player1_Y = 0.7;

float bidak_player2_X = 0.4;
float bidak_player2_Y = 0.4;

//Variabel untuk pergantian pemain
bool giliran_player1 = true;

// Variabel untuk menggeser observer
float geser_oberver_X = 0.1;
float geser_oberver_Y = 0.1;

//Variabel untuk batas Observer
const float batas_observer_kiri = 0.1;
const float batas_observer_kanan = 6.9;
const float batas_observer_bawah = 0.1;
const float batas_observer_atas = 11.9;


// Variabel untuk rotasi papan permainan
float sudut_rotasi_X = 0.0f;
float sudut_rotasi_Y = 0.0f;
float sudut_rotasi_Z = 0.0f;

// Variabel untuk pusat rotasi
float pusat_rotasi_X = 3.5f;
float pusat_rotasi_Y = 6.0f;
float pusat_rotasi_Z = 0.0f;

// Variabel untuk menyimpan sudut rotasi terakhir
float sudut_rotasi_terakhir_x = 0.0f;
float sudut_rotasi_terakhir_Y = 0.0f;
float sudut_rotasi_terakhir_Z = 0.0f;


bool isRotated = false;
bool rotasi_awal_dilakukan = false;

// Variabel global untuk mode warna
bool warna_transparan = false;

// gambar 5 koordinat X awal, Y awal, Z awal, kedalaman
void drawFour(float xAtas, float yBawah, float z, float depth) {
    float frontZ = z;
    float backZ = z + depth;

    // Bagian depan
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.9 + xAtas, 0.6 + yBawah, frontZ);
    glVertex3f(0.85 + xAtas, 0.6 + yBawah, frontZ);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, frontZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.75 + xAtas, 0.72 + yBawah, frontZ);
    glVertex3f(0.78 + xAtas, 0.72 + yBawah, frontZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.78 + xAtas, 0.76 + yBawah, frontZ);
    glVertex3f(0.75 + xAtas, 0.71 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.71 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.76 + yBawah, frontZ);
    glEnd();

    // Bagian belakang (menggunakan depth untuk memberikan kedalaman)
    glBegin(GL_POLYGON);
    glVertex3f(0.9 + xAtas, 0.6 + yBawah, backZ);
    glVertex3f(0.85 + xAtas, 0.6 + yBawah, backZ);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, backZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, backZ);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, backZ);
    glVertex3f(0.75 + xAtas, 0.72 + yBawah, backZ);
    glVertex3f(0.78 + xAtas, 0.72 + yBawah, backZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.78 + xAtas, 0.76 + yBawah, backZ);
    glVertex3f(0.75 + xAtas, 0.71 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.71 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.76 + yBawah, backZ);
    glEnd();

    // Menghubungkan depan dan belakang untuk membuat sisi 3D
    glBegin(GL_QUADS);
    // Sisi 1
    glVertex3f(0.9 + xAtas, 0.6 + yBawah, frontZ);
    glVertex3f(0.85 + xAtas, 0.6 + yBawah, frontZ);
    glVertex3f(0.85 + xAtas, 0.6 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.6 + yBawah, backZ);

    // Sisi 2
    glVertex3f(0.85 + xAtas, 0.6 + yBawah, frontZ);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, backZ);
    glVertex3f(0.85 + xAtas, 0.6 + yBawah, backZ);

    // Sisi 3
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, backZ);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, backZ);

    // Sisi 4
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.6 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.6 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, backZ);

    // Sisi 5
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, frontZ);
    glVertex3f(0.75 + xAtas, 0.72 + yBawah, frontZ);
    glVertex3f(0.75 + xAtas, 0.72 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, backZ);

    // Sisi 6
    glVertex3f(0.75 + xAtas, 0.72 + yBawah, frontZ);
    glVertex3f(0.78 + xAtas, 0.72 + yBawah, frontZ);
    glVertex3f(0.78 + xAtas, 0.72 + yBawah, backZ);
    glVertex3f(0.75 + xAtas, 0.72 + yBawah, backZ);

    // Sisi 7
    glVertex3f(0.78 + xAtas, 0.72 + yBawah, frontZ);
    glVertex3f(0.78 + xAtas, 0.76 + yBawah, frontZ);
    glVertex3f(0.78 + xAtas, 0.76 + yBawah, backZ);
    glVertex3f(0.78 + xAtas, 0.72 + yBawah, backZ);

    // Sisi 8
    glVertex3f(0.78 + xAtas, 0.76 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.76 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.76 + yBawah, backZ);
    glVertex3f(0.78 + xAtas, 0.76 + yBawah, backZ);

    // Sisi 9
    glVertex3f(0.9 + xAtas, 0.76 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.71 + yBawah, frontZ);
    glVertex3f(0.9 + xAtas, 0.71 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.76 + yBawah, backZ);

    // Sisi 10
    glVertex3f(0.9 + xAtas, 0.71 + yBawah, frontZ);
    glVertex3f(0.75 + xAtas, 0.71 + yBawah, frontZ);
    glVertex3f(0.75 + xAtas, 0.71 + yBawah, backZ);
    glVertex3f(0.9 + xAtas, 0.71 + yBawah, backZ);

    glEnd();
}


    // gambar 6 koordinat X awal, Y awal, Z awal, kedalaman
void drawSix(float x, float y, float z, float depth) {
    float frontZ = z;
    float backZ = z + depth;

    // Bagian depan
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(x + 0.9f, y + 0.9f, frontZ);
    glVertex3f(x + 0.9f, y + 0.85f, frontZ);
    glVertex3f(x + 0.75f, y + 0.85f, frontZ);
    glVertex3f(x + 0.75f, y + 0.9f, frontZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.75f, y + 0.9f, frontZ);
    glVertex3f(x + 0.75f, y + 0.6f, frontZ);
    glVertex3f(x + 0.8f, y + 0.6f, frontZ);
    glVertex3f(x + 0.8f, y + 0.9f, frontZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.8f, y + 0.6f, frontZ);
    glVertex3f(x + 0.9f, y + 0.6f, frontZ);
    glVertex3f(x + 0.9f, y + 0.65f, frontZ);
    glVertex3f(x + 0.8f, y + 0.65f, frontZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.9f, y + 0.75f, frontZ);
    glVertex3f(x + 0.9f, y + 0.6f, frontZ);
    glVertex3f(x + 0.85f, y + 0.6f, frontZ);
    glVertex3f(x + 0.85f, y + 0.75f, frontZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.9f, y + 0.75f, frontZ);
    glVertex3f(x + 0.8f, y + 0.75f, frontZ);
    glVertex3f(x + 0.8f, y + 0.7f, frontZ);
    glVertex3f(x + 0.9f, y + 0.7f, frontZ);
    glEnd();

    // Bagian belakang
    glBegin(GL_POLYGON);
    glVertex3f(x + 0.9f, y + 0.9f, backZ);
    glVertex3f(x + 0.9f, y + 0.85f, backZ);
    glVertex3f(x + 0.75f, y + 0.85f, backZ);
    glVertex3f(x + 0.75f, y + 0.9f, backZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.75f, y + 0.9f, backZ);
    glVertex3f(x + 0.75f, y + 0.6f, backZ);
    glVertex3f(x + 0.8f, y + 0.6f, backZ);
    glVertex3f(x + 0.8f, y + 0.9f, backZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.8f, y + 0.6f, backZ);
    glVertex3f(x + 0.9f, y + 0.6f, backZ);
    glVertex3f(x + 0.9f, y + 0.65f, backZ);
    glVertex3f(x + 0.8f, y + 0.65f, backZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.9f, y + 0.75f, backZ);
    glVertex3f(x + 0.9f, y + 0.6f, backZ);
    glVertex3f(x + 0.85f, y + 0.6f, backZ);
    glVertex3f(x + 0.85f, y + 0.75f, backZ);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + 0.9f, y + 0.75f, backZ);
    glVertex3f(x + 0.8f, y + 0.75f, backZ);
    glVertex3f(x + 0.8f, y + 0.7f, backZ);
    glVertex3f(x + 0.9f, y + 0.7f, backZ);
    glEnd();

    // Menghubungkan depan dan belakang untuk membuat sisi 3D
    glBegin(GL_QUADS);
    // Sisi 1
    glVertex3f(x + 0.9f, y + 0.9f, frontZ);
    glVertex3f(x + 0.9f, y + 0.85f, frontZ);
    glVertex3f(x + 0.9f, y + 0.85f, backZ);
    glVertex3f(x + 0.9f, y + 0.9f, backZ);

    // Sisi 2
    glVertex3f(x + 0.9f, y + 0.85f, frontZ);
    glVertex3f(x + 0.75f, y + 0.85f, frontZ);
    glVertex3f(x + 0.75f, y + 0.85f, backZ);
    glVertex3f(x + 0.9f, y + 0.85f, backZ);

    // Sisi 3
    glVertex3f(x + 0.75f, y + 0.85f, frontZ);
    glVertex3f(x + 0.75f, y + 0.9f, frontZ);
    glVertex3f(x + 0.75f, y + 0.9f, backZ);
    glVertex3f(x + 0.75f, y + 0.85f, backZ);

    // Sisi 4
    glVertex3f(x + 0.75f, y + 0.9f, frontZ);
    glVertex3f(x + 0.75f, y + 0.6f, frontZ);
    glVertex3f(x + 0.75f, y + 0.6f, backZ);
    glVertex3f(x + 0.75f, y + 0.9f, backZ);

    // Sisi 5
    glVertex3f(x + 0.75f, y + 0.6f, frontZ);
    glVertex3f(x + 0.8f, y + 0.6f, frontZ);
    glVertex3f(x + 0.8f, y + 0.6f, backZ);
    glVertex3f(x + 0.75f, y + 0.6f, backZ);

    // Sisi 6
    glVertex3f(x + 0.8f, y + 0.6f, frontZ);
    glVertex3f(x + 0.8f, y + 0.9f, frontZ);
    glVertex3f(x + 0.8f, y + 0.9f, backZ);
    glVertex3f(x + 0.8f, y + 0.6f, backZ);

    // Sisi 7
    glVertex3f(x + 0.8f, y + 0.6f, frontZ);
    glVertex3f(x + 0.9f, y + 0.6f, frontZ);
    glVertex3f(x + 0.9f, y + 0.6f, backZ);
    glVertex3f(x + 0.8f, y + 0.6f, backZ);

    // Sisi 8
    glVertex3f(x + 0.9f, y + 0.6f, frontZ);
    glVertex3f(x + 0.9f, y + 0.65f, frontZ);
    glVertex3f(x + 0.9f, y + 0.65f, backZ);
    glVertex3f(x + 0.9f, y + 0.6f, backZ);

    // Sisi 9
    glVertex3f(x + 0.9f, y + 0.65f, frontZ);
    glVertex3f(x + 0.8f, y + 0.65f, frontZ);
    glVertex3f(x + 0.8f, y + 0.65f, backZ);
    glVertex3f(x + 0.9f, y + 0.65f, backZ);

    // Sisi 10
    glVertex3f(x + 0.9f, y + 0.75f, frontZ);
    glVertex3f(x + 0.9f, y + 0.6f, frontZ);
    glVertex3f(x + 0.9f, y + 0.6f, backZ);
    glVertex3f(x + 0.9f, y + 0.75f, backZ);

    // Sisi 11
    glVertex3f(x + 0.9f, y + 0.75f, frontZ);
    glVertex3f(x + 0.85f, y + 0.75f, frontZ);
    glVertex3f(x + 0.85f, y + 0.75f, backZ);
    glVertex3f(x + 0.9f, y + 0.75f, backZ);

    // Sisi 12
    glVertex3f(x + 0.85f, y + 0.75f, frontZ);
    glVertex3f(x + 0.85f, y + 0.6f, frontZ);
    glVertex3f(x + 0.85f, y + 0.6f, backZ);
    glVertex3f(x + 0.85f, y + 0.75f, backZ);

    // Sisi 13
    glVertex3f(x + 0.85f, y + 0.75f, frontZ);
    glVertex3f(x + 0.8f, y + 0.75f, frontZ);
    glVertex3f(x + 0.8f, y + 0.75f, backZ);
    glVertex3f(x + 0.85f, y + 0.75f, backZ);

    // Sisi 14
    glVertex3f(x + 0.8f, y + 0.75f, frontZ);
    glVertex3f(x + 0.8f, y + 0.7f, frontZ);
    glVertex3f(x + 0.8f, y + 0.7f, backZ);
    glVertex3f(x + 0.8f, y + 0.75f, backZ);

    // Sisi 15
    glVertex3f(x + 0.8f, y + 0.7f, frontZ);
    glVertex3f(x + 0.9f, y + 0.7f, frontZ);
    glVertex3f(x + 0.9f, y + 0.7f, backZ);
    glVertex3f(x + 0.8f, y + 0.7f, backZ);

    glEnd();
}

void drawObserver (float x, float y){
    glColor3f(0,0,1);
    glTranslatef(x,y, 0.6f);
    glutSolidCone(0.1,0.2,50,50);
    glTranslatef(-x,-y, -0.6f);
}

void drawPlayer1 (float x , float y){
    glColor3f(1,0,0);
    glTranslatef(x,y,0.6f);
    glutSolidSphere(0.1,50,50);
    glTranslatef(-x,-y,-0.6f);
}

void drawPlayer2(float x, float y){
    glColor3f(0,0,0);
    glTranslatef(x,y,0.6f);
    glutSolidCube(0.3);
    glTranslatef(-x,-y,-0.6f);
}

void drawTangga(){
    //MENGGAMBAR TANGGA 1
    
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 0.6; i < 3.6; i += 0.4) {
        // depan
        glBegin(GL_POLYGON);
        glVertex3f(2.2, i, 1.0);
        glVertex3f(2.8, i, 1.0);
        glVertex3f(2.8, i + 0.1, 1.0);
        glVertex3f(2.2, i + 0.1, 1.0);
        glEnd();
        // belakang
        glBegin(GL_POLYGON);
        glVertex3f(2.2, i, 0.7);
        glVertex3f(2.8, i, 0.7);
        glVertex3f(2.8, i + 0.1, 0.7);
        glVertex3f(2.2, i + 0.1, 0.7);
        glEnd();
        // kiri
        glBegin(GL_POLYGON);
        glVertex3f(2.2, i, 1.0);
        glVertex3f(2.2, i, 0.7);
        glVertex3f(2.2, i + 0.1, 0.7);
        glVertex3f(2.2, i + 0.1, 1.0);
        glEnd();
        // kanan
        glBegin(GL_POLYGON);
        glVertex3f(2.8, i, 1.0);
        glVertex3f(2.8, i, 0.7);
        glVertex3f(2.8, i + 0.1, 0.7);
        glVertex3f(2.8, i + 0.1, 1.0);
        glEnd();
        // atas
        glBegin(GL_POLYGON);
        glVertex3f(2.2, i + 0.1, 1.0);
        glVertex3f(2.8, i + 0.1, 1.0);
        glVertex3f(2.8, i + 0.1, 0.7);
        glVertex3f(2.2, i + 0.1, 0.7);
        glEnd();
        // bawah
        glBegin(GL_POLYGON);
        glVertex3f(2.2, i, 1.0);
        glVertex3f(2.8, i, 1.0);
        glVertex3f(2.8, i, 0.7);
        glVertex3f(2.2, i, 0.7);
        glEnd();
    }
    // gagang kiri
    // depan
    glBegin(GL_POLYGON);
    glVertex3f(2.2, 0.4, 1.0);
    glVertex3f(2.3, 0.4, 1.0);
    glVertex3f(2.3, 3.6, 1.0);
    glVertex3f(2.2, 3.6, 1.0);
    glEnd();
    // belakang
    glBegin(GL_POLYGON);
    glVertex3f(2.2, 0.4, 0.7);
    glVertex3f(2.3, 0.4, 0.7);
    glVertex3f(2.3, 3.6, 0.7);
    glVertex3f(2.2, 3.6, 0.7);
    glEnd();
    // kiri
    glBegin(GL_POLYGON);
    glVertex3f(2.2, 0.4, 1.0);
    glVertex3f(2.2, 0.4, 0.7);
    glVertex3f(2.2, 3.6, 0.7);
    glVertex3f(2.2, 3.6, 1.0);
    glEnd();
    // kanan
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 0.4, 1.0);
    glVertex3f(2.3, 0.4, 0.7);
    glVertex3f(2.3, 3.6, 0.7);
    glVertex3f(2.3, 3.6, 1.0);
    glEnd();
    // atas
    glBegin(GL_POLYGON);
    glVertex3f(2.2, 3.6, 1.0);
    glVertex3f(2.3, 3.6, 1.0);
    glVertex3f(2.3, 3.6, 0.7);
    glVertex3f(2.2, 3.6, 0.7);
    glEnd();
    // bawah
    glBegin(GL_POLYGON);
    glVertex3f(2.2, 0.4, 1.0);
    glVertex3f(2.3, 0.4, 1.0);
    glVertex3f(2.3, 0.4, 0.7);
    glVertex3f(2.2, 0.4, 0.7);
    glEnd();

    // gagang kanan
    // depan
    glBegin(GL_POLYGON);
    glVertex3f(2.7, 0.4, 1.0);
    glVertex3f(2.8, 0.4, 1.0);
    glVertex3f(2.8, 3.6, 1.0);
    glVertex3f(2.7, 3.6, 1.0);
    glEnd();
    // belakang
    glBegin(GL_POLYGON);
    glVertex3f(2.7, 0.4, 0.7);
    glVertex3f(2.8, 0.4, 0.7);
    glVertex3f(2.8, 3.6, 0.7);
    glVertex3f(2.7, 3.6, 0.7);
    glEnd();
    // kiri
    glBegin(GL_POLYGON);
    glVertex3f(2.7, 0.4, 1.0);
    glVertex3f(2.7, 0.4, 0.7);
    glVertex3f(2.7, 3.6, 0.7);
    glVertex3f(2.7, 3.6, 1.0);
    glEnd();
    // kanan
    glBegin(GL_POLYGON);
    glVertex3f(2.8, 0.4, 1.0);
    glVertex3f(2.8, 0.4, 0.7);
    glVertex3f(2.8, 3.6, 0.7);
    glVertex3f(2.8, 3.6, 1.0);
    glEnd();
    // atas
    glBegin(GL_POLYGON);
    glVertex3f(2.7, 3.6, 1.0);
    glVertex3f(2.8, 3.6, 1.0);
    glVertex3f(2.8, 3.6, 0.7);
    glVertex3f(2.7, 3.6, 0.7);
    glEnd();
    // bawah
    glBegin(GL_POLYGON);
    glVertex3f(2.7, 0.4, 1.0);
    glVertex3f(2.8, 0.4, 1.0);
    glVertex3f(2.8, 0.4, 0.7);
    glVertex3f(2.7, 0.4, 0.7);
    glEnd();

    

    //MENGGAMBAR TANGGA 2
    
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 8.4 + 0.4; i < 11.5; i += 0.4) {
        // anak tangga
        // depan
        glBegin(GL_POLYGON);
        glVertex3f(6.2, i, 1.0);
        glVertex3f(7.2 - 0.4, i, 1.0);
        glVertex3f(7.2 - 0.4, i + 0.1, 1.0);
        glVertex3f(6.2, i + 0.1, 1.0);
        glEnd();
        // belakang
        glBegin(GL_POLYGON);
        glVertex3f(6.2, i, 0.7);
        glVertex3f(7.2 - 0.4, i, 0.7);
        glVertex3f(7.2 - 0.4, i + 0.1, 0.7);
        glVertex3f(6.2, i + 0.1, 0.7);
        glEnd();
        // kiri
        glBegin(GL_POLYGON);
        glVertex3f(6.2, i, 1.0);
        glVertex3f(6.2, i, 0.7);
        glVertex3f(6.2, i + 0.1, 0.7);
        glVertex3f(6.2, i + 0.1, 1.0);
        glEnd();
        // kanan
        glBegin(GL_POLYGON);
        glVertex3f(7.2 - 0.4, i, 1.0);
        glVertex3f(7.2 - 0.4, i, 0.7);
        glVertex3f(7.2 - 0.4, i + 0.1, 0.7);
        glVertex3f(7.2 - 0.4, i + 0.1, 1.0);
        glEnd();
        // atas
        glBegin(GL_POLYGON);
        glVertex3f(6.2, i + 0.1, 1.0);
        glVertex3f(7.2 - 0.4, i + 0.1, 1.0);
        glVertex3f(7.2 - 0.4, i + 0.1, 0.7);
        glVertex3f(6.2, i + 0.1, 0.7);
        glEnd();
        // bawah
        glBegin(GL_POLYGON);
        glVertex3f(6.2, i, 1.0);
        glVertex3f(7.2 - 0.4, i, 1.0);
        glVertex3f(7.2 - 0.4, i, 0.7);
        glVertex3f(6.2, i, 0.7);
        glEnd();
    }
    // gagang kiri
    // depan
    glBegin(GL_POLYGON);
    glVertex3f(6.2, 8.4, 1.0);
    glVertex3f(6.3, 8.4, 1.0);
    glVertex3f(6.3, 11.5, 1.0);
    glVertex3f(6.2, 11.5, 1.0);
    glEnd();
    // belakang
    glBegin(GL_POLYGON);
    glVertex3f(6.2, 8.4, 0.7);
    glVertex3f(6.3, 8.4, 0.7);
    glVertex3f(6.3, 11.5, 0.7);
    glVertex3f(6.2, 11.5, 0.7);
    glEnd();
    // kiri
    glBegin(GL_POLYGON);
    glVertex3f(6.2, 8.4, 1.0);
    glVertex3f(6.2, 8.4, 0.7);
    glVertex3f(6.2, 11.5, 0.7);
    glVertex3f(6.2, 11.5, 1.0);
    glEnd();
    // kanan
    glBegin(GL_POLYGON);
    glVertex3f(6.3, 8.4, 1.0);
    glVertex3f(6.3, 8.4, 0.7);
    glVertex3f(6.3, 11.5, 0.7);
    glVertex3f(6.3, 11.5, 1.0);
    glEnd();
    // atas
    glBegin(GL_POLYGON);
    glVertex3f(6.2, 11.5, 1.0);
    glVertex3f(6.3, 11.5, 1.0);
    glVertex3f(6.3, 11.5, 0.7);
    glVertex3f(6.2, 11.5, 0.7);
    glEnd();
    // bawah
    glBegin(GL_POLYGON);
    glVertex3f(6.2, 8.4, 1.0);
    glVertex3f(6.3, 8.4, 1.0);
    glVertex3f(6.3, 8.4, 0.7);
    glVertex3f(6.2, 8.4, 0.7);
    glEnd();

    //gagang kanan
    // depan
    glBegin(GL_POLYGON);
    glVertex3f(7.2 - 0.5, 8.4, 1.0);
    glVertex3f(7.2 - 0.4, 8.4, 1.0);
    glVertex3f(7.2 - 0.4, 11.5, 1.0);
    glVertex3f(7.2 - 0.5, 11.5, 1.0);
    glEnd();
    // belakang
    glBegin(GL_POLYGON);
    glVertex3f(7.2 - 0.5, 8.4, 0.7);
    glVertex3f(7.2 - 0.4, 8.4, 0.7);
    glVertex3f(7.2 - 0.4, 11.5, 0.7);
    glVertex3f(7.2 - 0.5, 11.5, 0.7);
    glEnd();
    // kiri
    glBegin(GL_POLYGON);
    glVertex3f(7.2 - 0.5, 8.4, 1.0);
    glVertex3f(7.2 - 0.5, 8.4, 0.7);
    glVertex3f(7.2 - 0.5, 11.5, 0.7);
    glVertex3f(7.2 - 0.5, 11.5, 1.0);
    glEnd();
    // kanan
    glBegin(GL_POLYGON);
    glVertex3f(7.2 - 0.4, 8.4, 1.0);
    glVertex3f(7.2 - 0.4, 8.4, 0.7);
    glVertex3f(7.2 - 0.4, 11.5, 0.7);
    glVertex3f(7.2 - 0.4, 11.5, 1.0);
    glEnd();
    // atas
    glBegin(GL_POLYGON);
    glVertex3f(7.2 - 0.5, 11.5, 1.0);
    glVertex3f(7.2 - 0.4, 11.5, 1.0);
    glVertex3f(7.2 - 0.4, 11.5, 0.7);
    glVertex3f(7.2 - 0.5, 11.5, 0.7);
    glEnd();
    // bawah
    glBegin(GL_POLYGON);
    glVertex3f(7.2 - 0.5, 8.4, 1.0);
    glVertex3f(7.2 - 0.4, 8.4, 1.0);
    glVertex3f(7.2 - 0.4, 8.4, 0.7);
    glVertex3f(7.2 - 0.5, 8.4, 0.7);
    glEnd();

   

    //MENGGAMBAR TANGGA 3
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 0.4 + 0.4; i < 5.4; i += 0.4) {
        //anak tangga
        //depan
        glBegin(GL_POLYGON);
        glVertex3f(i, 5.7, 1.0);
        glVertex3f(i, 5.7 - 0.4, 1.0);
        glVertex3f(i + 0.1, 5.7 - 0.4, 1.0);
        glVertex3f(i + 0.1, 5.7, 1.0);
        glEnd();
        //belakang
        glBegin(GL_POLYGON);
        glVertex3f(i, 5.7, 0.7);
        glVertex3f(i, 5.7 - 0.4, 0.7);
        glVertex3f(i + 0.1, 5.7 - 0.4, 0.7);
        glVertex3f(i + 0.1, 5.7, 0.7);
        glEnd();
        // Sisi kiri
        glBegin(GL_POLYGON);
        glVertex3f(i, 5.7, 1.0);
        glVertex3f(i, 5.7, 0.7);
        glVertex3f(i, 5.7 - 0.4, 0.7);
        glVertex3f(i, 5.7 - 0.4, 1.0);
        glEnd();
        // Sisi kanan
        glBegin(GL_POLYGON);
        glVertex3f(i + 0.1, 5.7, 1.0);
        glVertex3f(i + 0.1, 5.7, 0.7);
        glVertex3f(i + 0.1, 5.7 - 0.4, 0.7);
        glVertex3f(i + 0.1, 5.7 - 0.4, 1.0);
        glEnd();
        // Sisi atas
        glBegin(GL_POLYGON);
        glVertex3f(i, 5.7, 1.0);
        glVertex3f(i, 5.7, 0.7);
        glVertex3f(i + 0.1, 5.7, 0.7);
        glVertex3f(i + 0.1, 5.7, 1.0);
        glEnd();
        // Sisi bawah
        glBegin(GL_POLYGON);
        glVertex3f(i, 5.7 - 0.4, 1.0);
        glVertex3f(i, 5.7 - 0.4, 0.7);
        glVertex3f(i + 0.1, 5.7 - 0.4, 0.7);
        glVertex3f(i + 0.1, 5.7 - 0.4, 1.0);
        glEnd();
    }
    //gagang kiri
    //depan
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7, 1.0);
    glVertex3f(5.4, 5.7, 1.0);
    glVertex3f(5.4, 5.7 + 0.1, 1.0);
    glVertex3f(0.4, 5.7 + 0.1, 1.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7, 0.7);
    glVertex3f(5.4, 5.7, 0.7);
    glVertex3f(5.4, 5.7 + 0.1, 0.7);
    glVertex3f(0.4, 5.7 + 0.1, 0.7);
    glEnd();
    // Kiri
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7, 1.0);
    glVertex3f(0.4, 5.7, 0.7);
    glVertex3f(0.4, 5.7 + 0.1, 0.7);
    glVertex3f(0.4, 5.7 + 0.1, 1.0);
    glEnd();
    // Kanan
    glBegin(GL_POLYGON);
    glVertex3f(5.4, 5.7, 1.0);
    glVertex3f(5.4, 5.7, 0.7);
    glVertex3f(5.4, 5.7 + 0.1, 0.7);
    glVertex3f(5.4, 5.7 + 0.1, 1.0);
    glEnd();
    // Atas
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7 + 0.1, 1.0);
    glVertex3f(5.4, 5.7 + 0.1, 1.0);
    glVertex3f(5.4, 5.7 + 0.1, 0.7);
    glVertex3f(0.4, 5.7 + 0.1, 0.7);
    glEnd();
    // Bawah
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7, 1.0);
    glVertex3f(5.4, 5.7, 1.0);
    glVertex3f(5.4, 5.7, 0.7);
    glVertex3f(0.4, 5.7, 0.7);
    glEnd();

    //gagang kanan
    //depan
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7 - 0.5, 1.0);
    glVertex3f(5.4, 5.7 - 0.5, 1.0);
    glVertex3f(5.4, 5.7 - 0.4, 1.0);
    glVertex3f(0.4, 5.7 - 0.4, 1.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7 - 0.5, 0.7);
    glVertex3f(5.4, 5.7 - 0.5, 0.7);
    glVertex3f(5.4, 5.7 - 0.4, 0.7);
    glVertex3f(0.4, 5.7 - 0.4, 0.7);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7 - 0.5, 1.0);
    glVertex3f(0.4, 5.7 - 0.5, 0.7);
    glVertex3f(0.4, 5.7 - 0.4, 0.7);
    glVertex3f(0.4, 5.7 - 0.4, 1.0);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glVertex3f(5.4, 5.7 - 0.5, 1.0);
    glVertex3f(5.4, 5.7 - 0.5, 0.7);
    glVertex3f(5.4, 5.7 - 0.4, 0.7);
    glVertex3f(5.4, 5.7 - 0.4, 1.0);
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7 - 0.4, 1.0);
    glVertex3f(5.4, 5.7 - 0.4, 1.0);
    glVertex3f(5.4, 5.7 - 0.4, 0.7);
    glVertex3f(0.4, 5.7 - 0.4, 0.7);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 5.7 - 0.5, 1.0);
    glVertex3f(5.4, 5.7 - 0.5, 1.0);
    glVertex3f(5.4, 5.7 - 0.5, 0.7);
    glVertex3f(0.4, 5.7 - 0.5, 0.7);
    glEnd();

    


    //MENGGAMBAR TANGGA 4
    
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 0; i < 3; i += 0.5) {
        // anak tangga
        // depan
        glBegin(GL_POLYGON);
        glVertex3f(2.6f + i, 7.9f + i, 1.0);
        glVertex3f(2.5f + i, 7.8f + i, 1.0);
        glVertex3f(2.95f + i, 7.5f + i, 1.0);
        glVertex3f(3.0f + i, 7.6f + i, 1.0);
        glEnd();
        // belakang
        glBegin(GL_POLYGON);
        glVertex3f(2.6f + i, 7.9f + i, 0.7);
        glVertex3f(2.5f + i, 7.8f + i, 0.7);
        glVertex3f(2.95f + i, 7.5f + i, 0.7);
        glVertex3f(3.0f + i, 7.6f + i, 0.7);
        glEnd();
        // kiri
        glBegin(GL_POLYGON);
        glVertex3f(2.6f + i, 7.9f + i, 1.0);
        glVertex3f(2.5f + i, 7.8f + i, 1.0);
        glVertex3f(2.5f + i, 7.8f + i, 0.7);
        glVertex3f(2.6f + i, 7.9f + i, 0.7);
        glEnd();
        // kanan
        glBegin(GL_POLYGON);
        glVertex3f(2.95f + i, 7.5f + i, 1.0);
        glVertex3f(3.0f + i, 7.6f + i, 1.0);
        glVertex3f(3.0f + i, 7.6f + i, 0.7);
        glVertex3f(2.95f + i, 7.5f + i, 0.7);
        glEnd();
        // atas
        glBegin(GL_POLYGON);
        glVertex3f(2.6f + i, 7.9f + i, 1.0);
        glVertex3f(3.0f + i, 7.6f + i, 1.0);
        glVertex3f(3.0f + i, 7.6f + i, 0.7);
        glVertex3f(2.6f + i, 7.9f + i, 0.7);
        glEnd();
        // bawah
        glBegin(GL_POLYGON);
        glVertex3f(2.5f + i, 7.8f + i, 1.0);
        glVertex3f(2.95f + i, 7.5f + i, 1.0);
        glVertex3f(2.95f + i, 7.5f + i, 0.7);
        glVertex3f(2.5f + i, 7.8f + i, 0.7);
        glEnd();
    }

    //gagang kiri
    // Depan
    glBegin(GL_POLYGON);
    glVertex3f(2.4f, 7.7f, 1.0);
    glVertex3f(2.5f, 7.6f, 1.0);
    glVertex3f(5.4f, 10.7f, 1.0);
    glVertex3f(5.3f, 10.8f, 1.0);
    glEnd();
    // Belakang
    glBegin(GL_POLYGON);
    glVertex3f(2.4f, 7.7f, 0.7);
    glVertex3f(2.5f, 7.6f, 0.7);
    glVertex3f(5.4f, 10.7f, 0.7);
    glVertex3f(5.3f, 10.8f, 0.7);
    glEnd();
    // Sisi Kiri
    glBegin(GL_POLYGON);
    glVertex3f(2.4f, 7.7f, 1.0);
    glVertex3f(2.4f, 7.7f, 0.7);
    glVertex3f(5.3f, 10.8f, 0.7);
    glVertex3f(5.3f, 10.8f, 1.0);
    glEnd();
    // Sisi Kanan
    glBegin(GL_POLYGON);
    glVertex3f(2.5f, 7.6f, 1.0);
    glVertex3f(2.5f, 7.6f, 0.7);
    glVertex3f(5.4f, 10.7f, 0.7);
    glVertex3f(5.4f, 10.7f, 1.0);
    glEnd();
    // Sisi Atas
    glBegin(GL_POLYGON);
    glVertex3f(5.3f, 10.8f, 1.0);
    glVertex3f(5.3f, 10.8f, 0.7);
    glVertex3f(5.4f, 10.7f, 0.7);
    glVertex3f(5.4f, 10.7f, 1.0);
    glEnd();
    // Sisi Bawah
    glBegin(GL_POLYGON);
    glVertex3f(2.4f, 7.7f, 1.0);
    glVertex3f(2.4f, 7.7f, 0.7);
    glVertex3f(2.5f, 7.6f, 0.7);
    glVertex3f(2.5f, 7.6f, 1.0);
    glEnd();

    //gagang kanan
    //depan
    glBegin(GL_POLYGON);
    glVertex3f(2.7f, 7.3f, 1.0);
    glVertex3f(2.8f, 7.2f, 1.0);
    glVertex3f(5.7f, 10.3f, 1.0);
    glVertex3f(5.6f, 10.4f, 1.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(2.7f, 7.3f, 0.7);
    glVertex3f(2.8f, 7.2f, 0.7);
    glVertex3f(5.7f, 10.3f, 0.7);
    glVertex3f(5.6f, 10.4f, 0.7);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glVertex3f(2.7f, 7.3f, 1.0);
    glVertex3f(2.7f, 7.3f, 0.7);
    glVertex3f(2.8f, 7.2f, 0.7);
    glVertex3f(2.8f, 7.2f, 1.0);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glVertex3f(5.7f, 10.3f, 1.0);
    glVertex3f(5.7f, 10.3f, 0.7);
    glVertex3f(5.6f, 10.4f, 0.7);
    glVertex3f(5.6f, 10.4f, 1.0);
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glVertex3f(2.8f, 7.2f, 1.0);
    glVertex3f(2.8f, 7.2f, 0.7);
    glVertex3f(5.7f, 10.3f, 0.7);
    glVertex3f(5.7f, 10.3f, 1.0);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glVertex3f(2.7f, 7.3f, 1.0);
    glVertex3f(2.7f, 7.3f, 0.7);
    glVertex3f(5.6f, 10.4f, 0.7);
    glVertex3f(5.6f, 10.4f, 1.0);
    glEnd();

    
}

void drawUlar(){
        //MENGGAMBAR ULAR 1
    //kepala
    // depan
    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 9.5, 1.0);
    glVertex3f(5.6, 9.5, 1.0);
    glVertex3f(5.6, 7.4, 1.0);
    glVertex3f(5.5, 7.4, 1.0);
    glEnd();
    // belakang
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 9.5, 0.7);
    glVertex3f(5.6, 9.5, 0.7);
    glVertex3f(5.6, 7.4, 0.7);
    glVertex3f(5.5, 7.4, 0.7);
    glEnd();
    // kiri
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 9.5, 1.0);
    glVertex3f(5.5, 9.5, 0.7);
    glVertex3f(5.5, 7.4, 0.7);
    glVertex3f(5.5, 7.4, 1.0);
    glEnd();
    // kanan
    glBegin(GL_POLYGON);
    glVertex3f(5.6, 9.5, 1.0);
    glVertex3f(5.6, 9.5, 0.7);
    glVertex3f(5.6, 7.4, 0.7);
    glVertex3f(5.6, 7.4, 1.0);
    glEnd();
    // atas
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 9.5, 1.0);
    glVertex3f(5.6, 9.5, 1.0);
    glVertex3f(5.6, 9.5, 0.7);
    glVertex3f(5.5, 9.5, 0.7);
    glEnd();
    // bawah
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 7.4, 1.0);
    glVertex3f(5.6, 7.4, 1.0);
    glVertex3f(5.6, 7.4, 0.7);
    glVertex3f(5.5, 7.4, 0.7);
    glEnd();

    //badan
    // Depan
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 7.4, 1.0);
    glVertex3f(5.6, 7.4, 1.0);
    glVertex3f(3.2, 6.2, 1.0);
    glVertex3f(3.1, 6.2, 1.0);
    glEnd();
    // Belakang
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 7.4, 0.7);
    glVertex3f(5.6, 7.4, 0.7);
    glVertex3f(3.2, 6.2, 0.7);
    glVertex3f(3.1, 6.2, 0.7);
    glEnd();
    // Kiri
    glBegin(GL_POLYGON);
    glVertex3f(3.1, 6.2, 1.0);
    glVertex3f(3.1, 6.2, 0.7);
    glVertex3f(5.5, 7.4, 0.7);
    glVertex3f(5.5, 7.4, 1.0);
    glEnd();
    // Kanan
    glBegin(GL_POLYGON);
    glVertex3f(3.2, 6.2, 1.0);
    glVertex3f(3.2, 6.2, 0.7);
    glVertex3f(5.6, 7.4, 0.7);
    glVertex3f(5.6, 7.4, 1.0);
    glEnd();
    // Atas
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 7.4, 1.0);
    glVertex3f(5.5, 7.4, 0.7);
    glVertex3f(5.6, 7.4, 0.7);
    glVertex3f(5.6, 7.4, 1.0);
    glEnd();
    // Bawah
    glBegin(GL_POLYGON);
    glVertex3f(3.1, 6.2, 1.0);
    glVertex3f(3.1, 6.2, 0.7);
    glVertex3f(3.2, 6.2, 0.7);
    glVertex3f(3.2, 6.2, 1.0);
    glEnd();

    //ekor
    // depan
    glBegin(GL_POLYGON);
    glVertex3f(3.1, 6.2, 1.0);
    glVertex3f(3.2, 6.2, 1.0);
    glVertex3f(3.5, 3.5, 1.0);
    glVertex3f(3.5, 3.5, 1.0);
    glEnd();
    // belakang
    glBegin(GL_POLYGON);
    glVertex3f(3.1, 6.2, 0.7);
    glVertex3f(3.2, 6.2, 0.7);
    glVertex3f(3.5, 3.5, 0.7);
    glVertex3f(3.5, 3.5, 0.7);
    glEnd();
    // kiri
    glBegin(GL_POLYGON);
    glVertex3f(3.1, 6.2, 1.0);
    glVertex3f(3.1, 6.2, 0.7);
    glVertex3f(3.5, 3.5, 0.7);
    glVertex3f(3.5, 3.5, 1.0);
    glEnd();
    // kanan
    glBegin(GL_POLYGON);
    glVertex3f(3.2, 6.2, 1.0);
    glVertex3f(3.2, 6.2, 0.7);
    glVertex3f(3.5, 3.5, 0.7);
    glVertex3f(3.5, 3.5, 1.0);
    glEnd();
    // atas
    glBegin(GL_POLYGON);
    glVertex3f(3.1, 6.2, 1.0);
    glVertex3f(3.2, 6.2, 1.0);
    glVertex3f(3.2, 6.2, 0.7);
    glVertex3f(3.1, 6.2, 0.7);
    glEnd();
    // bawah
    glBegin(GL_POLYGON);
    glVertex3f(3.5, 3.5, 1.0);
    glVertex3f(3.5, 3.5, 0.7);
    glVertex3f(3.5, 3.5, 0.7);
    glVertex3f(3.5, 3.5, 1.0);
    glEnd();

    


    //MENGGAMBAR ULAR 2
    //kepala
    //depan
    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.5, 11.5, 1.0);
    glVertex3f(1.6, 11.5, 1.0);
    glVertex3f(2.6, 10.5, 1.0);
    glVertex3f(2.5, 10.5, 1.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(1.5, 11.5, 0.7);
    glVertex3f(1.6, 11.5, 0.7);
    glVertex3f(2.6, 10.5, 0.7);
    glVertex3f(2.5, 10.5, 0.7);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glVertex3f(1.5, 11.5, 1.0);
    glVertex3f(1.5, 11.5, 0.7);
    glVertex3f(2.5, 10.5, 0.7);
    glVertex3f(2.5, 10.5, 1.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glVertex3f(1.6, 11.5, 1.0);
    glVertex3f(1.6, 11.5, 0.7);
    glVertex3f(2.6, 10.5, 0.7);
    glVertex3f(2.6, 10.5, 1.0);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glVertex3f(1.5, 11.5, 1.0);
    glVertex3f(1.6, 11.5, 1.0);
    glVertex3f(1.6, 11.5, 0.7);
    glVertex3f(1.5, 11.5, 0.7);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 10.5, 1.0);
    glVertex3f(2.6, 10.5, 1.0);
    glVertex3f(2.6, 10.5, 0.7);
    glVertex3f(2.5, 10.5, 0.7);
    glEnd();

    //badan
    //depan
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 10.5, 1.0);
    glVertex3f(2.6, 10.5, 1.0);
    glVertex3f(2.6, 9.8, 1.0);
    glVertex3f(2.5, 9.8, 1.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 10.5, 0.7);
    glVertex3f(2.6, 10.5, 0.7);
    glVertex3f(2.6, 9.8, 0.7);
    glVertex3f(2.5, 9.8, 0.7);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 10.5, 1.0);
    glVertex3f(2.5, 10.5, 0.7);
    glVertex3f(2.5, 9.8, 0.7);
    glVertex3f(2.5, 9.8, 1.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glVertex3f(2.6, 10.5, 1.0);
    glVertex3f(2.6, 10.5, 0.7);
    glVertex3f(2.6, 9.8, 0.7);
    glVertex3f(2.6, 9.8, 1.0);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 10.5, 1.0);
    glVertex3f(2.6, 10.5, 1.0);
    glVertex3f(2.6, 10.5, 0.7);
    glVertex3f(2.5, 10.5, 0.7);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 9.8, 1.0);
    glVertex3f(2.6, 9.8, 1.0);
    glVertex3f(2.6, 9.8, 0.7);
    glVertex3f(2.5, 9.8, 0.7);
    glEnd();

    //ekor
    // Depan
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 9.8, 1.0);
    glVertex3f(2.6, 9.8, 1.0);
    glVertex3f(1.5, 9.3, 1.0);
    glVertex3f(1.5, 9.3, 1.0);
    glEnd();
    // Belakang
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 9.8, 0.7);
    glVertex3f(2.6, 9.8, 0.7);
    glVertex3f(1.5, 9.3, 0.7);
    glVertex3f(1.5, 9.3, 0.7);
    glEnd();
    // Kiri
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 9.8, 1.0);
    glVertex3f(2.5, 9.8, 0.7);
    glVertex3f(1.5, 9.3, 0.7);
    glVertex3f(1.5, 9.3, 1.0);
    glEnd();
    // Kanan
    glBegin(GL_POLYGON);
    glVertex3f(2.6, 9.8, 1.0);
    glVertex3f(2.6, 9.8, 0.7);
    glVertex3f(1.5, 9.3, 0.7);
    glVertex3f(1.5, 9.3, 1.0);
    glEnd();
    // Atas
    glBegin(GL_POLYGON);
    glVertex3f(2.5, 9.8, 1.0);
    glVertex3f(2.6, 9.8, 1.0);
    glVertex3f(2.6, 9.8, 0.7);
    glVertex3f(2.5, 9.8, 0.7);
    glEnd();
    // Bawah
    glBegin(GL_POLYGON);
    glVertex3f(1.5, 9.3, 1.0);
    glVertex3f(1.5, 9.3, 0.7);
    glVertex3f(2.6, 9.8, 0.7);
    glVertex3f(2.6, 9.8, 1.0);
    glEnd();

    


    //MENGGAMBAR ULAR 3
    
    glColor3f(0.0,0.0,1.0);
    //kepala
    // Depan
    glBegin(GL_POLYGON);
    glVertex3f(6.5, 3.5, 1.0);
    glVertex3f(6.5 + 0.1, 3.5, 1.0);
    glVertex3f(5.5 + 0.1, 2.4, 1.0);
    glVertex3f(5.5, 2.4, 1.0);
    glEnd();
    // Belakang
    glBegin(GL_POLYGON);
    glVertex3f(6.5, 3.5, 0.7);
    glVertex3f(6.5 + 0.1, 3.5, 0.7);
    glVertex3f(5.5 + 0.1, 2.4, 0.7);
    glVertex3f(5.5, 2.4, 0.7);
    glEnd();
    // Left side
    glBegin(GL_POLYGON);
    glVertex3f(6.5, 3.5, 1.0);
    glVertex3f(6.5, 3.5, 0.7);
    glVertex3f(5.5, 2.4, 0.7);
    glVertex3f(5.5, 2.4, 1.0);
    glEnd();
    // Right side
    glBegin(GL_POLYGON);
    glVertex3f(6.6, 3.5, 1.0);
    glVertex3f(6.6, 3.5, 0.7);
    glVertex3f(5.6, 2.4, 0.7);
    glVertex3f(5.6, 2.4, 1.0);
    glEnd();
    // Top side
    glBegin(GL_POLYGON);
    glVertex3f(6.5, 3.5, 1.0);
    glVertex3f(6.6, 3.5, 1.0);
    glVertex3f(6.6, 3.5, 0.7);
    glVertex3f(6.5, 3.5, 0.7);
    glEnd();
    // Bottom side
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 2.4, 1.0);
    glVertex3f(5.6, 2.4, 1.0);
    glVertex3f(5.6, 2.4, 0.7);
    glVertex3f(5.5, 2.4, 0.7);
    glEnd();


    //badan
    // Depan
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 2.4, 1.0);
    glVertex3f(5.6, 2.4, 1.0);
    glVertex3f(6.2, 1.7, 1.0);
    glVertex3f(6.1, 1.7, 1.0);
    glEnd();
    // Belakang
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 2.4, 0.7);
    glVertex3f(5.6, 2.4, 0.7);
    glVertex3f(6.2, 1.7, 0.7);
    glVertex3f(6.1, 1.7, 0.7);
    glEnd();
    // Kiri
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 2.4, 1.0);
    glVertex3f(5.5, 2.4, 0.7);
    glVertex3f(6.1, 1.7, 0.7);
    glVertex3f(6.1, 1.7, 1.0);
    glEnd();
    // Kanan
    glBegin(GL_POLYGON);
    glVertex3f(5.6, 2.4, 1.0);
    glVertex3f(5.6, 2.4, 0.7);
    glVertex3f(6.2, 1.7, 0.7);
    glVertex3f(6.2, 1.7, 1.0);
    glEnd();
    // Atas
    glBegin(GL_POLYGON);
    glVertex3f(5.5, 2.4, 1.0);
    glVertex3f(5.6, 2.4, 1.0);
    glVertex3f(5.6, 2.4, 0.7);
    glVertex3f(5.5, 2.4, 0.7);
    glEnd();
    // Bawah
    glBegin(GL_POLYGON);
    glVertex3f(6.1, 1.7, 1.0);
    glVertex3f(6.2, 1.7, 1.0);
    glVertex3f(6.2, 1.7, 0.7);
    glVertex3f(6.1, 1.7, 0.7);
    glEnd();

    //ekor
    // Depan
    glBegin(GL_POLYGON);
    glVertex3f(6.1, 1.7, 1.0);
    glVertex3f(6.1 + 0.1, 1.7, 1.0);
    glVertex3f(4.5, 0.7, 1.0);
    glVertex3f(4.5, 0.7, 1.0);
    glEnd();
    // Belakang
    glBegin(GL_POLYGON);
    glVertex3f(6.1, 1.7, 0.7);
    glVertex3f(6.1 + 0.1, 1.7, 0.7);
    glVertex3f(4.5, 0.7, 0.7);
    glVertex3f(4.5, 0.7, 0.7);
    glEnd();
    //Kiri
    glBegin(GL_POLYGON);
    glVertex3f(6.1, 1.7, 1.0);
    glVertex3f(6.1, 1.7, 0.7);
    glVertex3f(4.5, 0.7, 0.7);
    glVertex3f(4.5, 0.7, 1.0);
    glEnd();
    //Kanan
    glBegin(GL_POLYGON);
    glVertex3f(6.1 + 0.1, 1.7, 1.0);
    glVertex3f(6.1 + 0.1, 1.7, 0.7);
    glVertex3f(4.5, 0.7, 0.7);
    glVertex3f(4.5, 0.7, 1.0);
    glEnd();
    //Atas
    glBegin(GL_POLYGON);
    glVertex3f(6.1, 1.7, 1.0);
    glVertex3f(6.1 + 0.1, 1.7, 1.0);
    glVertex3f(6.1 + 0.1, 1.7, 0.7);
    glVertex3f(6.1, 1.7, 0.7);
    glEnd();
    //Bawah
    glBegin(GL_POLYGON);
    glVertex3f(4.5, 0.7, 1.0);
    glVertex3f(4.5, 0.7, 0.7);
    glVertex3f(6.1 + 0.1, 1.7, 0.7);
    glVertex3f(6.1, 1.7, 1.0);
    glEnd();


    
}
void drawKotak(bool warna_transparan) {


    if (warna_transparan) {
        glColor4f(0.5,1,0.5, 0.2);} //Warna Transparan
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


    //kotak 2


    if (warna_transparan) {
        glColor4f(1,1,0.5, 0.2);} //Warna Transparan
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
        glVertex3f(1,0,0);
        glVertex3f(1,1,0);
        glVertex3f(2,1,0);
        glVertex3f(2,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,0,0);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(2,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,0,0);
        glVertex3f(1,0,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,0,0);
        glVertex3f(1,0,0.5);
        glVertex3f(2,0,0.5);
        glVertex3f(2,0,0);
    glEnd();


    //kotak 3

    if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,0,0.5);
        glVertex3f(3,0,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(2,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,0,0);
        glVertex3f(2,1,0);
        glVertex3f(3,1,0);
        glVertex3f(3,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,0,0);
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(2,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,0,0);
        glVertex3f(2,0,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,0,0);
        glVertex3f(2,0,0.5);
        glVertex3f(3,0,0.5);
        glVertex3f(3,0,0);
    glEnd();


    //kotak 4

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,0,0.5);
        glVertex3f(4,0,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(3,1,0.5);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,0,0);
        glVertex3f(3,1,0);
        glVertex3f(4,1,0);
        glVertex3f(4,0,0);
    glEnd();

    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,0,0);
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(4,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,0,0);
        glVertex3f(3,0,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,1,0);
        glVertex3f(3,1,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(4,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,0,0);
        glVertex3f(3,0,0.5);
        glVertex3f(4,0,0.5);
        glVertex3f(4,0,0);
    glEnd();

    drawFour(3.0,0.0,0.7,0.1);

    //kotak 5

    if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
        glBegin(GL_POLYGON);
            // Sisi depan
            glVertex3f(4,0,0.5);
            glVertex3f(5,0,0.5);
            glVertex3f(5,1,0.5);
            glVertex3f(4,1,0.5);
        glEnd();

        glBegin(GL_POLYGON);
            // Sisi belakang
            glVertex3f(4,0,0);
            glVertex3f(4,1,0);
            glVertex3f(5,1,0);
            glVertex3f(5,0,0);
        glEnd();

        glBegin(GL_POLYGON);
            // Sisi kanan
            glVertex3f(5,0,0);
            glVertex3f(5,1,0);
            glVertex3f(5,1,0.5);
            glVertex3f(5,0,0.5);
        glEnd();
        glBegin(GL_POLYGON);
            // Sisi kiri
            glVertex3f(4,0,0);
            glVertex3f(4,0,0.5);
            glVertex3f(4,1,0.5);
            glVertex3f(4,1,0);
        glEnd();
         glBegin(GL_POLYGON);
            // Sisi atas
            glVertex3f(4,1,0);
            glVertex3f(4,1,0.5);
            glVertex3f(5,1,0.5);
            glVertex3f(5,1,0);
        glEnd();
         glBegin(GL_POLYGON);
            // Sisi atas
            glVertex3f(4,0,0);
            glVertex3f(4,0,0.5);
            glVertex3f(5,0,0.5);
            glVertex3f(5,0,0);
        glEnd();


    //kotak 6

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,1,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(6,0,0.5);
        glVertex3f(5,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,1,0);
        glVertex3f(6,1,0);
        glVertex3f(6,0,0);
        glVertex3f(5,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,0,0);
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(6,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,0,0);
        glVertex3f(5,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,0,0);
    glEnd();
     glBegin(GL_POLYGON);
            // Sisi atas
            glVertex3f(5,1,0);
            glVertex3f(5,1,0.5);
            glVertex3f(6,1,0.5);
            glVertex3f(6,1,0);
        glEnd();
         glBegin(GL_POLYGON);
            // Sisi atas
            glVertex3f(5,0,0);
            glVertex3f(5,0,0.5);
            glVertex3f(6,0,0.5);
            glVertex3f(6,0,0);
        glEnd();
    drawSix(5.0,0.0,0.7,0.1);


    //kotak 7

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,0,0.5);
        glVertex3f(7,0,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(6,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,0,0);
        glVertex3f(6,1,0);
        glVertex3f(7,1,0);
        glVertex3f(7,0,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,0,0);
        glVertex3f(7,1,0);
        glVertex3f(7,1,0.5);
        glVertex3f(7,0,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,0,0);
        glVertex3f(6,0,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(6,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(7,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,0,0);
        glVertex3f(6,0,0.5);
        glVertex3f(7,0,0.5);
        glVertex3f(7,0,0);
    glEnd();


    //kotak 8

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,1,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(6,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,1,0);
        glVertex3f(6,2,0);
        glVertex3f(7,2,0);
        glVertex3f(7,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,1,0);
        glVertex3f(7,2,0);
        glVertex3f(7,2,0.5);
        glVertex3f(7,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(6,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(7,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,1,0);
        glVertex3f(6,1,0.5);
        glVertex3f(7,1,0.5);
        glVertex3f(7,1,0);
    glEnd();


    //kotak 9

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,2,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(5,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,2,0);
        glVertex3f(6,2,0);
        glVertex3f(6,1,0);
        glVertex3f(5,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,1,0);
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(6,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,1,0);
        glVertex3f(5,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,1,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,2,0);
        glVertex3f(5,2,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(6,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,1,0);
        glVertex3f(5,1,0.5);
        glVertex3f(6,1,0.5);
        glVertex3f(6,1,0);
    glEnd();


    //kotak 10

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(4,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(5,2,0);
        glVertex3f(5,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,1,0);
        glVertex3f(5,2,0);
        glVertex3f(5,2,0.5);
        glVertex3f(5,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,1,0);
        glVertex3f(4,1,0.5);
        glVertex3f(5,1,0.5);
        glVertex3f(5,1,0);
    glEnd();


    //kotak 11

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,1,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(3,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,1,0);
        glVertex3f(3,2,0);
        glVertex3f(4,2,0);
        glVertex3f(4,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,1,0);
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(4,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,1,0);
        glVertex3f(3,1,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,1,0);
        glVertex3f(3,1,0.5);
        glVertex3f(4,1,0.5);
        glVertex3f(4,1,0);
    glEnd();


    //kotak 12

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(2,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,1,0);
        glVertex3f(2,2,0);
        glVertex3f(3,2,0);
        glVertex3f(3,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,1,0);
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(3,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,1,0);
        glVertex3f(2,1,0.5);
        glVertex3f(3,1,0.5);
        glVertex3f(3,1,0);
    glEnd();


    //kotak 13

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,1,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(1,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,1,0);
        glVertex3f(1,2,0);
        glVertex3f(2,2,0);
        glVertex3f(2,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,1,0);
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(2,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,1,0);
        glVertex3f(1,1,0.5);
        glVertex3f(2,1,0.5);
        glVertex3f(2,1,0);
    glEnd();


    //kotak 14

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(0,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,1,0);
        glVertex3f(0,2,0);
        glVertex3f(1,2,0);
        glVertex3f(1,1,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,1,0);
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(1,1,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(0,2,0.5);
        glVertex3f(0,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,1,0);
        glVertex3f(0,1,0.5);
        glVertex3f(1,1,0.5);
        glVertex3f(1,1,0);
    glEnd();

    drawFour(0.0,1.0,0.7,0.1);
    //kotak 21

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,2,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(6,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,2,0);
        glVertex3f(6,3,0);
        glVertex3f(7,3,0);
        glVertex3f(7,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,2,0);
        glVertex3f(7,3,0);
        glVertex3f(7,3,0.5);
        glVertex3f(7,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(7,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,2,0);
        glVertex3f(6,2,0.5);
        glVertex3f(7,2,0.5);
        glVertex3f(7,2,0);
    glEnd();


    //kotak 20

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,3,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,2,0.5);
        glVertex3f(5,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,3,0);
        glVertex3f(6,3,0);
        glVertex3f(6,2,0);
        glVertex3f(5,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,2,0);
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(6,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,2,0);
        glVertex3f(5,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,2,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,3,0);
        glVertex3f(5,3,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,3,0);
        glVertex3f(5,3,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(6,3,0);
    glEnd();


    //kotak 19

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(4,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,2,0);
        glVertex3f(4,3,0);
        glVertex3f(5,3,0);
        glVertex3f(5,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,2,0);
        glVertex3f(5,3,0);
        glVertex3f(5,3,0.5);
        glVertex3f(5,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,2,0);
        glVertex3f(4,2,0.5);
        glVertex3f(5,2,0.5);
        glVertex3f(5,2,0);
    glEnd();


    //kotak 18

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,2,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(3,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,2,0);
        glVertex3f(3,3,0);
        glVertex3f(4,3,0);
        glVertex3f(4,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,2,0);
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(4,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,2,0);
        glVertex3f(3,2,0.5);
        glVertex3f(4,2,0.5);
        glVertex3f(4,2,0);
    glEnd();


    //kotak 17

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(2,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,2,0);
        glVertex3f(2,3,0);
        glVertex3f(3,3,0);
        glVertex3f(3,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,2,0);
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(3,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,2,0);
        glVertex3f(2,2,0.5);
        glVertex3f(3,2,0.5);
        glVertex3f(3,2,0);
    glEnd();


    //kotak 16

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,2,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(1,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,2,0);
        glVertex3f(1,3,0);
        glVertex3f(2,3,0);
        glVertex3f(2,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,2,0);
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(2,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,2,0);
        glVertex3f(1,2,0.5);
        glVertex3f(2,2,0.5);
        glVertex3f(2,2,0);
    glEnd();
    drawSix(1.0,2.0,0.7,0.1);


    //kotak 15

    if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(0,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,2,0);
        glVertex3f(0,3,0);
        glVertex3f(1,3,0);
        glVertex3f(1,2,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,2,0);
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(1,2,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(0,3,0.5);
        glVertex3f(0,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,2,0);
        glVertex3f(0,2,0.5);
        glVertex3f(1,2,0.5);
        glVertex3f(1,2,0);
    glEnd();


    //kotak 22

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,3,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(6,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,3,0);
        glVertex3f(6,4,0);
        glVertex3f(7,4,0);
        glVertex3f(7,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,3,0);
        glVertex3f(7,4,0);
        glVertex3f(7,4,0.5);
        glVertex3f(7,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(7,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,3,0);
        glVertex3f(6,3,0.5);
        glVertex3f(7,3,0.5);
        glVertex3f(7,3,0);
    glEnd();


    //kotak 23

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,4,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,3,0.5);
        glVertex3f(5,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,4,0);
        glVertex3f(6,4,0);
        glVertex3f(6,3,0);
        glVertex3f(5,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,3,0);
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(6,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,3,0);
        glVertex3f(5,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,3,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,4,0);
        glVertex3f(5,4,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,4,0);
        glVertex3f(5,4,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(6,4,0);
    glEnd();


    //kotak 24

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(4,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,3,0);
        glVertex3f(4,4,0);
        glVertex3f(5,4,0);
        glVertex3f(5,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,3,0);
        glVertex3f(5,4,0);
        glVertex3f(5,4,0.5);
        glVertex3f(5,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,3,0);
        glVertex3f(4,3,0.5);
        glVertex3f(5,3,0.5);
        glVertex3f(5,3,0);
    glEnd();
    drawFour(4.0,3.0,0.7,0.1);

    //kotak 25

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,3,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(3,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,3,0);
        glVertex3f(3,4,0);
        glVertex3f(4,4,0);
        glVertex3f(4,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,3,0);
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(4,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,3,0);
        glVertex3f(3,3,0.5);
        glVertex3f(4,3,0.5);
        glVertex3f(4,3,0);
    glEnd();


    //kotak 26

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,3,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(2,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,3,0);
        glVertex3f(2,4,0);
        glVertex3f(3,4,0);
        glVertex3f(3,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,3,0);
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(3,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,3,0);
        glVertex3f(2,3,0.5);
        glVertex3f(3,3,0.5);
        glVertex3f(3,3,0);
    glEnd();
    drawSix(2.0,3.0,0.7,0.1);


    //kotak 27

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,3,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(1,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,3,0);
        glVertex3f(1,4,0);
        glVertex3f(2,4,0);
        glVertex3f(2,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,3,0);
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(2,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,3,0);
        glVertex3f(1,3,0.5);
        glVertex3f(2,3,0.5);
        glVertex3f(2,3,0);
    glEnd();


    //kotak 28

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,3,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(0,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,3,0);
        glVertex3f(0,4,0);
        glVertex3f(1,4,0);
        glVertex3f(1,3,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,3,0);
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(1,3,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(0,4,0.5);
        glVertex3f(0,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,4,0);
        glVertex3f(0,4,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,3,0);
        glVertex3f(0,3,0.5);
        glVertex3f(1,3,0.5);
        glVertex3f(1,3,0);
    glEnd();




    //kotak 35

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,4,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(6,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,4,0);
        glVertex3f(6,5,0);
        glVertex3f(7,5,0);
        glVertex3f(7,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,4,0);
        glVertex3f(7,5,0);
        glVertex3f(7,5,0.5);
        glVertex3f(7,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(7,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,4,0);
        glVertex3f(6,4,0.5);
        glVertex3f(7,4,0.5);
        glVertex3f(7,4,0);
    glEnd();


    //kotak 34

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,5,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,4,0.5);
        glVertex3f(5,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,5,0);
        glVertex3f(6,5,0);
        glVertex3f(6,4,0);
        glVertex3f(5,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,4,0);
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(6,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,4,0);
        glVertex3f(5,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,4,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,5,0);
        glVertex3f(5,5,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,5,0);
        glVertex3f(5,5,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(6,5,0);
    glEnd();
    drawFour(5.0,4.0,0.7,0.1);

    //kotak 33

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(4,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,4,0);
        glVertex3f(4,5,0);
        glVertex3f(5,5,0);
        glVertex3f(5,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,4,0);
        glVertex3f(5,5,0);
        glVertex3f(5,5,0.5);
        glVertex3f(5,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,4,0);
        glVertex3f(4,4,0.5);
        glVertex3f(5,4,0.5);
        glVertex3f(5,4,0);
    glEnd();


    //kotak 32

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,4,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(3,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,4,0);
        glVertex3f(3,5,0);
        glVertex3f(4,5,0);
        glVertex3f(4,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,4,0);
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(4,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,4,0);
        glVertex3f(3,4,0.5);
        glVertex3f(4,4,0.5);
        glVertex3f(4,4,0);
    glEnd();


    //kotak 31

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,4,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(2,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,4,0);
        glVertex3f(2,5,0);
        glVertex3f(3,5,0);
        glVertex3f(3,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,4,0);
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(3,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,4,0);
        glVertex3f(2,4,0.5);
        glVertex3f(3,4,0.5);
        glVertex3f(3,4,0);
    glEnd();


    //kotak 30

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,4,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(1,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,4,0);
        glVertex3f(1,5,0);
        glVertex3f(2,5,0);
        glVertex3f(2,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,4,0);
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(2,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,4,0);
        glVertex3f(1,4,0.5);
        glVertex3f(2,4,0.5);
        glVertex3f(2,4,0);
    glEnd();


    //kotak 29

    if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,4,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(0,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,4,0);
        glVertex3f(0,5,0);
        glVertex3f(1,5,0);
        glVertex3f(1,4,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,4,0);
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(1,4,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,4,0);
        glVertex3f(0,4,0.5);
        glVertex3f(0,5,0.5);
        glVertex3f(0,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,5,0);
        glVertex3f(0,5,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,4,0);
        glVertex3f(0,4,0.5);
        glVertex3f(1,4,0.5);
        glVertex3f(1,4,0);
    glEnd();


    //kotak 36

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,5,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(6,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,5,0);
        glVertex3f(6,6,0);
        glVertex3f(7,6,0);
        glVertex3f(7,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,5,0);
        glVertex3f(7,6,0);
        glVertex3f(7,6,0.5);
        glVertex3f(7,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(7,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,5,0);
        glVertex3f(6,5,0.5);
        glVertex3f(7,5,0.5);
        glVertex3f(7,5,0);
    glEnd();
    drawSix(6.0,5.0,0.7,0.1);

    //kotak 37

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,6,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,5,0.5);
        glVertex3f(5,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,6,0);
        glVertex3f(6,6,0);
        glVertex3f(6,5,0);
        glVertex3f(5,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,5,0);
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(6,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,5,0);
        glVertex3f(5,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,5,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,6,0);
        glVertex3f(5,6,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,6,0);
        glVertex3f(5,6,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(6,6,0);
    glEnd();


    //kotak 38

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(4,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,5,0);
        glVertex3f(4,6,0);
        glVertex3f(5,6,0);
        glVertex3f(5,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,5,0);
        glVertex3f(5,6,0);
        glVertex3f(5,6,0.5);
        glVertex3f(5,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,5,0);
        glVertex3f(4,5,0.5);
        glVertex3f(5,5,0.5);
        glVertex3f(5,5,0);
    glEnd();


    //kotak 39

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,5,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(3,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,5,0);
        glVertex3f(3,6,0);
        glVertex3f(4,6,0);
        glVertex3f(4,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,5,0);
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(4,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,5,0);
        glVertex3f(3,5,0.5);
        glVertex3f(4,5,0.5);
        glVertex3f(4,5,0);
    glEnd();


    //kotak 40

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,5,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(2,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,5,0);
        glVertex3f(2,6,0);
        glVertex3f(3,6,0);
        glVertex3f(3,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,5,0);
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(3,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,5,0);
        glVertex3f(2,5,0.5);
        glVertex3f(3,5,0.5);
        glVertex3f(3,5,0);
    glEnd();
    drawFour(2.0,5.0,0.7,0.1);

    //kotak 41

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,5,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(1,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,5,0);
        glVertex3f(1,6,0);
        glVertex3f(2,6,0);
        glVertex3f(2,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,5,0);
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(2,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,5,0);
        glVertex3f(1,5,0.5);
        glVertex3f(2,5,0.5);
        glVertex3f(2,5,0);
    glEnd();
    drawFour(1.0,5.0,0.7,0.1);

    //kotak 42

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,5,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(0,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,5,0);
        glVertex3f(0,6,0);
        glVertex3f(1,6,0);
        glVertex3f(1,5,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,5,0);
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(1,5,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,5,0);
        glVertex3f(0,5,0.5);
        glVertex3f(0,6,0.5);
        glVertex3f(0,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,6,0);
        glVertex3f(0,6,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,5,0);
        glVertex3f(0,5,0.5);
        glVertex3f(1,5,0.5);
        glVertex3f(1,5,0);
    glEnd();
    drawFour(0.0,5.0,0.7,0.1);

    //kotak 49

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,6,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(6,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,6,0);
        glVertex3f(6,7,0);
        glVertex3f(7,7,0);
        glVertex3f(7,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,6,0);
        glVertex3f(7,7,0);
        glVertex3f(7,7,0.5);
        glVertex3f(7,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(7,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,6,0);
        glVertex3f(6,6,0.5);
        glVertex3f(7,6,0.5);
        glVertex3f(7,6,0);
    glEnd();
    drawFour(6.0,6.0,0.7,0.1);

    //kotak 48

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,7,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,6,0.5);
        glVertex3f(5,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,7,0);
        glVertex3f(6,7,0);
        glVertex3f(6,6,0);
        glVertex3f(5,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,6,0);
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(6,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,6,0);
        glVertex3f(5,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,6,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,7,0);
        glVertex3f(5,7,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,7,0);
        glVertex3f(5,7,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(6,7,0);
    glEnd();
    drawFour(5.0,6.0,0.7,0.1);

    //kotak 47

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(4,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,6,0);
        glVertex3f(4,7,0);
        glVertex3f(5,7,0);
        glVertex3f(5,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,6,0);
        glVertex3f(5,7,0);
        glVertex3f(5,7,0.5);
        glVertex3f(5,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,6,0);
        glVertex3f(4,6,0.5);
        glVertex3f(5,6,0.5);
        glVertex3f(5,6,0);
    glEnd();
    drawFour(4.0,6.0,0.7,0.1);

    //kotak 46

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,6,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(3,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,6,0);
        glVertex3f(3,7,0);
        glVertex3f(4,7,0);
        glVertex3f(4,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,6,0);
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(4,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,6,0);
        glVertex3f(3,6,0.5);
        glVertex3f(4,6,0.5);
        glVertex3f(4,6,0);
    glEnd();
    drawFour(2.8,6.0,0.7,0.1);
    drawSix(3.0,6.0,0.7,0.1);

    //kotak 45

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,6,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(2,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,6,0);
        glVertex3f(2,7,0);
        glVertex3f(3,7,0);
        glVertex3f(3,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,6,0);
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(3,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,6,0);
        glVertex3f(2,6,0.5);
        glVertex3f(3,6,0.5);
        glVertex3f(3,6,0);
    glEnd();
    drawFour(2.0,6.0,0.7,0.1);

    //kotak 44

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,6,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(1,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,6,0);
        glVertex3f(1,7,0);
        glVertex3f(2,7,0);
        glVertex3f(2,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,6,0);
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(2,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,6,0);
        glVertex3f(1,6,0.5);
        glVertex3f(2,6,0.5);
        glVertex3f(2,6,0);
    glEnd();
    drawFour(1.0,6.0,0.7,0.1);
    drawFour(0.8,6.0,0.7,0.1);

    //kotak 43

    if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,6,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(0,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,6,0);
        glVertex3f(0,7,0);
        glVertex3f(1,7,0);
        glVertex3f(1,6,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,6,0);
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(1,6,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,6,0);
        glVertex3f(0,6,0.5);
        glVertex3f(0,7,0.5);
        glVertex3f(0,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,7,0);
        glVertex3f(0,7,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,6,0);
        glVertex3f(0,6,0.5);
        glVertex3f(1,6,0.5);
        glVertex3f(1,6,0);
    glEnd();
    drawFour(0.0,6.0,0.7,0.1);

    //kotak 50

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,7,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(6,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,7,0);
        glVertex3f(6,8,0);
        glVertex3f(7,8,0);
        glVertex3f(7,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,7,0);
        glVertex3f(7,8,0);
        glVertex3f(7,8,0.5);
        glVertex3f(7,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(7,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,7,0);
        glVertex3f(6,7,0.5);
        glVertex3f(7,7,0.5);
        glVertex3f(7,7,0);
    glEnd();


    //kotak 51

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,8,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,7,0.5);
        glVertex3f(5,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,8,0);
        glVertex3f(6,8,0);
        glVertex3f(6,7,0);
        glVertex3f(5,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,7,0);
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(6,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,7,0);
        glVertex3f(5,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,7,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,8,0);
        glVertex3f(5,8,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,8,0);
        glVertex3f(5,8,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(6,8,0);
    glEnd();


    //kotak 52

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(4,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,7,0);
        glVertex3f(4,8,0);
        glVertex3f(5,8,0);
        glVertex3f(5,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,7,0);
        glVertex3f(5,8,0);
        glVertex3f(5,8,0.5);
        glVertex3f(5,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,7,0);
        glVertex3f(4,7,0.5);
        glVertex3f(5,7,0.5);
        glVertex3f(5,7,0);
    glEnd();


    //kotak 53

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,7,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(3,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,7,0);
        glVertex3f(3,8,0);
        glVertex3f(4,8,0);
        glVertex3f(4,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,7,0);
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(4,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,7,0);
        glVertex3f(3,7,0.5);
        glVertex3f(4,7,0.5);
        glVertex3f(4,7,0);
    glEnd();


    //kotak 54

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,7,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(2,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,7,0);
        glVertex3f(2,8,0);
        glVertex3f(3,8,0);
        glVertex3f(3,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,7,0);
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(3,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,7,0);
        glVertex3f(2,7,0.5);
        glVertex3f(3,7,0.5);
        glVertex3f(3,7,0);
    glEnd();
    drawFour(2.0,7.0,0.7,0.1);

    //kotak 55

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,7,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(1,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,7,0);
        glVertex3f(1,8,0);
        glVertex3f(2,8,0);
        glVertex3f(2,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,7,0);
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(2,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,7,0);
        glVertex3f(1,7,0.5);
        glVertex3f(2,7,0.5);
        glVertex3f(2,7,0);
    glEnd();


    //kotak 56

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,7,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(0,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,7,0);
        glVertex3f(0,8,0);
        glVertex3f(1,8,0);
        glVertex3f(1,7,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,7,0);
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(1,7,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,7,0);
        glVertex3f(0,7,0.5);
        glVertex3f(0,8,0.5);
        glVertex3f(0,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,8,0);
        glVertex3f(0,8,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,7,0);
        glVertex3f(0,7,0.5);
        glVertex3f(1,7,0.5);
        glVertex3f(1,7,0);
    glEnd();
    drawSix(0.0,7.0,0.7,0.1);

    //kotak 63

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,8,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(6,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,8,0);
        glVertex3f(6,9,0);
        glVertex3f(7,9,0);
        glVertex3f(7,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,8,0);
        glVertex3f(7,9,0);
        glVertex3f(7,9,0.5);
        glVertex3f(7,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(7,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,8,0);
        glVertex3f(6,8,0.5);
        glVertex3f(7,8,0.5);
        glVertex3f(7,8,0);
    glEnd();
    drawSix(6.0,8.0,0.7,0.1);


    //kotak 62

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,9,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,8,0.5);
        glVertex3f(5,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,9,0);
        glVertex3f(6,9,0);
        glVertex3f(6,8,0);
        glVertex3f(5,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,8,0);
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(6,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,8,0);
        glVertex3f(5,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,8,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,9,0);
        glVertex3f(5,9,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,9,0);
        glVertex3f(5,9,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(6,9,0);
    glEnd();
    drawSix(5.0,8.0,0.7,0.1);

    //kotak 61

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(4,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,8,0);
        glVertex3f(4,9,0);
        glVertex3f(5,9,0);
        glVertex3f(5,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,8,0);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(4,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,8,0);
        glVertex3f(4,8,0.5);
        glVertex3f(5,8,0.5);
        glVertex3f(5,8,0);
    glEnd();
    drawSix(4.0,8.0,0.7,0.1);


    //kotak 60

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,8,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(3,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,8,0);
        glVertex3f(3,9,0);
        glVertex3f(4,9,0);
        glVertex3f(4,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,8,0);
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(4,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,8,0);
        glVertex3f(3,8,0.5);
        glVertex3f(4,8,0.5);
        glVertex3f(4,8,0);
    glEnd();
    drawSix(3.0,8.0,0.7,0.1);

    //kotak 59

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,8,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(2,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,8,0);
        glVertex3f(2,9,0);
        glVertex3f(3,9,0);
        glVertex3f(3,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,8,0);
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(3,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,8,0);
        glVertex3f(2,8,0.5);
        glVertex3f(3,8,0.5);
        glVertex3f(3,8,0);
    glEnd();


    //kotak 58

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,8,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(1,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,8,0);
        glVertex3f(1,9,0);
        glVertex3f(2,9,0);
        glVertex3f(2,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,8,0);
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(2,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,8,0);
        glVertex3f(1,8,0.5);
        glVertex3f(2,8,0.5);
        glVertex3f(2,8,0);
    glEnd();


    //kotak 57

    if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,8,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(0,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,8,0);
        glVertex3f(0,9,0);
        glVertex3f(1,9,0);
        glVertex3f(1,8,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,8,0);
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(1,8,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,8,0);
        glVertex3f(0,8,0.5);
        glVertex3f(0,9,0.5);
        glVertex3f(0,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,9,0);
        glVertex3f(0,9,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,8,0);
        glVertex3f(0,8,0.5);
        glVertex3f(1,8,0.5);
        glVertex3f(1,8,0);
    glEnd();


    //kotak 64

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,9,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(6,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,9,0);
        glVertex3f(6,10,0);
        glVertex3f(7,10,0);
        glVertex3f(7,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,9,0);
        glVertex3f(7,10,0);
        glVertex3f(7,10,0.5);
        glVertex3f(7,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(7,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,9,0);
        glVertex3f(6,9,0.5);
        glVertex3f(7,9,0.5);
        glVertex3f(7,9,0);
    glEnd();
    drawFour(6.0,9.0,0.7,0.1);
    drawSix(5.8,9.0,0.7,0.1);


    //kotak 65

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,10,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,9,0.5);
        glVertex3f(5,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,10,0);
        glVertex3f(6,10,0);
        glVertex3f(6,9,0);
        glVertex3f(5,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,9,0);
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(6,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,9,0);
        glVertex3f(5,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,9,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,10,0);
        glVertex3f(5,10,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,10,0);
        glVertex3f(5,10,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(6,10,0);
    glEnd();
    drawSix(5.0,9.0,0.7,0.1);


    //kotak 66

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(4,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,9,0);
        glVertex3f(4,10,0);
        glVertex3f(5,10,0);
        glVertex3f(5,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,9,0);
        glVertex3f(5,10,0);
        glVertex3f(5,10,0.5);
        glVertex3f(5,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,9,0);
        glVertex3f(4,9,0.5);
        glVertex3f(5,9,0.5);
        glVertex3f(5,9,0);
    glEnd();
    drawSix(4.0,9.0,0.7,0.1);
    drawSix(3.8,9.0,0.7,0.1);


    //kotak 67

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,9,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(3,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,9,0);
        glVertex3f(3,10,0);
        glVertex3f(4,10,0);
        glVertex3f(4,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,9,0);
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(4,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,9,0);
        glVertex3f(3,9,0.5);
        glVertex3f(4,9,0.5);
        glVertex3f(4,9,0);
    glEnd();
    drawSix(3.0,9.0,0.7,0.1);

    //kotak 68

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,9,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(2,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,9,0);
        glVertex3f(2,10,0);
        glVertex3f(3,10,0);
        glVertex3f(3,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,9,0);
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(3,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,9,0);
        glVertex3f(2,9,0.5);
        glVertex3f(3,9,0.5);
        glVertex3f(3,9,0);
    glEnd();
    drawSix(2.0,9.0,0.7,0.1);


    //kotak 69

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,9,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(1,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,9,0);
        glVertex3f(1,10,0);
        glVertex3f(2,10,0);
        glVertex3f(2,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,9,0);
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(2,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,9,0);
        glVertex3f(1,9,0.5);
        glVertex3f(2,9,0.5);
        glVertex3f(2,9,0);
    glEnd();
    drawSix(1.0,9.0,0.7,0.1);


    //kotak 70

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,9,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(0,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,9,0);
        glVertex3f(0,10,0);
        glVertex3f(1,10,0);
        glVertex3f(1,9,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,9,0);
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(1,9,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,9,0);
        glVertex3f(0,9,0.5);
        glVertex3f(0,10,0.5);
        glVertex3f(0,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,10,0);
        glVertex3f(0,10,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,9,0);
        glVertex3f(0,9,0.5);
        glVertex3f(1,9,0.5);
        glVertex3f(1,9,0);
    glEnd();



    //kotak 77

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,10,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(6,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,10,0);
        glVertex3f(6,11,0);
        glVertex3f(7,11,0);
        glVertex3f(7,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,10,0);
        glVertex3f(7,11,0);
        glVertex3f(7,11,0.5);
        glVertex3f(7,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(7,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,10,0);
        glVertex3f(6,10,0.5);
        glVertex3f(7,10,0.5);
        glVertex3f(7,10,0);
    glEnd();


    //kotak 76

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,11,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,10,0.5);
        glVertex3f(5,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,11,0);
        glVertex3f(6,11,0);
        glVertex3f(6,10,0);
        glVertex3f(5,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,10,0);
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(6,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,10,0);
        glVertex3f(5,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,10,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,11,0);
        glVertex3f(5,11,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,11,0);
        glVertex3f(5,11,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(6,11,0);
    glEnd();
    drawSix(5.0,10.0,0.7,0.1);

    //kotak 75

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(4,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,10,0);
        glVertex3f(4,11,0);
        glVertex3f(5,11,0);
        glVertex3f(5,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,10,0);
        glVertex3f(5,11,0);
        glVertex3f(5,11,0.5);
        glVertex3f(5,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,10,0);
        glVertex3f(4,10,0.5);
        glVertex3f(5,10,0.5);
        glVertex3f(5,10,0);
    glEnd();


    //kotak 74

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,10,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(3,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,10,0);
        glVertex3f(3,11,0);
        glVertex3f(4,11,0);
        glVertex3f(4,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,10,0);
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(4,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,10,0);
        glVertex3f(3,10,0.5);
        glVertex3f(4,10,0.5);
        glVertex3f(4,10,0);
    glEnd();
    drawFour(3.0,10.0,0.7,0.1);

    //kotak 73

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,10,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(2,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,10,0);
        glVertex3f(2,11,0);
        glVertex3f(3,11,0);
        glVertex3f(3,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,10,0);
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(3,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,10,0);
        glVertex3f(2,10,0.5);
        glVertex3f(3,10,0.5);
        glVertex3f(3,10,0);
    glEnd();


    //kotak 72

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,10,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(1,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,10,0);
        glVertex3f(1,11,0);
        glVertex3f(2,11,0);
        glVertex3f(2,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,10,0);
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(2,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,10,0);
        glVertex3f(1,10,0.5);
        glVertex3f(2,10,0.5);
        glVertex3f(2,10,0);
    glEnd();


    //kotak 71

    if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,10,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(0,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,10,0);
        glVertex3f(0,11,0);
        glVertex3f(1,11,0);
        glVertex3f(1,10,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,10,0);
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(1,10,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,10,0);
        glVertex3f(0,10,0.5);
        glVertex3f(0,11,0.5);
        glVertex3f(0,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,10,0);
        glVertex3f(0,10,0.5);
        glVertex3f(1,10,0.5);
        glVertex3f(1,10,0);
    glEnd();



    //kotak 78

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(6,11,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(7,12,0.5);
        glVertex3f(6,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(6,11,0);
        glVertex3f(6,12,0);
        glVertex3f(7,12,0);
        glVertex3f(7,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(7,11,0);
        glVertex3f(7,12,0);
        glVertex3f(7,12,0.5);
        glVertex3f(7,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,12,0);
        glVertex3f(6,12,0.5);
        glVertex3f(7,12,0.5);
        glVertex3f(7,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(6,11,0);
        glVertex3f(6,11,0.5);
        glVertex3f(7,11,0.5);
        glVertex3f(7,11,0);
    glEnd();


    //kotak 79

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(5,12,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,11,0.5);
        glVertex3f(5,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(5,12,0);
        glVertex3f(6,12,0);
        glVertex3f(6,11,0);
        glVertex3f(5,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(6,11,0);
        glVertex3f(6,12,0);
        glVertex3f(6,12,0.5);
        glVertex3f(6,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(5,11,0);
        glVertex3f(5,12,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(5,11,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,12,0);
        glVertex3f(5,12,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(5,12,0);
        glVertex3f(5,12,0.5);
        glVertex3f(6,12,0.5);
        glVertex3f(6,12,0);
    glEnd();


    //kotak 80

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(4,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(4,11,0);
        glVertex3f(4,12,0);
        glVertex3f(5,12,0);
        glVertex3f(5,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(5,11,0);
        glVertex3f(5,12,0);
        glVertex3f(5,12,0.5);
        glVertex3f(5,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(4,12,0.5);
        glVertex3f(4,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(5,12,0.5);
        glVertex3f(5,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(4,11,0);
        glVertex3f(4,11,0.5);
        glVertex3f(5,11,0.5);
        glVertex3f(5,11,0);
    glEnd();


    //kotak 81

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(3,11,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,12,0.5);
        glVertex3f(3,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(3,11,0);
        glVertex3f(3,12,0);
        glVertex3f(4,12,0);
        glVertex3f(4,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(4,11,0);
        glVertex3f(4,12,0);
        glVertex3f(4,12,0.5);
        glVertex3f(4,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(3,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,12,0);
        glVertex3f(3,12,0.5);
        glVertex3f(4,12,0.5);
        glVertex3f(4,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(3,11,0);
        glVertex3f(3,11,0.5);
        glVertex3f(4,11,0.5);
        glVertex3f(4,11,0);
    glEnd();


    //kotak 82

     if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(2,11,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(2,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(2,11,0);
        glVertex3f(2,12,0);
        glVertex3f(3,12,0);
        glVertex3f(3,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(3,11,0);
        glVertex3f(3,12,0);
        glVertex3f(3,12,0.5);
        glVertex3f(3,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(2,12,0.5);
        glVertex3f(2,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,12,0);
        glVertex3f(2,12,0.5);
        glVertex3f(3,12,0.5);
        glVertex3f(3,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(2,11,0);
        glVertex3f(2,11,0.5);
        glVertex3f(3,11,0.5);
        glVertex3f(3,11,0);
    glEnd();


    //kotak 83

     if (warna_transparan) {
        glColor4f(0.5,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(0.5,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(1,11,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,12,0.5);
        glVertex3f(1,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(1,11,0);
        glVertex3f(1,12,0);
        glVertex3f(2,12,0);
        glVertex3f(2,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(2,11,0);
        glVertex3f(2,12,0);
        glVertex3f(2,12,0.5);
        glVertex3f(2,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(1,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,12,0);
        glVertex3f(1,12,0.5);
        glVertex3f(2,12,0.5);
        glVertex3f(2,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(1,11,0);
        glVertex3f(1,11,0.5);
        glVertex3f(2,11,0.5);
        glVertex3f(2,11,0);
    glEnd();


    //kotak 84

    if (warna_transparan) {
        glColor4f(1,1,0.5,0.2);} //Warna Transparan
    else {
        glColor3f(1,1,0.5);}
    glBegin(GL_POLYGON);
        // Sisi depan
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(0,12,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi belakang
        glVertex3f(0,11,0);
        glVertex3f(0,12,0);
        glVertex3f(1,12,0);
        glVertex3f(1,11,0);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kanan
        glVertex3f(1,11,0);
        glVertex3f(1,12,0);
        glVertex3f(1,12,0.5);
        glVertex3f(1,11,0.5);
    glEnd();
    glBegin(GL_POLYGON);
        // Sisi kiri
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(0,12,0.5);
        glVertex3f(0,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,12,0);
        glVertex3f(0,12,0.5);
        glVertex3f(1,12,0.5);
        glVertex3f(1,12,0);
    glEnd();
     glBegin(GL_POLYGON);
        // Sisi atas
        glVertex3f(0,11,0);
        glVertex3f(0,11,0.5);
        glVertex3f(1,11,0.5);
        glVertex3f(1,11,0);
    glEnd();
    drawFour(0.0,11.0,0.7,0.1);
}


void drawPagar(){

    // BAWAH
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
     // Depan
        glVertex3f(0, 0, 0.8);
        glVertex3f(7, 0, 0.8);
        glVertex3f(7, 0.1, 0.8);
        glVertex3f(0, 0.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 0, 0.5);
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0.1, 0.5);
        glVertex3f(0, 0.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 0, 0.5);
        glVertex3f(0, 0, 0.8);
        glVertex3f(0, 0.1, 0.8);
        glVertex3f(0, 0.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(7, 0.1, 0.8);
        glVertex3f(7, 0.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 0.1, 0.5);
        glVertex3f(7, 0.1, 0.5);
        glVertex3f(7, 0.1,0.8);
        glVertex3f(0, 0.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();
    // ATAS
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 11.9, 0.8);
        glVertex3f(7, 11.9, 0.8);
        glVertex3f(7, 12, 0.8);
        glVertex3f(0, 12, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 11.9, 0.5);
        glVertex3f(7, 11.9, 0.5);
        glVertex3f(7, 12, 0.5);
        glVertex3f(0, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 11.9, 0.5);
        glVertex3f(0, 11.9, 0.8);
        glVertex3f(0, 12, 0.8);
        glVertex3f(0, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 11.9, 0.5);
        glVertex3f(7, 11.9, 0.8);
        glVertex3f(7, 12, 0.8);
        glVertex3f(7, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 12, 0.5);
        glVertex3f(7, 12, 0.5);
        glVertex3f(7, 12,0.8);
        glVertex3f(0, 12, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 11.9, 0.5);
        glVertex3f(7, 11.9, 0.5);
        glVertex3f(7, 11.9, 0.8);
        glVertex3f(0, 11.9, 0.8);
    glEnd();

    // KIRI
    glBegin(GL_POLYGON);
     // Depan
        glVertex3f(0, 0, 0.8);
        glVertex3f(0.1, 0, 0.8);
        glVertex3f(0.1, 12, 0.8);
        glVertex3f(0, 12, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 0, 0.5);
        glVertex3f(0.1, 0, 0.5);
        glVertex3f(0.1, 12, 0.5);
        glVertex3f(0, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 0, 0.5);
        glVertex3f(0, 0, 0.8);
        glVertex3f(0, 12, 0.8);
        glVertex3f(0, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(0.1, 0, 0.5);
        glVertex3f(0.1, 0, 0.8);
        glVertex3f(0.1, 12, 0.8);
        glVertex3f(0.1, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 12, 0.5);
        glVertex3f(0.1, 12, 0.5);
        glVertex3f(0.1, 12,0.8);
        glVertex3f(0, 12, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(0.1, 0, 0.5);
        glVertex3f(0.1, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();

    // KIRI
    glBegin(GL_POLYGON);
     // Depan
        glVertex3f(7, 0, 0.8);
        glVertex3f(6.9, 0, 0.8);
        glVertex3f(6.9, 12, 0.8);
        glVertex3f(7, 12, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(7, 0, 0.5);
        glVertex3f(6.9, 0, 0.5);
        glVertex3f(6.9, 12, 0.5);
        glVertex3f(7, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(7, 12, 0.8);
        glVertex3f(7, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6.9, 0, 0.5);
        glVertex3f(6.9, 0, 0.8);
        glVertex3f(6.9, 12, 0.8);
        glVertex3f(6.9, 12, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(7, 12, 0.5);
        glVertex3f(6.9, 12, 0.5);
        glVertex3f(6.9, 12,0.8);
        glVertex3f(7, 12, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(6.9, 0, 0.5);
        glVertex3f(6.9, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();


    // PAGAR TENGAH
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 0.9, 0.8);
        glVertex3f(6, 0.9, 0.8);
        glVertex3f(6, 1.1, 0.8);
        glVertex3f(0, 1.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 0.9, 0.5);
        glVertex3f(6, 0.9, 0.5);
        glVertex3f(6, 1.1, 0.5);
        glVertex3f(0, 1.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 0.9, 0.5);
        glVertex3f(0, 0.9, 0.8);
        glVertex3f(0, 1.1, 0.8);
        glVertex3f(0, 1.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 0.9, 0.5);
        glVertex3f(6, 0.9, 0.8);
        glVertex3f(6, 1.1, 0.8);
        glVertex3f(6, 1.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 1.1, 0.5);
        glVertex3f(6, 1.1, 0.5);
        glVertex3f(6, 1.1,0.8);
        glVertex3f(0, 1.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(6, 0, 0.5);
        glVertex3f(6, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();
    // 2
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 1.9, 0.8);
        glVertex3f(7, 1.9, 0.8);
        glVertex3f(7, 2.1, 0.8);
        glVertex3f(1, 2.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 1.9, 0.5);
        glVertex3f(7, 1.9, 0.5);
        glVertex3f(7, 2.1, 0.5);
        glVertex3f(1, 2.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 1.9, 0.5);
        glVertex3f(1, 1.9, 0.8);
        glVertex3f(1, 2.1, 0.8);
        glVertex3f(1, 2.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 1.9, 0.5);
        glVertex3f(7, 1.9, 0.8);
        glVertex3f(7, 2.1, 0.8);
        glVertex3f(7, 2.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 2.1, 0.5);
        glVertex3f(7, 2.1, 0.5);
        glVertex3f(7, 2.1,0.8);
        glVertex3f(1, 2.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0.5);
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(1, 0, 0.8);
    glEnd();
    //3
       glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 2.9, 0.8);
        glVertex3f(6, 2.9, 0.8);
        glVertex3f(6, 3.1, 0.8);
        glVertex3f(0, 3.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 2.9, 0.5);
        glVertex3f(6, 2.9, 0.5);
        glVertex3f(6, 3.1, 0.5);
        glVertex3f(0, 3.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 2.9, 0.5);
        glVertex3f(0, 2.9, 0.8);
        glVertex3f(0, 3.1, 0.8);
        glVertex3f(0, 3.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 2.9, 0.5);
        glVertex3f(6, 2.9, 0.8);
        glVertex3f(6, 3.1, 0.8);
        glVertex3f(6, 3.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 3.1, 0.5);
        glVertex3f(6, 3.1, 0.5);
        glVertex3f(6, 3.1,0.8);
        glVertex3f(0, 3.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(6, 0, 0.5);
        glVertex3f(6, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();

       // 4
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 3.9, 0.8);
        glVertex3f(7, 3.9, 0.8);
        glVertex3f(7, 4.1, 0.8);
        glVertex3f(1, 4.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 3.9, 0.5);
        glVertex3f(7, 3.9, 0.5);
        glVertex3f(7, 4.1, 0.5);
        glVertex3f(1, 4.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 3.9, 0.5);
        glVertex3f(1, 3.9, 0.8);
        glVertex3f(1, 4.1, 0.8);
        glVertex3f(1, 4.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 3.9, 0.5);
        glVertex3f(7, 3.9, 0.8);
        glVertex3f(7, 4.1, 0.8);
        glVertex3f(7, 4.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 4.1, 0.5);
        glVertex3f(7, 4.1, 0.5);
        glVertex3f(7, 4.1,0.8);
        glVertex3f(1, 4.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0.5);
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(1, 0, 0.8);
    glEnd();

      //5
       glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 4.9, 0.8);
        glVertex3f(6, 4.9, 0.8);
        glVertex3f(6, 5.1, 0.8);
        glVertex3f(0, 5.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 4.9, 0.5);
        glVertex3f(6, 4.9, 0.5);
        glVertex3f(6, 5.1, 0.5);
        glVertex3f(0, 5.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 4.9, 0.5);
        glVertex3f(0, 4.9, 0.8);
        glVertex3f(0, 5.1, 0.8);
        glVertex3f(0, 5.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 4.9, 0.5);
        glVertex3f(6, 4.9, 0.8);
        glVertex3f(6, 5.1, 0.8);
        glVertex3f(6, 5.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 5.1, 0.5);
        glVertex3f(6, 5.1, 0.5);
        glVertex3f(6, 5.1,0.8);
        glVertex3f(0, 5.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(6, 0, 0.5);
        glVertex3f(6, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();

      // 6
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 5.9, 0.8);
        glVertex3f(7, 5.9, 0.8);
        glVertex3f(7, 6.1, 0.8);
        glVertex3f(1, 6.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 5.9, 0.5);
        glVertex3f(7, 5.9, 0.5);
        glVertex3f(7, 6.1, 0.5);
        glVertex3f(1, 6.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 5.9, 0.5);
        glVertex3f(1, 5.9, 0.8);
        glVertex3f(1, 6.1, 0.8);
        glVertex3f(1, 6.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 5.9, 0.5);
        glVertex3f(7, 5.9, 0.8);
        glVertex3f(7, 6.1, 0.8);
        glVertex3f(7, 6.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 6.1, 0.5);
        glVertex3f(7, 6.1, 0.5);
        glVertex3f(7, 6.1,0.8);
        glVertex3f(1, 6.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0.5);
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(1, 0, 0.8);
    glEnd();

     //7
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 6.9, 0.8);
        glVertex3f(6, 6.9, 0.8);
        glVertex3f(6, 7.1, 0.8);
        glVertex3f(0, 7.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 6.9, 0.5);
        glVertex3f(6, 6.9, 0.5);
        glVertex3f(6, 7.1, 0.5);
        glVertex3f(0, 7.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 6.9, 0.5);
        glVertex3f(0, 6.9, 0.8);
        glVertex3f(0, 7.1, 0.8);
        glVertex3f(0, 7.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 6.9, 0.5);
        glVertex3f(6, 6.9, 0.8);
        glVertex3f(6, 7.1, 0.8);
        glVertex3f(6, 7.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 7.1, 0.5);
        glVertex3f(6, 7.1, 0.5);
        glVertex3f(6, 7.1,0.8);
        glVertex3f(0, 7.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(6, 0, 0.5);
        glVertex3f(6, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();

      // 8
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 7.9, 0.8);
        glVertex3f(7, 7.9, 0.8);
        glVertex3f(7, 8.1, 0.8);
        glVertex3f(1, 8.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 7.9, 0.5);
        glVertex3f(7, 7.9, 0.5);
        glVertex3f(7, 8.1, 0.5);
        glVertex3f(1, 8.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 7.9, 0.5);
        glVertex3f(1, 7.9, 0.8);
        glVertex3f(1, 8.1, 0.8);
        glVertex3f(1, 8.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 7.9, 0.5);
        glVertex3f(7, 7.9, 0.8);
        glVertex3f(7, 8.1, 0.8);
        glVertex3f(7, 8.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 8.1, 0.5);
        glVertex3f(7, 8.1, 0.5);
        glVertex3f(7, 8.1,0.8);
        glVertex3f(1, 8.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0.5);
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(1, 0, 0.8);
    glEnd();

      //9
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 8.9, 0.8);
        glVertex3f(6, 8.9, 0.8);
        glVertex3f(6, 9.1, 0.8);
        glVertex3f(0, 9.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 8.9, 0.5);
        glVertex3f(6, 8.9, 0.5);
        glVertex3f(6, 9.1, 0.5);
        glVertex3f(0, 9.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 8.9, 0.5);
        glVertex3f(0, 8.9, 0.8);
        glVertex3f(0, 9.1, 0.8);
        glVertex3f(0, 9.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 8.9, 0.5);
        glVertex3f(6, 8.9, 0.8);
        glVertex3f(6, 9.1, 0.8);
        glVertex3f(6, 9.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 9.1, 0.5);
        glVertex3f(6, 9.1, 0.5);
        glVertex3f(6, 9.1,0.8);
        glVertex3f(0, 9.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(6, 0, 0.5);
        glVertex3f(6, 0, 0.8);
        glVertex3f(0, 0, 0.8);
    glEnd();

      // 10
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(1, 9.9, 0.8);
        glVertex3f(7, 9.9, 0.8);
        glVertex3f(7, 10.1, 0.8);
        glVertex3f(1, 10.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(1, 9.9, 0.5);
        glVertex3f(7, 9.9, 0.5);
        glVertex3f(7, 10.1, 0.5);
        glVertex3f(1, 10.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(1, 9.9, 0.5);
        glVertex3f(1, 9.9, 0.8);
        glVertex3f(1, 10.1, 0.8);
        glVertex3f(1, 10.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(7, 9.9, 0.5);
        glVertex3f(7, 9.9, 0.8);
        glVertex3f(7, 10.1, 0.8);
        glVertex3f(7, 10.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(1, 10.1, 0.5);
        glVertex3f(7, 10.1, 0.5);
        glVertex3f(7, 10.1,0.8);
        glVertex3f(1, 10.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(1, 0, 0.5);
        glVertex3f(7, 0, 0.5);
        glVertex3f(7, 0, 0.8);
        glVertex3f(1, 0, 0.8);
    glEnd();
    //11
     glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        // Depan
        glVertex3f(0, 10.9, 0.8);
        glVertex3f(6, 10.9, 0.8);
        glVertex3f(6, 11.1, 0.8);
        glVertex3f(0, 11.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Belakang
        glVertex3f(0, 10.9, 0.5);
        glVertex3f(6, 10.9, 0.5);
        glVertex3f(6, 11.1, 0.5);
        glVertex3f(0, 11.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kiri
        glVertex3f(0, 10.9, 0.5);
        glVertex3f(0, 10.9, 0.8);
        glVertex3f(0, 11.1, 0.8);
        glVertex3f(0, 11.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Kanan
        glVertex3f(6, 10.9, 0.5);
        glVertex3f(6, 10.9, 0.8);
        glVertex3f(6, 11.1, 0.8);
        glVertex3f(6, 11.1, 0.5);
        glEnd();

        glBegin(GL_POLYGON);
        // Atas
        glVertex3f(0, 11.1, 0.5);
        glVertex3f(6, 11.1, 0.5);
        glVertex3f(6, 11.1,0.8);
        glVertex3f(0, 11.1, 0.8);
        glEnd();

        glBegin(GL_POLYGON);
        // Bawah
        glVertex3f(0, 0, 0.5);
        glVertex3f(6, 0, 0.5);
        glVertex3f(6, 0, 0.8);
        glVertex3f(0, 0, 0.8);
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


    if(warna_transparan) {
        drawKotak(true);
    }else {
        drawKotak(false);
    }

    drawPagar();
    drawObserver(geser_oberver_X,geser_oberver_Y );

    drawPlayer1(bidak_player1_X, bidak_player1_Y);
    drawPlayer2(bidak_player2_X, bidak_player2_Y);

    drawTangga();
    drawUlar();


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
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


}
void input(unsigned char key, int x, int y) {
    key = tolower(key); //Agar bisa menginput keyboard huruf besar dan kecil

    if (isRotated) { //Percabangan untuk rotasi papan permainan
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
            if (isRotated) {
                // Simpan sudut rotasi terakhir
                sudut_rotasi_terakhir_x = sudut_rotasi_X;
                sudut_rotasi_terakhir_Y = sudut_rotasi_Y;
                sudut_rotasi_terakhir_Z = sudut_rotasi_Z;
                // Reset sudut rotasi ke awal
                sudut_rotasi_X = 0.0f;
                sudut_rotasi_Y = 0.0f;
                sudut_rotasi_Z = 0.0f;
            } else {
                if (!rotasi_awal_dilakukan) {
                    sudut_rotasi_X = -20.0f;
                    rotasi_awal_dilakukan = true;
                } else {
                    sudut_rotasi_X = sudut_rotasi_terakhir_x;
                    sudut_rotasi_Y = sudut_rotasi_terakhir_Y;
                    sudut_rotasi_Z = sudut_rotasi_terakhir_Z;
                }
            }
            // Mengubah izin rotasi pada papan
            isRotated = !isRotated;
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
        case 27:
            exit(0);
    }
    glutPostRedisplay(); // Mengupdate dipslay atau tampilan

    //Fungsi Penggerak Bidak
    if (key == 32) {
        if (pemenang == 1) {
            cout << "Player 1 Menang" << endl;
        } else if (pemenang == 2 ){
            cout << "Player 2 Menang" << endl;
        }else{
                
        if(giliran_player1) {
            int rand_player1 = rollDice();
            cout << "Player1 Main : " << rand_player1 << " Nilai Dadu"<< endl;
            jumlahlemparan += rand_player1;
            cout << "Kotak Player 1 : " << jumlahlemparan << endl;
            cout <<"===========================================================" <<endl;
            if (jumlahlemparan == 1){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 0.4;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 2){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 0.7;
                giliran_player1 = false;
            }
            // TANGGA 1 
            else if (jumlahlemparan == 3) {
                bidak_player1_X = 2.4;
                bidak_player1_Y = 0.7;
                giliran_player1 = false;
                jumlahlemparan = 26;
                cout << "Player 1 Naik Tangga" << endl;
                bidak_player1_X = 2.4;
                bidak_player1_Y = 3.7;
            }
            else if (jumlahlemparan == 4){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 0.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 5){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 0.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 6){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 0.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 7){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 0.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 8){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan== 9){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 10){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 11){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 12){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 13){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 14){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 15){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 1.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 16){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 2.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 17){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 2.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 18){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 2.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 19){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 2.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 20){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 2.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 21){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 2.7;
                giliran_player1 = false;
            }
            // ULAR 1
            else if (jumlahlemparan == 22){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 3.7;
                giliran_player1 = false;
                cout << "Player 1 tertangkap Ular" << endl;
                jumlahlemparan = 5;
                bidak_player1_X = 4.4;
                bidak_player1_Y = 0.7;
            }
            else if (jumlahlemparan == 23){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 3.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 24){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 3.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 25){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 3.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 26){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 3.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 27){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 3.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 28){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 3.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 29){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 4.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 30){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 4.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 31){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 4.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 32){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 4.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 33){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 4.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 34){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 4.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 35){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 4.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 36){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 5.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 37){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 5.7;
                giliran_player1 = false;
                jumlahlemparan = 42;
                cout << "Player 1 Naik Tangga" << endl;
                bidak_player1_X = 0.4;
                bidak_player1_Y = 5.7;
            }
            else if (jumlahlemparan == 38){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 5.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 39){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 5.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 40){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 5.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 41){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 5.7;
                // jumlahlemparan = 3;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 42){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 5.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 43){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 6.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 44){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 6.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 45){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 6.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 46){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 6.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 47){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 6.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 48){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 6.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 49){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 6.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 50){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 7.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 51){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 7.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 52){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 7.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 53){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 7.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 54){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 7.7;
                giliran_player1 = false;
                jumlahlemparan = 76;
                cout << "Player 1 Naik Tangga" << endl;
                bidak_player1_X = 5.4;
                bidak_player1_Y = 10.7;
            }
            else if (jumlahlemparan == 55){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 7.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 56){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 7.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 57){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 8.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 58){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 8.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 59){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 8.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 60){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 8.7;
                giliran_player1 = false;
            }
           
            else if (jumlahlemparan == 61){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 8.7;
               
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 62){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 8.7;
                giliran_player1 = false;
            }
            // TANGGA 4
            else if (jumlahlemparan == 63){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 8.7;
                giliran_player1 = false;
                jumlahlemparan = 78;
                cout << "Player 1 Naik Tangga" << endl;
                bidak_player1_X = 6.4;
                bidak_player1_Y = 11.7;
            }
            else if (jumlahlemparan == 64){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 9.7;
                giliran_player1 = false;
            }
            // ULAR 2
            else if (jumlahlemparan == 65){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 9.7;
                giliran_player1 = false;
                jumlahlemparan  = 25;
                cout << "Player 1 tertangkap Ular" << endl;
                bidak_player1_X = 3.4;
                bidak_player1_Y = 3.7;
            }
            else if (jumlahlemparan == 66){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 9.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 67){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 9.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 68){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 9.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 69){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 9.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 70){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 9.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 71){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 10.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 72){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 10.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 73){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 10.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 74){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 10.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 75){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 10.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 76){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 10.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 77){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 10.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 78){
                bidak_player1_X = 6.4;
                bidak_player1_Y = 11.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 79){
                bidak_player1_X = 5.4;
                bidak_player1_Y = 11.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 80){
                bidak_player1_X = 4.4;
                bidak_player1_Y = 11.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan == 81){
                bidak_player1_X = 3.4;
                bidak_player1_Y = 11.7;
                giliran_player1 = false;
            }
            //Ular 3 (82-71)
            else if (jumlahlemparan == 82){
                bidak_player1_X = 2.4;
                bidak_player1_Y = 11.7;

                giliran_player1 = false;
            }
            else if (jumlahlemparan == 83){
                bidak_player1_X = 1.4;
                bidak_player1_Y = 11.7;
                giliran_player1 = false;
                jumlahlemparan = 69;
                cout << "Player 1 tertangkap Ular" << endl;
                bidak_player1_X = 1.4;
                bidak_player1_Y = 9.7;
            }
            else if (jumlahlemparan == 84){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 11.7;
                giliran_player1 = false;
            }
            else if (jumlahlemparan > 84){
                bidak_player1_X = 0.4;
                bidak_player1_Y = 11.7;
                cout << "Player2 Menang" << endl;
                pemenang = 1;
            }
         }
         else {
            cout << "Letak Awal Player2 : " << jumlahlemparan2 << endl;
            int rand_player2 = rollDice();
            cout << "Player2 mendapatkan : " << rand_player2 <<" Nilai Dadu"<< endl;
            jumlahlemparan2 += rand_player2;
            cout << "Letak Player2  : " << jumlahlemparan2 << endl;
            cout <<"===========================================================" <<endl;
            if (jumlahlemparan2 == 1){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 0.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 2){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 0.4;
                giliran_player1 = true;
            }
            // TANGGA 1
            else if (jumlahlemparan2 == 3) {
                bidak_player2_X = 2.4;
                bidak_player2_Y = 0.4;
                giliran_player1 = true;
                jumlahlemparan2 = 26;
                cout << "Player 2 Naik Tangga" << endl;
                bidak_player2_X = 2.4;
                bidak_player2_Y = 3.4;
            }
            else if (jumlahlemparan2 == 4){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 0.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 5){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 0.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 6){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 0.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 7){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 0.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 8){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2== 9){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 10){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 11){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 12){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 13){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 14){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 15){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 1.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 16){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 2.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 17){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 2.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 18){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 2.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 19){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 2.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 20){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 2.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 21){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 2.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 22){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 3.4;
                giliran_player1 = true;
                jumlahlemparan2 = 5;
                cout << "Player 2 tertangkap Ular" << endl;
                bidak_player2_X = 4.4;
                bidak_player2_Y = 0.4;
            }
            else if (jumlahlemparan2 == 23){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 3.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 24){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 3.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 25){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 3.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 26){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 3.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 27){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 3.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 28){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 3.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 29){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 4.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 30){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 4.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 31){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 4.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 32){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 4.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 33){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 4.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 34){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 4.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 35){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 4.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 36){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 5.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 37){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 5.4;
                giliran_player1 = true;
                jumlahlemparan2 = 42;
                cout << "Player 2 Naik Tangga" << endl;
                bidak_player2_X = 0.4;
                bidak_player2_Y = 5.4;

            }
            else if (jumlahlemparan2 == 38){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 5.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 39){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 5.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 40){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 5.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 41){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 5.4;
                // jumlahlemparan2 = 3;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 42){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 5.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 43){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 6.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 44){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 6.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 45){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 6.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 46){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 6.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 47){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 6.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 48){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 6.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 49){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 6.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 50){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 7.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 51){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 7.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 52){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 7.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 53){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 7.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 54){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 7.4;
                giliran_player1 = true;
                jumlahlemparan2 = 76;
                cout << "Player 2 Naik Tangga" << endl;
                bidak_player2_X = 5.4;
                bidak_player2_Y = 10.4;

            }
            else if (jumlahlemparan2 == 55){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 7.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 56){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 7.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 57){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 8.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 58){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 8.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 59){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 8.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 60){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 8.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 61){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 8.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 62){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 8.4;
                giliran_player1 = true;
            }
            // TANGgA 4
            else if (jumlahlemparan2 == 63){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 8.4;
                giliran_player1 = true;
                jumlahlemparan2 = 78;
                cout << "Player 2 Naik Tangga" << endl;
                bidak_player2_X = 6.4;
                bidak_player2_Y = 11.4;

            }
            else if (jumlahlemparan2 == 64){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 9.4;
                giliran_player1 = true;
            }
            // ULAR 2
            else if (jumlahlemparan2 == 65){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 9.4;
                giliran_player1 = true;
                jumlahlemparan2 = 25;
                cout << "Player 2 tertangkap Ular" << endl;
                bidak_player2_X = 3.4;
                bidak_player2_Y = 3.4;

            }
            else if (jumlahlemparan2 == 66){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 9.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 67){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 9.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 68){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 9.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 69){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 9.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 70){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 9.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 71){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 10.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 72){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 10.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 73){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 10.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 74){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 10.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 75){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 10.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 76){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 10.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 77){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 10.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 78){
                bidak_player2_X = 6.4;
                bidak_player2_Y = 11.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 79){
                bidak_player2_X = 5.4;
                bidak_player2_Y = 11.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 80){
                bidak_player2_X = 4.4;
                bidak_player2_Y = 11.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 81){
                bidak_player2_X = 3.4;
                bidak_player2_Y = 11.4;
                giliran_player1 = true;
            }
        
            else if (jumlahlemparan2 == 82){
                bidak_player2_X = 2.4;
                bidak_player2_Y = 11.4;

                giliran_player1 = true;
            }
            else if (jumlahlemparan2 == 83){
                bidak_player2_X = 1.4;
                bidak_player2_Y = 11.4;
                giliran_player1 = true;
                jumlahlemparan2 = 69;
                cout << "Player 2 tertangkap Ular" << endl;
                bidak_player2_X = 1.4;
                bidak_player2_Y = 9.4;
            }
            else if (jumlahlemparan2 == 84){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 11.4;
                giliran_player1 = true;
            }
            else if (jumlahlemparan2 > 84){
                bidak_player2_X = 0.4;
                bidak_player2_Y = 11.4;
                cout << "Player2 Menang" << endl;
                pemenang =2;
            }
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
