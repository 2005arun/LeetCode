class Solution {
public:
    vector<int> dp;
    int mod=1e9+7;
    int recur(int days,int n,int delay,int forget){
        if(dp[days]!=-1) return dp[days];
        int tot=(days+forget>n);
        for(int i=delay;i<forget;i++){
            if(days+i>n) break;
            tot=(tot+recur(days+i,n,delay,forget))%mod;
        }
        return dp[days]=tot;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp.assign(n+1,-1);
        return recur(1,n,delay,forget);
    }
};