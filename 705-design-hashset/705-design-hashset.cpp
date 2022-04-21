class MyHashSet {
public:
    set<int> st;
    MyHashSet() {
        
    }
    
    void add(int key) {
        st.insert(key);
    }
    
    void remove(int key) {
        auto it=st.lower_bound(key);
        if(*it==key){
            st.erase(it);
        }
    }
    
    bool contains(int key) {
        auto it=st.lower_bound(key);
        return *it==key;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */