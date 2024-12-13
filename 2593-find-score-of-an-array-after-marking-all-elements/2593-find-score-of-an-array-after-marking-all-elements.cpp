class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<int> marks(nums.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        for(int i=0;i<nums.size();i++) minheap.push({nums[i],i});
        long long sum=0;
        while(!minheap.empty()){
            auto [value,i]=minheap.top();
            minheap.pop();
            if(marks[i]!=1){
                sum+=value;
                marks[i]=1;
                if(i-1>=0) marks[i-1]=1;
                if(i+1<nums.size()) marks[i+1]=1;
            }
        }
        return sum;
    }
};