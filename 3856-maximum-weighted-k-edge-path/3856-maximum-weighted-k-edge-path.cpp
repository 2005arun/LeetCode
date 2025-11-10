class Solution {
public:
    // int bfs(int n,vector<vector<pair<int,int>>> &adj,int k,int t){
    //     queue<vector<int>> q;
    //     q.push({n,0,0});
    //     int maxm=0;
    //     while(!q.empty()){
    //         int node=q.front()[0];
    //         int wt=q.front()[1];
    //         int step=q.front()[2];
    //         q.pop();
    //         if(step==k){
    //             if(wt<t) maxm=max(wt,maxm);
    //             continue;
    //         }
    //         // if(adj[node].size()==0) continue;
    //         for(auto it:adj[node]){
    //             int adjnode=it.first;
    //             int adjwt=it.second;
    //             q.push({adjnode,adjwt+wt,step+1});
    //         }
    //     }
    //     return maxm;
    // }

    int step,target;
    vector<vector<pair<int,int>>> adj;
    // vector<vector<vector<int>>> dp;
    // int dfs(int node,int k,int sum){
    //     if(step==k) return sum;
    //     if(k>step) return -1;
    //     if(dp[node][k][sum]!=-1) return dp[node][k][sum];
    //     int maxm=-1;
    //     for(auto it:adj[node]){
    //         int newtot=sum+it.second;
    //         if(newtot>=target) continue;
    //         int next=dfs(it.first,k+1,newtot);
    //         if(next!=-1) maxm=max(maxm,next);
    //     }
    //     return dp[node][k][sum]=maxm;
    // }

    vector<vector<unordered_map<int,int>>> dp;

    int dfs(int node, int k, int sum) {
        if (k == step) return sum;
        if (sum >= target) return -1;
        if (dp[node][k].count(sum)) return dp[node][k][sum];

        int maxm = -1;
        for (auto &it : adj[node]) {
            int newSum = sum + it.second;
            if (newSum >= target) continue;
            int next = dfs(it.first, k + 1, newSum);
            if (next != -1)
                maxm = max(maxm, next);
        }
        return dp[node][k][sum] = maxm;
    }

    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        if(k==0) return 0;
        adj.assign(n,{});
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }

        // int maxm=0;
        // // cout<<maxm<<" ";
        // for(int i=0;i<n;i++){
        //     maxm=max(maxm,bfs(i,adj,k,t));
        // }
        // return maxm==0?-1:maxm;

        step=k;
        target=t;
        dp.assign(n, vector<unordered_map<int,int>>(k + 1));        
        int maxm=-1;
        for(int i=0;i<n;i++){
            int tot=dfs(i,0,0);
            maxm=max(maxm,tot);
        }
        return maxm;
    }
};