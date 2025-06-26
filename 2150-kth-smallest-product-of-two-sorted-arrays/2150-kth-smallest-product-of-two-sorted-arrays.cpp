#define ll long long
class Solution {
public:
    bool ischeck(ll mid,vector<int>& nums1, vector<int>& nums2, ll k){
        ll cnt=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>0){
                ll l=0,r=nums2.size()-1;
                while(l<=r){
                    ll m=l+(r-l)/2;
                    if((ll)nums1[i]*nums2[m] <= mid){
                        l=m+1;
                    }
                    else r=m-1;
                }
                cnt+=l;
            }
            else if(nums1[i]<0){
                ll l=0,r=nums2.size()-1;
                while(l<=r){
                    ll m=l+(r-l)/2;
                    if((ll)nums1[i]*nums2[m] > mid){
                        l=m+1;
                    }
                    else r=m-1;
                }
                cnt+=nums2.size()-l;
                // ll l=-1,r=nums2.size();
                // while(l+1<r){
                //     ll m=l+(r-l)/2;
                //     if((ll)nums1[i]*nums2[m] > mid){
                //         l=m;
                //     }
                //     else r=m;
                // }
                // cnt+=nums2.size()-r;
            }
            else{
                if(0<=mid){
                    cnt+=nums2.size();
                }
            }
        }
        return cnt>=k;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll left=-1e10,right=1e10;
        while(left<=right){
            ll mid=left+(right-left)/2;
            if(ischeck(mid,nums1,nums2,k)){
                right=mid-1;
            }
            else left=mid+1;
        }
        return left;
    }
};