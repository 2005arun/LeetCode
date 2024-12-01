class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> hash;
        for(auto i:arr){
            if(hash.find(i*2)!=hash.end() || ((i%2==0) && hash.find(i/2)!=hash.end())){
                return true;
            }
            hash[i]++;
        }
        return false;
    }
};