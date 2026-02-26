class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<int> ans;
        vector<bool> visited(n,false);
        queue<int> q;
        
        visited[0]=true;
        q.push(0);
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            ans.push_back(frontNode);
            
            for(int neighbor:adj[frontNode]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }
};