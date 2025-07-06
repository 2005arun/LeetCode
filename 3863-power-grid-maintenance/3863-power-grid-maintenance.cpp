class Solution {
public:
    vector<int> par,size;
    int findPar(int node){
        if(par[node]==node) return node;
        return par[node]=findPar(par[node]);
    }
    void findUnion(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        return;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,set<int>>hash;
        par.resize(c+1);
        size.assign(c+1,1);
        for(int i=1;i<=c;i++) par[i]=i;
        for(auto &it:connections){
            findUnion(it[0],it[1]);
        }
        for(int i=1;i<=c;i++){
            int a=findPar(i);
            hash[a].insert(i);
        }
        vector<int> res;
        for(auto &i:queries){
            if(i[0]==1){
                int a=findPar(i[1]);
                if(hash[a].count(i[1])==1) res.push_back(i[1]);
                else if(hash[a].size()==0) res.push_back(-1);
                else{
                    res.push_back(*hash[a].begin());
                }
            }
            else{
                int a=findPar(i[1]);
                hash[a].erase(i[1]);
            }
        }
        return res;
    }
};