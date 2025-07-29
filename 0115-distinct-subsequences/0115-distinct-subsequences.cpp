class Solution {
public:
    // vector<vector<int>> dp;
    // int recur(int i,int j,string s,string t){
    //     // if(ind==s.size()){
    //     //     if(res==t) return 1;
    //     //     return 0;
    //     // }
    //     // int take=recur(ind+1,s,t,res+s[ind]);
    //     // int non_take=recur(ind+1,s,t,res);
    //     // return take+non_take;

    //     if(j>=t.size()) return 1;
    //     if(i>=s.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int match=0,non_match=0;
    //     if(s[i]==t[j]){
    //         match=recur(i+1,j+1,s,t)+recur(i+1,j,s,t);
    //     }
    //     else non_match=recur(i+1,j,s,t);
    //     return dp[i][j]=match+non_match;
    // }
    int numDistinct(string s, string t) {
        // dp.assign(s.size(),vector<int>(t.size(),-1));
        // return recur(0,0,s,t);

        vector<vector<double>> dp(s.size()+1,vector<double>(t.size()+1,0));
        for(int i=0;i<s.size();i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[s.size()][t.size()];
    }
};