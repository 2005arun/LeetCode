class Solution {
public:
    int mod=1e9+7;
    int numSub(string s) {
        int r=0;
        int tot=0;
        while(r<s.size()){
            if(s[r]=='1'){
                int cnt=0;
                while(r<s.size()){
                    if(s[r]=='0'){
                        break;
                    }
                    cnt++;
                    tot+=(cnt%mod);
                    tot%=mod;
                    r++;
                }
            }
            r++;
        }
        return tot%mod;
    }
};