class Solution {
public:
    bool isvowel(char ch){
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U') return true;
        return false;
    }
    bool isValid(string word) {
        bool vowel=false,cons=false;
        if(word.size()<3) return false;
        for(int i=0;i<word.size();i++){
            if(isvowel(word[i])) vowel=true;
            else if(word[i]>='a' && word[i]<='z' || word[i]>='A' && word[i]<='Z') cons=true;
            else if(word[i]>='0' && word[i]<='9') continue;
            else return false;
        } 
        return vowel && cons;
    }
};