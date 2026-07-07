class Queue {
public:
    
    void push(int x) {
        s1.push(x);
    }

    
    void pop(void) {
        transfer(s1, s2);
        s2.pop();
        transfer(s2, s1);
    }

    
    int peek(void) {
        transfer(s1, s2);
        int ret = s2.top();
        transfer(s2, s1);
        return ret;
    }

    
    bool empty(void) {
        return s1.empty();
    }
private:
    stack<int> s1, s2;
    void transfer(stack<int>& s1, stack<int>& s2) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
};