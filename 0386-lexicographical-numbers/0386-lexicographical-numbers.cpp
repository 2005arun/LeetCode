class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vec;
        vector<int> ve;
        for(int i=1;i<=n;i++){
            vec.push_back(to_string(i));
        }
        sort(vec.begin(),vec.end());
        for(auto it:vec){
            ve.push_back(stoi(it));
        }
        return ve;
    }
};