class Solution {
public:
    bool dfs(vector<int>graph[],vector<int>&vis,int node,int color){
        vis[node]=color;
        for(auto it:graph[node]){
            if(vis[it]==-1) {
                if(!dfs(graph,vis,it,!color)) 
                    return false;
            }
            else if(color==vis[it])
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==-1)
                if(!dfs(adj,vis,i,0)) return false;
        }
        return true;
	}

};