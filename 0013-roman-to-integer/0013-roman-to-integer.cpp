class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> hash={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int i=0;
        int sum=0;
        while(i<s.size()){
            if(i+1<s.size() && hash[s[i]]<hash[s[i+1]]){
                sum+=(hash[s[i+1]]-hash[s[i]]);
                i+=2;
            }
            else{
                sum+=hash[s[i]];
                i++;
            }
        }
        return sum;
    }
};