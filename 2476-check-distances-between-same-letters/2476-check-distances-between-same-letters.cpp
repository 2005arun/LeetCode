class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,vector<int>> hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]].push_back(i);
        }
        for(int i=0;i<distance.size();i++){
            char ch='a'+i;
            if(hash[ch].size()==0) continue;
            int dist=distance[i];
            // cout<<hash[ch][1]-hash[ch][0]-1;
            if((hash[ch][1]-hash[ch][0]-1) != dist) return false;
        }
        return true;
    }
};