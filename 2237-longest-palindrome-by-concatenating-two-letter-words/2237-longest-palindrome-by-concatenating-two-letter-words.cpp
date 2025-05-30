class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // unordered_map<string,int> hash;
        // int res=0;
        // bool found=false;
        // for(auto i:words){
        //     string str=i;
        //     reverse(i.begin(),i.end());
        //     if(hash.find(i)!=hash.end()){
        //         res+=4;
        //         hash[i]--;
        //         hash.erase(i);
        //     }
        //     else {
        //         hash[str]++;
        //     }
        // }
        // for(auto it:hash){
        //     if(it.second==1 && it.first[0]==it.first[1]){
        //         res+=2;
        //         break;
        //     }
        // }
        // return res;
        int grid[26][26];
        int res=0,cnt=0;
        memset(grid,0,sizeof(grid));
        for(auto i:words){
            int a=i[0]-'a';
            int b=i[1]-'a';
            if(grid[b][a]>0){
                res+=4;
                grid[b][a]--;
                if(a==b) cnt--;
            }
            else{
                grid[a][b]++;
                if(a==b) cnt++;
            }
        }
        if(cnt>0) res+=2;
        return res;
    }
};