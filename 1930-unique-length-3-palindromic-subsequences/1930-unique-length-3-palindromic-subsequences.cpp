class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>prefix(26,-1);
        vector<int> suffix(26,-1);
        for(int i=0;i<s.size();i++){
            if(suffix[s[i]-'a']==-1) suffix[s[i]-'a']=i;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(prefix[s[i]-'a']==-1) prefix[s[i]-'a']=i;
        }
        int res=0;
        for(int i=0;i<26;i++){
            int str=suffix[i];
            int end=prefix[i];
            if(str==-1) continue;
            set<char> st;
            str++;
            while(str<end){
                st.insert(s[str]);
                str++;
            }
            res+=st.size();
        }
        return res;
    }
};