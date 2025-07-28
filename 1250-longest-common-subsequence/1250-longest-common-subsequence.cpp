class Solution {
public:
    int lcs(string text1,string text2, int ind1,int ind2,vector<vector<int>> &dp){
        if(ind1==text1.size() || ind2==text2.size()) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]) dp[ind1][ind2]= 1+lcs(text1,text2,ind1+1,ind2+1,dp);
        else dp[ind1][ind2]=max(lcs(text1,text2,ind1+1,ind2,dp),lcs(text1,text2,ind1,ind2+1,dp));

        return dp[ind1][ind2];
    } 
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        // vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        // vector<vector<int>> dp(n+1,vector<int>(m+1));

        // return lcs(text1,text2,0,0,dp);

        // for(int i=0;i<=text1.size();i++){
        //     dp[i][0]=0;
        // }
        // for(int i=0;i<=text2.size();i++){
        //     dp[0][i]=0;
        // }
        // for(int ind1=1;ind1<=text1.size();ind1++){
        //     for(int ind2=1;ind2<=text2.size();ind2++){
        //         if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2]= 1+dp[ind1-1][ind2-1];
        //         else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        //     }
        // }
        // return dp[n][m];

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int ind1 = n - 1; ind1 >= 0; ind1--) {
            for (int ind2 = m - 1; ind2 >= 0; ind2--) {
                if (text1[ind1] == text2[ind2]) {
                    dp[ind1][ind2] = 1 + dp[ind1 + 1][ind2 + 1];
                } else {
                    dp[ind1][ind2] = max(dp[ind1 + 1][ind2], dp[ind1][ind2 + 1]);
                }
            }
        }

        return dp[0][0];
    }
};