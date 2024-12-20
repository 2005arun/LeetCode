class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(j!=(i+1) && nums[j]==nums[j-1]){
                    continue;
                }
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum=sum+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l]==nums[l+1])l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
        // set<vector<int>> st;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         set<int> hash;
        //         for(int k=j+1;k<nums.size();k++){
        //             long long four=target-(nums[i]+nums[j]+nums[k]);
        //             if(hash.find(four)!=hash.end()){
        //                 vector<int> temp={nums[i],nums[j],nums[k],four};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //             hash.insert(nums[k]);
        //         }
        //     }
        // }
        // vector<vector<int>> res(st.begin(),st.end());
        // return res;
    }
};