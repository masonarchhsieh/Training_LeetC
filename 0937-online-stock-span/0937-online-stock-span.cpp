class StockSpanner {
    vector<int> v;
public:
    StockSpanner() {
        v.clear();
    }
    
    int next(int price) {
        v.push_back(price);
        int cnt = 0;
        for (auto i = v.rbegin(); i != v.rend(); ++i) {
            if (*i > price)
                break;
            cnt++;
        }


        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */