#include <iostream>
#include <vector>
using namespace std;

void dfsMatrix(int r, int c, vector<vector<int>>& grid) {

    int rows = grid.size();
    int cols = grid[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return;

    grid[r][c] = 0;

    dfsMatrix(r + 1, c, grid);
    dfsMatrix(r - 1, c, grid);
    dfsMatrix(r, c + 1, grid);
    dfsMatrix(r, c - 1, grid);
}

int numIslands(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int islands = 0;
    for (size_t r = 0; r < grid.size(); r++) {
        for (size_t c = 0; c < grid[0].size(); c++) {
            if (grid[r][c] == 1) {
                islands++;
                dfsMatrix(r, c, grid);
            }
        }
    }
    return islands;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    cout << "Number of islands: " << numIslands(grid) << endl;
    return 0;
}