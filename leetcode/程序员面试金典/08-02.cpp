#include <cstring>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool step(vector<vector<int> > & obstacleGrid, int r, int c, vector<vector<int> > & path, bool & arrive){
    if(arrive) return true;
    if(r + 1 == obstacleGrid.size() && c + 1 == obstacleGrid[0].size() && obstacleGrid[r][c] != 1) {
        path.push_back((vector<int>){r, c});
        return arrive = true;
    }
    if(obstacleGrid[r][c] == 0){
        path.push_back((vector<int>){r, c});
        if(r + 1 < obstacleGrid.size())
            arrive = step(obstacleGrid, r + 1, c, path, arrive);
        if(c + 1 < obstacleGrid[0].size())
            arrive |= step(obstacleGrid, r, c + 1, path, arrive);
        if(!arrive)
            path.pop_back();
    }
    if(!arrive) obstacleGrid[r][c] = 1;
    return arrive;
}

vector<vector<int> > pathWithObstacles(vector<vector<int> >& obstacleGrid) {
    vector<vector<int> > path;
    bool arrive = false;
    step(obstacleGrid, 0, 0, path, arrive);

    return path;
}

vector<vector<int> > pathWithObstacles(vector<vector<int> >& obstacleGrid) {
    vector<vector<int> > res;
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][cols - 1] == 1)
        return res;
    bool d[rows][cols];
    memset(d, 0, sizeof(bool)*rows*cols);
    d[0][0] = 1;
    for(int i = 1; i < rows; i++)
        d[i][0] = d[i - 1][0] && !obstacleGrid[i][0];
    for(int i = 1; i < cols; i++)
        d[0][i] = d[0][i - 1] && !obstacleGrid[0][i];
    for(int i = 1; i < rows; i++)
        for(int j = 1; j < cols; j++)
            d[i][j] = (d[i - 1][j] || d[i][j - 1]) && !obstacleGrid[i][j];
    if(!d[rows - 1][cols - 1])
        return res;
    int i = rows - 1, j = cols - 1;
    while(i > 0 || j > 0) {
        res.push_back({i, j});
        if(i > 0 && d[i - 1][j]) i--;
        else j--;
    }
    res.push_back({0, 0});
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<vector<int> > grid;
    grid.push_back({0, 0, 0}); grid.push_back({0, 1, 0}); grid.push_back({0, 0, 0});
    vector<vector<int> > path = pathWithObstacles(grid);
    for(auto c: path){
        for(auto a: c)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}

