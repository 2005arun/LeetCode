class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        // int n=nums.size();
        // vector<long long> dp(n,0),prefix(n);
        // prefix[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]+nums[i];
        // }
        // for(int i=0;i<n;i++){
        //     if(i) dp[i]=dp[i-1];
        //     if(prefix[i]%k==0) dp[i]=max(dp[i],prefix[i]);
        //     for(int j=0;j<i;j++){
        //         if(prefix[i]%k==prefix[j]%k){
        //             dp[i]=max(dp[i],dp[j]+(prefix[i]-prefix[j]));
        //         }
        //     }
        // }
        // int tot=prefix[n-1];
        // return tot-dp[n-1];

        int n=nums.size();
        vector<long long> dp(n,0),prefix(n);
        vector<long long> best(k,-LLONG_MAX);
        best[0]=0;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(i) dp[i]=dp[i-1];
            int r=prefix[i]%k;
            if(r<0) r+=k;
            if(best[r]!=-LLONG_MAX) dp[i]=max(dp[i],prefix[i]+best[r]);
            best[r]=max(best[r],dp[i]-prefix[i]);
        }
        long long tot=prefix[n-1];
        return tot-dp[n-1];
    }
};