class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,string str,int s){
        if(s>26 || s==0) return 0;
        if(i>=str.size()) return 1;
        if(dp[i][s]!=-1) return dp[i][s];
        int take=recur(i+1,str,str[i]-'0');
        int non_take=recur(i+1,str,(s*10+(str[i]-'0')));
        return dp[i][s]=take+non_take;
    }
    int numDecodings(string s) {
        dp.assign(s.size()+1,vector<int>(26+1,-1));
        return recur(1,s,s[0]-'0');
    }
};