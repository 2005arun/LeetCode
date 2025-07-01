class Solution {
public:
    int mod=1e9+7;
    void precompute(int n,vector<int> &p){
        p[0]=1;
        for(int i=1;i<n;i++){
            p[i]=(p[i-1]*2LL)%mod;
        }
        return;
    }
    int numSubseq(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<int> p(nums.size());
        precompute(nums.size(),p);
        long long cnt=0;
        while(l<=r){
            long long sum=nums[l]+nums[r];
            if(sum<=target){
                cnt=(cnt+p[r-l])%mod;
                l++;
            }
            else r--;
        }
        return cnt;
    }
};