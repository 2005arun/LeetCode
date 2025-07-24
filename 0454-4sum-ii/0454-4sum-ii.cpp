class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         for(int k=0;k<nums3.size();k++){
        //             for(int l=0;l<nums4.size();l++){
        //                 if(nums1[i]+nums2[j]+nums3[k]+nums4[l]==0) cnt++;
        //             }
        //         }
        //     }
        // }
        // return cnt;
        unordered_map<int,int> hash;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                hash[sum]++;
            }
        }
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                int sum=nums3[i]+nums4[j];
                if(hash.find(-sum)!=hash.end()) cnt+=hash[-sum];
            }
        }
        return cnt;
    }
};