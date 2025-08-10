class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> res;
        int val=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i) {
                val&=nums[i];
            }
        }
        if(val==-1) return 0;
        return val;
    }
};