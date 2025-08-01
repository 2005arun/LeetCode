class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> bit(32,-1);
        vector<int> res;
        int cur=0;
        for(int i=nums.size()-1;i>=0;i--){
            cur|=nums[i];
            int pos=0;
            while(cur>0){
                if(cur&1) bit[pos]=i;
                cur/=2;
                pos++;
            }
            int ind=*max_element(bit.begin(),bit.end());
            if(ind==-1) res.push_back(1);
            else res.push_back(ind-i+1);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};