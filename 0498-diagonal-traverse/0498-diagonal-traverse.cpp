class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int cnt=1;
        for(int c=0;c<mat[0].size();c++){
            int j=c,i=0;
            vector<int> vec;
            while(i<mat.size() && j>=0){
                vec.push_back(mat[i][j]);
                i++,j--;
            }
            if(cnt%2!=0) reverse(vec.begin(),vec.end());
            cnt++;
            res.insert(res.end(),vec.begin(),vec.end());
        }
        for(int r=1;r<mat.size();r++){
            int i=r,j=mat[0].size()-1;
            vector<int> vec;
            while(i<mat.size() && j>=0){
                vec.push_back(mat[i][j]);
                i++,j--;
            }
            if(cnt%2!=0) reverse(vec.begin(),vec.end());
            cnt++;
            res.insert(res.end(),vec.begin(),vec.end());
        }
        return res;
    }
};