class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> vec;
        int i=0;
        while(i<nums.size()){
            int ind=i+3;
            vector<int> v;
            while(ind<=nums.size() && i<ind){
                v.push_back(nums[i]);
                i++;
            }
            vec.push_back(v);
        }
        for(auto i:vec){
            if(i[i.size()-1]-i[0] > k) return {};
        }
        return vec;
    }
};