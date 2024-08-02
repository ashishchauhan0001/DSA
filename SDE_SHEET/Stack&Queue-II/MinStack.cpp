class MinStack {
public:
list<int>l;
    MinStack() {
        
    }
    
    void push(int val) {
        l.push_front(val);
    }
    
    void pop() {
        l.pop_front();
    }
    
    int top() {
        return l.front();
    }
    
    int getMin() {
        return *min_element(l.begin(),l.end());
    }
};