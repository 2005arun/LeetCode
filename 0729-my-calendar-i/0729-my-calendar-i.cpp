class MyCalendar {
public:
    map<int,int> hash;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        hash[startTime]++;
        hash[endTime]--;
        int cnt=0;
        for(auto i:hash){
            cnt+=i.second;
            if(cnt>=2){
                hash[startTime]--;
                hash[endTime]++;
                if(hash[startTime]==0) hash.erase(startTime);
                if(hash[endTime]==0) hash.erase(endTime);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */