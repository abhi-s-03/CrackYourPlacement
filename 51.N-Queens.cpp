class Solution {
public:
    void helper(int n,vector<vector<string>> &ans,vector<int>&left,vector<int>&udig,vector<int>&ldig, vector<string> &board,int j){
        if(j==n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(left[i]==0 && udig[j-i+n-1]==0 && ldig[i+j]==0){
                board[i][j]='Q';
                left[i]=1;
                udig[j-i+n-1]=1;
                ldig[i+j]=1;
                helper(n,ans,left,udig,ldig,board,j+1);
                board[i][j]='.';
                left[i]=0;
                udig[j-i+n-1]=0;
                ldig[i+j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for (int i = 0; i < n; ++i) {
            board[i] = s;
        }
        vector<int>left(n,0),udig(2*n-1,0),ldig(2*n-1,0);
        helper(n,ans,left,udig,ldig,board,0);
        return ans;
    }
};