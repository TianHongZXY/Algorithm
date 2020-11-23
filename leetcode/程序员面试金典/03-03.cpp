#include <stack>
#include <vector>
using namespace std;

class StackOfPlates {
public:
    int _cap;
    vector<stack<int> > stack_set;
    StackOfPlates(int cap):_cap(cap) {
        stack<int> a;
        stack_set.push_back(a);
    }
    
    void push(int val) {
        if(_cap == 0) return;
        if(stack_set[stack_set.size() - 1].size() >= _cap){
            stack<int> a;
            stack_set.push_back(a);
        }
        stack_set[stack_set.size() - 1].push(val);
    }
    
    int pop() {
        if(stack_set[0].empty())
            return -1;
        int res = stack_set[stack_set.size() - 1].top();
        stack_set[stack_set.size() - 1].pop();
        if(stack_set.size() != 1 && stack_set[stack_set.size() - 1].size() == 0)
            stack_set.pop_back();
        return res;
    }
    
    int popAt(int index) {
        if(index > stack_set.size() - 1 || stack_set[index].empty())
            return -1;
        int res = stack_set[index].top();
        stack_set[index].pop();
        if(stack_set[index].size() == 0 && stack_set.size() > 1)
            stack_set.erase(stack_set.begin() + index);
        return res;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

class StackOfPlates2 {
    int sz;
    vector<vector<int> *> stk; //使用数组存储栈数组的指针
    vector<int> idx; //存储对应栈数组栈顶元素下标
public:
    StackOfPlates2(int cap) {        
        sz = cap;
    }
    
    void push(int val) {        
        if(sz <= 0) return; //cap可能等于0
        if(stk.empty() || idx.back() == sz){ //看情况新建栈数组
            stk.push_back(new vector<int>(sz + 1));
            idx.push_back(0);
        }
        auto &topstk = *stk.back(); //注意是引用
        topstk[++idx.back()] = val; //存储数据
    }
    
    int pop() {
        if(stk.empty()) return -1;
        auto &topstk = *stk.back();
        int res = topstk[idx.back()--];
        if(idx.back() == 0) stk.pop_back(), idx.pop_back(); //在适当的时候删除栈数组
        return res;
    }  

    int popAt(int index) {
        if(stk.size() <= index) return -1;
        auto &idxstk = *stk[index];
        int res = idxstk[idx[index]--];
        if(idx[index] == 0) stk.erase(stk.begin() + index), idx.erase(idx.begin() + index); //在适当的时候删除栈数组
        return res;
    }
};