class Solution {
public:
    int helper(vector<vector<int>>& grid,int x,int y,int n){
        if(x<0 || y<0 || x==grid.size() || y==grid[0].size() || grid[x][y] ==-1) return 0;
        if(grid[x][y]==2){
            if(n==0) return 1;
            return 0;
        }
        n--;
        grid[x][y]=-1;
        int ans=helper(grid,x+1,y,n)+helper(grid,x-1,y,n)+helper(grid,x,y+1,n)+helper(grid,x,y-1,n);
        grid[x][y]=0;
        n++;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x,y,n=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    n++;
                else if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        return helper(grid,x,y,n);
    }
};