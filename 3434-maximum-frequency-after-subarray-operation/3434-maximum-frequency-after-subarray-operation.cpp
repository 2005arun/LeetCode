class Solution {
public:
    int recur(int t,vector<int> &nums,int k){
        int maxm=0,cur=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k) cur--;
            else if(nums[i]==t) cur++;

            if(cur<0) cur=0;
            maxm=max(maxm,cur);
        }
        return maxm;
    }
    int maxFrequency(vector<int>& nums, int k) {
        // unordered_map<int,int> hash;
        // int s=0,cnt=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==k){
        //         s--;
        //     }
        //     else{
        //         hash[nums[i]]++;
        //         s=max(s,hash[nums[i]]);
        //         // cout<<s<<" ";
        //     }
        // }
        // return cnt+s;

        unordered_map<int,int> hash;
        int maxm=0;
        for(auto i:nums) hash[i]++;
        for(auto i:hash){
            maxm=max(maxm,recur(i.first,nums,k));
        }
        return hash[k]+maxm;
    }
};