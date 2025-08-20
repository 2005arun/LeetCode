class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> vec(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            vec[i][0]=matrix[i][0];
        }
        for(int i=0;i<matrix[0].size();i++){
            vec[0][i]=matrix[0][i];
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0) {
                    vec[i][j]=0;
                    continue;
                }
                int minim=min({vec[i-1][j-1],vec[i-1][j],vec[i][j-1]});
                vec[i][j]=minim+1;
            }
        }
        int sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=vec[i][j];
            }
        }
        return sum;
    }
};