class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        
        int time=0;
        q.push({-1,-1});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            if(x==-1 && y==-1){
                if(q.size()==1) break;
                else{
                    time++;
                    q.pop();
                    q.push({-1,-1});
                }
            }
            else{
                if(x-1>=0 && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                if(y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
                if(x+1<n && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                }
                if(y+1<m && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
                q.pop();
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};