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
        
        // dp.assign(n+1,vector<int>(n+1,0));
        // for(int i=0;i<n+1;i++){
        //     dp[i][n]=1;
        // }
        // for(int p=n;p>=1;p--){
        //     for(int sum=300;sum>=0;sum--){
        //         if((sum+pow(p,x))>n) continue;
        //         int take=dp[p+1][sum+pow(p,x)];
        //         int non_take=dp[p+1][sum];
        //         dp[p][sum]=(take+non_take)%mod;
        //     }
        // }
        // return dp[1][0];
    }
};