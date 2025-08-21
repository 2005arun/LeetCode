class Solution {
public:
    int hist(vector<int> &arr){
        stack<int> st;
        vector<int> pse(arr.size()),nse(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        // while(!st.empty()) st.pop();
        // for(int i=arr.size()-1;i>=0;i--){
        //     while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        //     if(st.empty()) nse[i]=arr.size();
        //     else nse[i]=st.top();
        //     st.push(i);
        // }
        // for(auto i:nse) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:pse) cout<<i<<" ";
        // cout<<endl;
        vector<int> dp(arr.size());
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) {
                dp[i]=0;
                continue;
            }
            int diff=i-pse[i];
            int val=(diff*arr[i]);
            if(pse[i]>=0) val+=dp[pse[i]];
            dp[i]=val;
        }
        int tot=accumulate(dp.begin(),dp.end(),0);
        cout<<tot<<" ";
        return tot;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int sum=0;
        vector<vector<int>> prefix(mat.size(),vector<int> (mat[0].size()));
        for(int i=0;i<mat[0].size();i++){
            prefix[0][i]=mat[0][i];
        }
        for(int i=1;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    prefix[i][j]=0;
                    continue;
                }
                prefix[i][j]=prefix[i-1][j]+mat[i][j];
            }
        }
        for(int i=0;i<mat.size();i++){
            sum+=hist(prefix[i]);
        }
        return sum;
    }
};