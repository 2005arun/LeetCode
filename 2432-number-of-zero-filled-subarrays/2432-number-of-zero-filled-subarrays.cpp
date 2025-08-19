class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int l=0,r=0;
        long long cnt=0,ans=0;
        while(r<nums.size()){
            while(l<=r && cnt>0){
                if(nums[l]!=0) cnt--;
                l++;
            }
            if(nums[r]!=0){
                cnt++;
            }
            else{
                ans+=(r-l+1);
            }
            r++;
        }
        return ans;
    }
};