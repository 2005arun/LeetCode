class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        for(auto &i:initialBoxes) q.push(i);
        int sum=0;
        set<int> st;
        while(!q.empty()){
            int box=q.front();
            q.pop();
            if(status[box]==1){
                sum+=candies[box];
                for(auto &it:keys[box]){
                    if(st.find(it)!=st.end()){
                        st.erase(it);
                        q.push(it);
                    }
                    status[it]=1;
                }
                for(auto &it:containedBoxes[box]){
                    q.push(it);
                }
            }
            else{
                st.insert(box);
            }
        }
        return sum;
    }
};