class Solution {
  public:
    bool dfsCycle(vector<vector<int>> &adj,vector<bool> &visited, vector<bool> &recPath, int node){
        visited[node]=true;
        recPath[node]=true;
        
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfsCycle(adj,visited,recPath,neighbor)){
                    return true;
                }
            }else if(recPath[neighbor]){
                    return true;
            }
        }
        
        recPath[node]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,false);
        vector<bool> recPath(V,false);
        
        for (int i=0;i<V;i++) {
            if (!visited[i]) {
                if (dfsCycle(adj,visited,recPath,i)) {
                    return true;
                }
            }
        }
        return false;
    }
};