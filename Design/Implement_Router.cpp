// 3508. Implement Router


class Router {
public:
    int MAX_SIZE;
    queue<string> q;
    unordered_map<string, vector<int>> packetStoreMap;      // {"S_D_T" -> [S,D,T] } 
    unordered_map<int, vector<int>> destinationMap;

    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

        if(packetStoreMap.find(key) != packetStoreMap.end()) return false;

        q.push(key);
        packetStoreMap[key] = {source, destination, timestamp};
        destinationMap[destination].push_back(timestamp);

        if(q.size() > MAX_SIZE) forwardPacket();
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};

        string key = q.front();
        q.pop();
        
        vector<int> result = packetStoreMap[key];
        int D = result[1];
        packetStoreMap.erase(key);
        destinationMap[D].erase(destinationMap[D].begin());

        return result;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destinationMap.find(destination);

        if(it == destinationMap.end() || it->second.empty()) return 0;

        vector<int> &timestamps = it->second;
        int i = lower_bound(begin(timestamps), end(timestamps), startTime) - begin(timestamps);
        int j = upper_bound(begin(timestamps), end(timestamps), endTime) - begin(timestamps);
        return j-i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */