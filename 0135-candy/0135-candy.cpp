class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> vec1(ratings.size());
        vec1[0]=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                vec1[i]=vec1[i-1]+1;
            }
            else{
                vec1[i]=1;
            }
        }
        vector<int> vec2(ratings.size());
        vec2[ratings.size()-1]=1;
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                vec2[i]=vec2[i+1]+1;
            }
            else{
                vec2[i]=1;
            }
        }
        int total=0;
        for(int i=0;i<vec1.size();i++){
            total+=max(vec1[i],vec2[i]);
        }
        return total;
    }
};