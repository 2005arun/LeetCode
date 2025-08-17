// class Solution {
// public:
//     // unordered_map<string,int> dp;
//     vector<int> dp;
//     vector<vector<int>> pal;
//     int recur(int ind,string s){
//         if(ind==s.size()) return 0;
//         int minim=INT_MAX;
//         // if(dp.find(str)!=0) return dp[str];
//         if(dp[ind]!=-1) return dp[ind];
//         for(int i=ind;i<s.size();i++){
//             int l=ind,r=i;
//             // bool palin=true;
//             // while(l<=r){
//             //     if(s[l]!=s[r]){
//             //         palin=false;
//             //         break;
//             //     }
//             //     l++,r--;
//             // }
//             if(pal[l][r]){
//                 int tot=1+recur(i+1,s);
//                 minim=min(minim,tot);
//             }
//         }
//         // return dp[str]=minim;
//         return dp[ind]=minim;
//     }
//     int minCut(string s) {
//         // int l=0,r=s.size()-1;
//         // int f=0;
//         // while(l<=r){
//         //     if(s[l]!=s[r]){
//         //         f=1;
//         //         break;
//         //     }
//         //     l++,r--;
//         // }
//         // if(f==0) return 0;

//         // l=0,r=s.size()-2;
//         // f=0;
//         // while(l<=r){
//         //     if(s[l]!=s[r]){
//         //         f=1;
//         //         break;
//         //     }
//         //     l++,r--;
//         // }
//         // if(f==0) return 1;

//         dp.assign(s.size(),-1);
//         pal.assign(s.size(),vector<int>(s.size(),0));
//         for(int i=0;i<s.size();i++) pal[i][i]=1;
//         for(int len=2;len<=s.size();len++){
//             for(int i=0;i+len-1<s.size();i++){
//                 int j=i+len-1;
//                 if(s[i]==s[j]){
//                     if(len==2) pal[i][j]=1;
//                     else pal[i][j]=pal[i+1][j-1];
//                 }
//             }
//         }
//         return recur(0,s)-1;


//     }
// };


class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            dp[i] = i; // worst case: cut before every char
        }

        for (int center = 0; center < n; center++) {
            // Odd length palindrome
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (l == 0) dp[r] = 0;
                else dp[r] = min(dp[r], dp[l-1] + 1);
                l--, r++;
            }

            // Even length palindrome
            l = center, r = center+1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (l == 0) dp[r] = 0;
                else dp[r] = min(dp[r], dp[l-1] + 1);
                l--, r++;
            }
        }

        return dp[n-1];
    }
};
