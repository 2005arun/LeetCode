class Solution {
public:
    string maximumBinaryString(string binary) {
        int zero=0,one=0;
        string ans="";
        int sone=0;
        for(int i=0;i<binary.size();i++){
            if(binary[i]=='1') sone++;
            else break;
        }
        for(int i=0;i<sone;i++) ans+='1';
        for(int i=sone;i<binary.size();i++){
            if(binary[i]=='0') zero++;
            else one++;
        }
        for(int i=1;i<zero;i++){
            ans+='1';
        }
        if(zero>0) ans+='0';
        for(int i=0;i<one;i++){
            ans+='1';
        }
        return ans;
    }
};