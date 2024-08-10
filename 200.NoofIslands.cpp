class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int x,int y){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && !vis[x][y] && grid[x][y]=='1'){
            vis[x][y]=1;
            dfs(grid,vis,x+1,y);
            dfs(grid,vis,x-1,y);
            dfs(grid,vis,x,y+1);
            dfs(grid,vis,x,y-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,vis,i,j);
                    c++;
                }
            }
        }
        return c;
    }
};