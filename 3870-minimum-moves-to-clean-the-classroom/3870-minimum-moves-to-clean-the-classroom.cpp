class Solution {
public:
    // void recur(int r,int c,vector<string> &classroom,int energy,int e,int cnt_liter,
    //            int step,int &minim,int n,int m,int dr[],int dc[],set<tuple<int,int,int,int>> &vis){
    //     if(cnt_liter==0){
    //         minim=min(minim,step);
    //         return;
    //     }
    //     if(e==0) return;
    //     auto state = make_tuple(r, c, e, cnt_liter);
    //     if (vis.count(state)) return;
    //     vis.insert(state);
    //     for(int i=0;i<4;i++){
    //         int nrow=r+dr[i];
    //         int ncol=c+dc[i];
    //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
    //             if(classroom[nrow][ncol]=='.'){
    //                 recur(nrow,ncol,classroom,energy,e-1,cnt_liter,step+1,minim,n,m,dr,dc,vis);
    //             }
    //             else if(classroom[nrow][ncol]=='L'){
    //                 classroom[nrow][ncol] = '.';
    //                 recur(nrow,ncol,classroom,energy,e-1,cnt_liter-1,step+1,minim,n,m,dr,dc,vis);
    //                 classroom[nrow][ncol] = 'L';
    //             }
    //             else if(classroom[nrow][ncol]=='R'){
    //                 recur(nrow,ncol,classroom,energy,energy,cnt_liter,step+1,minim,n,m,dr,dc,vis);
    //             }
    //         }
    //     }
    // }
    int minMoves(vector<string>& classroom, int energy) {
        // int cnt_liter=0;
        // int r=0,c=0;
        // int dr[]={-1,1,0,0};
        // int dc[]={0,0,1,-1};
        // for(int i=0;i<classroom.size();i++){
        //     for(int j=0;j<classroom[0].size();j++){
        //         if(classroom[i][j]=='L') cnt_liter++;
        //         if(classroom[i][j]=='S'){
        //             r=i;
        //             c=j;
        //         }
        //     }
        // }
        // set<tuple<int,int,int,int>> vis;
        // int minim=INT_MAX;
        // recur(r,c,classroom,energy,energy,cnt_liter,0,minim,classroom.size(),classroom[0].size(),dr,dc,vis);
        // if(minim==INT_MAX) return -1;
        // return minim;
        int n=classroom.size();
        int m=classroom[0].size();
        pair<int,int> start;
        vector<pair<int,int>> vec;
        map<pair<int,int>,int> hash;
        int l=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='S'){
                    start.first=i;
                    start.second=j;
                }
                else if(classroom[i][j]=='L'){
                    vec.push_back({i,j});
                    hash[{i,j}]=l++;
                }
            }
        }
        bool vis[20][20][1<<10][51];
        memset(vis,false,sizeof(vis));
        struct State{
            int x,y,mask,e,d;
        };
        queue<State> q;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        vis[start.first][start.second][0][energy]=true;
        q.push({start.first,start.second,0,energy,0});
        while(!q.empty()){
            State u=q.front();
            q.pop();
            if(u.mask==(1<<l)-1) return u.d;
            if(u.e==0) continue;
            for(int i=0;i<4;i++){
                int nrow=u.x+dr[i];
                int ncol=u.y+dc[i];
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || classroom[nrow][ncol]=='X') continue;
                int ne=u.e-1;
                if(classroom[nrow][ncol]=='R') ne=energy;
                int nmask=u.mask;
                if(classroom[nrow][ncol]=='L'){
                    nmask|=(1<<hash[{nrow,ncol}]);
                }
                if(!vis[nrow][ncol][nmask][ne]){
                    vis[nrow][ncol][nmask][ne]=true;
                    q.push({nrow,ncol,nmask,ne,u.d+1});
                }
            }
        }
        return -1;
    }
};