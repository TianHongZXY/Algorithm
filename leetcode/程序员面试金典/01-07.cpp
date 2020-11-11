#include <vector>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
    // 先沿主对角线翻折，再左右翻折
    // a_(i)(j)=a'(j)(i)，再a_(i)(j)=a'(j)(i)=a''(j)(N-i+1)
    int N = matrix[0].size();
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N / 2; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N - 1 - j] = tmp;
        }
}

int main(){
    // 还有个方法为：目标顺时针转90度，即a_(i)(j) = a'(j)(N-i+1)
    // 先上下翻折a_(i)(j)=a'(N-i+1)(j)，再转置a_(i)(j)=a'(N-i+1)(j)=a''(j)(N-i+1)
}