class Solution {
public:
    int deci(string s){
        int val=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                val+=(1<<i);
            }
        }
        return val;
    }
    int longestSubsequence(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') ans++;
        }
        string bin="";
        for(int i=s.size()-1;i>=0;i--){
            bin.push_back(s[i]);
            if(bin.size()>=32) break;
            if(s[i]=='1'){
                int dec=deci(bin);
                if(dec<=k){
                    ans++;
                }
                else break;
            }
        }
        return ans;
    }
};