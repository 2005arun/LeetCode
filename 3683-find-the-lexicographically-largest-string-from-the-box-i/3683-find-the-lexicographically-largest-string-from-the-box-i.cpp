class Solution {
public:
    string answerString(string word, int numFriends) {
        string maxstr="";
        if(numFriends==1) return word;
        for(int i=0;i<word.size();i++){
            int len=word.size()-numFriends+1-i;
            // cout<<len;
            string str=word.substr(i,i+len);
            // cout<<str<<" ";
            if(str>maxstr) maxstr=str;
        }
        return maxstr;
    }
};