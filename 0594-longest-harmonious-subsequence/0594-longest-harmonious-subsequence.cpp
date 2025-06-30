class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        unordered_map<int,int> hash;
        int maxlen=0;
        for(int i=0;i<nums.size();i++) hash[nums[i]]++;
        set<int> st;
        st.insert(nums.begin(),nums.end());
        for(auto &i:st){
            if(!st.count(i+1)) continue;
            maxlen=max(maxlen,hash[i]+hash[i+1]);
        }
        return maxlen;
    }
};