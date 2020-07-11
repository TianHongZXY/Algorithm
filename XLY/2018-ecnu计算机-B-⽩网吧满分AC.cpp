#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 250000
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define LL long long
using namespace std;
int n,m,q,a[N+5],b[N+5];
class FastIO
{
    private:
        #define FS 100000
        #define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
        #define tn (x<<3)+(x<<1)
        #define D isdigit(c=tc())
        char c,*A,*B,FI[FS];
    public:
        I FastIO() {A=B=FI;}
        Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
}F;
class Solver1
{
    private:
        int dc,dv[2*N+5],cnt[2*N+5];
    public:
        I void Solve()
        {
            RI i,x,ans=0;for(i=1;i<=n;++i) dv[++dc]=a[i],dv[++dc]=b[i]+1;
            sort(dv+1,dv+dc+1),dc=unique(dv+1,dv+dc+1)-dv-1;//离散化
            for(i=1;i<=n;++i)//差分
                x=lower_bound(dv+1,dv+dc+1,a[i])-dv,++cnt[x],
                x=lower_bound(dv+1,dv+dc+1,b[i]+1)-dv,--cnt[x];
            for(i=1;i<=dc;++i) cnt[i]+=cnt[i-1],Gmax(ans,cnt[i]);//统计前缀和
            printf("%d\n",ans);//输出答案
        }
}S1;
class Solver2
{
    private:
        I LL gcd(Con LL& x,Con LL& y) {return y?gcd(y,x%y):x;}
    public:
        I void Solve()
        {
            RI i;LL s=0,g;for(i=1;i<=n;++i) s+=b[i]-a[i]+1;//统计区间长度和
            g=gcd(s,m),s/=g,m/=g,printf("%lld/%lld\n",s,m);//除以总点数
        }
}S2;
int main()
{
    RI i;for(F.read(n),F.read(m),i=1;i<=n;++i) F.read(a[i]),F.read(b[i]);
    return F.read(q),q^2&&(S1.Solve(),0),q^1&&(S2.Solve(),0),0;
}