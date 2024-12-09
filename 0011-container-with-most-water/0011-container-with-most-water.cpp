class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int total=0;
        while(l<r){
            if(height[l]<height[r]){
                total=max(total,(min(height[l],height[r])*(r-l)));
                l+=1;
            }
            else{
                total=max(total,(min(height[l],height[r])*(r-l)));
                r-=1;
            }
        }
        return total;
    }
};