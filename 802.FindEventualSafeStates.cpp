class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&vis,vector<int>&path,vector<int>&check,int node){
        vis[node]=1;
        path[node]=1;
        check[node]=0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(graph,vis,path,check,it)){
                    return true;
                }
            }
            else if(path[it]){
                return true;
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>check(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(graph,vis,path,check,i);
        }
        for(int i=0;i<n;i++){
            if(check[i])
                ans.push_back(i);
        }
        return ans;
    }
};