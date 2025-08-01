class Solution {
public:
    vector<vector<int>> dp;
    bool recur(int i,int j,string s,string p){
        if(i==0 && j==0) return true;
        if(j==0 && i>0) return false;
        if(i==0 && j>0){
            for(int k=1;k<=j;k++) if(p[k-1]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool op1=false;
        bool op2=false;
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            op1=recur(i-1,j-1,s,p);
        }
        else if(p[j-1]=='*'){
            op2=recur(i-1,j,s,p) || recur(i,j-1,s,p);
        }
        return dp[i][j]=op1||op2;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        // dp.assign(n+1,vector<int>(m+1,-1));
        // return recur(n,m,s,p);

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++) dp[i][0]=0;
        for(int j=1;j<=m;j++) {
            int fl=1;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*'){
                    fl=0;
                    break;
                }
            }
            dp[0][j]=fl;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j]=0;
            }
        }
        return dp[n][m];
    }
};