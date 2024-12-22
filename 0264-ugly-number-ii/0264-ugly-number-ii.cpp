class Solution {
public:
    // bool isugly(int n){
    //     if(n<=0) return false;
    //     vector<int> arr{2,3,5};
    //     for(auto i:arr){
    //         while(n%i==0) n/=i;
    //     }
    //     return n==1;
    // }
    int nthUglyNumber(int n) {
        // int cnt=1;
        // int i=1;
        // while(true){
        //     if(isugly(i)==true){
        //         if(cnt==n) return i;
        //         cnt++;
        //     }
        //     i++;
        // }
        vector<int> dp(n);
        dp[0]=1;
        int i2=0,i3=0,i5=0;
        int next1=2,next2=3,next3=5;
        for(int i=1;i<n;i++){
            int ugly=min({next1,next2,next3});
            dp[i]=ugly;
            if(ugly==next1){
                i2++;
                next1=dp[i2]*2;
            }
            if(ugly==next2){
                i3++;
                next2=dp[i3]*3;
            }
            if(ugly==next3){
                i5++;
                next3=dp[i5]*5;
            }
        }
        return dp[n-1];
    }
};