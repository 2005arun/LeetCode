// class Router {
// public:
//     queue<tuple<int,int,int>> q;
//     map<tuple<int,int,int>,bool> hash;
//     int limit;
//     Router(int memoryLimit) {
//         limit=memoryLimit;
//     }
    
//     bool addPacket(int source, int destination, int timestamp) {
//         tuple<int,int,int> pack=make_tuple(source,destination,timestamp);
//         if(hash.find(pack)!=hash.end()){
//             return false;
//         }
//         if(hash.size()>=limit){
//             auto it=q.front();
//             q.pop();
//             int src,des,time;
//             tie(src,des,time)=it;
//             hash.erase(it);
//         }
//         hash[pack]=true;
//         q.push(pack);
//         return true;
//     }
    
//     vector<int> forwardPacket() {
//         if(q.empty()) return {};
//         auto it=q.front();
//         q.pop();
//         int src,des,time;
//         tie(src,des,time)=it;
//         hash.erase(it);
//         return {src,des,time};
//     }
    
//     int getCount(int destination, int startTime, int endTime) {
//         int cnt=0;
//         for(auto &i:hash){
//             auto it=i.first;
//             int src,des,time;
//             tie(src,des,time)=it;
//             if(des==destination && time>=startTime && time<=endTime){
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Router {
private:
    int limit;
    queue<tuple<int, int, int>> q; 
    unordered_set<string> packetSet; 
    unordered_map<int, vector<int>> destMap; 
    string getKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = getKey(source, destination, timestamp);
        if (packetSet.count(key)) return false;


        if (q.size() >= limit) {
            auto oldest = q.front(); q.pop();
            int s, d, t;
            tie(s, d, t) = oldest;
            packetSet.erase(getKey(s, d, t));
            auto& vec = destMap[d];
            vec.erase(lower_bound(vec.begin(), vec.end(), t));
        }

        q.emplace(source, destination, timestamp);
        packetSet.insert(key);
        destMap[destination].push_back(timestamp); 

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto front = q.front(); q.pop();
        int s, d, t;
        tie(s, d, t) = front;

        packetSet.erase(getKey(s, d, t));
        auto& vec = destMap[d];
        vec.erase(lower_bound(vec.begin(), vec.end(), t));

        return {s, d, t};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto& vec = destMap[destination];
        return upper_bound(vec.begin(), vec.end(), endTime) -
               lower_bound(vec.begin(), vec.end(), startTime);
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */