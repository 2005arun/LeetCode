class Solution {
public:
    int countCollisions(string directions) {
        vector<int> right(directions.size(),false),left(directions.size(),false);
        bool r=false;
        bool l=false;
        for(int i=0;i<directions.size();i++){
            if(directions[i]=='S' || directions[i]=='R') r=true;
            else left[i]=r;
        }
        for(int i=directions.size()-1;i>=0;i--){
            if(directions[i]=='S' || directions[i]=='L') l=true;
            else right[i]=l;
        }
        // for(auto i:left) cout<<i<<" ";
        int cnt=0;
        int i=0;
        while(i<directions.size()){
            if(directions[i]=='R'){
                if(i+1<directions.size() && directions[i+1]=='L'){
                    cnt+=2;
                    i+=2;
                    continue;
                }
                else if(right[i]==true){
                    cnt+=1;
                }
            }
            else if(directions[i]=='L' && left[i]==true){
                cnt+=1;
            }
            i++;
        }
        return cnt;
    }
};