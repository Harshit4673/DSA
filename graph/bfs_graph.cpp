// gfg
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        vector<int> visited(adj.size(), 0); // To track visited nodes
        vector<int> ans;                    // Stores BFS traversal result
        queue<int> q;

        q.push(0); // Start BFS from node 0
        ans.push_back(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (int i = 0; i < adj[temp].size(); ++i)
            {
                int curr = adj[temp][i];
                if (!visited[curr])
                {
                    ans.push_back(curr);
                    visited[curr] = 1;
                    q.push(curr);
                }
            }
        }

        return ans;
    }

    /*
    Time Complexity: O(V + E)
    - Each vertex is visited once, and all its edges are processed once.

    Space Complexity: O(V)
    - 'visited', 'queue', and 'ans' each take O(V) space.
    */
};

int main()
{
    Solution sol;

    // Example graph represented as an adjacency list
    // 0 -> 1, 2
    // 1 -> 0, 3
    // 2 -> 0, 4
    // 3 -> 1
    // 4 -> 2
    vector<vector<int>> adj = {
        {1, 2}, // Neighbors of node 0
        {0, 3}, // Neighbors of node 1
        {0, 4}, // Neighbors of node 2
        {1},    // Neighbors of node 3
        {2}     // Neighbors of node 4
    };

    vector<int> bfsTraversal = sol.bfs(adj);

    cout << "BFS Traversal: ";
    for (int node : bfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
