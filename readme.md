```markdown
# Snake Game

A simple console-based Snake game written in C.

## Overview

This is a classic Snake game implemented in C. The game runs in the console, where the player controls the snake to eat the fruit and grow the tail. The goal is to achieve the highest score possible without colliding with the snake's own tail.

## Features

- Classic Snake game mechanics
- Console-based graphics
- Score tracking
- Option to restart the game after collision

## Getting Started

### Prerequisites

To compile and run this game, you need:

- A C compiler (e.g., GCC)
- Windows operating system (uses `<windows.h>` and `<conio.h>` for console operations)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/snake-game.git
   cd snake-game
```

2. Compile the game:

   ```bash
   gcc -o snake main.c game.c
   ```

### Running the Game

Run the compiled executable:

```bash
./snake
```

### Controls

- `W`: Move up
- `A`: Move left
- `S`: Move down
- `D`: Move right
- `X`: Exit the game

## Code Structure

- `main.c`: Contains the `main` function which initializes and starts the game loop.
- `game.c`: Implements the game logic, including drawing the game board, processing input, and handling collisions.
- `game.h`: Header file defining constants, data structures, and function prototypes used in the game.

## How to Play

1. Launch the game.
2. Use `W`, `A`, `S`, `D` keys to move the snake.
3. Eat the fruit (`F`) to gain points and grow the tail.
4. Avoid colliding with the snake's own tail.
5. If you collide with the tail, you will be prompted to play again.

## Contributing

If you want to contribute to this project, feel free to fork the repository and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project was inspired by the classic Snake game.
