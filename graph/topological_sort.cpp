//gfg topologiccal sort

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return topological sort of a directed graph//bfs
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        queue<int> q;
        vector<int> ans;
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Creating adjacency list and calculating indegree
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // Push all nodes with indegree 0
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Kahn's Algorithm for Topological Sorting
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for (int curr : adj[temp]) {
                indegree[curr]--;
                if (indegree[curr] == 0) {
                    q.push(curr);
                }
            }
        }

        return ans;
    }



    //2nd approach 
        // DFS function for topological sorting
    void dfs(int el, vector<vector<int>>& adj, vector<int>& visited, stack<int>& s) {
        visited[el] = 1; // Mark current node as visited
        for (int i = 0; i < adj[el].size(); ++i) {
            int curr = adj[el][i];
            if (visited[curr] == 0) {
                dfs(curr, adj, visited, s);
            }
        }
        s.push(el); // Push the node after all its children are processed
    }

    // Function to perform topological sort using DFS
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> s;
        vector<int> ans;
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);

        // Create adjacency list
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        // Call DFS for all unvisited nodes
        for (int i = 0; i < V; ++i) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, s);
            }
        }

        // Pop from stack to get topological order
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };

    vector<int> result = sol.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
