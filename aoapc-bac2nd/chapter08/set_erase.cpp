#include <set>
#include <cstdio>
using namespace std;

struct Candidate{
    int a, g;
    Candidate(int a, int g): a(a), g(g) {}
    bool operator < (const Candidate &rhs) const{
        return a < rhs.a;// || (a == rhs.a && g < rhs.g);
    }
};

int main(){
    set<Candidate> s;
    s.insert(Candidate(10, 10));
    printf("%d\n", s.empty());
    // 这个操作会erase掉上面添加的元素，因为set的erase根据元素的 < 操作符判断是否相同
    // 如果把上面的注释再加上判断g，就不会erase了
    s.erase(Candidate(10, 8));
    printf("%d\n", s.empty());
    return 0;
}