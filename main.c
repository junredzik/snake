#include "game.h"
#include <windows.h>

int main() {
    InitializeGame();
    while (1 > 0) {
        Draw();
        ProcessInput();
        GameLogic();
        Sleep(100);
    }
    return 0;
}