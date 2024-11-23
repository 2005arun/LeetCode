class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // set<vector<int>> st;
        // for(int i=0;i<nums.size();i++){
        //     set<int> hashset;
        //     for(int j=i+1;j<nums.size();j++){
        //         int third=-(nums[i]+nums[j]);
        //         if(hashset.find(third)!=hashset.end()){
        //             vector<int> temp={nums[i],nums[j],third};
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> res(st.begin(),st.end());
        // return res;
        vector<vector<int>> vec;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if((nums[i]+nums[j]+nums[k])==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    vec.push_back(temp);
                    j++,k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if((nums[i]+nums[j]+nums[k])<0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return vec;
    }
};