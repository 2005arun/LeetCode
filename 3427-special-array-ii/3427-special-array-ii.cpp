class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> prefix(n);
        int ev=0;
        if(nums[0]%2==0) ev=1;
        prefix[0]=1;
        for(int i=1;i<n;i++){
            if(ev==1 && nums[i]%2!=0){
                prefix[i]=1+prefix[i-1];
                ev=0;
            }
            else if(ev==0 && nums[i]%2==0){
                prefix[i]=1+prefix[i-1];
                ev=1;
            }
            else prefix[i]=prefix[i-1]-1;
        }
        vector<bool> res;
        for(auto i:queries){
            int s=i[0],e=i[1];
            int val=prefix[s];
            int find=val+(e-s);
            if(prefix[e]==find) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};