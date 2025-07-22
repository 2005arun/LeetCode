class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        int l=0,r=0;
        set<int> st;
        int maxm=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(l<=r && st.count(nums[r])>=1){
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            st.insert(nums[r]);
            maxm=max(sum,maxm);
            r++;
        }
        return maxm;
    }
};