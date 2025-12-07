// #define int long long;
class Solution {
public:
    bool ispalin(int num){
        string str=bitset<32> (num).to_string();
        string res=str.substr(str.find('1'));
        string re1=res;
        reverse(res.begin(),res.end());
        return re1==res;
    }
    vector<int> minOperations(vector<int>& nums) {
        // vector<int> output;
        // for(int i=0;i<nums.size();i++){
        //     int cnt=0;
        //     string str=bitset<32> (nums[i]).to_string();
        //     string res=str.substr(str.find('1'));
        //     cout<<res<<" ";
        //     int l=0,r=res.size()-1;
        //     while(l<=r){
        //         if(res[l]!=res[r]){
        //             int rr=1<<r;
        //             int ll=1<<l;
        //             // cout<<rr<<" "<<ll<<" ";
        //             int first,second;
        //             if(res[r]=='0'){
        //                 // cout<<cnt<<" ";
        //                 first=cnt+ll;
        //                 second=cnt-rr;
        //                 cout<<i<<first<<" "<<second<<" ";
        //             }
        //             else{
        //                 first=cnt-ll;
        //                 second=cnt+rr;
        //                 // cout<<i<<first<<" "<<second<<" ";
        //             }
        //             cnt=min(abs(first),abs(second));
        //             // cout<<i<<cnt<<" ";
        //         }
        //         l++,r--;
        //     }
        //     output.push_back(abs(cnt));
        // }
        
        // int v=3664+23;
        // string str=bitset<32> (v).to_string();
        // string res=str.substr(str.find('1'));
        // cout<<res<<" ";
        // // v=3521-38;
        // // str=bitset<32> (v).to_string();
        // // res=str.substr(str.find('1'));
        // // cout<<res;
        // return output;

        vector<int> vec;
        for(int i=1;i<=5000;i++){
            if(ispalin(i)){
                vec.push_back(i);
            }
        }
        vector<int> out;
        for(auto i:nums){
            int cnt=500;
            auto val=upper_bound(vec.begin(),vec.end(),i);
            if(val!=vec.end()){
                cnt=*val-i;
            }
            if(val!=vec.begin()) {
                cnt=min(cnt,i-*prev(val));
            }
            out.push_back(cnt);
        }
        return out;
    }
};