class Solution {
public:
    vector<vector<vector<int>>> dp;
    int recur(int i,vector<int> &prices,int j,int l,int k){
        if(i==prices.size() || l>=k) return 0;
        if(dp[i][j][l]!=-1) return dp[i][j][l];
        int maxprofit=0;
        if(j){
            maxprofit=max(-prices[i]+recur(i+1,prices,0,l,k),recur(i+1,prices,1,l,k));
        }
        else{
            maxprofit=max(prices[i]+recur(i+1,prices,1,l+1,k),recur(i+1,prices,0,l,k));
        }
        return dp[i][j][l]=maxprofit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // dp.assign(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return recur(0,prices,1,0,k);
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1)));
        for(int i=0;i<2;i++){
            for(int j=0;j<=k;j++){
                dp[n][i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++) dp[i][j][k]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=0;l<k;l++){
                    int maxprofit=0;
                    if(j){
                        maxprofit=max(-prices[i]+dp[i+1][0][l],dp[i+1][1][l]);
                    }
                    else{
                        maxprofit=max(prices[i]+dp[i+1][1][l+1],dp[i+1][0][l]);
                    }
                    dp[i][j][l]=maxprofit;
                }
            }
        }
        return dp[0][1][0];
    }
};