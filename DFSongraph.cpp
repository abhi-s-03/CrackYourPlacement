class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],int node,vector<int>&ans,int vis[]){
        vis[node]=1;
        ans.push_back(node);
        for(auto x:adj[node]){
            if(!vis[x]) dfs(adj,x,ans,vis);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        vector<int>ans;
        dfs(adj,0,ans,vis);
        return ans;
    }
};