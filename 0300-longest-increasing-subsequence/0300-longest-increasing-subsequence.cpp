class Solution {
public:
    vector<vector<int>> dp;
    int recur(int ind,vector<int> &nums,int n,int prevind){
        if(ind==n) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
        int take=0;
        if(prevind==-1 || nums[ind]>nums[prevind]) take=1+recur(ind+1,nums,n,ind);
        int non_take=recur(ind+1,nums,n,prevind);
        return dp[ind][prevind+1]=max(take,non_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // dp.assign(n,vector<int>(n+1,-1));
        // return recur(0,nums,n,-1);

        dp.assign(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prevind=ind-1;prevind>=-1;prevind--){
                int take=0;
                if(prevind==-1 || nums[ind]>nums[prevind]) take=1+dp[ind+1][ind+1];
                int non_take=dp[ind+1][prevind+1];
                dp[ind][prevind+1]=max(take,non_take);
            }
        }
        return dp[0][0];
    }
};