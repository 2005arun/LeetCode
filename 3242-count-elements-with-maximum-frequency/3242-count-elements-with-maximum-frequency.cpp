class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> hash;
        int maxm=0;
        for(auto i:nums){
            hash[i]++;
            if(hash[i]>maxm){
                maxm=hash[i];
            }
        }
        int sum=0;
        for(auto i:hash){
            if(i.second==maxm) sum+=i.second;
        }
        return sum;
    }
};