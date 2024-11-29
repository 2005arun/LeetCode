class Solution {
    void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n,vector<int> &left,vector<int> &upper,vector<int> &lower){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && upper[n-1+col-row]==0 && lower[col+row]==0){
                board[row][col]='Q';
                left[row]=1;
                upper[n-1+col-row]=1;
                lower[col+row]=1;
                solve(col+1,ans,board,n,left,upper,lower);
                board[row][col]='.';
                left[row]=0;
                upper[n-1+col-row]=0;
                lower[col+row]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<std::string>> ans;
        vector<std::string>board(n,string(n,'.'));
        vector<int>leftrow(n,0);
        vector<int>upperdiagonal(2*n-1,0);
        vector<int>lowerdiagonal(2*n-1,0);
        solve(0,ans,board,n,leftrow,upperdiagonal,lowerdiagonal);
        return ans;
    }
};