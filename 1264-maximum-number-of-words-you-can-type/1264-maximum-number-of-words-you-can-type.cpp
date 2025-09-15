class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st;
        for(auto i:brokenLetters) st.insert(i);
        int cnt=0;
        vector<string> vec;
        stringstream ss (text);
        string word;
        while(ss >> word){
            vec.push_back(word);
        }
        for(auto i:vec){
            int f=0;
            for(auto j:i){
                if(st.count(j)!=0){
                    f=1;
                    break;
                }
            }
            if(f==0) cnt++;
        }
        return cnt;
    }
};