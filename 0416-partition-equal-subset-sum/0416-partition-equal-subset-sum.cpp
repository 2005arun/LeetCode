class Solution {
public:
    // bool recur(vector<int> &nums,int tot,int n,int ind,int sum){
    //     if(tot==sum) return true;
    //     if(sum>tot || ind>=n) return false;
    //     if(recur(nums,tot-nums[ind],n,ind+1,sum+nums[ind])==true) return true;
    //     if(recur(nums,tot,n,ind+1,sum)==true) return true;
    //     return false;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int tot=accumulate(nums.begin(),nums.end(),0);
    //     return recur(nums,tot,nums.size(),0,0);
    // }
    vector<vector<int>> dp;
    bool recur(vector<int> &nums,int tot,int n,int ind,int sum){
        if(tot==sum) return true;
        if(sum>tot || ind>=n) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        if(recur(nums,tot-nums[ind],n,ind+1,sum+nums[ind])==true) return dp[ind][sum]=true;
        if(recur(nums,tot,n,ind+1,sum)==true) return dp[ind][sum]=true;
        return dp[ind][sum]=false;
    }
    bool canPartition(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        dp.assign(nums.size(),vector<int>(tot+1,-1));
        return recur(nums,tot,nums.size(),0,0);
    }
};