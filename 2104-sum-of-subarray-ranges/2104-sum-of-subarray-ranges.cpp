class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int r=0,l=0;
        long long sum=0;
        int minval=nums[0],maxval=nums[0];
        while(l<nums.size()){
            minval=nums[l];
            maxval=nums[l];
            r=l;
            while(r<nums.size()){
                minval=std::min(minval,nums[r]);
                maxval=std::max(maxval,nums[r]);
                sum+=(maxval-minval);
                r++;
            }
            l++;
        }
        return sum;
    }
};