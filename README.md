# Game of Life

## Description
Game of Life is a simple implementation of Conway's Game of Life using the terminal. The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway. It is a zero-player game that simulates the evolution of a grid of cells based on a set of rules. Each cell can be in one of two states: alive or dead. The rules determine the state of each cell in the next generation based on its current state and the states of its eight neighbors.

## Features
- Random initialization of the grid with the ability to specify a seed value
- Continuously updated display of the grid as the generations evolve
- Clear visualization of the alive and dead cells using ASCII characters
- Terminal-based user interface for ease of use

## Setup
1. Ensure you have a C compiler installed on your system (e.g., GCC).
2. Clone the repository or download the source code files.
3. Navigate to the directory containing the source code files.
4. Compile the program using the following command: `gcc game_of_life.c -o game_of_life`
6. Run the compiled executable: `game_of_life`
7. Enter a seed value when prompted to initialize the grid.
8. Observe the Game of Life simulation running in the terminal window.
9. To stop the simulation, use `Ctrl+C` to send the SIGINT signal.

Enjoy the Game of Life simulation!
