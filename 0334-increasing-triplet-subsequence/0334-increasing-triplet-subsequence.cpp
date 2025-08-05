class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // for(int i=1;i<nums.size();i++){
        //     if(temp.size()==3) return true;
        //     if(temp.back()<nums[i]) temp.push_back(nums[i]);
        //     else{
        //         int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
        //         temp[ind]=nums[i];
        //     }
        // }
        // if(temp.size()==3) return true;
        // return false;

        int f=INT_MIN,s=INT_MIN,t=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(f!=INT_MIN && s!=INT_MIN && t!=INT_MIN) return true;
            if(f==INT_MIN) f=nums[i];
            else if(s==INT_MIN){
                if(f<nums[i]) s=nums[i];
                else f=nums[i];
            }
            else if(t==INT_MIN){
                if(f<nums[i] && s<nums[i]) t=nums[i];
                else if(f<nums[i] && s>nums[i]) s=nums[i];
                else if(f>nums[i]) f=nums[i];
            }
        }
        if(f!=INT_MIN && s!=INT_MIN && t!=INT_MIN) return true;
        return false;
    }
};