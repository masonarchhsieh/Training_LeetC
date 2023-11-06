class SeatManager {
    set<int> _set;
    int n;
public:
    SeatManager(int n) {
        _set.clear();
        this->n = n;
        for (auto i = 1; i <= n; i++)\
            _set.insert(i);
    }
    
    int reserve() {
        int val = *(_set.begin());
        _set.erase(_set.begin());
        return val;
    }
    
    void unreserve(int seatNumber) {
        _set.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */