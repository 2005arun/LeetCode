class Solution {
public:
    // void subset(int ind,vector<int> &nums,vector<vector<int>> &res,vector<int> &vec){
    //     if(ind==nums.size()){
    //         res.push_back(vec);
    //         return ;
    //     }
    //     vec.push_back(nums[ind]);
    //     subset(ind+1,nums,res,vec);
    //     vec.pop_back();
    //     subset(ind+1,nums,res,vec);
    //     return ;
    // }
    vector<vector<int>> dp;
    int recur(int i,vector<int> &nums,int maxm,int x){
        if(i==nums.size()){
            return x==maxm;
        }
        if(dp[i][x]!=-1) return dp[i][x];
        int non_take=recur(i+1,nums,maxm,x);
        int take=recur(i+1,nums,maxm,x|nums[i]);
        return dp[i][x]=take+non_take;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        // vector<vector<int>> res;
        // vector<int> vec;
        // subset(0,nums,res,vec);
        int n=nums.size();
        int maxm=0;
        for(auto i:nums){
            maxm|=i;
        }
        // int cnt=0;
        // for(auto i:res){
        //     int x=0;
        //     for(auto j:i){
        //         x|=j;
        //     }
        //     if(x==maxm) cnt++;
        // }
        // return cnt;
        dp.assign(n,vector<int>(maxm+1,-1));
        int x=0;
        return recur(0,nums,maxm,x);
    }
};