class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0,i=0;
        while(i<nums.size()){
            int a=nums[i];
            i++;
            while(i<nums.size() && nums[i]-a <=k){
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};