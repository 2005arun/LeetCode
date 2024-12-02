class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums2.size(),-1);
        // for(int i=0;i<nums2.size();i++){
        //     for(int j=i+1;j<nums2.size();j++){
        //         if(nums2[j]>nums2[i]){
        //             arr[i]=nums2[j];
        //             break;
        //         } 
        //     }
        // }
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()) st.push(nums2[i]);
            else if(nums2[i]<st.top()){
                arr[i]=st.top();
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && nums2[i]>st.top()){
                    st.pop();
                }
                if(!st.empty()) arr[i]=st.top();
                st.push(nums2[i]);
            }
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(arr[j]);
                }
            }
        }
        return ans;
    }
};