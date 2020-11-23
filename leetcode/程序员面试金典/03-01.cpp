#include <cstdio>
/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */

// 一位数组切分法，也可以用二维数组
class TripleInOne {
private:
    int *stack;
    int sidx[3];
    int maxn;
public:
    TripleInOne(int stackSize) {
        stack = new int[stackSize * 3 + 3];
        sidx[0] = sidx[1] = sidx[2] = 0;
        maxn = stackSize;
    }
    
    void push(int stackNum, int value) {
        if(sidx[stackNum] == maxn) return;
        
        stack[++sidx[stackNum] * 3 + stackNum] = value;
    }
    
    int pop(int stackNum) {
        if(isEmpty(stackNum)) return -1;
        return stack[sidx[stackNum]-- * 3 + stackNum];
    }
    
    int peek(int stackNum) {
        if(isEmpty(stackNum)) return -1;
        return stack[sidx[stackNum] * 3 + stackNum];
    }
    
    bool isEmpty(int stackNum) {
        return sidx[stackNum] == 0;
    }

};

class TripleInOne2 {
public:
    int *stack;
    int top[3];
    int stackSize;
    TripleInOne2(int stackSize):stackSize(stackSize) {
        stack = new int[stackSize*3];
        top[0]=top[1]=top[2]=0;
    }
    
    void push(int stackNum, int value) {
        if(top[stackNum] < stackSize)
            stack[stackSize*stackNum + top[stackNum]++]=value;
    }
    
    int pop(int stackNum) {
        if(top[stackNum] <= 0)
            return -1;
        else
            return stack[stackSize*stackNum + (--top[stackNum])];
    }
    
    int peek(int stackNum) {
        if(top[stackNum] <= 0)
            return -1;
        else
            return stack[stackSize*stackNum + (top[stackNum]-1)];
    }
    
    bool isEmpty(int stackNum) {
        return top[stackNum]==0;
    }
};

int main(){
    TripleInOne *t = new TripleInOne(3);
    t->push(0, 1);
    t->push(0, 2);

    printf("%d\n", t->pop(0));
    printf("%d\n", t->peek(0));
    printf("%d\n", t->isEmpty(0));
}