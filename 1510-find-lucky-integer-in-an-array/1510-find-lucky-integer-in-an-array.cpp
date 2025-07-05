class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> hash;
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        int maxnum=-1;
        for(int i=0;i<arr.size();i++){
            if(hash[arr[i]]==arr[i]){
                maxnum=max(maxnum,arr[i]);
            }
        }
        return maxnum;
    }
};