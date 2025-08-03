class Solution {
public:
    vector<vector<int>> dp;
    int recur(int ind,vector<int> &prices,int buy){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int maxprofit=0;
        if(buy){
            maxprofit=max(-prices[ind]+recur(ind+1,prices,0),recur(ind+1,prices,1));
        }
        else{
            maxprofit=max(prices[ind]+recur(ind+2,prices,1),recur(ind+1,prices,0));
        }
        return dp[ind][buy]=maxprofit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n+1,vector<int>(2,-1));
        return recur(0,prices,1);
    }
};