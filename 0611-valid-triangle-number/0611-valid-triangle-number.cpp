class Solution {
public:
    int recur(vector<int> &vec,int n){
        int l=0,r=1;
        int cnt=0;
        while(l<n-2){
            r=l+1;
            while(r<n-1){
                int ans=vec[l]+vec[r]-1;
                int ind=upper_bound(vec.begin(),vec.end(),ans)-vec.begin();
                // cout<<ind<<" ";
                cnt+=(ind-r-1);
                cout<<cnt<<" ";
                r++;
            }
            l++;
        }
        return cnt;
    }
    int triangleNumber(vector<int>& nums) {
        // vector<int> vec;
        // for(auto i:nums){
        //     if(i==0) continue;
        //     vec.push_back(i);
        // }
        // if(vec.size()<3) return 0;
        sort(nums.begin(),nums.end());
        // int ans=recur(vec,vec.size());
        int cnt=0;
        for(int k=nums.size()-1;k>=2;k--){
            int l=0,r=k-1;
            while(l<r){
                if(nums[l]+nums[r] > nums[k]){
                    cnt+=(r-l);
                    r--;
                }
                else l++;
            }
        }
        return cnt;
    }
};