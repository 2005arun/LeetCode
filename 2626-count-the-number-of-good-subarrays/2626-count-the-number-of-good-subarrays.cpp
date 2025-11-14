class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long cnt=0;
        int l=0,r=0;
        unordered_map<int,int> hash;
        int tot=0;
        while(r<nums.size()){
            hash[nums[r]]++;
            tot+=hash[nums[r]]-1;
            while(tot>=k){
                cnt+=(nums.size()-r);
                tot-=hash[nums[l]]-1;
                hash[nums[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};