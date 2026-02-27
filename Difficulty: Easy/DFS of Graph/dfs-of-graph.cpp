class Solution {
  public:
    void dfsHelper(int node,vector<vector<int>>&adj, vector<bool> &visited, vector<int> &result){
        visited[node]=true;
        result.push_back(node);
        
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                dfsHelper(neighbor,adj,visited,result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size(); // no of nodes or vertices
        vector<int> result; // dfs traversal
        vector<bool> visited(V,false); //visited array
        
        dfsHelper(0,adj,visited,result);
        
        return result;
    }
};