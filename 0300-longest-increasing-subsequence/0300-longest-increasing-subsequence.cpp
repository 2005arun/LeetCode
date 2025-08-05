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
        dp.assign(n,vector<int>(n+1,-1));
        return recur(0,nums,n,-1);
    }
};