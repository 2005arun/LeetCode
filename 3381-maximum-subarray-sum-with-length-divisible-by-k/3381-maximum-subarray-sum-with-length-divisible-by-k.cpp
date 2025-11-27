class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // int a=nums.size()%k;
        // int len=nums.size()-a;
        // int l=0,r=len-1;
        // long long sum=0;
        // long long maxm=0;
        // for(int i=0;i<=r;i++){
        //     sum+=nums[i];
        // }
        // maxm=sum;
        // r++;
        // while(r<nums.size()){
        //     sum-=nums[l];
        //     l++;
        //     sum+=nums[r];
        //     r++;
        //     maxm=max(maxm,sum);
        // }
        // return maxm;

        unordered_map<int,long long> hash;
        hash[0]=0;
        long long sum=0;
        long long maxm=LLONG_MIN;
        for(int i=1;i<=nums.size();i++){
            sum+=nums[i-1];
            if(hash.find(i%k)!=hash.end()){
                maxm=max(maxm,sum-hash[i%k]);
                hash[i%k]=min(hash[i%k],sum);
                continue;
            }
            hash[i]=sum;
        }
        return maxm;
    }
};