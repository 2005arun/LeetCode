class Solution {
    private:
    void f(vector<vector<int>> &ds,vector<int> &ans,int freq[],vector<int> nums){
        if(ans.size()==nums.size()){
            ds.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ans.push_back(nums[i]);
                freq[i]=1;
                f(ds,ans,freq,nums);
                freq[i]=0;
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ds;
        vector<int> ans;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        f(ds,ans,freq,nums);
        return ds;
    }
};