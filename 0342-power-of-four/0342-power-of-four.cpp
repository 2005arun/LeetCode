class Solution {
public:
    bool isPowerOfFour(int n) {
        int a=n/4;
        int l=0,h=a;
        while(l<=h){
            int mid=(l+h)/2;
            if(pow(4,mid)>n) h=mid-1;
            else if(pow(4,mid)<n) l=mid+1;
            else return true;
        }
        return false;
    }
};