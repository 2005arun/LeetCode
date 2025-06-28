class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({i,nums[i]});
        }
        sort(vec.begin(),vec.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.second>b.second;
        });
        int i=0;
        vector<pair<int,int>> res;
        while(k--){
            res.push_back({vec[i].first,vec[i].second});
            i++;
        }
        sort(res.begin(),res.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return a.first<b.first;
        });
        vector<int> free;
        for(int i=0;i<res.size();i++){
            free.push_back(res[i].second);
        }
        return free;
    }
};