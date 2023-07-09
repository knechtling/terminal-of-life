#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 40

// Function to initialize the grid with random values
void initialize_grid(bool grid[HEIGHT][WIDTH], int seed) {
    srand(seed);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the current state of the grid
void print_grid(bool grid[HEIGHT][WIDTH]) {
    system("clear"); // Use system("cls") for Windows
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j]) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to calculate the next generation of the grid
void get_next_generation(bool grid[HEIGHT][WIDTH], bool next_grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Count the number of live neighbors
            int live_neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    int neighbor_x = (i + x + HEIGHT) % HEIGHT;
                    int neighbor_y = (j + y + WIDTH) % WIDTH;
                    live_neighbors += grid[neighbor_x][neighbor_y];
                }
            }

            // Apply the rules of the game
            if (grid[i][j] && (live_neighbors < 2 || live_neighbors > 3)) {
                next_grid[i][j] = false;  // Cell dies due to underpopulation or overpopulation
            } else if (!grid[i][j] && live_neighbors == 3) {
                next_grid[i][j] = true;   // Cell becomes alive due to reproduction
            } else {
                next_grid[i][j] = grid[i][j]; // Cell stays the same
            }
        }
    }
}

int main() {
    bool grid[HEIGHT][WIDTH];
    bool next_grid[HEIGHT][WIDTH];
    int seed;

    printf("Enter seed value: ");
    scanf("%d", &seed);

    initialize_grid(grid, seed);

    while (1) {
        print_grid(grid);

        get_next_generation(grid, next_grid);

        // Copy the elements from next_grid to grid
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                grid[i][j] = next_grid[i][j];
            }
        }

        sleep(1);
    }

    return 0;
}
