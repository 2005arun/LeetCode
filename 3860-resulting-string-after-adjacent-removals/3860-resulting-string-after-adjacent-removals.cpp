class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for(char ch:s){
            if(st.empty()) st.push(ch);
            else{
                int c=st.top();
                if(c=='a'){
                    if(ch=='z' || ch=='b') st.pop();
                    else st.push(ch);
                }
                else if(c=='z'){
                    if(ch=='y' || ch=='a') st.pop();
                    else st.push(ch);
                }
                else if(char(c+1) == ch || char(c-1)==ch) st.pop();
                else{
                    // cout<<ch<<" ";
                    st.push(ch);
                }
            }
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};