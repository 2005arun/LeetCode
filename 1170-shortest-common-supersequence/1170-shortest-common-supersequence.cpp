class Solution {
public:
    vector<vector<int>> dp;
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        dp.assign(n+1,vector<int>(m+1,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         if(str1[i]==str2[j]) dp[i][j]=1+dp[i+1][j+1];
        //         else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        //     }
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // cout<<dp[0][0];
        string res="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                res+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                res+=str1[i-1];
                i--;
            }
            else{
                res+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            res+=str1[i-1];
            i--;
        }
        while(j>0){
            res+=str2[j-1];
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};