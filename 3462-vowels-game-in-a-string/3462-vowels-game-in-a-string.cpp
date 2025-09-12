class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    bool doesAliceWin(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])==true) {
                cnt++;
            }
        }
        if(cnt==0) return false;
        return true;
    }
};