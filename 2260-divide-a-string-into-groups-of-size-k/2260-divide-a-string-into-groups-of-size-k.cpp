class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int i=0;
        vector<string> res;
        while(i<s.size()){
            int a=i+k;
            string str="";
            while(i<a && i<s.size()){
                str.push_back(s[i]);
                i++;
            }
            while(str.size()<k){
                str.push_back(fill);
            }
            res.push_back(str);
        }
        return res;
    }
};