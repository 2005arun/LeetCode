class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minind=min_element(nums.begin(),nums.end())-nums.begin();
        int maxind=max_element(nums.begin(),nums.end())-nums.begin();
        int mindiff=min(minind,maxind);
        int maxdiff=max(minind,maxind);
        int val1=nums.size()-mindiff;
        int val2=maxdiff+1;
        int val3=mindiff+1+(nums.size()-maxdiff);
        return min({val1,val2,val3});
    }
};