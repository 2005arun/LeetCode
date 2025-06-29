class Solution {
public:
// memo + recur
    // int check(int i,vector<int> &nums,int n,vector<int> &dp){
    //     if(i==n-1) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int minm=INT_MAX;
    //     for(int j=1;j<=nums[i];j++){
    //         if(i+j<=n-1){
    //             int temp=check(i+j,nums,n,dp);
    //             if(temp!=INT_MAX) minm=min(minm,temp+1);
    //         }
    //     }
    //     return dp[i]=minm;
    // }
    int jump(vector<int>& nums) {
        // greedy
        // int l=0,r=0;
        // int jumps=0;
        // while(r<nums.size()-1){
        //     int far=0;
        //     for(int i=l;i<=r;i++){
        //         far=max(far,i+nums[i]);
        //     }
        //     l=r+1;
        //     r=far;
        //     jumps++;
        // }
        // return jumps;

        // vector<int> dp(nums.size(),-1);
        // return check(0,nums,nums.size(),dp);

        // tabulation
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j < n) dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};