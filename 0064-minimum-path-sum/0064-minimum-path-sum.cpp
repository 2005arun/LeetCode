class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int j,int n,int m,vector<vector<int>> &grid){
        if(i==n-1 && j==m-1) return grid[i][j];
        if(i>=n || j>=m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=recur(i+1,j,n,m,grid);
        int right=recur(i,j+1,n,m,grid);
        return dp[i][j]=grid[i][j]+min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return recur(0,0,n,m,grid);

        // dp.assign(n+1,vector<int>(m+1));
        // dp[0][0]=grid[0][0];

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         int left=dp[i-1][j];
        //         int right=dp[i][j-1];
        //         dp[i][j]=grid[i][j]+min(left,right);
        //     }
        // }
        // return dp[n-1][m-1];
    }
};