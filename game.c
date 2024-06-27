#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h> 

#define MAX_TAIL 100

typedef struct {
    int x, y;
} Position;

Position snake, fruit;
int score, tailLength;
Position tail[MAX_TAIL];
enum eDirection direction;

void InitializeGame() {
    direction = STOP;
    snake.x = WIDTH / 2;
    snake.y = HEIGHT / 2;
    fruit.x = rand() % WIDTH;
    fruit.y = rand() % HEIGHT;
    score = 0;
    tailLength = 0;
}

void ClearScreen() {
    system("cls");
}

void DrawBorder() {
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
}

void Draw() {
    const int bufferSize = (WIDTH + 2) * (HEIGHT + 2);
    char buffer[bufferSize];
    memset(buffer, ' ', bufferSize); 

    for (int i = 0; i < WIDTH + 2; i++) {
        buffer[i] = '#';
        buffer[(HEIGHT + 1) * (WIDTH + 2) + i] = '#';
    }
    for (int i = 0; i < HEIGHT + 2; i++) {
        buffer[i * (WIDTH + 2)] = '#';
        buffer[i * (WIDTH + 2) + WIDTH + 1] = '#';
    }

    buffer[(snake.y + 1) * (WIDTH + 2) + snake.x + 1] = 'O';
    buffer[(fruit.y + 1) * (WIDTH + 2) + fruit.x + 1] = 'F';
    for (int i = 0; i < tailLength; i++) {
        buffer[(tail[i].y + 1) * (WIDTH + 2) + tail[i].x + 1] = 'o';
    }

    char scoreText[20];
    sprintf(scoreText, "Wynik: %d", score);
    memcpy(buffer + (HEIGHT + 2) * (WIDTH + 2) - strlen(scoreText) - 1, scoreText, strlen(scoreText));

    ClearScreen();
    for (int i = 0; i < HEIGHT + 2; i++) {
        fwrite(&buffer[i * (WIDTH + 2)], sizeof(char), WIDTH + 2, stdout);
        printf("\n");
    }
}

void ProcessInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': direction = LEFT; break;
            case 'd': direction = RIGHT; break;
            case 'w': direction = UP; break;
            case 's': direction = DOWN; break;
            case 'x': exit(0); break;
        }
    }
}

void UpdateTail() {
    Position prev = {snake.x, snake.y};
    Position temp;
    for (int i = 0; i < tailLength; i++) {
        temp = tail[i];
        tail[i] = prev;
        prev = temp;
    }
}

void UpdatePosition() {
    switch (direction) {
        case LEFT: snake.x--; break;
        case RIGHT: snake.x++; break;
        case UP: snake.y--; break;
        case DOWN: snake.y++; break;
    }

    if (snake.x >= WIDTH) snake.x = 0;
    else if (snake.x < 0) snake.x = WIDTH - 1;
    if (snake.y >= HEIGHT) snake.y = 0;
    else if (snake.y < 0) snake.y = HEIGHT - 1;
}

void CheckCollision() {
    for (int i = 0; i < tailLength; i++)
        if (tail[i].x == snake.x && tail[i].y == snake.y) {
            ClearScreen();
            printf("\n\n\n\n"); 
            for (int j = 0; j < (WIDTH - 12) / 2; j++) printf(" "); 
            printf("Koniec gry! Wynik: %d\n", score);
            char choice;
            do {
                for (int j = 0; j < (WIDTH - 16) / 2; j++) printf(" "); 
                printf("Zagraj ponownie? (y/n): ");
                choice = _getch();
                if (choice == 'y' || choice == 'Y') {
                    InitializeGame();
                    return; 
                } else if (choice == 'n' || choice == 'N') {
                    exit(0);
                }
            } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
        }

    if (snake.x == fruit.x && snake.y == fruit.y) {
        score += 10;
        fruit.x = rand() % WIDTH;
        fruit.y = rand() % HEIGHT;
        tailLength++;
    }
}
void GameLogic() {
    UpdateTail();
    UpdatePosition();
    CheckCollision();
}