#include <cstdio>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> cache, queue;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        cache.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        if(!queue.empty()){ // 如果queue当前非空，直接弹出top即为front
            res = queue.top(); queue.pop();
        }
         // 如果queue当前为空，那么把cache全部都搬到queue上，此时对queue进行pop的顺序就是先进先出
        else {
            move_cache_to_queue();
            res = queue.top(); queue.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(!queue.empty()) return queue.top();
        else move_cache_to_queue();
        return queue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (cache.empty() && queue.empty());
    }

    void move_cache_to_queue(){
        while(!cache.empty()){
            queue.push(cache.top());
            cache.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char const *argv[])
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);

    int param_2 = obj->peek();
    obj->pop();
    // int param_3 = obj->peek();
    bool param_4 = obj->empty();
    printf("%d %s\n", param_2,  param_4 ? "true" : "false");
    return 0;
}
