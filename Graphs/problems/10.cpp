#include <iostream>
#include <vector>
using namespace std;

struct Point { int r, c; };

bool solveMazeDFS(int r, int c, vector<vector<int>>& maze, vector<vector<bool>>& vis, vector<Point>& path) {
    int rows = maze.size();
    int cols = maze[0].size();

    if (r == rows - 1 && c == cols - 1) {
        path.push_back({r, c});
        return true;
    }

    if (r < 0 || r >= rows || c < 0 || c >= cols || maze[r][c] == 0 || vis[r][c]) return false;

    vis[r][c] = true;
    path.push_back({r, c});

    // Move directions: Down, Up, Right, Left
    int dR[] = {1, -1, 0, 0};
    int dC[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        if (solveMazeDFS(r + dR[i], c + dC[i], maze, vis, path)) return true;
    }

    path.pop_back(); // Backtrack
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    vector<Point> path;

    if (solveMazeDFS(0, 0, maze, vis, path)) {
        cout << "Path from (0,0) to (3,3): ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << "(" << path[i].r << ", " << path[i].c << ")" << (i == path.size() - 1 ? "" : ", ");
        }
        cout << endl;
    }
    return 0;
}