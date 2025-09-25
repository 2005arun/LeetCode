class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int j,vector<vector<int>> &vec,int n){
        if(i==n || j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(vec[i][1]<vec[j][0]){
            take=1+recur(j,j+1,vec,n);
        }
        // else take=recur(i,j+1,vec,n);
        int non_take=max(recur(i,j+1,vec,n),recur(j,j+1,vec,n));
        return dp[i][j]=max(take,non_take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        int n=pairs.size();
        dp.assign(n+1,vector<int>(n+1,0));
        // return recur(0,1,pairs,pairs.size())+1;

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                int take=0;
                if(pairs[i][1]<pairs[j][0]) take=1+dp[j][j+1];
                int non_take=max(dp[i][j+1],dp[j][j+1]);
                dp[i][j]=max(take,non_take);
            }
        }
        return dp[0][1]+1;
    }
};