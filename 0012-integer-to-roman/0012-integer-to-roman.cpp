class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> hash={
            {"I",1},{"IV",4},{"IX",9},{"V",5},{"X",10},{"XL",40},
            {"XC",90},{"L",50},{"C",100},{"CD",400},{"CM",900},
            {"D",500},{"M",1000}
        };
        sort(hash.begin(),hash.end(),[](const pair<string,int> &a,const pair<string,int> &b){
            return a.second>b.second;
        });
        string res="";
        for(int i=0;i<hash.size();i++){
            int div=num/hash[i].second;
            for(int j=0;j<div;j++) res+=hash[i].first;
            num%=hash[i].second;
        }
        return res;
    }
};