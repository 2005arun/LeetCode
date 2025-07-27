class Solution {
public:
    int mod=1e9+7;
    int offset=0;
    vector<vector<int>> dp;
    int recur(int start,int end,int k,int step){
        if(step==k) {
            return start==end;
        }
        if(step>k) return 0;
        if(dp[start+1000][step]!=-1) return dp[start+1000][step];
        int front=recur(start+1,end,k,step+1);
        int back=recur(start-1,end,k,step+1);
        return dp[start+1000][step]=(front+back)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        dp.assign(3000,vector<int>(k+1,-1));
        return recur(startPos,endPos,k,0)%mod;
    }
};