#include <iostream>
using namespace std;

#define N 4

// A utility function to print the solution path
void printSolution(int solution[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }
}

// Check if the current cell is a valid move
bool isSafe(int maze[N][N], int x, int y)
{
    // Check if (x, y) is a valid index and is not blocked
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the maze problem
bool solveMazeUtil(int maze[N][N], int x, int y, int solution[N][N])
{
    // Base case: if (x, y) is the destination
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        solution[x][y] = 1;
        return true;
    }

    // Check if the current cell is valid
    if (isSafe(maze, x, y))
    {
        // Mark the current cell as part of the solution
        solution[x][y] = 1;

        // Move right in the x direction
        if (solveMazeUtil(maze, x + 1, y, solution))
            return true;

        // Move down in the y direction
        if (solveMazeUtil(maze, x, y + 1, solution))
            return true;

        // If neither move is valid, backtrack (unmark the cell)
        solution[x][y] = 0;
        return false;
    }

    return false;
}

// Function to solve the maze problem
bool solveMaze(int maze[N][N])
{
    int solution[N][N] = {{0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};

    if (solveMazeUtil(maze, 0, 0, solution) == false)
    {
        cout << "No solution exists\n";
        return false;
    }

    printSolution(solution);
    return true;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};

    solveMaze(maze);
    return 0;
}
