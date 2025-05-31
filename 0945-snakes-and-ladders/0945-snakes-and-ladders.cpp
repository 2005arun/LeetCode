class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> grid(n,vector<int>(m));
        int k=0;
        bool rev=true;
        for(int i=n-1;i>=0;i--){
            int l=0;
            if(rev){
                for(int j=0;j<m;j++){
                    grid[k][l]=board[i][j];
                    l++;
                }
            }
            else{
                for(int j=m-1;j>=0;j--){
                    grid[k][l]=board[i][j];
                    l++;
                }
            }
            rev=!rev;
            k++;
        }
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;
        q.push({1,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int val=it.first;
            int level=it.second;
            if(val==n*n) return level;
            for(int i=1;i<=6;i++){
                int v=val+i;
                int ncol=(v-1)%n;
                int nrow=(v-1)/n;
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0){
                    if(vis[nrow][ncol]==0 && grid[nrow][ncol]==-1){
                        vis[nrow][ncol]=1;
                        q.push({v,level+1});
                    }
                    else{
                        v=grid[nrow][ncol];
                        if(vis[nrow][ncol]==0) {
                            vis[nrow][ncol]=1;
                            q.push({v,level+1});
                        }
                    }
                }
            }
        }
        return -1;

    }
};