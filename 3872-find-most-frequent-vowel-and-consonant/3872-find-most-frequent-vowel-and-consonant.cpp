class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowel;
        unordered_map<char,int> cons;
        for(auto &i:s){
            if(i=='a' || i=='e' || i=='o' || i=='u' || i=='i'){
                vowel[i]++;
            }
            else{
                cons[i]++;
            }
        }
        int maxm=0;
        for(auto i:vowel){
            if(i.second>maxm){
                maxm=i.second;
            }
        }
        int maxmc=0;
        for(auto i:cons){
            if(i.second>maxmc) maxmc=i.second;
        }
        return maxm+maxmc;
    }
};