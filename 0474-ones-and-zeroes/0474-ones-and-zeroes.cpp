class Solution {
public:
    vector<vector<vector<int>>> dp;
    int recur(int i,int m,int n,vector<pair<int,int>> &vec){
        if(m<0 || n<0) return -100;
        if(i==vec.size()) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int take=1+recur(i+1,m-vec[i].first,n-vec[i].second,vec);
        int non_take=recur(i+1,m,n,vec);
        return dp[i][m][n]=max(take,non_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> vec;
        for(int i=0;i<strs.size();i++){
            int a=0,b=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') a++;
                else b++;
            }
            vec.push_back({a,b});
        }
        dp.assign(vec.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return recur(0,m,n,vec);
    }
};