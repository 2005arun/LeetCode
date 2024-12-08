class Solution {
public:
    int countPrimes(int n) {
        // int cnt=0;
        // for(int i=2;i<n;i++){
        //     if(i==2 || i==3|| i==5||i==7){
        //         cnt++;
        //     }
        //     else if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0) cnt++;
        // }
        // return cnt;
        int cnt=0;
        if(n<2) return 0; 
        vector<int> prime(n,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<n;i++){
            if(prime[i]==1){
                for(int j=i*i;j<n;j+=i){
                    prime[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(prime[i]==1) cnt++;
        }
        return cnt;
    }
};