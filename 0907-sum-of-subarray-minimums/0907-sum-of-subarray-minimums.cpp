class Solution {
public:
    vector<int> NSE(vector<int> &nse,vector<int> arr){
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            nse[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> PSE(vector<int> &pse,vector<int> arr){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=(int)(1e9+7);
        vector<int> nse(arr.size());
        NSE(nse,arr);
        vector<int> pse(arr.size());
        PSE(pse,arr);
        int total=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total=(total+(left*right*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};