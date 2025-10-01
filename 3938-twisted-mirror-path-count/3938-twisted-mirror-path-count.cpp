// class Solution {
// public:
//     int recur(int i,int j,vector<vector<int>> &grid){
//         if(i>=grid.size() || j>=grid[0].size()) return 0;
//         if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
//         int right=0,down=0,dia=0;
//         if((i+1<grid.size() && grid[i+1][j]==1) || (j+1<grid[0].size() && grid[i][j+1]==1)) dia=recur(i+1,j+1,grid);
//         if(i+1<grid.size() && grid[i+1][j]!=1) down=recur(i+1,j,grid);
//         if(j+1<grid[0].size() && grid[i][j+1]!=1) right=recur(i,j+1,grid);
//         return dia+right+down;
//     }
//     int uniquePaths(vector<vector<int>>& grid) {
//         return recur(0,0,grid);
//     }
// };

class Solution {
public:
    const int mod = 1e9 + 7;
    int m, n;
    vector<vector<long long>> memo; // memoization table

    // Reflection logic
    pair<int,int> reflect(int i,int j,int dir,vector<vector<int>>& grid) {
        while (i>=0 && i<m && j>=0 && j<n && grid[i][j]==1) {
            if (dir==0) { 
                i++;
                dir=1;
            } else { 
                j++;
                dir=0;
            }
        }
        if (i<0 || i>=m || j<0 || j>=n) return {-1,-1};
        return {i,j};
    }
    long long dfs(int i, int j, vector<vector<int>>& grid) {
     
        if (i==m-1 && j==n-1) return 1;
        if (memo[i][j] != -1) return memo[i][j];

        long long ways = 0;

        if (j+1 < n) {
            auto [x,y] = reflect(i, j+1, 0, grid);
            if (x != -1) {
                ways = (ways + dfs(x,y,grid)) % mod;
            }
        }

        if (i+1 < m) {
            auto [x,y] = reflect(i+1, j, 1, grid);
            if (x != -1) {
                ways = (ways + dfs(x,y,grid)) % mod;
            }
        }

        return memo[i][j] = ways;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<long long>(n, -1));
        return dfs(0,0,grid);
    }
};
