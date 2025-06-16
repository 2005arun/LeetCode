class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxm=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]) maxm=max(maxm,nums[j]-nums[i]);
            }
        }
        return maxm;
    }
};