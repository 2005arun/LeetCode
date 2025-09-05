class Solution {
public:
    int recur(int i,int j,vector<vector<int>> &grid){
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        int right=0,down=0,dia=0;
        if((i+1<grid.size() && grid[i+1][j]==1) || (j+1<grid[0].size() && grid[i][j+1]==1)) dia=recur(i+1,j+1,grid);
        if(i+1<grid.size() && grid[i+1][j]!=1) down=recur(i+1,j,grid);
        if(j+1<grid[0].size() && grid[i][j+1]!=1) right=recur(i,j+1,grid);
        return dia+right+down;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        return recur(0,0,grid);
    }
};