class Solution {
public:
    void helper(vector<vector<int>>& board,int i,int j,int m,int n){
        int c=0,val;
        if(i==m-1 && j==n)
            return;
        if(j==n){
            i++;
            j=0;
        }
        if(i-1>=0){
            if(j-1>=0 && board[i-1][j-1]==1)
                c++;
            if(board[i-1][j]==1)
                c++;
            if(j+1<n && board[i-1][j+1]==1)
                c++;
        }
        if(j-1>=0 && board[i][j-1]==1)
            c++;
        if(j+1<n && board[i][j+1]==1)
            c++;
        if(i+1<m){
            if(j-1>=0 && board[i+1][j-1]==1)
                c++;
            if(board[i+1][j]==1)
                c++;
            if(j+1<n && board[i+1][j+1]==1)
                c++;
        } 
        if(board[i][j]==1){
            if(c<2 || c>3)
                val=0;
            else
                val=1;
        }
        else{
            if(c==3)
                val=1;
            else
                val=0;
        }
        helper(board,i,j+1,m,n);
        board[i][j]=val;
        return;
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        helper(board,0,0,board.size(),board[0].size());
    }
};