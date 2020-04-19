#include <bits/stdc++.h>	//万能头文件
using namespace std ;
char c1[4] = {'C','H','O','N'} ;  //常量数组，c1对应d1
float d1[4] = {12.01,1.008,16.00,14.01} ;
int main()
{
    int n; cin >> n; while(n--) {
        char a[85]; cin >> a;						//存放化学式的数组
        int len = strlen(a) ; 						//求化学式长度，于遍历时使用。
        float sum = 0 ;								//存放结果。
        for(int i = (len-1); i >= 0; i--) {	 		//逆序遍历，优点在于识别数字。
            float num = 1.0 ;
            if(isdigit(a[i])) {						//如果是数字
                num = (a[i]-'0'); i--;				//num更新成该数字，向前挪一位
                if(isdigit(a[i])) { num += ((a[i]-'0')*10); i--; }	//如果上一位还是数字，该数*10加num。(相当于十位数) ，向前挪一位
            }
            if(isalpha(a[i])) {  //判断是否是字母
                int k = 0 ;
                for(k = 0 ;k < 4; k++)
                    if(a[i] == c1[k]) { sum += (num*d1[k]); break; }
            }
        }
        printf("%.3f\n",sum) ;
    }
    return 0 ;
}
