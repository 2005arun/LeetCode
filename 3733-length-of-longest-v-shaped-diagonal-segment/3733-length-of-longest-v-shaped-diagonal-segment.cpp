class Solution {
public:
    vector<vector<int>> dirs={{1,1},{1,-1},{-1,-1},{-1,1}};
    // vector<vector<vector<vector<vector<int>>>>> dp;
    int dp[501][501][2][4][3];
    int recur(int i,int j,vector<vector<int>> &grid,int f,int dir,int val){
        if(dp[i][j][f][dir][val]!=-1) return dp[i][j][f][dir][val];
        int ni=i+dirs[dir][0];
        int nj=j+dirs[dir][1];
        if(ni<0 || ni>=grid.size() || nj<0 || nj>=grid[0].size() || grid[ni][nj]!=val) return 0;
        int non_take=1+recur(ni,nj,grid,f,dir,2-val);
        int take=0;
        if(f==0){
            take=1+recur(ni,nj,grid,1,(dir+1)%4,2-val);
        }
        return dp[i][j][f][dir][val]=max(take,non_take);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        // dp.assign(n,vector<vector<vector<vector<int>>>>(m,
        // vector<vector<vector<int>>>(2,vector<vector<int>>(4,vector<int>(3,-1)))));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    for(int dir=0;dir<4;dir++){
                        ans=max(ans,1+recur(i,j,grid,0,dir,2));
                    }
                }
            }
        }
        return ans;
    }
};