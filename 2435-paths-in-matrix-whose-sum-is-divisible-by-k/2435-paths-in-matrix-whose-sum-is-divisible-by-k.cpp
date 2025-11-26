class Solution {
public:
    int m=1e9+7;
    vector<vector<vector<int>>> dp;
    int recur(int i,int j,vector<vector<int>> &grid,int k,int mod){
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            mod=(mod+grid[i][j])%k;
            if(mod==0) return 1;
            return 0;
        }
        if(dp[i][j][mod]!=-1) return dp[i][j][mod];
        int right=recur(i,j+1,grid,k,(mod+grid[i][j])%k);
        int down=recur(i+1,j,grid,k,(mod+grid[i][j])%k);
        return dp[i][j][mod]=(right+down)%m;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.assign(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        return recur(0,0,grid,k,0)%m;
    }
};