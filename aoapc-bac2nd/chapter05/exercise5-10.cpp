//
// Created by TianHongZXY on 2020/4/6.
// 过了udebug，但UVa还是WA，以后再找找问题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
map<string, int> word2id;
map<int, set<int> > wordid2docuid;
map<int, vector<int> > wordid2docs;
char line[80 + 10];

struct document{
    vector<set<int> > lineswordid;
    vector<string> linesstr;
    set<int> containwords;
};

bool foundnothing(string word){
    if (!word2id.count(word)){
        cout << "Sorry, I found nothing." << endl;
        cout << "==========" << endl;
        return true;
    }
    else{
        return false;
    }
}

int main(){
    document docus[maxn];
    int n, m;
    string word;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        while(cin.get(line, 80) && line[0] != '*'){
            getchar();
            string linestr(line);
            docus[i].linesstr.push_back(linestr);
            int len = linestr.length();
            for(int j = 0; j < len; j++){
                if(!isalpha(line[j])) line[j] = ' ';
                else line[j] = tolower(line[j]);
            }
            linestr = string(line);
            stringstream ss(linestr);
            set<int> linewordid;
            while(ss >> word){
                if(!word2id.count(word))
                    word2id[word] = word2id.size();
                int wordid = word2id[word];
                if(!wordid2docuid[wordid].count(i)){
                    wordid2docuid[wordid].insert(i);
                    wordid2docs[wordid].push_back(i);
                }
                linewordid.insert(wordid);
                docus[i].containwords.insert(wordid);
            }
            docus[i].lineswordid.push_back(linewordid);
        }
        getchar();
    }
    scanf("%d", &m);
    getchar();
    string cmdline;
    for(int i = 0; i < m; i++){
        getline(cin, cmdline);
        stringstream ss(cmdline);
        string cmds[3];
        ss >> cmds[0] >> cmds[1] >> cmds[2];
        if (cmds[1] == "" and cmds[2] == ""){
            if(foundnothing(cmds[0])) continue;
            int wordid = word2id[cmds[0]];
            int numdoc = wordid2docs[wordid].size();
            for(int d=0; d < numdoc - 1; d++){
                for(int j = 0; j < docus[wordid2docs[wordid][d]].lineswordid.size(); j++){
                    if (docus[wordid2docs[wordid][d]].lineswordid[j].count(wordid)){
                        cout << docus[wordid2docs[wordid][d]].linesstr[j] << endl;
                    }
                }
                cout << "----------" << endl;
            }
            for(int j = 0; j < docus[wordid2docs[wordid][numdoc-1]].lineswordid.size(); j++){
                if (docus[wordid2docs[wordid][numdoc-1]].lineswordid[j].count(wordid)){
                    cout << docus[wordid2docs[wordid][numdoc-1]].linesstr[j] << endl;
                }
            }
            cout << "==========" << endl;
        } else if(cmds[1] == "AND"){
            if(foundnothing(cmds[0]) || foundnothing(cmds[2])) continue;
            int wordid1 = word2id[cmds[0]];
            int wordid2 = word2id[cmds[2]];
            vector<int> toprint;
            set_intersection(wordid2docuid[wordid1].begin(), wordid2docuid[wordid1].end(),
                      wordid2docuid[wordid2].begin(), wordid2docuid[wordid2].end(), inserter(toprint, toprint.begin()));
            for(int j = 0; j < toprint.size() - 1; j++){
                document doc = docus[toprint[j]];
                for(int k = 0; k < doc.lineswordid.size(); k++)
                    if(doc.lineswordid[k].count(wordid1) || doc.lineswordid[k].count(wordid2))
                        cout << doc.linesstr[k] << endl;
                cout << "----------" << endl;
            }
            document doc = docus[toprint[toprint.size() - 1]];
            for(int k = 0; k < doc.lineswordid.size(); k++)
                if(doc.lineswordid[k].count(wordid1) || doc.lineswordid[k].count(wordid2))
                    cout << doc.linesstr[k] << endl;
            cout << "==========" << endl;
        } else if(cmds[1] == "OR"){
            set<int> w1docs; set<int> w2docs;
            int wordid1 = -1, wordid2 = -1;
            if (!word2id.count(cmds[0]) && !word2id.count(cmds[2])) {foundnothing(cmds[0]); continue;}
            else if(word2id.count(cmds[0]) && !word2id.count(cmds[2])) { w1docs = wordid2docuid[word2id[cmds[0]]]; wordid1=word2id[cmds[0]];}
            else if(word2id.count(cmds[2]) && !word2id.count(cmds[0])) { w2docs = wordid2docuid[word2id[cmds[2]]]; wordid2=word2id[cmds[2]];}
            else {w1docs = wordid2docuid[word2id[cmds[0]]]; w2docs = wordid2docuid[word2id[cmds[2]]];
                  wordid1=word2id[cmds[0]]; wordid2 = word2id[cmds[2]];}
            vector<int> toprint;
            set_union(w1docs.begin(), w1docs.end(),
                      w2docs.begin(), w2docs.end(), inserter(toprint, toprint.begin()));
            int numdoc = toprint.size();
            for(int j = 0; j < numdoc - 1; j++){
                document doc = docus[toprint[j]];
                for(int k = 0; k < doc.lineswordid.size(); k++)
                    if(doc.lineswordid[k].count(wordid1) || doc.lineswordid[k].count(wordid2))
                        cout << doc.linesstr[k] << endl;
                cout << "----------" << endl;
            }
            document doc = docus[toprint[numdoc-1]];
            for(int k = 0; k < doc.lineswordid.size(); k++)
                if(doc.lineswordid[k].count(wordid1) || doc.lineswordid[k].count(wordid2))
                    cout << doc.linesstr[k] << endl;
            cout << "==========" << endl;
        } else{
            int wordid;
            // 如果词表里没这个词，打印所有文章
            if(!word2id.count(cmds[1])) wordid = -1;
            else wordid = word2id[cmds[1]];
            int toprintdocs[maxn];
            int k = 0;
            for(int j = 0; j < n; j++){
                if (!docus[j].containwords.count(wordid)){
                    toprintdocs[k++] = j;
                }
            }
            if (k == 0) {
                foundnothing("AND"); continue;
            }
            for(int j = 0; j < k - 1; j++){
                for(string s: docus[toprintdocs[j]].linesstr)
                    cout << s << endl;
                cout << "----------" << endl;
            }
            for (string s: docus[toprintdocs[k-1]].linesstr)
                cout << s << endl;
            cout << "==========" << endl;
        }
    }


    return 0;
}
