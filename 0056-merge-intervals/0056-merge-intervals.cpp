class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        // for(int i=0;i<intervals.size();i++){
        //     int a=intervals[i][0];
        //     int b=intervals[i][1];
        //     if(!res.empty() && b<=res.back()[1]){
        //         continue;
        //     }
        //     for(int j=i+1;j<intervals.size();j++){
        //         if(intervals[j][0]<=b) b=max(b,intervals[j][1]);
        //         else break;
        //     }
        //     res.push_back({a,b});
        // }
        // return res;
        for(int i=0;i<intervals.size();i++){
            if(res.empty() || res.back()[1]<intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};