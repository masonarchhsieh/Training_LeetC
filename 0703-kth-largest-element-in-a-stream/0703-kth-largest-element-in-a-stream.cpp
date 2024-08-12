class KthLargest {
    vector<int> v;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        v = nums;
        sort(v.begin(), v.end());
    }
    
    int add(int val) {
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), val);
        v.insert(it, val);
        return v.at(v.size() - _k);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */