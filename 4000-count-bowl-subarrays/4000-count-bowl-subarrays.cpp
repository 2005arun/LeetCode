class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long cnt=0;
        stack<int> st,st2;
        vector<int> vec1(nums.size()),vec2(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            vec1[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()]<nums[i]) st2.pop();
            vec2[i]=st2.empty()?nums.size():st2.top();
            st2.push(i);
        }
        for(int i=0;i<nums.size();i++){
            if(vec1[i]!=-1 && vec2[i]!=nums.size()){
                cnt++;
            } 
        }
        return cnt;
    }
};