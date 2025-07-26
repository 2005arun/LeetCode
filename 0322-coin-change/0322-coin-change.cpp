class Solution {
public:
    // vector<vector<int>> dp;
    // int recur(int ind,vector<int> &coins,int amount,int n){
    //     if(ind==n-1){
    //         if(amount%coins[ind]==0) return amount/coins[ind];
    //         else return 1e9;
    //     }
    //     if(dp[ind][amount]!=-1) return dp[ind][amount];
    //     int non_take=0+recur(ind+1,coins,amount,n);
    //     int take=INT_MAX;
    //     if(amount-coins[ind] >=0 ){
    //         take=1+recur(ind,coins,amount-coins[ind],n);
    //     }
    //     return dp[ind][amount]=min(take,non_take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        sort(coins.begin(),coins.end(),greater<int>());
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int non_take=0+dp[i-1][amt];
                int take=INT_MAX;
                if(amt-coins[i]>=0) take=1+dp[i][amt-coins[i]];
                dp[i][amt]=min(take,non_take);
            }
        }
        if(dp[n-1][amount]==1e9) return -1;
        return dp[n-1][amount];
        // dp.assign(n,vector<int>(amount+1,-1));
        // int res=recur(0,coins,amount,n);
        // if(res>=1e9) return -1;
        // return res;
    }
};