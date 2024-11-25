class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // long long res=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     long long product=1;
        //     for(int j=i;j<nums.size();j++){
        //         product*=nums[j];
        //         res=std::max(res,product);
        //     }
        // }
        // return res;
        double long suf=1,pre=1,maxim=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pre==0){
                pre=1;
            }
            if(suf==0){
                suf=1;
            }
            pre*=nums[i];
            suf*=nums[n-i-1];
            maxim=std::max(maxim,std::max(pre,suf));
        }
        return maxim;
        // if (nums.empty()) return 0;

        // long long max = nums[0], min = nums[0];
        // long long res = nums[0];

        // for (int i = 1; i < nums.size(); ++i) {
        //     long long tmp = max;
        //     max = std::max({(long long)nums[i], max * nums[i], min * nums[i]});
        //     min = std::min({(long long)nums[i], tmp * nums[i], min * nums[i]});
        //     res = std::max(res, max);
        // }

        // return (int)res;
        // if (nums.empty()) return 0;

        // double long maxi = LLONG_MIN; // Use long long to handle large products
        // double long prod = 1;
        // for (int i = 0; i < nums.size(); i++) {
        //     prod *= nums[i];
        //     maxi = max(prod, maxi);
        //     if (prod == 0) {
        //         prod = 1;
        //     }
        // }

        // prod = 1;
        // for (int i = nums.size() - 1; i >= 0; i--) {
        //     prod *= nums[i];
        //     maxi = max(prod, maxi);
        //     if (prod == 0) {
        //         prod = 1;
        //     }
        // }

        // return (int)maxi;
    }
};


