//
// Created by TianHongZXY on 2020/4/18.
//
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <map>

// 暂未解决已访问过节点的问题，死循环
using namespace std;

typedef string VerterType;
typedef double EdgeType;

typedef struct EdgeNode{ // 图上的某条边ab
    string adjvex; // 点b的data
    EdgeType weight; // a/b的值
    struct EdgeNode *next; // 指向点a的另一个邻接点
}EdgeNode;

typedef struct VertexNode{ // 图上的点a
    VerterType data; // 点a存储的信息
    EdgeNode *firstedge; // 点a的边表头指针
}VertexNode;

map<string, VertexNode> str2ver;


void CreateALGraph(vector<vector<string> > equations, vector<double> values){
    int i = 0;
    for(auto item: equations){
        if(!str2ver.count(item[0])){
            auto v = new VertexNode;
            v->data  = item[0];
            v->firstedge = NULL;
            str2ver[item[0]] = *v;
        }
        if(!str2ver.count(item[1])){
            auto u = new VertexNode;
            u->data  = item[1];
            u->firstedge = NULL;
            str2ver[item[1]] = *u;
        }
        auto ev= new EdgeNode;
        ev->adjvex = item[1];
        ev->weight = values[i];
        ev->next = str2ver[item[0]].firstedge;
        str2ver[item[0]].firstedge = ev;

        auto eu= new EdgeNode;
        eu->adjvex = item[0];
        eu->weight = 1.0 / values[i];
        eu->next = str2ver[item[1]].firstedge;
        str2ver[item[1]].firstedge = eu;
        i++;
    }
}

bool dfs(EdgeNode *a, string tgt, double result, vector<double>& res){
    bool found_tgt = false;
    if(a->adjvex == tgt){
        cout << a->adjvex << " " << a->weight << endl;
        result *= a->weight;
        res.push_back(result);
        return true;
    }
    else{
        cout << a->adjvex << " " << a->weight << endl;
        result *= a->weight;
        VertexNode b = str2ver[a->adjvex];
        EdgeNode *p = b.firstedge;
        while(p && !found_tgt){
            found_tgt = dfs(p, tgt, result, res);
            p = p->next;
        }
    }
    return found_tgt;
}

vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
    CreateALGraph(equations, values);
    vector<double> res;
    for(auto item: queries){
        if((!str2ver.count(item[0])) || (!str2ver.count(item[1]))){
            res.push_back(-1); continue;
        }
        double result = 1.0;
        EdgeNode* p = str2ver[item[0]].firstedge;
        bool found_tgt = false;
        while(p && !found_tgt){
            found_tgt = dfs(p, str2ver[item[1]].data, result, res);
            p = p->next;
        }
        if(!found_tgt) res.push_back(-1);
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

