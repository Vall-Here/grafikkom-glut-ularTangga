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
void drawFour(float xAtas, float yBawah) {
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.9 + xAtas, 0.6 + yBawah);
    glVertex2f(0.85 + xAtas, 0.6 + yBawah);
    glVertex2f(0.85 + xAtas, 0.90 + yBawah);
    glVertex2f(0.9 + xAtas, 0.90 + yBawah);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.9 + xAtas, 0.90 + yBawah);
    glVertex2f(0.85 + xAtas, 0.90 + yBawah);
    glVertex2f(0.75 + xAtas, 0.72 + yBawah);
    glVertex2f(0.78 + xAtas, 0.72 + yBawah);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.78 + xAtas, 0.76 + yBawah);
    glVertex2f(0.75 + xAtas, 0.71 + yBawah);
    glVertex2f(0.9 + xAtas, 0.71 + yBawah);
    glVertex2f(0.9 + xAtas, 0.76 + yBawah);
    glEnd();
}


void drawSix(float xAtas, float yBawah) {
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);

    glVertex2f(xAtas + 0.9f, yBawah + 0.9f);
    glVertex2f(xAtas + 0.9f, yBawah + 0.85f);
    glVertex2f(xAtas + 0.75f, yBawah + 0.85f);
    glVertex2f(xAtas + 0.75f, yBawah + 0.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(xAtas + 0.75f, yBawah + 0.9f);
    glVertex2f(xAtas + 0.75f, yBawah + 0.6f);
    glVertex2f(xAtas + 0.8f, yBawah + 0.6f);
    glVertex2f(xAtas + 0.8f, yBawah + 0.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(xAtas + 0.8f, yBawah + 0.6f);
    glVertex2f(xAtas + 0.9f, yBawah + 0.6f);
    glVertex2f(xAtas + 0.9f, yBawah + 0.65f);
    glVertex2f(xAtas + 0.8f, yBawah + 0.65f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(xAtas + 0.9f, yBawah + 0.75f);
    glVertex2f(xAtas + 0.9f, yBawah + 0.6f);
    glVertex2f(xAtas + 0.85f, yBawah + 0.6f);
    glVertex2f(xAtas + 0.85f, yBawah + 0.75f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(xAtas + 0.9f, yBawah + 0.75f);
    glVertex2f(xAtas + 0.8f, yBawah + 0.75f);
    glVertex2f(xAtas + 0.8f, yBawah + 0.7f);
    glVertex2f(xAtas + 0.9f, yBawah + 0.7f);
    glEnd();
}



void drawLadder(float startX, float startY, float endX, float endY, int category) {
    switch (category) {
        case 1: // Tangga vertical
            glColor3f(1.0f, 0.0f, 0.0f);
            for (float i = startY+ 0.4 ; i < endY; i+=0.4) {
                // Menggambar anak tangga
                    glBegin(GL_POLYGON);
                    glVertex2f(startX, i );
                    glVertex2f(endX - 0.4, i);
                    glVertex2f(endX -0.4 , i + 0.1);
                    glVertex2f(startX, i + 0.1);
                    glEnd();

            }

            // Menggambar gagang tangga
            glBegin(GL_POLYGON);
            glVertex2f(startX, startY);
            glVertex2f(startX + 0.1, startY);
            glVertex2f(startX + 0.1, endY);
            glVertex2f(startX, endY);
            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(endX - 0.5, startY);
            glVertex2f(endX - 0.4, startY);
            glVertex2f(endX - 0.4, endY);
            glVertex2f(endX - 0.5, endY);
            glEnd();
            break;
        case 2: // Tangga horizontal

            glColor3f(1.0f, 0.0f, 0.0f);
            for (float i = startX + 0.4; i < endX; i += 0.4) {
                glBegin(GL_POLYGON);
                glVertex2f(i, startY);
                glVertex2f(i, endY - 0.4);
                glVertex2f(i + 0.1, endY - 0.4);
                glVertex2f(i + 0.1, startY);
                glEnd();
            }

            // Menggambar gagang tangga
            glBegin(GL_POLYGON);
            glVertex2f(startX, startY);
            glVertex2f(endX, startY);
            glVertex2f(endX, startY + 0.1);
            glVertex2f(startX, startY + 0.1);
            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(startX, endY - 0.5);
            glVertex2f(endX, endY - 0.5);
            glVertex2f(endX, endY - 0.4);
            glVertex2f(startX, endY - 0.4);
            glEnd();
            break;
        case 3: // Tangga diagonal
           glColor3f(1.0f, 0.0f, 0.0f);
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

            for (float i = 0; i < 3; i += 0.5){
            glBegin(GL_POLYGON);
            glVertex2f(2.6f + i, 7.9f + i);
            glVertex2f(2.5f + i, 7.8f + i);
            glVertex2f(2.95f + i, 7.5f + i);
            glVertex2f(3.0f + i, 7.6f + i);

            glEnd();
            }
            break;
        default:

            break;
    }
}

void drawSnake(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(X1, Y1);
    glVertex2f(X1 + 0.1, Y1);
    glVertex2f(X2 + 0.1, Y2);
    glVertex2f(X2, Y2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(X2, Y2);
    glVertex2f(X2 + 0.1, Y2);
    glVertex2f(X3 + 0.1, Y3);
    glVertex2f(X3, Y3);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(X3, Y3);
    glVertex2f(X3 + 0.1, Y3);
    glVertex2f(X4, Y4);
    glVertex2f(X4, Y4);
    glEnd();
}

void drawSquare(float x, float y, bool isDark) {
    if (isDark) {
        glColor3f(0.0, 0.0, 0.8);
    } else {
        glColor3f(0.9, 0.9, 0.9);
    }
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}





void drawPlayer(float x, float y, bool isSquare) {
    if (isSquare) {
        // Draw the player as a square
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x, y - 0.2);
        glVertex2f(x - 0.17, y - 0.2);
        glVertex2f(x - 0.17, y);
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

    int boxNum = 1;
    bool leftToRight = true;

    drawSquare(0,0,true);
    drawSquare(1,0,false);
    drawSquare(2,0,true);
    drawSquare(3,0,false);
    drawFour(3,0);
    drawSquare(4,0,true);
    drawSquare(5,0,false);
    drawSix(5,0);
    drawSquare(6,0,true);
    drawSquare(0,1,false);
    drawSquare(1,1,true);
    drawSquare(2,1,false);
    drawSquare(3,1,true);
    drawSquare(4,1,false);
    drawSquare(5,1,true);
    drawSquare(6,1,false);
    drawSquare(0,2,true);
    drawSquare(1,2,false);
    drawSquare(2,2,true);
    drawSquare(3,2,false);
    drawSquare(4,2,true);
    drawSquare(5,2,false);
    drawSquare(6,2,true);
    drawSquare(0,3,false);
    drawSquare(1,3,true);
    drawSquare(2,3,false);
    drawSquare(3,3,true);
    drawSquare(4,3,false);
    drawSquare(5,3,true);
    drawSquare(6,3,false);
    drawSquare(0,4,true);
    drawSquare(1,4,false);
    drawSquare(2,4,true);
    drawSquare(3,4,false);
    drawSquare(4,4,true);
    drawSquare(5,4,false);
    drawSquare(6,4,true);
    drawSquare(0,5,false);
    drawSquare(1,5,true);
    drawSquare(2,5,false);
    drawSquare(3,5,true);
    drawSquare(4,5,false);
    drawSquare(5,5,true);
    drawSquare(6,5,false);
    drawSquare(0,6,true);
    drawSquare(1,6,false);
    drawSquare(2,6,true);
    drawSquare(3,6,false);
    drawSquare(4,6,true);
    drawSquare(5,6,false);
    drawSquare(6,6,true);
    drawSquare(0,7,false);
    drawSquare(1,7,true);
    drawSquare(2,7,false);
    drawSquare(3,7,true);
    drawSquare(4,7,false);
    drawSquare(5,7,true);
    drawSquare(6,7,false);
    drawSquare(0,8,true);
    drawSquare(1,8,false);
    drawSquare(2,8,true);
    drawSquare(3,8,false);
    drawSquare(4,8,true);
    drawSquare(5,8,false);
    drawSquare(6,8,true);
    drawSquare(0,9,false);
    drawSquare(1,9,true);
    drawSquare(2,9,false);
    drawSquare(3,9,true);
    drawSquare(4,9,false);
    drawSquare(5,9,true);
    drawSquare(6,9,false);
    drawSquare(0,10,true);
    drawSquare(1,10,false);
    drawSquare(2,10,true);
    drawSquare(3,10,false);
    drawSquare(4,10,true);
    drawSquare(5,10,false);
    drawSquare(6,10,true);
    drawSquare(0,11,false);
    drawSquare(1,11,true);
    drawSquare(2,11,false);
    drawSquare(3,11,true);
    drawSquare(4,11,false);
    drawSquare(5,11,true);
    drawSquare(6,11,false);



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

    drawLadder(2.2, 0.4, 3.2, 3.6, 1);
    drawLadder(0.4, 5.7, 5.4, 5.7, 2);
    drawLadder(6.2, 8.4, 7.2, 11.5, 1);
    drawLadder(0, 0, 0, 0, 3);

    drawSnake(5.5, 9.5, 5.5, 7.4, 3.1, 6.2, 3.5, 3.5);
    drawSnake(1.5, 11.5, 2.5, 10.5, 2.5, 9.8, 1.5, 9.3);
    drawSnake(6.5, 3.5, 5.5, 2.4, 6.1, 1.7, 4.5, 0.7);

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
    drawPlayer(player1X, player1Y, true);
    drawPlayer(player2X, player2Y, false);

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


