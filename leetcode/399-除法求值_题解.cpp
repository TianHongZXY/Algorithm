#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

bool flag;

double dfs(unordered_map<string,unordered_map<string,double> >&hash,set<string>&visited,string temp,string end){
    if(hash[temp].find(end) != hash[temp].end()){//发现temp->end在图中存在，返回true;
        flag = true;
        return hash[temp][end];//并返回他的权值
    }
    if(visited.find(temp) != visited.end()){//遇到重复节点，
        flag = false;
        return -1;
    }
    visited.insert(temp);//插入visited
    for(auto it : hash[temp]){
        string s = it.first;//相邻的结点
        double t = it.second;//权重
        double r = dfs(hash,visited,s,end);//以刚才temp相邻的结点s，为结点，继续向下寻找
        if(flag){//发现在temp的邻接点里找到了
            double sum = r*t;//乘以temp->s的权值t
            return sum;//返回
        }
    }
    return -1;//找不到
}

vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
    unordered_map<string,unordered_map<string,double> >hash;
    for(int i = 0;i<equations.size();i++){
        string str = equations[i][0];
        string str1 = equations[i][1];
        hash[str][str1] = values[i];
        hash[str1][str] = 1.0/values[i];//把倒数也弄出来
    }
    vector<double>res(queries.size());
    for(int i=0;i<queries.size();i++){
        string str1 = queries[i][0];
        string str2 = queries[i][1];
        if(hash.find(str1) == hash.end() || hash.find(str2) == hash.end())//两个有一个不存在
            res[i] = -1.0;
        else if(str1 == str2 )//两个相等
            res[i] = 1.0;
        else if(hash[str1].find(str2) != hash[str1].end())
            res[i] = hash[str1][str2];//有这个
        else{//只能找邻接边了
            set<string>visited;//每一次都要重新设置visited
            flag = false;
            double t = dfs(hash,visited,str1,str2);//t接受返回值
            if(flag){//，找到了，同时要记忆化更新， 这样在下一次就能更快的查找
                res[i] = t; 
                hash[str1][str2] = t;
                hash[str2][str1] = 1.0/t;
            }
            else
                res[i] = -1;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // equations = [ ["a", "b"], ["b", "c"] ],
    // values = [2.0, 3.0],
    // queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
    vector<vector<string> > equations;
    vector<string> e1; e1.push_back("a"); e1.push_back("b");
    vector<string> e2; e2.push_back("b"); e2.push_back("c");

    equations.push_back(e1); equations.push_back(e2);

    vector<double> values;
    values.push_back(2.0); values.push_back(3.0);
    vector<string> e3; e3.push_back("a"); e3.push_back("c");
    vector<string> e4; e4.push_back("b"); e4.push_back("a");
    vector<string> e5; e5.push_back("a"); e5.push_back("e");
    vector<string> e6; e6.push_back("a"); e6.push_back("a");
    vector<string> e7; e7.push_back("x"); e7.push_back("x");

    vector<vector<string> > queries;
    queries.push_back(e3);queries.push_back(e4);queries.push_back(e5);queries.push_back(e6);queries.push_back(e7);
    vector<double> res = calcEquation(equations, values, queries);

    for(auto item: res) cout << item << endl;
    return 0;
}