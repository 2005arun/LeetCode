class Solution {
public:
    long long flowerGame(int n, int m) {
        long long neven=n/2;
        long long nodd=n-neven;

        long long meven=m/2;
        long long modd=m-meven;

        return neven*modd+nodd*meven;
        
    }
};