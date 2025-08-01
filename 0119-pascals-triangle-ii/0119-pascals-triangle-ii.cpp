class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        long long ans=1;
        for(int i=0;i<rowIndex;i++){
            ans*=(rowIndex-i);
            ans/=i+1;
            res.push_back(ans);
        }
        return res;
    }
};