// User function Template for C++

class Solution {
    void dfs(int node,vector<bool> &visited,vector<vector<int>> &adj){
        visited[node]=true;
        
        for(int j=0;j<adj.size();j++){
            if(adj[node][j]==1&&!visited[j]){
                dfs(j,visited,adj);
            }
        }
        
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count=0;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};