class Solution {
public:
    bool compare(string str1,string str2){
        if(str1.size()!=str2.size()+1) return false;
        // cout<<str1<<" "<<str2<<endl;
        int l=0,r=0;
        while(l<str1.size()){
            if(str1[l]==str2[r]){
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        if(l==str1.size() && r==str2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        int res=1;
        sort(words.begin(),words.end(),[](const string &str1,const string &str2){
            return str1.size()<str2.size();
        });
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    res=max(res,dp[i]);
                }
            }
        }
        return res;
    }
};