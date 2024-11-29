class Solution {
private:
    void f(int ind,int n,vector<vector<int>> &ds,vector<int> &arr,vector<int> &nums){
        if(ind==n){
            ds.push_back(arr);
            return;
        }
        arr.push_back(nums[ind]);
        f(ind+1,n,ds,arr,nums);
        arr.pop_back();
        f(ind+1,n,ds,arr,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ds;
        vector<int>arr;
        f(0,n,ds,arr,nums);
        return ds;
    }
};