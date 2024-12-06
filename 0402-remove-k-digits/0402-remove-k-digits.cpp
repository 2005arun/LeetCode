class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        if(num.size()==k) return "0";
        else if(num.size()==1 && k==0) return num;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && num[i]<st.back() && k>0){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while(k>0){
            st.pop_back();
            k--;
        }
        string s="";
        for(auto i:st){
            s+=i;
        }
        size_t one=s.find_first_not_of('0');
        if(one == string::npos) return "0";
        return s.substr(one);
    }
};