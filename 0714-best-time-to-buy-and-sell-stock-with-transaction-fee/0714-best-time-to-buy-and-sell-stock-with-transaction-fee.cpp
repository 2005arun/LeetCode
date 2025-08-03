class Solution {
public:
    vector<vector<int>> dp;
    int l=0;
    int recur(int ind,vector<int> &prices,int buy,int fee){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int maxprofit=0;
        if(buy){
            maxprofit=max(-prices[ind]+recur(ind+1,prices,0,fee),recur(ind+1,prices,1,fee));
        }
        else{
            maxprofit=max((prices[ind]-fee)+recur(ind+1,prices,1,fee),recur(ind+1,prices,0,fee));
        }
        return dp[ind][buy]=maxprofit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.assign(n+1,vector<int>(2,-1));
        int maxval=recur(0,prices,1,fee);
        // cout<<l;
        return maxval;
    }
};