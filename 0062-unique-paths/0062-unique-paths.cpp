class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int j,int n,int m){
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=recur(i,j+1,n,m);
        int right=recur(i+1,j,n,m);
        return dp[i][j]=left+right;
    }
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n));
        // return recur(0,0,m,n);
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int left=(j-1 >= 0)?dp[i][j-1]:0;
                int right=(i-1 >= 0)?dp[i-1][j]:0;
                dp[i][j]=left+right;
            }
        }
        return dp[m-1][n-1];
    }
};