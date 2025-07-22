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

    // vector<vector<int>> dp;
    // bool recur(vector<int> &nums,int tot,int n,int ind,int sum){
    //     if(tot==sum) return true;
    //     if(sum>tot || ind>=n) return false;
    //     if(dp[ind][sum]!=-1) return dp[ind][sum];
    //     if(recur(nums,tot-nums[ind],n,ind+1,sum+nums[ind])==true) return dp[ind][sum]=true;
    //     if(recur(nums,tot,n,ind+1,sum)==true) return dp[ind][sum]=true;
    //     return dp[ind][sum]=false;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int tot=accumulate(nums.begin(),nums.end(),0);
    //     dp.assign(nums.size(),vector<int>(tot+1,-1));
    //     return recur(nums,tot,nums.size(),0,0);
    // }
    bool subset(vector<int> &nums,int tot){
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool>(tot+1));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=tot) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=tot;target++){
                bool take=false;
                if(nums[i]<=target) take=dp[i-1][target-nums[i]];
                bool non_take=dp[i-1][target];
                dp[i][target]=take|non_take;
            }
        }
        return dp[n-1][tot];
    }
    bool canPartition(vector<int>& nums) {
        int n=accumulate(nums.begin(),nums.end(),0);
        int tot=n/2;
        if(n%2!=0) return false;
        return subset(nums,tot);
    }    
};