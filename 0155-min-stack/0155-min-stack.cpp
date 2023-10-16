class MinStack {
    stack<int> st;
    multiset<int> _multiset;
    
public:
    MinStack() {
        // st.clear();
        // _multiset.clear();
    }
    
    void push(int val) {
        st.push(val);
        _multiset.insert(val);
    }
    
    void pop() {
        if (st.empty())
            return;
        _multiset.erase(_multiset.find(st.top()));
        for (auto i : _multiset)
            cout << i << endl;
        st.pop();
    }
    
    int top() {
        if (st.empty())
            return -1;
        return st.top();
    }
    
    int getMin() {   
        return *(_multiset.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */