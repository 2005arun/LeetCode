class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int maxm=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0)sum=0;
            maxm=max(sum,maxm);
        }
        int s=0;
        int minim=INT_MAX;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s>0)s=0;
            minim=min(s,minim);
        }
        int res=max(abs(maxm),abs(minim));
        return res;
        // int premin=0;
        // int premax=0,sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     premin=min(sum,premin);
        //     premax=max(sum,premax);
        // }
        // return abs(premin)+premax;
    }
};