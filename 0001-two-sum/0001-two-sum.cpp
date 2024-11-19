class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int first = 0;
        // int last = 0;
        // for(int i = 0; i < nums.size() - 1; i++) {
        //     for(int j = 1 ; j < nums.size(); j++) {
        //         if(nums[i] + nums[j] == target && i != j){
        //             first = i;
        //             last = j;
        //             break;
        //         }
        //     }
        // }
        // return {first,last};
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int a=target-nums[i];
            if(hash.find(a)!=hash.end() && hash[a]!=i){
                return {hash[a],i};
            }
        }
        return {-1,-1};
        // int l=0,r=nums.size()-1;
        // while(l<=r){
        //     if((nums[l]+nums[r])==target) return {l,r};
        //     else if((nums[l]+nums[r])>target){
        //         r--;
        //     }
        //     else{
        //         l++;
        //     }
        // }
        // return {-1,-1};
    }
};