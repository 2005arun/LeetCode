class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            st.insert(i);
        }
        for(int i=0;i<=nums.size();i++){
            if(st.find(i+1)==st.end()) return i+1;
        }
        return nums.size()+1;
    }
};