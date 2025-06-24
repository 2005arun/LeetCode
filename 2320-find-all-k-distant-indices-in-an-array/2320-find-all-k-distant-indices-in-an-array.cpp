class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ind;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key) ind.push_back(i);
        }
        vector<int> vec;
        set<int> st;
        for(int i=0;i<ind.size();i++){
            int a=(ind[i]-k) <0?0:(ind[i]-k);
            int b=ind[i]+k;
            for(int j=a;j<=b && j<nums.size();j++) st.insert(j);
        }
        vec.insert(vec.end(),st.begin(),st.end());
        return vec;
    }
};