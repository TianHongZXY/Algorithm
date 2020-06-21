#include <cstdio>
using namespace std;
int main()
{
	// freopen("t.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		int t=0;
		getchar();
		char c;
		for(int i=0;i<n;i++){
			scanf("%c",&c);
			if(c=='B') t++;
		}
		if(n==2) {
			printf("N\n");
			continue;
		}
		if(n==3){
		    if(t==1){
			    printf("Y\n");
			    continue;
		    }
            else{
			    printf("N\n");
			    continue;
		    }
        }
		if(t>1&&t<n-1){
			printf("Y\n");
			continue;
		}
        else{
			printf("N\n");
			continue;
		}
	}

	return 0;
}