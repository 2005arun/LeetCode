class Solution {
public:
    // int recur(int node,vector<vector<int>> &adj,int &dia){
    //     int lh=0,rh=0;
    //     for(auto it:adj[node]){
    //         int height=1+recur(it,adj,dia);
    //         if(height>lh){
    //             rh=lh;
    //             lh=height;
    //         }
    //         else if(height>rh){
    //             rh=height;
    //         }
    //     }
    //     dia=max(dia,lh+rh);
    //     // cout<<lh<<" ";
    //     return lh;
    // }
    int maindist;
    void dfs(int node,vector<vector<int>> &adj,int &maxnode,int dist,int parnode){
        if(dist > maindist){
            maindist=dist;
            maxnode=node;
        }
        for(auto &it:adj[node]){
            if(it==parnode) continue;
            dfs(it,adj,maxnode,dist+1,node);
        }
    }
    int recur(int node,vector<vector<int>> &adj){
        int A=node;
        maindist=0;
        dfs(node,adj,A,0,-1);
        maindist=0;
        int B=A;
        dfs(B,adj,B,0,-1);
        return maindist;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=0;
        for(auto i:edges1){
            n=max(n,max(i[0],i[1]));
        }
        int m=0;
        for(auto i:edges2){
            m=max(m,max(i[0],i[1]));
        }
        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);
        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        int res1=recur(0,adj1);
        int res2=recur(0,adj2);
        // cout<<res1<<" "<<res2;
        int ans1=ceil(float(res1)/2);
        int ans2=ceil(float(res2)/2);
        cout<<ans1<<" "<<ans2;
        return max({res1,res2,ans1+ans2+1});
    }
};