class Solution {
public:
    vector<int> vec;
    void recur(int i,int n){
        if(i>n) return;
        vec.push_back(i);
        for(int ind=0;ind<=9;ind++){
            if(i*10+ind >n) break;
            recur(i*10+ind,n);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        // vector<string> vec;
        // vector<int> ve;
        // for(int i=1;i<=n;i++){
        //     vec.push_back(to_string(i));
        // }
        // sort(vec.begin(),vec.end());
        // for(auto it:vec){
        //     ve.push_back(stoi(it));
        // }
        // return ve;
        for(int i=1;i<=9;i++){
            if(i>n) break;
            recur(i,n);
        }
        return vec;
    }
};