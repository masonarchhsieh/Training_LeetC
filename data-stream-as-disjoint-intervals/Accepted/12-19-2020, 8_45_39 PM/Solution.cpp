// https://leetcode.com/problems/data-stream-as-disjoint-intervals

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    SummaryRanges() {
    }
    
    void addNum(int val) {
        vector<int>::iterator it;
        it = find (nums.begin(), nums.end(), val);
        if (it != nums.end())
            return;
        
        nums.push_back(val);
        sort(nums.begin(), nums.end());
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        
        for (int i=0; i<nums.size(); i++) {
            int j = i;
            
            while (j+1 < nums.size() && (long) (long) nums[j+1] - (long) nums[j] == 1)
                j++;
            
            if (i==j)
                res.push_back(vector<int>{nums[i], nums[i]});
            else
                res.push_back(vector<int>{nums[i], nums[j]});
            i = j;
        }
        
        
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */