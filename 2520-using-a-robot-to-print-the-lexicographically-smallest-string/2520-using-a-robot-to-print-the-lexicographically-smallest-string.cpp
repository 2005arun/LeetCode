class Solution {
public:
    string robotWithString(string s) {
        string p="";
        int n=s.size();
        stack<char> st;
        unordered_map<char,int> hash;
        char mn='a';
        for(int i=0;i<n;i++) hash[s[i]]++;
        for(int i=0;i<n;i++){
            hash[s[i]]--;
            st.push(s[i]);
            while(mn!='z' && hash[mn]==0){
                mn++;
            }
            while(!st.empty() && st.top()<=mn){
                p.push_back(st.top());
                st.pop();
            }
        }
        return p;
    }
};