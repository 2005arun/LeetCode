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

        // dp.assign(n+1,vector<int>(n+1,0));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int prevind=ind-1;prevind>=-1;prevind--){
        //         int take=0;
        //         if(prevind==-1 || nums[ind]>nums[prevind]) take=1+dp[ind+1][ind+1];
        //         int non_take=dp[ind+1][prevind+1];
        //         dp[ind][prevind+1]=max(take,non_take);
        //     }
        // }

        vector<int> dp(n);
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    res=max(res,1+dp[i]);
                }
            }
        }
        return res;
        // return dp[0][0];
    }
};