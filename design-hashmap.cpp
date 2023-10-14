class MyHashMap {
public:
    unordered_map<int, int> st;
    MyHashMap() {
       
    }
    
    void put(int key, int value) {
        st[key] = value;
    }
    
    int get(int key) {
        if(st.count(key)){
            return st[key];
        }
        return -1;
    }
    
    void remove(int key) {
        st.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */