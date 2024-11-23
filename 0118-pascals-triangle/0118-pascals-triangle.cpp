class Solution {
public:
    // int ncr(int n,int r){
    //     int ans=1;
    //     for(int i=0;i<r;i++){
    //         ans=ans*(n-i);
    //         ans=ans/(i+1);
    //     }
    //     return ans;
    // }
    vector<int> find(int r){
        vector<int> vec;
        int ans=1;
        vec.push_back(1);
        for(int i=1;i<r;i++){
            ans=ans*(r-i);
            ans=ans/i;
            vec.push_back(ans);
        }
        return vec;
    }
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> res;
        // for(int i=1;i<=numRows;i++){
        //     vector<int> vec;
        //     for(int j=1;j<=i;j++){
        //         vec.push_back(ncr(i-1,j-1));
        //     }
        //     res.push_back(vec);
        // }
        // return res;
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++){
            res.push_back(find(i));
        }
        return res;
    }
};