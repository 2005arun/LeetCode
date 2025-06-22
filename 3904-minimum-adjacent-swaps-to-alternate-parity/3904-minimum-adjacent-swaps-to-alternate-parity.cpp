class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> even, odd;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        }

        if (abs(static_cast<int>(even.size() - odd.size())) > 1) return -1;

        int res = INT_MAX;

        // Try starting with even if possible
        if (even.size() >= odd.size()) {
            int cost = 0;
            for (int i = 0; i < even.size(); i++) {
                int target = 2 * i;
                cost += abs(even[i] - target);
            }
            res = min(res, cost);
        }
        if (odd.size() >= even.size()) {
            int cost = 0;
            for (int i = 0; i < odd.size(); i++) {
                int target = 2 * i;
                cost += abs(odd[i] - target);
            }
            res = min(res, cost);
        }

        return res;
    }
};
