class Solution {
public:
    bool isprime(int n){
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
    
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(auto &i:hash){
            if(isprime(i.second)) return true;
        }
        return false;
    }
};