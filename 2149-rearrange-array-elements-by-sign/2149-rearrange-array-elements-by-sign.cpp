class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int>p;
        // vector<int> n;
        // for(auto i:nums){
        //     if(i<0) n.push_back(i);
        //     else p.push_back(i);
        // }
        // vector<int> res;
        // int l=0,r=0;
        // while(l<p.size() && r<n.size()){
        //     res.push_back(p[l]);
        //     res.push_back(n[r]);
        //     l++;
        //     r++;
        // }
        // while(l<p.size()){
        //     res.push_back(p[l]);
        //     l++;
        // }
        // while(r<n.size()){
        //     res.push_back(n[r]);
        //     r++;
        // }
        // return res;
        vector<int> vec(nums.size());
        int p=0,n=1;
        for(auto i:nums){
            if(i>0){
                vec[p]=i;
                p+=2;
            }
            else{
                vec[n]=i;
                n+=2;
            }
        }
        return vec;
    }
};