class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int j,vector<int> &cuts){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j]; 
        int minim=INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int tot=(cuts[j+1]-cuts[i-1])+recur(i,ind-1,cuts)+recur(ind+1,j,cuts);
            minim=min(minim,tot);
        }
        return dp[i][j]=minim;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        dp.assign(cuts.size()+2,vector<int>(cuts.size()+2,-1));
        sort(cuts.begin(),cuts.end());
        return recur(1,cuts.size()-2,cuts);
    }
};