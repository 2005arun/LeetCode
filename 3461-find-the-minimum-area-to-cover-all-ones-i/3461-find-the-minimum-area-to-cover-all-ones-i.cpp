class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int srind=m;
        int erind=0;
        int scind=n;
        int ecind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    srind=min(srind,i);
                    scind=min(scind,j);
                    erind=max(erind,i);
                    ecind=max(ecind,j);
                }
            }
        }
        return (erind-srind+1)*(ecind-scind+1);
    }
};