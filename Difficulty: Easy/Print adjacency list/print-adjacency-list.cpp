class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>> result(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i].first, v=edges[i].second;
            result[u].push_back(v);
            result[v].push_back(u);
        }
        return result;
    }
};