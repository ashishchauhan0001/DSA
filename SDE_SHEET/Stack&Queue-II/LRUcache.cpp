class LRUCache {
    unordered_map<int,pair<int,list<int>::iterator>>m;
    list<int>l; // for storing the keys
    int size;
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            l.erase(m[key].second);
            l.push_front(key);
            m[key].second=l.begin();
            return m[key].first;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            l.erase(m[key].second);
        }else if(m.size() >= size){
            auto it=l.back(); // least used
            l.pop_back();
            m.erase(it); // bcz we are storing the key in list
        }
        l.push_front(key);
        m[key]={value,l.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */