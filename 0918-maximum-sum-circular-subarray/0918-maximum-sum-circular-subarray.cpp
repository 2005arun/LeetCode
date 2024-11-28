class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalmax=INT_MIN,globalmin=INT_MAX;
        int cmax=0,cmin=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            if(cmax<0) cmax=0;
            cmax+=nums[i];
            globalmax=max(globalmax,cmax);

            if(cmin>0) cmin=0;
            cmin+=nums[i];
            globalmin=min(globalmin,cmin);
        }
        if(globalmax<0) return globalmax;
        return max(globalmax,total-globalmin);
        
        
        
        // vector<int> res(nums.begin(),nums.end());
        // res.insert(res.end(),nums.begin(),nums.end());
        // int sum=0,maxsum=INT_MIN;
        // for(int i=0;i<res.size();i++){
        //     sum+=res[i];
        //     maxsum=max(maxsum,sum);
        //     if(sum<0) sum=0;
        // }
        // return maxsum;
        
        
        
        // int sum=0;
        // int maxsum=INT_MIN;
        // int minsum=INT_MAX;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     maxsum=max(maxsum,sum);
        //     if(sum<0) sum=0;
        // }
        // sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     minsum=min(sum,minsum);
        //     if(sum>0) sum=0;
        // }
        // if(maxsum<0) return maxsum;
        // return max(maxsum,sum-minsum);
    }
};