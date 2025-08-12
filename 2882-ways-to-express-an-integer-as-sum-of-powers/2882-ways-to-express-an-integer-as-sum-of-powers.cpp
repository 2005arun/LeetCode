class Solution {
public:
    vector<vector<int>> dp;
    int mod=1e9+7;
    int recur(int p,int n,int x,int sum){
        if(sum==n) return 1;
        if((sum+pow(p,x))>n) return 0;
        if(dp[p][sum]!=-1) return dp[p][sum];
        int take=recur(p+1,n,x,sum+pow(p,x));
        int non_take=recur(p+1,n,x,sum);
        return dp[p][sum]=(take+non_take)%mod;
    }
    int numberOfWays(int n, int x) {
        dp.assign(300+1,vector<int>(300+1,-1));
        return recur(1,n,x,0);
    }
};