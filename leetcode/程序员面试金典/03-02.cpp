#include <cstdio>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> min_s;
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if(min_s.empty() || x <= min_s.top())
            min_s.push(x);
    }
    
    void pop() {
        if(s.empty()) return;
        int tmp = s.top(); s.pop();
        if(tmp == min_s.top()) min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

class MinStack2 {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int _min = INT_MAX;
    MinStack2() {

    }
    
    void push(int x) {
        if(x <= _min){
            s.push(_min);
            _min = x;
        }
        s.push(x);
    }
    
    void pop() {
        if(s.empty()) return;
        int tmp = s.top(); s.pop();
        if(tmp == _min){
            _min = s.top(); s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return _min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */