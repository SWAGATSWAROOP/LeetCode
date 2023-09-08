class TimeMap {
public:
    unordered_map<string,map<int,string>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!map.count(key))return "";
        auto itr = map[key].upper_bound(timestamp);
        if(itr == map[key].begin())return "";
        return prev(itr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */