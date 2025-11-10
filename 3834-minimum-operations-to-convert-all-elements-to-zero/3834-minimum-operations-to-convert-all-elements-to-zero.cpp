class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,vector<pair<int,int>>> hash;
        vector<int> nse(nums.size());
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i]=st.empty()?nums.size():st.top();
            st.push(i);
        }
        // for(auto i:nse) cout<<i<<" ";
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) continue;
            if(hash.count(nums[i])!=0){
                pair<int,int> p=hash[nums[i]].back();
                // cout<<p.first<<" "<<p.second<<" ";
                if(nse[i]-1<=p.second) continue;
                else{
                    hash[nums[i]].push_back({i,nse[i]-1});
                    continue;
                }
            }
            hash[nums[i]].push_back({i,nse[i]-1});
        }
        // for(auto i:hash){
        //     cout<<i.first<<" "<<i.second.size()<<endl;
        // }
        int cnt=0;
        for(auto i:hash){
            cnt+=i.second.size();
        }
        return cnt;
    }
};