class Solution {
public:
    int ncr(int n,int r){
        int ans=1;
        for(int i=0;i<r;i++){
            ans=ans*(n-i);
            ans=ans/(i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++){
            vector<int> vec;
            for(int j=1;j<=i;j++){
                vec.push_back(ncr(i-1,j-1));
            }
            res.push_back(vec);
        }
        return res;
    }
};