#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dRow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dCol[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool dfsWord(int r, int c, int index, vector<vector<char>>& grid, string& word) {
    if (index == word.length()) return true;

    int rows = grid.size();
    int cols = grid[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != word[index]) return false;

    char temp = grid[r][c];
    grid[r][c] = '*';

    for (int i = 0; i < 8; i++) {
        if (dfsWord(r + dRow[i], c + dCol[i], index + 1, grid, word)) return true;
    }

    grid[r][c] = temp; 
    return false;
}

bool exist(vector<vector<char>>& grid, string word) {
    for (size_t r = 0; r < grid.size(); r++) {
        for (size_t c = 0; c < grid[0].size(); c++) {
            if (grid[r][c] == word[0]) {
                if (dfsWord(r, c, 0, grid, word)) return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    if (exist(grid, word)) cout << "Word 'ABCCED' exists in the grid" << endl;
    return 0;
}