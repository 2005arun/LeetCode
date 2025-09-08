class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> vec;
        if(n%2==0){
            int a=n/2;
            for(int i=a;i>0;i--){
                vec.push_back(-i);
            }
            for(int i=1;i<=a;i++){
                vec.push_back(i);
            }
        }
        else{
            int a=n/2;
            for(int i=1;i<=a;i++){
                vec.push_back(i);
            }
            vec.push_back(0);
            for(int i=1;i<=a;i++){
                vec.push_back(-i);
            }
        }
        return vec;
    }
};