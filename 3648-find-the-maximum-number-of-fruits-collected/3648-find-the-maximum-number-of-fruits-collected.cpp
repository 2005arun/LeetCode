class Solution {
public:
    // vector<vector<int>> vis;
    // vector<vector<int>> dp;
    // vector<vector<int>> dp2;
    // int recur(int i,int j,vector<vector<int>> &fruits,int level,int n){
    //     if(vis[i][j]==1 || i>=n || i<0 || j>=n || level>n-1) return 0;
    //     if(i==n-1 && j==n-1 && level==n-1) return fruits[i][j];
    //     if(dp2[i][j]!=-1) return dp2[i][j];
    //     int left=fruits[i][j]+recur(i-1,j+1,fruits,level+1,n);
    //     int dia=fruits[i][j]+recur(i,j+1,fruits,level+1,n);
    //     int right=fruits[i][j]+recur(i+1,j+1,fruits,level+1,n);
    //     return dp2[i][j]=max({left,dia,right}); 
    // }
    // int recur1(int i,int j,vector<vector<int>> &fruits,int level,int n){
    //     if(i==n-1 && j==n-1 && level==n-1) return fruits[i][j];
    //     if(i>=n || j>=n || level>n-1 || vis[i][j]==1) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int left=fruits[i][j]+recur1(i+1,j-1,fruits,level+1,n);
    //     int dia=fruits[i][j]+recur1(i+1,j,fruits,level+1,n);
    //     int right=fruits[i][j]+recur1(i+1,j+1,fruits,level+1,n);
    //     return dp[i][j]=max({left,dia,right}); 
    // }
    // int maxCollectedFruits(vector<vector<int>>& fruits) {
    //     int n=fruits.size();
    //     vis.assign(n,vector<int>(n,0));
    //     dp.assign(n,vector<int>(n,-1));
    //     dp2.assign(n,vector<int>(n,-1));
    //     int firstsum=0;
    //     for(int i=0;i<n;i++){
    //         firstsum+=fruits[i][i];
    //         vis[i][i]=1;
    //     }
    //     int level=0;
    //     int secondsum=recur1(0,n-1,fruits,level,n);
    //     level=0;
    //     int thirdsum=recur(n-1,0,fruits,level,n);
    //     cout<<secondsum<<" "<<thirdsum;
    //     int tot=(secondsum+thirdsum);
    //     return tot+firstsum;
    //     return 0;
    // }

    vector<vector<int>> vis;
    vector<vector<int>> dp;
    vector<vector<int>> dp2;

    int recur(int i, int j, vector<vector<int>> &fruits, int level, int n){
        // if(i==n-1 && j==n-1 && (level>=n || level<n-1)) return -1000000;
        if(i < 0 || i >= n || j >= n || level > n-1 || vis[i][j] == 1) return INT_MIN;
        if(i == n-1 && j == n-1 && level == n-1) return fruits[i][j];
        if(dp2[i][j] != -1) return dp2[i][j];

        int left = fruits[i][j] + recur(i-1, j+1, fruits, level+1, n);
        int dia = fruits[i][j] + recur(i, j+1, fruits, level+1, n);
        int right = fruits[i][j] + recur(i+1, j+1, fruits, level+1, n);
        return dp2[i][j] = max({left, dia, right}); 
    }

    int recur1(int i, int j, vector<vector<int>> &fruits, int level, int n){
        // if(i==n-1 && j==n-1 && (level>=n || level<n-1)) return -1000000;
        if(i < 0 || i >= n || j < 0 || j >= n || level > n-1 || vis[i][j] == 1) return INT_MIN;
        if(i == n-1 && j == n-1 && level == n-1) return fruits[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int left = fruits[i][j] + recur1(i+1, j-1, fruits, level+1, n);
        int dia = fruits[i][j] + recur1(i+1, j, fruits, level+1, n);
        int right = fruits[i][j] + recur1(i+1, j+1, fruits, level+1, n);
        return dp[i][j] = max({left, dia, right}); 
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vis.assign(n, vector<int>(n, 0));
        dp.assign(n, vector<int>(n, -1));
        dp2.assign(n, vector<int>(n, -1));

        int firstsum = 0;
        for(int i = 0; i < n; i++) {
            firstsum += fruits[i][i];
            vis[i][i] = 1;
        }
        vis[n-1][n-1]=0;

        int level = 0;
        int secondsum = recur1(0, n-1, fruits, level, n);
        level = 0;
        int thirdsum = recur(n-1, 0, fruits, level, n);

        // cout << secondsum << " " << thirdsum << endl;
        cout<<firstsum<<" "<<secondsum<<" "<<thirdsum;
        int tot = secondsum + thirdsum;
        return tot + firstsum - (fruits[n-1][n-1]*2);
    }
};