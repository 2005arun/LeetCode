class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int l=0,m=0,r=0,cnt=0;
        while(m<nums.size() && nums[m]==nums[l]) m++;
        while(r<nums.size()){
            if(l>=nums.size()-2 || m>=nums.size()-1) return cnt;
            r=m+1;
            while(r<nums.size() && nums[m]==nums[r]) r++;
            if(r>=nums.size()) return cnt;
            if(nums[m]>nums[l] && nums[m]>nums[r] || nums[m]<nums[l] && nums[m]<nums[r]) cnt++;
            l=m;
            m=r;
        }
        return cnt;
    }
};