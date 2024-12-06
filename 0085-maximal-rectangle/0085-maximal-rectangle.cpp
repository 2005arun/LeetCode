class Solution {
public:
    int his(vector<int> &arr){
        int maxm=0;
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int ele=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                int nse=i;
                maxm=max(maxm,(arr[ele]*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            int nse=arr.size();
            maxm=max(maxm,(arr[ele]*(nse-pse-1)));
        }
        return maxm;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> presum(matrix.size(),vector<int>(matrix[0].size()));
        for(int j=0;j<matrix[0].size();j++){
            int sum=0;
            for(int i=0;i<matrix.size();i++){
                sum+=1;
                if(matrix[i][j]=='0') sum=0;
                presum[i][j]=sum;
            }
        }
        int maxm=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            maxm=max(maxm,his(presum[i]));
        }
        return maxm;
    }
};