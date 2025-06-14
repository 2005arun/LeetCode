class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> nums;
        int n=num;
        while(n!=0){
            nums.push_back(n%10);
            n/=10;
        }
        int i;
        reverse(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++){
            if(nums[i]!=9) break;
        }
        int a;
        if(i<nums.size()) a=nums[i];
        int maxm=0,minim=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a) maxm=maxm*10+9;
            else maxm=maxm*10+nums[i];
        }
        cout<<maxm<<" ";
        a=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a) minim=minim*10+0;
            else minim=minim*10+nums[i];
        }
        // cout<<maxm<<" "<<minim;
        return maxm-minim;
    }
};