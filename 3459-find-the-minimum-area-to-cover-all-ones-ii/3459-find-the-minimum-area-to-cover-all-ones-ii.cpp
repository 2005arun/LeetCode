class Solution {
public:
    int findrectangle(int r1, int r2, int c1, int c2, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minr=n, minc=m, maxr=-1, maxc=-1;

        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                if(grid[i][j]==1){
                    minr=min(minr,i);
                    minc=min(minc,j);
                    maxr=max(maxr,i);
                    maxc=max(maxc,j);
                }
            }
        }
        if(maxr==-1) return 0; 
        return (maxr-minr+1)*(maxc-minc+1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int low_x=m, low_y=n, high_x=-1, high_y=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    low_x=min(low_x,j);
                    low_y=min(low_y,i);
                    high_x=max(high_x,j);
                    high_y=max(high_y,i);
                }
            }
        }
        if(high_x==-1) return 0;

        int maxm=INT_MAX;

        for(int i=low_y;i<high_y;i++){
            for(int j=low_x;j<high_x;j++){
                for(int k=1;k<=4;k++){
                    int a=0,b=0,c=0;
                    switch(k){
                        case 1:
                            a=findrectangle(low_y,i,low_x,j,grid);
                            b=findrectangle(low_y,i,j+1,high_x,grid);
                            c=findrectangle(i+1,high_y,low_x,high_x,grid);
                            break;
                        case 2:
                            a=findrectangle(low_y,i,low_x,j,grid);
                            b=findrectangle(i+1,high_y,low_x,j,grid);
                            c=findrectangle(low_y,high_y,j+1,high_x,grid);
                            break;
                        case 3:
                            a=findrectangle(low_y,high_y,low_x,j,grid);
                            b=findrectangle(low_y,i,j+1,high_x,grid);
                            c=findrectangle(i+1,high_y,j+1,high_x,grid);
                            break;
                        case 4:
                            a=findrectangle(low_y,i,low_x,high_x,grid);
                            b=findrectangle(i+1,high_y,low_x,j,grid);
                            c=findrectangle(i+1,high_y,j+1,high_x,grid);
                            break;
                    }
                    if(a && b && c) maxm=min(maxm,a+b+c);
                }
            }
        }
        for(int i=low_y;i<=high_y-2;i++){
            for(int j=i+1;j<=high_y-1;j++){
                int a=findrectangle(low_y,i,low_x,high_x,grid);
                int b=findrectangle(i+1,j,low_x,high_x,grid);
                int c=findrectangle(j+1,high_y,low_x,high_x,grid);
                if(a && b && c) maxm=min(maxm,a+b+c);
            }
        }

        for(int i=low_x;i<=high_x-2;i++){
            for(int j=i+1;j<=high_x-1;j++){
                int a=findrectangle(low_y,high_y,low_x,i,grid);
                int b=findrectangle(low_y,high_y,i+1,j,grid);
                int c=findrectangle(low_y,high_y,j+1,high_x,grid);
                if(a && b && c) maxm=min(maxm,a+b+c);
            }
        }

        return maxm==INT_MAX?0:maxm;
    }
};
