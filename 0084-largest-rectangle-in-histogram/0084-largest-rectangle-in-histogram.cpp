class Solution {
public:
    // void pse(vector<int> heights,vector<int> &PSE){
    //     stack<int> st;
    //     for(int i=0;i<heights.size();i++){
    //         while(!st.empty() && heights[i]<heights[st.top()]) st.pop();
    //         PSE[i]=st.empty()?-1:st.top();
    //         st.push(i);
    //     }
    // }
    // void nse(vector<int> heights,vector<int> &NSE){
    //     stack<int> st;
    //     for(int i=heights.size()-1;i>=0;i--){
    //         while(!st.empty() && heights[i]<=heights[st.top()]) st.pop();
    //         NSE[i]=st.empty()?heights.size():st.top();
    //         st.push(i);
    //     }
    // }
    int largestRectangleArea(vector<int>& heights) {
        // vector<int> NSE(heights.size());
        // vector<int> PSE(heights.size());
        // int maxm=INT_MIN;
        // nse(heights,NSE);
        // pse(heights,PSE);
        // for(int i=0;i<heights.size();i++){
        //     maxm=max(maxm,(heights[i]*(NSE[i]-PSE[i]-1)));
        // }
        // return maxm;
        stack<int> st;
        int maxm=INT_MIN;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxm=max(maxm,(heights[ele]*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=st.top();
            st.pop();
            int nse=heights.size();
            int pse=st.empty()?-1:st.top();
            maxm=max(maxm,(heights[ele]*(nse-pse-1)));
        }
        return maxm;
    }
};