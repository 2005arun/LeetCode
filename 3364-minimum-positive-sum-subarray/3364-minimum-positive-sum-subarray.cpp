class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minsum = INT_MAX; 
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];  
                int subarray_length = j - i + 1;
                if (subarray_length >= l && subarray_length <= r) {
                    if (sum > 0) {
                        minsum = min(minsum, sum);  
                    }
                }
            }
        }
        return (minsum == INT_MAX) ? -1 : minsum;
    }
};