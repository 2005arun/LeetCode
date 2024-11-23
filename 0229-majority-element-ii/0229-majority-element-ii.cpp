class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> hash;
        vector<int> vec;
        for(auto i:nums){
            hash[i]++;
        }
        for(auto i:hash){
            if(i.second>(nums.size()/3)){
                vec.push_back(i.first);
            }
        }
        return vec;
    }
};