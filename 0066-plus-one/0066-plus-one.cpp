class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // long long a;
        // for(int i=0;i<digits.size();i++){
        //     a=a*10+digits[i];
        // }
        // int res=a+1;
        // vector<int> v;
        // while(res!=0){
        //     v.push_back(res%10);
        //     res/=10;
        // }
        // reverse(v.begin(),v.end());
        // return v;
        vector<int> vec;
        int f=0;
        if(digits[digits.size()-1]==9){
            vec.push_back(0);
            for(int i=digits.size()-2;i>=0;i--){
                if(f==0 && digits[i]==9) vec.push_back(0);
                else if(f==0){
                    vec.push_back(digits[i]+1);
                    f=1;
                }
                else vec.push_back(digits[i]);
            }
            if(f==0) vec.push_back(1);
        }
        else{
            for(int i=digits.size()-1;i>=0;i--){
                if(i==digits.size()-1) vec.push_back(digits[i]+1);
                else vec.push_back(digits[i]);
            }
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};