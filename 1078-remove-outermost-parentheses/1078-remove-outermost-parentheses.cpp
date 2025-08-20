class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0,tot=0;
        string res;
        vector<string> vec;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
                tot++;
            }
            else {
                tot++;
                if(cnt==1){
                    int diff=i-tot+2;
                    vec.push_back(s.substr(diff,tot-2));
                    tot=0;
                }
                cnt--;
            }
        }
        for(auto i:vec){
            for(auto j:i) res.push_back(j);
        }
        return res;
    }
};