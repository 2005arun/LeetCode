class Solution {
public:
    int maxDepth(string s) {
        int maxm=0;
        int cnt=0;
        for(auto i:s){
            // if(i>='0' && i<='9'){
            //     maxm=max(maxm,cnt);
            // }
            if(i=='(') cnt++;
            else if(i==')') cnt--;
            maxm=max(maxm,cnt);
        }
        // maxm=max(maxm,cnt);
        return maxm;
    }
};