class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],int vis[],int path[],int node){
        vis[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,path,it)) return true;
            }
            else if(path[it]) return true;
        }
        
        
        path[node]=0;
        return false;
        
    }
    bool isCyclic(int v, vector<int> adj[]) {
        int vis[v]={0};
        int path[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(adj,vis,path,i)) return true;
            }
        }
        return false;
    }
};