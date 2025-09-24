class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<long long,int> hash;
        if(numerator==0) return "0";
        string ans="";
        if(numerator<0 && denominator>=0) ans+='-';
        else if(denominator<0 && numerator>=0) ans+='-';
        long long num=llabs((long long)numerator);
        long long den=llabs((long long)denominator);
        long long a=num/den;
        cout<<a<<" ";
        ans+=to_string(a);
        long long rem=num%den;
        if(rem==0) return ans;
        ans+=".";
        while(rem!=0){
            if(hash.find(rem)!=hash.end()){
                ans.insert(hash[rem],1,'(');
                ans+=')';
                return ans;
            }
            hash[rem]=ans.size();
            rem*=10;
            ans+=to_string(rem/den);
            rem%=den;
        }
        return ans;
    }
}; 