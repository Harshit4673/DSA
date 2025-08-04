//leetcode 200
// VS Code compatible C++ code with full structure and explanation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        // Visited matrix to track visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Directions: up, left, down, right
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        queue<pair<int, int>> q;

        // Traverse the entire grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Start BFS if unvisited land ('1') is found
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    count++; // New island found

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        // Visit all 4 connected directions
                        for (int k = 0; k < 4; ++k) {
                            int a = x + dir[k].first;
                            int b = y + dir[k].second;

                            if (a >= 0 && a < n && b >= 0 && b < m &&
                                grid[a][b] == '1' && vis[a][b] == 0) {
                                q.push({a, b});
                                vis[a][b] = 1;
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};

// Time Complexity: O(N × M) where N = number of rows, M = number of columns
// - Each cell is visited once.
// Space Complexity: O(N × M) for visited matrix and queue storage in worst case

// For VS Code, make sure your main function includes test case runner if needed.
int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of islands: " << sol.numIslands(grid) << endl;
    return 0;
}
