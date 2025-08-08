class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        int i=0;
        int t=0;
        vector<int> index;
        int n=tasks.size();
        while(i<n){
            if(pq.empty()){
                t=max(t,tasks[i][0]);
            }
            while(i<n && tasks[i][0]<=t){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            t+=pq.top().first;
            index.push_back(pq.top().second);
            pq.pop();
        }
        while(!pq.empty()){
            index.push_back(pq.top().second);
            pq.pop();
        }
        return index;
    }
};