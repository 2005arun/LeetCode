class Solution {
public:
    vector<int> pse(vector<int> arr,vector<int> &PSE){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            PSE[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return PSE;
    }
    vector<int> nse(vector<int> arr,vector<int> &NSE){
        int n=arr.size();
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            NSE[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return NSE;
    }
    vector<int> pge(vector<int> arr,vector<int> &PGE){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]>=arr[st.top()]) st.pop();
            PGE[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return PGE;
    }
    vector<int> nge(vector<int> arr,vector<int> &NGE){
        int n=arr.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>arr[st.top()]) st.pop();
            NGE[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return NGE;
    }
    long long summax(vector<int> arr){
        vector<int> NGE(arr.size());
        vector<int> PGE(arr.size());
        nge(arr,NGE);
        pge(arr,PGE);
        long long total=0;
        for(int i=0;i<arr.size();i++){
            int left=i-PGE[i];
            int right=NGE[i]-i;
            total=total+(left*right*1LL*arr[i]);
        }
        return total;
    }
    long long summin(vector<int> arr){
        vector<int> NSE(arr.size());
        vector<int> PSE(arr.size());
        nse(arr,NSE);
        pse(arr,PSE);
        long long total=0;
        for(int i=0;i<arr.size();i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;
            total=total+(left*right*1LL*arr[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        // int r=0,l=0;
        // long long sum=0;
        // int minval=nums[0],maxval=nums[0];
        // while(l<nums.size()){
        //     minval=nums[l];
        //     maxval=nums[l];
        //     r=l;
        //     while(r<nums.size()){
        //         minval=std::min(minval,nums[r]);
        //         maxval=std::max(maxval,nums[r]);
        //         sum+=(maxval-minval);
        //         r++;
        //     }
        //     l++;
        // }
        // return sum;
        return summax(nums)-summin(nums);
    }
};