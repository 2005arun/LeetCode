class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        if(n==1) return true;
        vector<int> vec;
        for(int i=0;i<str.size();i++){
            vec.push_back(str[i]-'0');
        }
        sort(vec.begin(),vec.end());
        // for(auto i:vec) cout<<i<<' ';
        do{
            int tot=0;
            for(int i=0;i<vec.size();i++){
                tot*=10;
                tot+=vec[i];
            }
            // cout<<tot<<" ";
            if(tot>1 && (tot&(tot-1))==0) return true;
        }while(next_permutation(vec.begin(),vec.end()));

        return false;
    }
};