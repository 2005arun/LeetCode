class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        // if(n%2==0){
        //     return {n-1,1};
        // }
        // return {2,n-2};
        for(int i=1;i<n;i++){
            int  a=i,b=n-i;
            int s1=a,s2=b;
            cout<<a<<" "<<b<<" ";
            int f=0;
            while(a!=0){
                if(a%10==0) {
                    f=1;
                    break;
                }
                a/=10;
            }
            if(f==1) continue;
            while(b!=0){
                if(b%10==0){
                    f=1;
                    break;
                }
                b/=10;
            }
            if(f==0) return {s1,s2};
        }
        return {1,1};
    }
};