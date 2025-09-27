class Solution {
public:
    double find_value(vector<int> &x1,vector<int> &x2,vector<int> &x3){
        int ansx=x1[0]*(x2[1]-x3[1]);
        int ansy=x2[0]*(x3[1]-x1[1]);
        int ansz=x3[0]*(x1[1]-x2[1]);
        int value=abs(ansx+ansy+ansz);
        double res=0.5*value;
        return res;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        // int maxx=0;
        // int minx=0;
        // for(auto i:points){
        //     maxx=max(maxx,i[0]);
        //     minx=max(minx,i[1]);
        // }
        // int ans=maxx*minx;
        // // cout<<ans;
        // return double(ans/2.0);

        double res=0;
        for(int i=0;i<points.size()-2;i++){
            for(int j=i+1;j<points.size()-1;j++){
                for(int k=j+1;k<points.size();k++){
                    double ans=find_value(points[i],points[j],points[k]);
                    res=max(ans,res);
                }
            }
        }
        return res;
    }
};