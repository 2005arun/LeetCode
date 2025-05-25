class Solution {
public:
    long long recur(int n,int k){
        if(n<=k) return n;
        return k*(recur(n-k,k));
    }
    long long minCuttingCost(int n, int m, int k) {
        long long sum=0;
        if(n<=k && m<=k) return 0;
        if(n<=k && m>k){
            sum+=recur(m,k);
        }
        else if(m<=k && n>k) sum+=recur(n,k);
        else{
            sum+=recur(n,k);
            sum+=recur(m,k);
        }
        return sum;
    }
};