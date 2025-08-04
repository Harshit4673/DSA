/*
    Approach:
    ----------
    - This uses Breadth-First Search (BFS) to simulate rotting process.
    - All initially rotten oranges (value 2) are enqueued.
    - Each level of BFS represents one minute elapsed. All fresh oranges (value 1) adjacent to rotten ones become rotten.
    - Process repeats until there are no more changes possible.
    - If any fresh orange remains at the end, return -1.

    Time Complexity:  O(N * M)
        - Each cell is visited at most once.
    Space Complexity: O(N * M)
        - The queue may store up to O(N * M) positions in the worst case.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;      // For BFS
        int fresh = 0;                // Count of fresh oranges
        int time = 0;                 // Time elapsed (in minutes)

        // Initialize queue with all rotten oranges, count fresh ones
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0) return 0; // No fresh oranges, no time needed

        // 4-directional movement (up, left, down, right)
        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false; // Flag to check if any fresh orange rotted this minute

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                // Visit all adjacent cells
                for (auto [dx, dy] : dir) {
                    int a = x + dx;
                    int b = y + dy;

                    // If adjacent cell is fresh orange, rot it
                    if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 1) {
                        grid[a][b] = 2;   // Mark as rotten
                        q.push({a, b});   // Add to queue for next round
                        fresh--;
                        rotted = true;
                    }
                }
            }

            if (rotted) time++; // Only increment time if some orange rotted this minute
        }

        // If all fresh oranges have rotted, return time; else return -1
        return (fresh == 0) ? time : -1;
    }
};

int main() {
    /*
    Example input:
    3x3 grid:
    [[2,1,1],
     [1,1,0],
     [0,1,1]]
    Expected output: 4

    Explanation: Rotting spreads as follows (in minutes):
    - Minute 1: [[2,2,1], [2,1,0], [0,1,1]]
    - Minute 2: [[2,2,2], [2,2,0], [0,1,1]]
    - Minute 3: [[2,2,2], [2,2,0], [0,2,1]]
    - Minute 4: [[2,2,2], [2,2,0], [0,2,2]]
    */

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    Solution sol;
    int res = sol.orangesRotting(grid);
    cout << "Minimum minutes until all oranges rot (or -1 if impossible): " << res << endl;

    return 0;
}
