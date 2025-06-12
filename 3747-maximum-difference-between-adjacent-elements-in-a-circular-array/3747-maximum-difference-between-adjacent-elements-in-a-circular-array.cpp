class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int sum=INT_MIN;
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++){
            sum=max(sum,abs(nums[i]-nums[i-1]));
        }
        sum=max(sum,abs(nums[nums.size()-1]-nums[0]));
        return sum;
    }
};