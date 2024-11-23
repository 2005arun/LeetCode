class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // map<int,int> hash;
        // vector<int> vec;
        // for(auto i:nums){
        //     hash[i]++;
        // }
        // for(auto i:hash){
        //     if(i.second>(nums.size()/3)){
        //         vec.push_back(i.first);
        //     }
        // }
        // return vec;
        int cnt1=0;
        int cnt2=0;
        int el1,el2;
        
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && nums[i]!=el1){
                el2=nums[i];
                cnt2++;
            }
            else if(el1==nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else cnt1--,cnt2--;
        }
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(el1==nums[i]) c1++;
            else if(el2==nums[i]) c2++;
        }
        vector<int> ls;
        if(c1>(nums.size()/3)){
            ls.push_back(el1);
        }
        if(c2>(nums.size()/3)){
            ls.push_back(el2);
        }
        return ls;
    }
};