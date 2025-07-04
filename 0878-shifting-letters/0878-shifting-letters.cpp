// #define int long long
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long> vec;
        long long j=s.size()-1;
        long long sum=0;
        while(j>=0){
            long long a=s[j]-'a';
            cout<<a<<" ";
            sum+=shifts[j];
            if(a+sum >= 26){
                a+=sum;
                vec.push_back(a%26);
            }
            else vec.push_back(a+sum);
            j--;
        }
        reverse(vec.begin(),vec.end());
        string str="";
        for(int i=0;i<vec.size();i++){
            str.push_back(vec[i]+'a');
        }
        return str;
    }
};