class Solution {
public:
    int func(int req,vector<int> nums){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>req) cnt+=ceil((double)nums[i]  / req )- 1;
        }
        return cnt;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxm=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxm=max(maxm,nums[i]);
        }
        int l=1,h=maxm;
        int value=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(func(mid,nums)<=maxOperations){
                value=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return value;
    }
};