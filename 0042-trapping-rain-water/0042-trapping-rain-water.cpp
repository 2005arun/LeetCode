class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // // vector<int> premax(n);
        // // premax[0]=height[0];
        // // for(int i=1;i<n;i++){
        // //     premax[i]=max(premax[i-1],height[i]);
        // // }
        // vector<int> sufmax(n);
        // sufmax[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     sufmax[i]=max(sufmax[i+1],height[i]);
        // }
        // int total=0;
        // int pre=0;
        // for(int i=0;i<n;i++){
        //     pre=max(pre,height[i]);
        //     total+=min(pre,sufmax[i])-height[i];
        // }
        // return total;
        int l=0,r=n-1;
        int total=0;
        int leftmax=height[l],rightmax=height[r];
        while(l<r){
            if(leftmax<rightmax){
                l+=1;
                leftmax=max(leftmax,height[l]);
                total+=leftmax-height[l];
            }
            else{
                r-=1;
                rightmax=max(rightmax,height[r]);
                total+=rightmax-height[r];
            }
        }
        return total;
    }
};