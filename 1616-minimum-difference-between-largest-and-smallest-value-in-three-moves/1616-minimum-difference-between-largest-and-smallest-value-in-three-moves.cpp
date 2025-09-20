class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=4) return 0;
        int l=2;
        int r=nums.size();
        int minim=INT_MAX;
        while(l>=-1){
            minim=min(minim,nums[r-1]-nums[l+1]);
            l--;
            r--;
        }
        return minim;
    }
};