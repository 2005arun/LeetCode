class Solution {
public:
    int recur(int i,int n,vector<int> &nums,int target,int sum){
        if(i==n-1){
            if(sum-nums[n-1]==target && sum+nums[n-1]==target) return 2;
            else if(sum-nums[n-1]==target || sum+nums[n-1]==target) return 1;
            return 0;
        }
        int minus=recur(i+1,n,nums,target,sum-nums[i]);
        int add=recur(i+1,n,nums,target,sum+nums[i]);
        return minus+add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return recur(0,n,nums,target,0);
    }
};