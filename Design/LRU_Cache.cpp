// 146. LRU Cache


// Approach-1: (Using vector) -> TLE
using P = pair<int,int>;
class LRUCache {
public:
    vector<P> cache;
    int n;

    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                P temp = cache[i];
                cache.erase(begin(cache)+i);
                cache.push_back(temp);
                return temp.second;
            }

        }

        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(begin(cache)+i);
                cache.push_back({key, value});
                return;
            }
        }

        if(cache.size() == n){
            cache.erase(begin(cache));
            cache.push_back({key, value});
        }else{
            cache.push_back({key, value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




// Approach-1: (Using DLL)