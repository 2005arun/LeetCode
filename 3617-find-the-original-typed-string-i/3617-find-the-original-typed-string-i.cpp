class Solution {
public:
    int possibleStringCount(string word) {
        int i=0;
        int cnt=1;
        while(i<word.size()){
            int f=0;
            char a=word[i];
            i++;
            while(i<word.size() && word[i]==a){
                cnt++;
                i++;
                f=1;
            }
        }
        return cnt;
    }
};