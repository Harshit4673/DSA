// gfg
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    // Function to return Depth First Traversal of given graph.
    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<int> visited(adj.size(), 0); // Visited tracking
        vector<int> ans;                    // Stores DFS traversal
        stack<int> q;
        q.push(0); // Start DFS from node 0

        while (!q.empty())
        {
            int temp = q.top();
            q.pop();

            if (!visited[temp])
            {
                visited[temp] = 1;
                ans.push_back(temp);
            }

            // Push adjacent nodes in reverse to maintain order
            for (int i = adj[temp].size() - 1; i >= 0; --i)
            {
                int curr = adj[temp][i];
                if (!visited[curr])
                {
                    q.push(curr);
                }
            }
        }

        return ans;
    }

    /*
    Time Complexity: O(V + E)
    - Each vertex and edge is visited once in DFS traversal.

    Space Complexity: O(V)
    - Stack, visited array, and answer vector all take O(V) space.
    */
};

int main()
{
    Solution sol;

    // Example graph (undirected)
    // 0 -> 1, 2
    // 1 -> 0, 3
    // 2 -> 0, 4
    // 3 -> 1
    // 4 -> 2
    vector<vector<int>> adj = {
        {1, 2}, // Neighbors of 0
        {0, 3}, // Neighbors of 1
        {0, 4}, // Neighbors of 2
        {1},    // Neighbors of 3
        {2}     // Neighbors of 4
    };

    vector<int> dfsTraversal = sol.dfs(adj);

    cout << "DFS Traversal: ";
    for (int node : dfsTraversal)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
