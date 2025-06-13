// class Solution {
// public:
//     void back(int open,int close,stack<char> &st,vector<string> res,int n){
//         if(open==n && close==n){
//             string s="";
//             while(!st.empty()){
//                 s+=st.top();
//                 st.pop();
//             }
//             res.push_back(s);
//         }
//         if(open<n){
//             st.push('(');
//             back(open+1,close,st,res,n);
//             st.pop();
//         }
//         if(close<n){
//             st.push(')');
//             back(open,close+1,st,res,n);
//             st.pop();
//         }
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         stack<char> st;
//         back(0,0,st,res,n);
//         return res;
//     }
// };
class Solution {
public:
    void back(int open, int close, string s, vector<string> &res, int n) {
        if (open == n && close == n) {
            res.push_back(s);
            return;
        }
        
        if (open < n) {
            back(open + 1, close, s + '(', res, n);
        }
        

        if (close < open) {
            back(open, close + 1, s + ')', res, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        back(0, 0, s, res, n);  
        return res;
    }
};
