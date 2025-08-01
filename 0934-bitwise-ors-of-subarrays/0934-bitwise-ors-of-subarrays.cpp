class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> st;
        set<int> prev;
        st.insert(arr[0]);
        prev.insert(arr[0]);
        for(int i=1;i<arr.size();i++){
            set<int> cur;
            cur.insert(arr[i]);
            for(auto j:prev){
                cur.insert(arr[i]|j);
            }
            prev=cur;
            st.insert(cur.begin(),cur.end());
        }
        return st.size();
    }
};