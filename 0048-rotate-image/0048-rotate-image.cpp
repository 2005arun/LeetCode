class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> vec(matrix.size(),vector<int>(matrix[0].size()));
        int x=0;
        for(int j=0;j<matrix[0].size();j++){
            int y=0;
            for(int i=matrix.size()-1;i>=0;i--){
                vec[x][y]=matrix[i][j];
                y++;
            }
            x++;
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i][j]=vec[i][j];
            }
        }
    }
};