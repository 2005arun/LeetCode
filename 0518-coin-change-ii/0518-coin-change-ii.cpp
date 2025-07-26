class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int amount,vector<int> &coins,int n){
        if(i==n-1){
            if(amount%coins[n-1]==0) return 1;
            else return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int non_take=recur(i+1,amount,coins,n);
        int take=0;
        if(amount-coins[i]>=0) take=recur(i,amount-coins[i],coins,n);
        return dp[i][amount]=take+non_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return recur(0,amount,coins,n);
    }
};