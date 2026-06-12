#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Point { int r, c; };

// Custom comparator for using Point as key in std::map
bool operator<(const Point& a, const Point& b) {
    if (a.r != b.r) return a.r < b.r;
    return a.c < b.c;
}

void findTreasure(vector<vector<int>>& maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    
    queue<Point> Q;
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    map<Point, Point> parent;

    Q.push({0, 0});
    vis[0][0] = true;
    parent[{0, 0}] = {-1, -1};

    int dR[] = {-1, 1, 0, 0};
    int dC[] = {0, 0, -1, 1};
    Point treasure = {-1, -1};

    while (!Q.empty()) {
        Point curr = Q.front();
        Q.pop();

        if (maze[curr.r][curr.c] == 999) {
            treasure = curr;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dR[i];
            int nc = curr.c + dC[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] != 1 && !vis[nr][nc]) {
                vis[nr][nc] = true;
                parent[{nr, nc}] = curr;
                Q.push({nr, nc});
            }
        }
    }

    if (treasure.r == -1) return;

    // Build the path back
    vector<Point> path;
    for (Point p = treasure; p.r != -1; p = parent[p]) {
        path.push_back(p);
    }
    reverse(path.begin(), path.end());

    cout << "Path to treasure: ";
    for (size_t i = 0; i < path.size(); i++) {
        cout << "(" << path[i].r << "," << path[i].c << ")" << (i == path.size() - 1 ? "" : ", ");
    }
    cout << endl;
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 999, 0},
        {0, 0, 0, 1}
    };
    findTreasure(maze);
    return 0;
}