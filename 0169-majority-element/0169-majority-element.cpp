class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int> hash;
        // for(int i=0;i<nums.size();i++){
        //     hash[nums[i]]++;
        // }
        // int sum=INT_MIN;
        // int res=INT_MIN;
        // for(auto i:hash){
        //     if(i.second>sum){
        //         sum=i.second;
        //         res=i.first;
        //     }
        // }
        // return res;
        int element=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                element=nums[i];
                cnt++;
            }
            else if(element==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element){
                c++;
            }
        }
        if(c>=nums.size()/2){
            return element;
        }
        return -1;
    }
};