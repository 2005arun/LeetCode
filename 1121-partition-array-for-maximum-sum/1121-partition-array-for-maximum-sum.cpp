class Solution {
public:
    vector<int> dp;
    int recur(int ind,vector<int> &arr,int k,int n){
        if(ind==n) return 0;
        int ans=INT_MIN;
        int maxm=0;
        int len=0;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<min(n,ind+k);i++){
            maxm=max(maxm,arr[i]);
            len++;
            int sum=(len*maxm)+recur(i+1,arr,k,n);
            ans=max(ans,sum);
        }
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // dp.assign(n,-1);
        // return recur(0,arr,k,n);

        dp.assign(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int ans=INT_MIN;
            int maxm=0;
            int len=0;
            for(int i=ind;i<min(n,ind+k);i++){
                maxm=max(maxm,arr[i]);
                len++;
                int sum=(len*maxm)+dp[i+1];
                ans=max(ans,sum);
            }
            dp[ind]=ans;
        }
        return dp[0];
    }
};