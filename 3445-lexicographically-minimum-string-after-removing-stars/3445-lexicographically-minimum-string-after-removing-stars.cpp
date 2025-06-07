class Solution {
public:
    struct compare{
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<s.size();i++){
            if(!pq.empty() && s[i]=='*'){
                // cout<<pq.top().second<<" ";
                pq.pop();
            }
            else pq.push({s[i]-'a',i});
        }
        vector<pair<int,int>> vec;
        while(!pq.empty()){
            vec.push_back(pq.top());
            // cout<<pq.top().second<<" ";
            pq.pop();
        }
        sort(vec.begin(),vec.end(),[](const pair<int,int>&a,const pair<int,int> &b){
            return a.second<b.second;
        });
        string res="";
        for(auto &i:vec){
            // cout<<i.first<<" ";
            char ch=char(i.first+97);
            res.push_back(ch);
        }
        return res;
    }
};