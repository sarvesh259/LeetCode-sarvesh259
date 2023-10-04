class MyHashMap {
private:
    // int sz=1e6+1;
    unordered_map<int,int> a;
public:
    MyHashMap() {
        a.clear();
    }
    
    void put(int key, int value) {
        a[key]=value;
    }
    
    int get(int key) {
        if(a.find(key)!=a.end())
        return a[key];
        return -1;
    }
    
    void remove(int key) {
        a[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */