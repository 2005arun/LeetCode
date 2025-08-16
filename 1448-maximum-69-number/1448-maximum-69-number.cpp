class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        // int maxm=num;
        // for(int i=0;i<str.size();i++){
        //     if(str[i]=='9'){
        //         str[i]='6';
        //         int ans=stoi(str);
        //         maxm=max(ans,maxm);
        //         str[i]='9';
        //     }
        //     else{
        //         str[i]='9';
        //         int ans=stoi(str);
        //         maxm=max(maxm,ans);
        //         str[i]='6';
        //     }
        // }
        // return maxm;

        for(int i=0;i<str.size();i++){
            if(str[i]=='6'){
                str[i]='9';
                break;
            }
        }
        return stoi(str);
    }
};