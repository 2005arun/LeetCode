class Solution {
public:
    vector<int> par;
    int findPar(int ch){
        if(par[ch]==ch) return ch;
        return par[ch]=findPar(par[ch]);
    }
    void findUnion(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v) return;
        if(ulp_u < ulp_v) par[ulp_v]=ulp_u;
        else par[ulp_u]=ulp_v;
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        par.resize(27);
        for(int i=0;i<26;i++){
            par[i]=i;
            // cout<<par[i]<<" ";
        }
        for(int i=0;i<s1.size();i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            // cout<<u<<" "<<v<<" "<<endl;
            findUnion(u,v);
        }
        string res="";
        for(int i=0;i<baseStr.size();i++){
            int ch=findPar(baseStr[i]-'a');
            res.push_back(char(ch+97));
        }
        return res;
    }
};