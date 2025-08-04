//leetcode 207

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);             // Stores indegree of each node
        vector<vector<int>> adj(numCourses);             // Adjacency list for course graph

        // Build graph and fill indegrees
        for (const auto& pre : prerequisites) {
            int u = pre[1], v = pre[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push all nodes with 0 indegree (no prerequisites)
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int completed = 0;  // Count of courses completed

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completed++;

            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        return completed == numCourses;
    }

    /*
    Time Complexity: O(V + E)
    - V: numCourses (nodes), E: prerequisites (edges)
    - We traverse all nodes and edges once in BFS.

    Space Complexity: O(V + E)
    - For adjacency list and indegree array.
    */






    //2nd 
        // Helper function to detect cycle using DFS
    bool cycleCheck(vector<int> adj[], vector<int>& visited,
                    vector<int>& dfsVisited, int node) {
        visited[node] = 1;
        dfsVisited[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (cycleCheck(adj, visited, dfsVisited, neighbor))
                    return true;
            } else if (dfsVisited[neighbor]) {
                return true; // cycle detected
            }
        }

        dfsVisited[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];  // Adjacency list

        // Build the graph
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> dfsVisited(numCourses, 0);

        // DFS for each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (cycleCheck(adj, visited, dfsVisited, i))
                    return false;  // cycle found
            }
        }
        return true;
    }

    /*
    Time Complexity: O(V + E)
    - V = numCourses, E = number of prerequisites
    - Each node and edge is visited once in DFS.

    Space Complexity: O(V + E)
    - For adjacency list, visited and dfsVisited arrays.
    */
};

int main() {
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    if (sol.canFinish(numCourses, prerequisites))
        cout << "All courses can be finished.\n";
    else
        cout << "It is not possible to finish all courses.\n";

    return 0;
}
