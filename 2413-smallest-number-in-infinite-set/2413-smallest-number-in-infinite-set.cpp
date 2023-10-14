class SmallestInfiniteSet {
    int nums[1001];
    bool n_exists[1001];
    int smallestIndex;
public:
    SmallestInfiniteSet() {
        for (auto i = 1; i <= 1000; i++) {
            nums[i] = i;
            n_exists[i] = true;
        }
        smallestIndex = 1;
    }
    
    int popSmallest() {
        while (!n_exists[smallestIndex]) {
            smallestIndex++;
        }
        n_exists[smallestIndex] = false;
        return nums[smallestIndex++];
    }
    
    void addBack(int num) {
        if (!n_exists[num]) {
            n_exists[num] = true;
            smallestIndex = min(num, smallestIndex);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */