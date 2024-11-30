#include <iostream>
using namespace std;

// Constants for the maze dimensions
const int WIDTH = 5;
const int HEIGHT = 5;

// Maze representation
// 0 - Open path
// 1 - Wall
// 2 - Part of the solution path
int maze[HEIGHT][WIDTH] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// Function to print the maze with solution path
void printMaze() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (maze[i][j] == 1)
                cout << "# ";  // Wall
            else if (maze[i][j] == 2)
                cout << ". ";  // Solution path
            else
                cout << "  ";  // Empty space
        }
        cout << endl;
    }
}

// Recursive function to solve the maze
bool solveMaze(int x, int y) {
    // Base case: Check if (x, y) is out of bounds or a wall
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH || maze[x][y] == 1 || maze[x][y] == 2) {
        return false;
    }

    // Base case: Check if we've reached the end of the maze (bottom-right corner)
    if (x == HEIGHT - 1 && y == WIDTH - 1) {
        maze[x][y] = 2;  // Mark the end as part of the solution
        return true;
    }

    // Mark current cell as part of the solution path
    maze[x][y] = 2;

    // Try moving in each direction: right, down, left, up
    // Right
    if (solveMaze(x, y + 1)) return true;
    // Down
    if (solveMaze(x + 1, y)) return true;
    // Left
    if (solveMaze(x, y - 1)) return true;
    // Up
    if (solveMaze(x - 1, y)) return true;

    // Backtrack: If no path is found, unmark the current cell
    maze[x][y] = 0;

    return false;  // No solution found from this position
}

int main() {
    // Start the maze solver from the top-left corner (0,0)
    if (solveMaze(0, 0)) {
        cout << "Path found:\n";
    } else {
        cout << "No path found.\n";
    }
    printMaze();  // Display the maze with the solution path
    return 0;
}
