class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U') return true;
        return false;
    }
    string sortVowels(string s) {
        vector<int> vec;
        vector<char> st;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                vec.push_back(i);
                st.push_back(s[i]);
            }
        }
        sort(st.begin(),st.end());
        int j=0;
        for(auto i:vec){
            s[i]=st[j];
            j++;
        }
        return s;
    }
};