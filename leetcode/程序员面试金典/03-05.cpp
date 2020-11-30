#include <stack>
#include <iostream>
using namespace std;

class SortedStack {
public:
    stack<int> cache, min_stack;
    SortedStack() {
        
    }
    
    void push(int val) {
        if(!min_stack.empty() && val > min_stack.top())
            while(!min_stack.empty() && val > min_stack.top()){
                cache.push(min_stack.top());
                min_stack.pop();
            }
        else
            while(!cache.empty() && val < cache.top()){
                min_stack.push(cache.top());
                cache.pop();
            }
        min_stack.push(val);
    }
    
    void pop() {
        if(!cache.empty())
            move_cache_to_min();
        if(!min_stack.empty())
            min_stack.pop();
    }
    
    int peek() {
        if(!cache.empty())
            move_cache_to_min();
        if(min_stack.empty()) return -1;
        else return min_stack.top();
    }
    
    bool isEmpty() {
        return cache.empty() && min_stack.empty();
    }

    void move_cache_to_min(){
    while(!cache.empty()){
        min_stack.push(cache.top());
        cache.pop();
    }
    }
};

int main(int argc, char const *argv[])
{
    SortedStack* obj = new SortedStack();
    obj->push(3);
    obj->push(4);
    obj->push(2);
    obj->push(7);
    obj->push(5);
    obj->push(1);
    obj->push(9);
    int param_1 = obj->peek();
    obj->pop();
    // bool param_2 = obj->isEmpty();
    int param_3 = obj->peek();
    obj->pop();
    int param_4 = obj->peek();
    obj->pop();
    int param_5 = obj->peek();
    obj->pop();
    int param_6 = obj->peek();
    obj->pop();
    int param_7 = obj->peek();
    obj->pop();
    cout << param_1 << " " << param_3 << " " << param_4 <<  " " 
    << param_5 << " " << param_6 << " " << param_7 << " " << endl;
    return 0;
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */