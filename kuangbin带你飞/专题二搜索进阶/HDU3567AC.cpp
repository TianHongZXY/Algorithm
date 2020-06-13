#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
int vis1[363000],vis2[363000];
int ed[]={1,2,3,4,5,6,7,8,0};
string path[363000];//记录路径

int cantor(int s[]){//康托展开，进行状态压缩
    int sum=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)
            if(s[j]<s[i]) cnt++;
        sum+=cnt*fac[9-i-1];
    }
    return sum;
}

struct node{
    int s[9];
    int cur,n;//同A*算法
    int deep;//记录所在层次
}t[2];

int d[][2]={{1,0},{0,-1},{0,1},{-1,0}};
char dr1[]="dlru",dr2[]="urld";//这里前后遍历的方向相反，路径也相反

void bfs(node &t1,node &t2){//可以看出，双BFS的前后代码几乎是对称的，vis两个，队列两个
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    if(t1.n==t2.n) {cout<<0<<endl<<endl;return;}
    queue<node> q,qq;
    q.push(t1);
    vis1[t1.n]=1;
    path[t1.n]="";
    qq.push(t2);
    vis2[t2.n]=1;
    path[t2.n]="";
    int L=0;//记录层次，既然是双向的，肯定是你一层，我一层的顺序依次进行
    while(!q.empty() || !qq.empty()){
        while(q.front().deep==L){
            node tmp=q.front();
            q.pop();
            int x=tmp.cur/3,y=tmp.cur%3;
            for(int p=0;p<4;p++){
                int tx=x+d[p][0],ty=y+d[p][1];
                if(tx<0 || ty<0 || tx>2 || ty>2) continue;
                node tmp2=tmp;
                tmp2.cur=tx*3+ty;
                swap(tmp2.s[tmp.cur],tmp2.s[tmp2.cur]);
                tmp2.n=cantor(tmp2.s);
                tmp2.deep=tmp.deep+1;
                if(vis2[tmp2.n]){//如果找到解，打印路径
                    cout<<(int)path[tmp2.n].size()+(int)path[tmp.n].size()+1<<endl;//打印长度
                    reverse(path[tmp2.n].begin(),path[tmp2.n].end());
                    cout<<path[tmp.n]<<dr1[p]<<path[tmp2.n]<<endl;
                    return;
                }
                if(vis1[tmp2.n]) continue;
                vis1[tmp2.n]=1;
                path[tmp2.n]=path[tmp.n];
                path[tmp2.n]+=dr1[p];
                q.push(tmp2);

            }
        }
        while(qq.front().deep==L){
            node tmp=qq.front();
            qq.pop();
            int x=tmp.cur/3,y=tmp.cur%3;
            for(int p=0;p<4;p++){
                int tx=x+d[p][0],ty=y+d[p][1];
                if(tx<0 || ty<0 || tx>2 || ty>2) continue;
                node tmp2=tmp;
                tmp2.cur=tx*3+ty;
                swap(tmp2.s[tmp.cur],tmp2.s[tmp2.cur]);
                tmp2.n=cantor(tmp2.s);
                tmp2.deep=tmp.deep+1;
                //下面 if 得注意，我们不能像杭电1043那样就打印了，因为我们不能确定这条路径的字典序是最小的，
                //要找到最小的字典序，还得由正向BFS确定，我们这里跳过对其操作，由下一步的正向BFS打印
                if(vis1[tmp2.n])  continue;
                //下面这里的 if 注意，由于是反方向遍历，&&后面的比较必须有，否则WA
                if(vis2[tmp2.n] && path[tmp2.n][(int)path[tmp2.n].size()-1]<dr2[p]) continue;
                vis2[tmp2.n]=1;
                path[tmp2.n]=path[tmp.n]; // 返回上一层的字符串状态
                path[tmp2.n]+=dr2[p]; // 选用更小的这一步
                qq.push(tmp2);
            }
        }
        L++;//层次+1
    }
}

int main(){
    //freopen("C:\\Documents and Settings\\All Users\\桌面\\in.txt","r",stdin);
    //freopen("C:\\Documents and Settings\\All Users\\桌面\\out2.txt","w",stdout);
    int T;cin>>T;
    for(int p=1;p<=T;p++)
    {
        char ch;
        for(int j=0;j<2;j++)
        for(int i=0;i<9;i++){
            cin>>ch;
            if(ch=='X') {
                ch='0';
                t[j].cur=i;
            }
            t[j].s[i]=ch-'0';
        }
        t[0].n=cantor(t[0].s);t[0].deep=0;
        t[1].n=cantor(t[1].s);t[1].deep=0;

        printf("Case %d: ",p);
        bfs(t[0],t[1]);
    }
    return 0;
}