class DataStream {
    int value;
    int k;
    int counter;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        counter = 0;
    }
    
    bool consec(int num) {
        if (num != value) {
            counter = 0;
            return false;
        }
        return ++counter >= this->k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */