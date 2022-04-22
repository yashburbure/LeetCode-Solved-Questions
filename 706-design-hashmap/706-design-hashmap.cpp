class MyHashMap {
public:
    map<int,int> mp;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        mp[key]=value;
    }
    
    int get(int key) {
        auto it=mp.lower_bound(key);
        if(it==mp.end()) return -1;
        else if(it->first!=key) return -1;
        return mp[key];
    }
    
    void remove(int key) {
        auto it=mp.lower_bound(key);
        if(it==mp.end()) return ;
        if(it->first==key) mp.erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */