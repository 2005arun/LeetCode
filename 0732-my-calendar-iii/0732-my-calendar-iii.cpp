class MyCalendarThree {
public:
    map<int,int> hash;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        hash[startTime]++;
        hash[endTime]--;
        int cnt=0;
        int maxm=0;
        for(auto i:hash){
            cnt+=i.second;
            maxm=max(maxm,cnt);
        }
        return maxm;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */