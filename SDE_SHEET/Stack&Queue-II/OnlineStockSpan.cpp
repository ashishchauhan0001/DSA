//  T.C--> O(1)  and S.C--> O(N)
class StockSpanner {
public:
list<int> l;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(l.empty()){
            l.push_front(price); // 
            return 1;
        }
        int ans=0;
        l.push_front(price);
        for(auto it=l.begin();it!=l.end();it++){
            if((*it)<=price) ans++;
            else break;
        }

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */