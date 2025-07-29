
//leetcode547

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    // Helper BFS to traverse all nodes in a connected component
    void bfs(int start, vector<int>& vis, vector<vector<int>>& adj) {
        queue<int> q;
        vis[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < adj[node].size(); i++) {
                if (adj[node][i] == 1 && !vis[i]) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }

    // Main function to count number of connected components (provinces)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, vis, isConnected);
                count++; // New province found
            }
        }
        return count;
    }

    /*
    Time Complexity: O(n^2)
    - For each of the n nodes, we potentially check all n neighbors due to adjacency matrix.

    Space Complexity: O(n)
    - For visited array and queue during BFS.
    */



    // Iterative DFS to explore all connected nodes   , not optimal
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int& el) {
        stack<int> s;
        s.push(el);

        while (!s.empty()) {
            int temp = s.top();
            s.pop();

            if (visited[temp] == 0) {
                visited[temp] = 1;
            }

            for (int i = 0; i < adj[temp].size(); ++i) {
                int curr = adj[temp][i];
                if (visited[curr] == 0) {
                    s.push(curr);
                }
            }
        }
    }

    // Count number of connected components (provinces)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                cnt++;
                dfs(adj, visited, i);
            }
        }

        return cnt;
    }

    /*
    Time Complexity: O(n^2)
    - Converting matrix to list takes O(n^2).
    - DFS traversal is O(V + E), which is also O(n^2) in worst-case dense graphs.

    Space Complexity: O(n^2)
    - Adjacency list can store up to n*(n-1) edges in a fully connected graph.
    - Visited array and stack use O(n).
    */
};

int main() {
    Solution sol;

    // Example input graph (adjacency matrix)
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int provinces = sol.findCircleNum(isConnected);
    cout << "Number of Provinces: " << provinces << endl;

    return 0;
}


    // Iterative DFS to explore all connected nodes   , not optimal
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int& el) {
        stack<int> s;
        s.push(el);

        while (!s.empty()) {
            int temp = s.top();
            s.pop();

            if (visited[temp] == 0) {
                visited[temp] = 1;
            }

            for (int i = 0; i < adj[temp].size(); ++i) {
                int curr = adj[temp][i];
                if (visited[curr] == 0) {
                    s.push(curr);
                }
            }
        }
    }

    // Count number of connected components (provinces)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                cnt++;
                dfs(adj, visited, i);
            }
        }

        return cnt;
    }

    /*
    Time Complexity: O(n^2)
    - Converting matrix to list takes O(n^2).
    - DFS traversal is O(V + E), which is also O(n^2) in worst-case dense graphs.

    Space Complexity: O(n^2)
    - Adjacency list can store up to n*(n-1) edges in a fully connected graph.
    - Visited array and stack use O(n).
    */

