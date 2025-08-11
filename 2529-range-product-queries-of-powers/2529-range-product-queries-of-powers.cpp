class Solution {
public:
    long long modpow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> vec;
        int mod=1e9+7;
        int i=0;
        // if((n&(n-1))==0) return {n};
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0) {
                vec.push_back((1<<i)%mod);
            }
        }
        // for(auto i:vec) cout<<i<<" "; 
        vector<int> precompute(vec.size()+1,1);
        precompute[0]=vec[0];
        for(int i=1;i<vec.size();i++){
            precompute[i]=((long long)precompute[i-1]*vec[i])%mod;
        }
        vector<int> res;
        for(auto i:queries){
            int r=i[0];
            int c=i[1];
            // cout<<r<<" "<<c<<" ";
            if(r==0) res.push_back(precompute[c]);
            else {
                long long val=modpow(precompute[r-1],mod-2,mod);
                res.push_back((precompute[c]*val)%mod);
            }
        }
        return res;
    }
};