class Solution {
public:
    vector<vector<vector<int>>> dp;
    int recur(int ind,vector<int> prices,int buy,int count){
        if(ind==prices.size() || count>=2) return 0;
        if(dp[ind][buy][count]!=-1) return dp[ind][buy][count];
        int maxprofit=0;
        if(buy){
            maxprofit=max(-prices[ind]+recur(ind+1,prices,0,count),recur(ind+1,prices,1,count));
        }
        else{
            maxprofit=max(prices[ind]+recur(ind+1,prices,1,count+1),recur(ind+1,prices,0,count));
        }
        return dp[ind][buy][count]=maxprofit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // dp.assign(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return recur(0,prices,1,0);

        dp.assign(n+1,vector<vector<int>>(2,vector<int>(3)));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                dp[n][i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][2]=0;
            }
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int count=0;count<2;count++){
                    int maxprofit=0;
                    if(buy){
                        maxprofit=max(-prices[ind]+dp[ind+1][0][count],dp[ind+1][1][count]);
                    }
                    else{
                        maxprofit=max(prices[ind]+dp[ind+1][1][count+1],dp[ind+1][0][count]);
                    }
                    dp[ind][buy][count]=maxprofit;
                }
            }
        }
        // cout<<dp[0][0][0]<<" "<<dp[0][0][1]<<" "<<dp[0][1][0]<<" "<<dp[0][1][1];
        return dp[0][1][0];
    }
};