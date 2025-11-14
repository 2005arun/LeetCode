class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> vec(n,vector<int>(n,0));
        for(auto i:queries){
            int r1=i[0];
            int c1=i[1];
            int r2=i[2];
            int c2=i[3];
            for(int j=r1;j<=r2;j++){
                for(int k=c1;k<=c2;k++){
                    vec[j][k]+=1;
                }
            }
        }
        return vec;
    }
};