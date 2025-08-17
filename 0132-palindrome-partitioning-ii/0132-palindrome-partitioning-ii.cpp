class Solution {
public:
    // unordered_map<string,int> dp;
    vector<int> dp;
    int recur(int ind,string s){
        if(ind==s.size()) return 0;
        int minim=INT_MAX;
        // if(dp.find(str)!=0) return dp[str];
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<s.size();i++){
            int l=ind,r=i;
            bool palin=true;
            while(l<=r){
                if(s[l]!=s[r]){
                    palin=false;
                    break;
                }
                l++,r--;
            }
            if(palin){
                int tot=1+recur(i+1,s);
                minim=min(minim,tot);
            }
        }
        // return dp[str]=minim;
        return dp[ind]=minim;
    }
    int minCut(string s) {
        int l=0,r=s.size()-1;
        int f=0;
        while(l<=r){
            if(s[l]!=s[r]){
                f=1;
                break;
            }
            l++,r--;
        }
        if(f==0) return 0;
        l=0,r=s.size()-2;
        f=0;
        while(l<=r){
            if(s[l]!=s[r]){
                f=1;
                break;
            }
            l++,r--;
        }
        if(f==0) return 1;
        dp.assign(s.size(),-1);
        return recur(0,s)-1;
    }
};