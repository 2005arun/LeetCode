class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0) prefix[i]=0;
            else prefix[i]=nums[i]+prefix[i-1];
        }
        // for(auto i:prefix) cout<<i<<" ";
        int i;
        int ind=nums.size();
        vector<int> zero(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            zero[i]=ind;
            if(nums[i]==0) ind=i;
        }
        // for(auto i:zero) cout<<i<<" ";
        int maxm=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                if(nums[i]==0) maxm=max(maxm,prefix[zero[i]-1]);
                else maxm=max(maxm,prefix[zero[i]-1]-1);
            }
            else{
                if(nums[i]==0) maxm=max(maxm,prefix[i-1]+(prefix[zero[i]-1]-prefix[i]));
                else maxm=max(maxm,prefix[i-1]+(prefix[zero[i]-1]-prefix[i]-1));
            }
        }
        return maxm;
    }
};