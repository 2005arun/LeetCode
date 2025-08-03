class Solution {
public:
    vector<vector<int>> dp;
    int recur(int ind,vector<int> &prices,int buy){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int maxprofit=0;
        if(buy){
            maxprofit=max(-prices[ind]+recur(ind+1,prices,0),0+recur(ind+1,prices,1));
        }
        else{
            maxprofit=max(prices[ind]+recur(ind+1,prices,1),0+recur(ind+1,prices,0));
        }
        return dp[ind][buy]=maxprofit;
    }
    int maxProfit(vector<int>& prices) {
        // dp.assign(prices.size(),vector<int>(2,-1));
        // return recur(0,prices,1);
        int n=prices.size();
        dp.assign(n+1,vector<int>(2));  
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int maxprofit=0;
                if(j){
                    maxprofit=max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                    maxprofit=max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][j]=maxprofit;
            }
        }     
        // cout<<dp[0][0]<<" "<<dp[0][1]<<" "; 
        return dp[0][1];
    }
};