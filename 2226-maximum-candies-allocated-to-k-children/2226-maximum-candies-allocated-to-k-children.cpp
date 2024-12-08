class Solution {
public:
    bool func(int mid,vector<int> candies,long long k){
        long long cnt=0;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>=mid){
                cnt +=(double)candies[i]/mid;
            }
        }
        if(cnt>=k) return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        // if(accumulate(candies.begin(),candies.end(),0)<k) return 0;
        // if(accumulate(candies.begin(),candies.end(),0)==k) return 1;
        int l=1,h=*max_element(candies.begin(),candies.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(mid,candies,k)==true) l=mid+1;
            else h=mid-1;
        }
        return h;
    }
};