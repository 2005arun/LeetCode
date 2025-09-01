class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // vector<double> vec;
        // for(auto i:classes){
        //     vec.push_back(i[0]/float(i[1]));
        // }
        // int l=0;
        // double sum=accumulate(vec.begin(),vec.end(),0.0);
        // double maxm=sum/classes.size();
        // // cout<<maxm<<" ";
        // // cout<<vec.size()<<" ";
        // // for(auto i:vec) cout<<i<<" ";
        // while(l<vec.size()){
        //     double rem=sum-vec[l];
        //     // cout<<classes[l][1]+extraStudents<<" ";
        //     double diff=(classes[l][0]+extraStudents)/float(classes[l][1]+extraStudents);
        //     rem+=diff;
        //     cout<<rem<<" ";
        //     maxm=max(maxm,rem/classes.size());
        //     l++;
        // }
        // return maxm;

        // priority_queue<pair<double,pair<int,int>>,vector<pair<double,
        // pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq;
        // for(auto i:classes){
        //     pq.push({i[0]/float(i[1]),{i[0],i[1]}});
        // }
       
        // double res=0.0;
        // while(extraStudents--){
        //     // cout<<pq.top().first<<" ";
        //     auto it=pq.top();
        //     pq.pop();
        //     int a=it.second.first+1;
        //     int b=it.second.second+1;
        //     pq.push({a/float(b),{a,b}});
        // }
        // while(!pq.empty()){
        //     double it=pq.top().first;
        //     // cout<<it<<" ";
        //     pq.pop();
        //     res+=it;
        // }
        // // cout<<res<<" ";
        // return res/classes.size();

        priority_queue<pair<double,int>> pq;
        for(int i=0;i<classes.size();i++){
            double ans=((classes[i][0]+1)/float(classes[i][1]+1))-(classes[i][0]/float(classes[i][1]));
            pq.push({ans,i});
        }
        while(extraStudents--){
            int i=pq.top().second;
            pq.pop();
            classes[i][0]+=1;
            classes[i][1]+=1;
            // cout<<classes[i][0]<<" ";
            double ans=((classes[i][0]+1)/float(classes[i][1]+1))-(classes[i][0]/float(classes[i][1]));
            pq.push({ans,i});
        }
        double res=0.0;
        for(auto i:classes){
            double ans=i[0]/float(i[1]);
            res+=ans;
        }
        return res/classes.size();
    }
};