class Solution {
public:
    // void subset(int i,vector<int> &nums,vector<int> vec,vector<vector<int>> &res){
    //     if(i==nums.size()){
    //         res.push_back(vec);
    //         return;
    //     }
    //     vec.push_back(nums[i]);
    //     subset(i+1,nums,vec,res);
    //     vec.pop_back();
    //     subset(i+1,nums,vec,res);
    // }

    // count no of elements:
    // int recur(int ind,vector<int> &nums,int n,int prevind){
    //     if(ind==n) return 0;
    //     int take=0;
    //     if(prevind==-1 || nums[ind]%nums[prevind]==0){
    //         take=1+recur(ind+1,nums,n,ind);
    //     }
    //     int non_take=recur(ind+1,nums,n,prevind);
    //     return max(take,non_take);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,0);
        vector<int> hash(n);
        int maxm=0;
        int lastind=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            // cout<<i<<" ";
            int res=0;
            for(int j=0;j<i;j++){
                // cout<<j<<" ";
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    // cout<<j<<" ";
                    dp[i]=1+dp[j];
                    // cout<<dp[i]<<" ";
                    hash[i]=j;
                    res=max(res,dp[i]);
                }
            }
            if(res>maxm){
                maxm=res;
                lastind=i;
            }
        }
        vector<int> out;
        cout<<lastind<<" ";
        while(hash[lastind]!=lastind){
            out.push_back(nums[lastind]);
            lastind=hash[lastind];
        }
        out.push_back(nums[lastind]);
        return out;

        // cout<<recur(0,nums,n,-1);
        // return {};

        // vector<vector<int>> res;
        // vector<int> vec;
        // subset(0,nums,vec,res);
        // vector<int> out;
        // for(auto it:res){
        //     int f=0;
        //     for(int i=0;i<it.size();i++){
        //         for(int j=i;j<it.size();j++){
        //             if(it[i]%it[j]!=0 && it[j]%it[i]!=0){
        //                 f=1;
        //                 break;
        //             }
        //         }
        //         if(f==1) break;
        //     }
        //     if(f==0 && out.size() < it.size()){
        //         out=it;
        //     }
        // }
        // return out;
    }
};