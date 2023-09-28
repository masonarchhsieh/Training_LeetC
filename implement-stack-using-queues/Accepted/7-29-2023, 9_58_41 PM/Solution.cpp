// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
    queue<int> st, st_b;
public:
    MyStack() {
    }
    
    void push(int x) {
        while (!st.empty()) {
            st_b.push(st.front());
            st.pop();
        }
        st.push(x);
        while (!st_b.empty()) {
            st.push(st_b.front());
            st_b.pop();
        }
    }
    
    int pop() {
        int tmp = st.front();
        st.pop();
        return tmp;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */