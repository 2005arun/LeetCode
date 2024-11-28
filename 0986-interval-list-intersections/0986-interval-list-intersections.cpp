class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int s1=0,s2=0;
        vector<int> temp(2);
        vector<vector<int>> res;
        while(s1<firstList.size() && s2<secondList.size()){
            if(firstList[s1][0]<=secondList[s2][1] && secondList[s2][0]<=firstList[s1][1]){
                temp[0]=max(firstList[s1][0],secondList[s2][0]);
                temp[1]=min(firstList[s1][1],secondList[s2][1]);
                res.push_back(temp);
            }
            if(firstList[s1][1]<secondList[s2][1]) s1++;
            else s2++;
        }
        return res;
    }
};