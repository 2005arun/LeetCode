class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxm=-1;
        int ind=-1;
        for(int i=0;i<dimensions.size();i++){
            double res=sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
            // cout<<res<<" ";
            if(res>maxm){
                ind=i;
                maxm=res;
            }
            if(res==maxm){
                if(dimensions[i][0]*dimensions[i][1]>dimensions[ind][0]*dimensions[ind][1]){
                    ind=i;
                }
            }
        }
        return dimensions[ind][0]*dimensions[ind][1];
    }
};