class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int l=0,r=k-1;
        // vector<int>res;
        // while(r<nums.size()){
        //     int maxm=INT_MIN;
        //     for(int i=l;i<r+1;i++){
        //         maxm=std::max(maxm,nums[i]);
        //     }
        //     res.push_back(maxm);
        //     l++,r++;
        // }
        // return res;
        deque<int> dq;
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<=(i-k)) dq.pop_front();
            while(!dq.empty() && nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) vec.push_back(nums[dq.front()]);
        }
        return vec;

        for(int i=0;i,nums.size();i++){
            
        }
    }
};