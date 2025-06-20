class Solution {
public:
    int check(int i,int n,int dp[]){
        if(i>n) return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=check(i+1,n,dp)+check(i+2,n,dp);
    }
    int climbStairs(int n) {
        // if(n<1){
        //     return 1;
        // }
        // int i;
        // int *arr=new int[n+1];
        // arr[0]=1;
        // arr[1]=1;
        // for(i=2;i<n+1;i++){
        //     arr[i]=arr[i-1]+arr[i-2];
        // }
        // int result=arr[n];
        // return result;
        int dp[n];
        memset(dp,-1,sizeof dp);
        return check(0,n,dp);
    }
};