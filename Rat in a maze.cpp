#include <iostream>
using namespace std;

const int N = 4;

int maze[N][N] = {
    {1, 1, 0, 1},
    {1, 1, 1, 1},
    {0, 1, 0, 1},
    {1, 1, 1, 1}
};

bool visited[N][N] = {false};

int pathCount = 0;

void findPaths(int row, int col, string path) {

    // Check boundaries and invalid cells
    if (row < 0 || col < 0 || row >= N || col >= N) {
        return;
    }

    // Check obstacle or already visited cell
    if (maze[row][col] == 0 || visited[row][col] == true) {
        return;
    }

    // Destination reached
    if (row == N - 1 && col == N - 1) {
        pathCount++;
        cout << "Path " << pathCount << ": " << path << endl;
        return;
    }

    // Mark current cell as visited
    visited[row][col] = true;

    // Move up
    findPaths(row - 1, col, path + "U");

    // Move down
    findPaths(row + 1, col, path + "D");

    // Move left
    findPaths(row, col - 1, path + "L");

    // Move right
    findPaths(row, col + 1, path + "R");

    // Backtrack: unmark current cell
    visited[row][col] = false;
}

int main() {

    findPaths(0, 0, "");

    if (pathCount == 0) {
        cout << "No valid path exists!" << endl;
    }

    return 0;
}
