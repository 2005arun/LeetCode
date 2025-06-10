class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> hash;
        for(auto i:s){
            hash[i]++;
        }
        int even=INT_MAX;
        int odd=INT_MIN;
        for(const auto &pair:hash){
            if(pair.second%2==0){
                even=min(even,pair.second);
            }
            else{
                odd=max(odd,pair.second);
            }
        }
        return odd-even;
    }
};