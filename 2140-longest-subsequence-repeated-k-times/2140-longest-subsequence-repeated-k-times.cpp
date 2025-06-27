class Solution {
public:
    bool isexits(string &temp,string s,int k){
        string check="";
        while(k--){
            check+=temp;
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==check[j]){
                j++;
            }
            if(j==check.size()) break;
        }
        return j==check.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        q.push("");
        string ans="";
        while(!q.empty()){
            string it=q.front();
            q.pop();
            for(char ch='a';ch<='z';ch++){
                string temp=it+ch;
                if(isexits(temp,s,k)){
                    q.push(temp);
                    if(temp.size()>ans.size() || temp>ans){
                        ans=temp;
                    }
                }
            }
        }
        return ans;
    }
};