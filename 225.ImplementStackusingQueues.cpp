class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {
        
    }
    
    void push(int x) {
        que1.push(x);
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        swap(que1, que2);
    }
    
    int pop() {
        int result = que2.front();
        que2.pop();

        return result;
    }
    
    int top() {
        return que2.front();
    }
    
    bool empty() {
        return que2.empty();
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