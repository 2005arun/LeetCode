class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int l=0,r=0,v=0;
        for(int i=0;i<m;i++){
            res.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            res.push_back(nums2[i]);
        }
        sort(res.begin(),res.end());
        nums1=res;
    }
};