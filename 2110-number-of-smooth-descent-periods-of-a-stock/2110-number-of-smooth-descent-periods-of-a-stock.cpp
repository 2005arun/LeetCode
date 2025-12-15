class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long tot=0;
        int l=0,r=0;
        while(r<prices.size()){
            if(r-l+1==1){
                r++;
                tot=tot+1;
                continue;
            }
            else{
                if(prices[r-1]-prices[r] ==1){
                    tot=tot+(r-l+1);
                    r++;
                }
                else{
                    l=r;
                }
            }
        }
        return tot;
    }
};