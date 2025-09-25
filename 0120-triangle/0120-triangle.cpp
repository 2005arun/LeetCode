class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int j,vector<vector<int>> &triangle){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int top=recur(i+1,j,triangle);
        int topleft=recur(i+1,j+1,triangle);
        return dp[i][j]=triangle[i][j]+min(top,topleft);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        dp.assign(n,vector<int>(m,0));
        // return recur(0,0,triangle);

        for(int i=0;i<m;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int top=dp[i+1][j];
                int topleft=dp[i+1][j+1];
                dp[i][j]=triangle[i][j]+min(top,topleft);
            }
        }
        return dp[0][0];
    }
};