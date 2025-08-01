class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxm=*max_element(nums.begin(),nums.end());
        int maxlen=0;
        int i=0;
        int curlen=0;
        while(i<nums.size()){
            if(maxm==nums[i]){
                curlen++;
                maxlen=max(maxlen,curlen);
            }
            else curlen=0;
            i++;
        }
        return maxlen;
    }
};