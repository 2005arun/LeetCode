class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int j,string word1,string word2){
        if(j==0 && i==0) {
            if(word1[i]==word2[j]) return 0;
            else return 1;
        }
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return 0+recur(i-1,j-1,word1,word2);
        int insert=1+recur(i,j-1,word1,word2);
        int del=1+recur(i-1,j,word1,word2);
        int replace=1+recur(i-1,j-1,word1,word2);
        return dp[i][j]=min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return recur(n-1,m-1,word1,word2);
    }
};