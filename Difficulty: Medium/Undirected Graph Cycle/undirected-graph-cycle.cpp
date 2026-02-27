class Solution {
public:
    // Recursive helper to detect cycle
    bool dfsUtil(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsUtil(neighbor, node, adj, visited)) {
                    return true; // cycle found
                }
            }
            // If neighbor is visited and not parent → cycle
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list from edge pairs
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        // Step 2: DFS cycle detection
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsUtil(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};