class Solution {
public:
    void subset(int ind,vector<int> &nums,vector<vector<int>> &res,vector<int> &vec){
        if(ind==nums.size()){
            res.push_back(vec);
            return ;
        }
        vec.push_back(nums[ind]);
        subset(ind+1,nums,res,vec);
        vec.pop_back();
        subset(ind+1,nums,res,vec);
        return ;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        subset(0,nums,res,vec);
        int maxm=0;
        for(auto i:nums){
            maxm|=i;
        }
        int cnt=0;
        for(auto i:res){
            int x=0;
            for(auto j:i){
                x|=j;
            }
            if(x==maxm) cnt++;
        }
        return cnt;
    }
};