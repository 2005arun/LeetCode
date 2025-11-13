class Solution {
public:
    int maxOperations(string s) {
        int cnt=0;
        int c=0;
        int tot=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                tot+=cnt;
                c=cnt;
            }
            else{
                cnt=c+1;
            }
        }
        return tot;
    }
};