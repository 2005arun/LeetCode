class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod=1e9+7;
    int recur(int i,vector<int> &nums,int lastparity,int cnt){
        if(cnt>=3) return 0;
        if(i>=nums.size()) return 1;
        if(dp[i][lastparity+1][cnt]!=-1) return dp[i][lastparity+1][cnt];
        int non_take=recur(i+1,nums,lastparity,cnt);

        int parity=nums[i]%2;
        int take=0;
        if(lastparity==-1 || parity!=lastparity){
            take=recur(i+1,nums,parity,1);
        }
        else take=recur(i+1,nums,lastparity,cnt+1);
        return dp[i][lastparity+1][cnt]=(take+non_take)%mod;
    }
    int countStableSubsequences(vector<int>& nums) {
        dp.assign(nums.size(),vector<vector<int>>(4,vector<int>(5,-1)));
        return recur(0,nums,-1,0)-1;
    }
};