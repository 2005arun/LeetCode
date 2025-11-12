class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        int f=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                f=1;
                break;
            }
        }
        if(f==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=1) cnt++;
            }
            return cnt;
        }
        int mincnt=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            int cnt=0;
            vector<int> vec(nums.begin(),nums.end());
            f=0;
            for(int j=i;j<vec.size()-1;j++){
                vec[j+1]=__gcd(vec[j],vec[j+1]);
                if(vec[j+1]==1){
                    cnt++;
                    f=1;
                    break;
                }
                cnt++;
            }
            if(f==1) mincnt=min(mincnt,cnt);
            cout<<mincnt<<" ";
        }
        if(mincnt==nums.size()) return -1;
        return mincnt+nums.size()-1;
    }
};