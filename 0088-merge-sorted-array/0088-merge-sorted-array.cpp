class Solution {
public:
    // void swapr(vector<int>& nums1, vector<int>& nums2,int ind1,int ind2){
    //     if(nums1[ind1]>nums2[ind2]){
    //         swap(nums1[ind1],nums2[ind2]);
    //     }
    // }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int> res;
        // int l=0,r=0,v=0;
        // for(int i=0;i<m;i++){
        //     res.push_back(nums1[i]);
        // }
        // for(int i=0;i<n;i++){
        //     res.push_back(nums2[i]);
        // }
        // sort(res.begin(),res.end());
        // nums1=res;
        
        // int l=0,r=0;
        // while(l<m && r<n){
        //     if(nums1[l]<=nums2[r]){
        //         res.push_back(nums1[l]);
        //         l++;
        //     }
        //     else {
        //         res.push_back(nums2[r]);
        //         r++;
        //     }
        // }
        // while(l<m){
        //     res.push_back(nums1[l]);
        //     l++;
        // }
        // while(r<n){
        //     res.push_back(nums2[r]);
        //     r++;
        // }
        // nums1=res;
        // int l=m-1,r=0;
        // while(l>=0 && r<n){
        //     if(nums1[l]>nums2[r]){
        //         swap(nums1[l],nums2[r]);
        //         l--,r++;
        //     } 
        //     else{
        //         break;
        //     }
        // }
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        
        if (n == 0) return;

        int len = m + n;
        int gap = (len / 2) + (len % 2);
        while (gap > 0) {
            int l = 0, r = gap;

            while (r < len) {
                if (l < m && r < m) {
                    if (nums1[l] > nums1[r]) {
                        swap(nums1[l], nums1[r]);
                    }
                }
                else if (l < m && r >= m) {
                    if (nums1[l] > nums2[r - m]) {
                        swap(nums1[l], nums2[r - m]);
                    }
                }
                else {
                    if (nums2[l - m] > nums2[r - m]) {
                        swap(nums2[l - m], nums2[r - m]);
                    }
                }
                l++;
                r++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};