class Solution {
public:
    // void lpsarray(vector<int> &lps,string pat){
    //     int length=0;
    //     int i=1;
    //     lps[0]=0;
    //     while(i<pat.size()){
    //         if(pat[length]==pat[i]){
    //             length++;
    //             lps[i]=length;
    //             i++;
    //         }
    //         else{
    //             if(length==0){
    //                 lps[i]=0;
    //                 i++;
    //             }
    //             else{
    //                 length=lps[length-1];
    //             }
    //         }
    //     }
    // }
    // bool kmp(string pat,string txt){
    //     vector<int> lps(pat.size());
    //     lpsarray(lps,pat);
    //     int i=0,j=0;
    //     while(i<txt.size()){
    //         if(txt[i]==pat[j]){
    //             i++,j++;
    //         }
    //         if(j==pat.size()){
    //             return true;
    //         }
    //         else if(i<txt.size() && pat[j]!=txt[i]){
    //             if(j!=0){
    //                 j=lps[j-1];
    //             }
    //             else{
    //                 i++;
    //             }
    //         }
    //     }
    //     return false;
    // }
    vector<string> stringMatching(vector<string>& words) {
        set<string> res;
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        // for(int i=0;i<words.size()-1;i++){
        //     for(int j=i+1;j<words.size();j++){
        //         if(kmp(words[i],words[j])){
        //             res.insert(words[i]);
        //         }
        //     }
        // }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[j].find(words[i])!=string::npos){
                    res.insert(words[i]);
                }
            }
        }
        vector<string> result(res.begin(),res.end());
        return result;
    }
};