class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // vector<int> space;
        // int val=0;
        // for(int i=0;i<startTime.size();i++){
        //     int diff=startTime[i]-val;
        //     if(diff>0) space.push_back(diff);
        //     val=endTime[i];
        // }
        // int diff=eventTime-val;
        // if(diff>=0) space.push_back(diff);
        // int a=space.size();
        // if(a-k <=1) return accumulate(space.begin(),space.end(),0);
        // int n=a-k;
        // int l=0,r=0;
        // int sum=0;
        // while(r<n){
        //     sum+=space[r];
        //     r++;
        // }
        // int maxm=sum;
        // while(r<a){
        //     maxm=max(maxm,(sum-space[l++]+space[r++]));
        // }
        // return maxm;
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int sum=0;
        int i=0;
        int diff=0;
        while(i<k+1){
            sum+=startTime[i]-diff;
            diff=endTime[i];
            i++;
        }
        int val=0;
        int maxm=sum;
        int j=0;
        while(i<endTime.size()){
            sum+=startTime[i]-diff;
            diff=endTime[i];
            sum-=startTime[j]-val;
            val=endTime[j];
            maxm=max(maxm,sum);
            i++;
            j++;
        }
        return maxm;
    }
};