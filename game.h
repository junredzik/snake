#ifndef GAME_H
#define GAME_H

#define WIDTH 20
#define HEIGHT 20

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};

void InitializeGame();
void Draw();
void ProcessInput();
void GameLogic();

#endif