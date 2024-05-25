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

int rollDice() {
    return (rand() % 6) + 1;
}
void drawFour(float xAtas, float yBawah , float z) {
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.9 + xAtas, 0.6 + yBawah, z);
    glVertex3f(0.85 + xAtas, 0.6 + yBawah, z);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, z);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.9 + xAtas, 0.90 + yBawah, z);
    glVertex3f(0.85 + xAtas, 0.90 + yBawah, z);
    glVertex3f(0.75 + xAtas, 0.72 + yBawah, z);
    glVertex3f(0.78 + xAtas, 0.72 + yBawah, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.78 + xAtas, 0.76 + yBawah, z);
    glVertex3f(0.75 + xAtas, 0.71 + yBawah, z);
    glVertex3f(0.9 + xAtas, 0.71 + yBawah, z);
    glVertex3f(0.9 + xAtas, 0.76 + yBawah, z);
    glEnd();
}


void drawSix(float xAtas, float yBawah, float z) {
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);

    glVertex3f(xAtas + 0.9f, yBawah + 0.9f, z);
    glVertex3f(xAtas + 0.9f, yBawah + 0.85f, z);
    glVertex3f(xAtas + 0.75f, yBawah + 0.85f, z);
    glVertex3f(xAtas + 0.75f, yBawah + 0.9f, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(xAtas + 0.75f, yBawah + 0.9f, z);
    glVertex3f(xAtas + 0.75f, yBawah + 0.6f, z);
    glVertex3f(xAtas + 0.8f, yBawah + 0.6f, z);
    glVertex3f(xAtas + 0.8f, yBawah + 0.9f, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(xAtas + 0.8f, yBawah + 0.6f, z);
    glVertex3f(xAtas + 0.9f, yBawah + 0.6f, z);
    glVertex3f(xAtas + 0.9f, yBawah + 0.65f, z);
    glVertex3f(xAtas + 0.8f, yBawah + 0.65f,z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(xAtas + 0.9f, yBawah + 0.75f, z);
    glVertex3f(xAtas + 0.9f, yBawah + 0.6f, z);
    glVertex3f(xAtas + 0.85f, yBawah + 0.6f, z);
    glVertex3f(xAtas + 0.85f, yBawah + 0.75f, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(xAtas + 0.9f, yBawah + 0.75f, z);
    glVertex3f(xAtas + 0.8f, yBawah + 0.75f, z);
    glVertex3f(xAtas + 0.8f, yBawah + 0.7f, z);
    glVertex3f(xAtas + 0.9f, yBawah + 0.7f, z);
    glEnd();
}

void drawSquare(float x, float y, float z, bool isDark) {
    if (isDark) {
        glColor3f(0.0, 0.0, 0.8);
    } else {
        glColor3f(0.9, 0.9, 0.9);
    }
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x + 1, y, z);
    glVertex3f(x + 1, y + 1, z);
    glVertex3f(x, y + 1, z);
    glEnd();
}

void drawPlayer(float x, float y, float z, bool isSquare) {
    if (isSquare) {
        // Draw the player as a square
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(x, y, z);
        glVertex3f(x, y - 0.2, z);
        glVertex3f(x - 0.17, y - 0.2, z);
        glVertex3f(x - 0.17, y, z);
        glEnd();
    } else {
        // Draw the player as a polygon (default: triangle)
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x - 0.1, y + 0.2);
        glVertex2f(x - 0.2, y);
        glEnd();
    }
}

void rollDiceAndUpdatePosition() {
    currentPlayer = (currentPlayer == 2) ? 1 : 2;

    // Gulir dadu
    diceResult = rollDice();

    // Cetak hasil dadu ke konsol
    printf("Player %d rolled a %d\n", currentPlayer, diceResult);

    // Perbarui posisi pemain sesuai dengan giliran mereka
    int& playerPosition = (currentPlayer == 1) ? player1Position : player2Position;
    playerPosition += diceResult;

    if (playerPosition > rows * cols) {
        playerPosition = rows * cols;
    }

    if (playerPosition == rows * cols) {
        printf("Player %d wins!\n", currentPlayer);

    }

    // Cek jika pemain mendarat di tangga atau ular
    switch (playerPosition) {
        case 3: // Ladder
            printf("Player %d climbed a ladder! Move forward to square 26.\n", currentPlayer);
            playerPosition = 26;
            break;
        case 37: // Ladder
            printf("Player %d climbed a ladder! Move forward to square 42.\n", currentPlayer);
            playerPosition = 42;
            break;
        case 54: // Ladder
            printf("Player %d climbed a ladder! Move forward to square 76.\n", currentPlayer);
            playerPosition = 76;
            break;
        case 63: // Ladder
            printf("Player %d climbed a ladder! Move forward to square 63.\n", currentPlayer);
            playerPosition = 77;
            break;
        case 22: // Snake
            printf("Player %d landed on a snake! Move back to square 5.\n", currentPlayer);
            playerPosition = 5;
            break;
        case 65: // Snake
            printf("Player %d landed on a snake! Move back to square 25.\n", currentPlayer);
            playerPosition = 25;
            break;

        case 83: // Snake
            printf("Player %d landed on a snake! Move back to square 69.\n", currentPlayer);
            playerPosition = 69;
            break;
        default:
            break;
    }


    glutPostRedisplay();
}


void drawBoard() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    //kotak 1
    drawSquare(0,0,0,true);
    drawSquare(0,0,0.25,true);
    //kotak 2
    drawSquare(1,0,0,false);
    drawSquare(1,0,0.25,false);
    //kotak 3
    drawSquare(2,0,0,true);
    drawSquare(2,0,0.25,true);
    //kotak 4
    drawSquare(3,0,0,false);
    drawSquare(3,0,0.25,false);
    drawFour(3,0,1);
    //kotak 5
    drawSquare(4,0,0,true);
    drawSquare(4,0,0.25,true);
    //kotak 6
    drawSquare(5,0,0,false);
    drawSquare(5,0,0.25,false);
    drawSix(5,0, 1);
    //kotak 7
    drawSquare(6,0,0,true);
    drawSquare(6,0,0.25,true);
    //kotak 8
    drawSquare(0,1,0,false);
    drawSquare(0,1,0.25,false);
    //kotak 9
    drawSquare(6,1,0,false);
    drawSquare(6,1,0.25,false);
    //kotak 10
    drawSquare(5,1,0,true);
    drawSquare(5,1,0.25,true);
    //kotak 11
    drawSquare(4,1,0,false);
    drawSquare(4,1,0.25,false);
    //kotak 12
    drawSquare(3,1,0,true);
    drawSquare(3,1,0.25,true);
    //kotak 13
    drawSquare(2,1,0,false);
    drawSquare(2,1,0.25,false);
    //kotak 14
    drawSquare(1,1,0,true);
    drawSquare(1,1,0.25,true);

    drawSquare(0,2,0,true);
    drawSquare(1,2,0,false);
    drawSquare(2,2,0,true);
    drawSquare(3,2,0,false);
    drawSquare(4,2,0,true);
    drawSquare(5,2,0,false);
    drawSquare(6,2,0,true);
    drawSquare(0,3,0,false);
    drawSquare(1,3,0,true);
    drawSquare(2,3,0,false);
    drawSquare(3,3,0,true);
    drawSquare(4,3,0,false);
    drawSquare(5,3,0,true);
    drawSquare(6,3,0,false);
    drawSquare(0,4,0,true);
    drawSquare(1,4,0,false);
    drawSquare(2,4,0,true);
    drawSquare(3,4,0,false);
    drawSquare(4,4,0,true);
    drawSquare(5,4,0,false);
    drawSquare(6,4,0,true);
    drawSquare(0,5,0,false);
    drawSquare(1,5,0,true);
    drawSquare(2,5,0,false);
    drawSquare(3,5,0,true);
    drawSquare(4,5,0,false);
    drawSquare(5,5,0,true);
    drawSquare(6,5,0,false);
    drawSquare(0,6,0,true);
    drawSquare(1,6,0,false);
    drawSquare(2,6,0,true);
    drawSquare(3,6,0,false);
    drawSquare(4,6,0,true);
    drawSquare(5,6,0,false);
    drawSquare(6,6,0,true);
    drawSquare(0,7,0,false);
    drawSquare(1,7,0,true);
    drawSquare(2,7,0,false);
    drawSquare(3,7,0,true);
    drawSquare(4,7,0,false);
    drawSquare(5,7,0,true);
    drawSquare(6,7,0,false);
    drawSquare(0,8,0,true);
    drawSquare(1,8,0,false);
    drawSquare(2,8,0,true);
    drawSquare(3,8,0,false);
    drawSquare(4,8,0,true);
    drawSquare(5,8,0,false);
    drawSquare(6,8,0,true);
    drawSquare(0,9,0,false);
    drawSquare(1,9,0,true);
    drawSquare(2,9,0,false);
    drawSquare(3,9,0,true);
    drawSquare(4,9,0,false);
    drawSquare(5,9,0,true);
    drawSquare(6,9,0,false);
    drawSquare(0,10,0,true);
    drawSquare(1,10,0,false);
    drawSquare(2,10,0,true);
    drawSquare(3,10,0,false);
    drawSquare(4,10,0,true);
    drawSquare(5,10,0,false);
    drawSquare(6,10,0,true);
    drawSquare(0,11,0,false);
    drawSquare(1,11,0,true);
    drawSquare(2,11,0,false);
    drawSquare(3,11,0,true);
    drawSquare(4,11,0,false);
    drawSquare(5,11,0,true);
    drawSquare(6,11,0,false);

    drawFour(0,1,1);
    drawSix(1,2,1);
    drawFour(4,3,1);
    drawSix(2,3,1);
    drawFour(5,4,1);
    drawSix(5.9,5,1);
    drawFour(1,6,1);
    drawFour(0.8,6,1);
    drawSix(3,6,1);
    drawFour(2,7,1);
    drawSix(0,7,1);
    drawFour(5.9,9,1);
    drawSix(4,9,1);
    drawSix(3.8,9,1);
    drawFour(3,10,1);
    drawSix(5,10,1);
    drawFour(0,11,1);

    drawFour(2,5,1);
    drawFour(1,5,1);
    drawFour(0,5,1);
    drawFour(0,6,1);
    drawFour(2,6,1);
    drawFour(2.8,6,1);
    drawFour(4,6,1);
    drawFour(5,6,1);
    drawFour(5.9,6,1);

    drawSix(3,8,1);
    drawSix(4,8,1);
    drawSix(5,8,1);
    drawSix(5.9,8,1);
    drawSix(5.7,9,1);
    drawSix(5,9,1);
    drawSix(4,9,1);
    drawSix(3,9,1);
    drawSix(2,9,1);
    drawSix(1,9,1);


   // Pagar

    for (int i = 0; i < rows; ++i) {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f((i % 2), i + 0.95);
        glVertex2f((i % 2) + 6.0, i + 0.95);
        glVertex2f((i % 2) + 6.0, i + 1.05);
        glVertex2f((i % 2), i + 1.05);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0);
    glVertex2f(cols, 0);
    glVertex2f(cols, 0.1);
    glVertex2f(0.0, 0.1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(cols - 0.1, 0);
    glVertex2f(cols, 0);
    glVertex2f(cols, rows);
    glVertex2f(cols - 0.1, rows);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(cols, rows);
    glVertex2f(0, rows);
    glVertex2f(0, rows - 0.1);
    glVertex2f(cols, rows - 0.1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0, rows);
    glVertex2f(0.1, rows);
    glVertex2f(0.1, 0);
    glVertex2f(0, 0);
    glEnd();

    //MENGGAMBAR TANGGA
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 0.4 + 0.4 ; i < 3.6; i+=0.4) {
        glBegin(GL_POLYGON);
        glVertex2f(2.2, i );
        glVertex2f(3.2 - 0.4, i);
        glVertex2f(3.2 -0.4 , i + 0.1);
        glVertex2f(2.2, i + 0.1);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glVertex2f(2.2, 0.4);
    glVertex2f(2.2 + 0.1, 0.4);
    glVertex2f(2.2 + 0.1, 3.6);
    glVertex2f(2.2, 3.6);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(3.2 - 0.5, 0.4);
    glVertex2f(3.2 - 0.4, 0.4);
    glVertex2f(3.2 - 0.4, 3.6);
    glVertex2f(3.2 - 0.5, 3.6);
    glEnd();

    //MENGGAMBAR TANGGA 2
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 8.4 + 0.4 ; i < 11.5; i+=0.4) {
        glBegin(GL_POLYGON);
        glVertex2f(6.2, i );
        glVertex2f(7.2 - 0.4, i);
        glVertex2f(7.2 -0.4 , i + 0.1);
        glVertex2f(6.2, i + 0.1);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glVertex2f(6.2, 8.4);
    glVertex2f(6.2 + 0.1, 8.4);
    glVertex2f(6.2 + 0.1, 11.5);
    glVertex2f(6.2, 11.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(7.2 - 0.5, 8.4);
    glVertex2f(7.2 - 0.4, 8.4);
    glVertex2f(7.2 - 0.4, 11.5);
    glVertex2f(7.2 - 0.5, 11.5);
    glEnd();

    //MENGGAMBAR TANGGA 3
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 0.4 + 0.4; i < 5.4; i += 0.4) {
        glBegin(GL_POLYGON);
        glVertex2f(i, 5.7);
        glVertex2f(i, 5.7 - 0.4);
        glVertex2f(i + 0.1, 5.7 - 0.4);
        glVertex2f(i + 0.1, 5.7);
        glEnd();
    }

    glBegin(GL_POLYGON);
    glVertex2f(0.4, 5.7);
    glVertex2f(5.4, 5.7);
    glVertex2f(5.4, 5.7 + 0.1);
    glVertex2f(0.4, 5.7 + 0.1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.4, 5.7 - 0.5);
    glVertex2f(5.4, 5.7 - 0.5);
    glVertex2f(5.4, 5.7 - 0.4);
    glVertex2f(0.4, 5.7 - 0.4);
    glEnd();

    //MENGGAMBAR TANGGA 4
    glColor3f(1.0f, 0.0f, 0.0f);
    for (float i = 0; i < 3; i += 0.5){
    glBegin(GL_POLYGON);
    glVertex2f(2.6f + i, 7.9f + i);
    glVertex2f(2.5f + i, 7.8f + i);
    glVertex2f(2.95f + i, 7.5f + i);
    glVertex2f(3.0f + i, 7.6f + i);
    glEnd();
    }

    glBegin(GL_POLYGON);
    glVertex2f(2.4f, 7.7f);
    glVertex2f(2.5f, 7.6f);
    glVertex2f(5.4f, 10.7f);
    glVertex2f(5.3f, 10.8f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.7f, 7.3f);
    glVertex2f(2.8f, 7.2f);
    glVertex2f(5.7f, 10.3f);
    glVertex2f(5.6f, 10.4f);
    glEnd();

    //MENGGAMBAR ULAR
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.5, 9.5);
    glVertex2f(5.5 + 0.1, 9.5);
    glVertex2f(5.5 + 0.1, 7.4);
    glVertex2f(5.5, 7.4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(5.5, 7.4);
    glVertex2f(5.5 + 0.1, 7.4);
    glVertex2f(3.1 + 0.1, 6.2);
    glVertex2f(3.1, 6.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(3.1, 6.2);
    glVertex2f(3.1 + 0.1, 6.2);
    glVertex2f(3.5, 3.5);
    glVertex2f(3.5, 3.5);
    glEnd();

    //MENGGAMBAR ULAR 2
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1.5, 11.5);
    glVertex2f(1.5 + 0.1, 11.5);
    glVertex2f(2.5 + 0.1, 10.5);
    glVertex2f(2.5, 10.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.5, 10.5);
    glVertex2f(2.5 + 0.1, 10.5);
    glVertex2f(2.5 + 0.1, 9.8);
    glVertex2f(2.5, 9.8);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.5, 9.8);
    glVertex2f(2.5 + 0.1, 9.8);
    glVertex2f(1.5, 9.3);
    glVertex2f(1.5, 9.3);
    glEnd();

    //MENGGAMBAR ULAR 3
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(6.5, 3.5);
    glVertex2f(6.5 + 0.1, 3.5);
    glVertex2f(5.5 + 0.1, 2.4);
    glVertex2f(5.5, 2.4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(5.5, 2.4);
    glVertex2f(5.5 + 0.1, 2.4);
    glVertex2f(6.1 + 0.1, 1.7);
    glVertex2f(6.1, 1.7);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(6.1, 1.7);
    glVertex2f(6.1 + 0.1, 1.7);
    glVertex2f(4.5, 0.7);
    glVertex2f(4.5, 0.7);
    glEnd();


    // Calculate player 1 position based on player1Position
    int row1 = (player1Position - 1) / cols;
    int col1 = (player1Position - 1) % cols;
    float player1X, player1Y;

    // Adjust player 1 position based on the direction of movement
    if (row1 % 2 == 0) {
        player1X = col1 + 0.65; // Move right
    } else {
        player1X = cols - col1 - 0.65; // Move left
    }
    player1Y = row1 + 0.35; // Adjust the position to center the player

    // Calculate player 2 position based on player2Position
    int row2 = (player2Position - 1) / cols;
    int col2 = (player2Position - 1) % cols;
    float player2X, player2Y;

    // Adjust player 2 position based on the direction of movement
    if (row2 % 2 == 0) {
        player2X = col2 + 0.65; // Move right
    } else {
        player2X = cols - col2 - 0.65; // Move left
    }
    player2Y = row2 + 0.65; // Adjust the position to center the player

    // Draw players
    drawPlayer(player1X, player1Y, 0, true);
    drawPlayer(player2X, player2Y, 1, false);

    glFlush();
}


// Handle key presses
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 32: // Space key
            rollDiceAndUpdatePosition();
            break;
        default:
            break;
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, cols, 0.0, rows);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ular Tangga");
    glutDisplayFunc(drawBoard);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeypress);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
    return 0;
}
