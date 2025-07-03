class Solution {
public:
    void cfor(string &w,string s,int i){
        if(i==s.size()) return ;
        w.push_back(s[i]+1);
        cfor(w,s,i+1);
    }
    void recur(string &s,int k){
        if(s.size()>=k){
            return ;
        }
        string word="";
        cfor(word,s,0);
        // for(int i=0;i<s.size();i++){
        //     word.push_back(s[i]+1);
        // }
        s+=word;
        recur(s,k);
    }
    char kthCharacter(int k) {
        string str="a";
        recur(str,k);
        return str[k-1];
    }
};