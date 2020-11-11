#include <vector>
#include <set>
#include <cstring>
using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
    set<int> row, col;
    int M = matrix.size(), N = matrix[0].size();
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++){
            if(matrix[i][j] == 0){
                row.insert(i); col.insert(j);
            }
        }
    for(int r : row){
        vector<int> a(N);
        matrix[r] = a;
    }
    for(int c : col){
        for(int i = 0; i < M; i++)
            matrix[i][c] = 0;
    }
}

void setZeroes2(vector<vector<int> >& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    int row[M], col[N];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(!matrix[i][j])
                row[i] = col[j] = 1;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(row[i] || col[j])
                matrix[i][j] = 0;
}
