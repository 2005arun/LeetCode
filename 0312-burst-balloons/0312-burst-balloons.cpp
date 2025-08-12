class Solution {
public:
    vector<vector<int>> dp;
    int recur(int i,int j,vector<int> &nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int tot=INT_MIN;
        for(int k=i;k<=j;k++){
            tot=max(tot,((nums[i-1]*nums[k]*nums[j+1])+recur(i,k-1,nums)+recur(k+1,j,nums)));
        }
        return dp[i][j]=tot;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // dp.assign(nums.size(),vector<int>(nums.size(),-1));
        // return recur(1,nums.size()-2,nums);

        dp.assign(nums.size(),vector<int>(nums.size(),0));
        for(int i=nums.size()-2;i>=1;i--){
            for(int j=1;j<=nums.size()-2;j++){
                if(i>j) continue;
                int tot=INT_MIN;
                for(int k=i;k<=j;k++){
                    tot=max(tot,(nums[i-1]*nums[k]*nums[j+1])+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=tot;
            }
        }
        return dp[1][nums.size()-2];
    }
};