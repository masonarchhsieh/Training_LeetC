// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
    queue<int> q1, q2;
    int count;
public:
    MyStack() {
        count = 0;
    }
    
    void push(int x) {
        q1.push(x);
        count++;
    }
    
    int pop() {
        int temp = q1.back();
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        q1 = q2;
        count--;
        return temp;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return (count == 0);
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