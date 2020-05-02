//
// Created by TianHongZXY on 2020/3/29.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
//    ----------cin>>用法----------
   char a;
   int b;
   float c;
//    敲下回车后，输入的字符串才被送到缓冲区，回车符'\n'一起被送入
//    cin忽略并清除输入缓冲区的换行符、tab、空格等分隔符
   cin >> a >> b >> c;
   cout << a << ' ' << b << ' ' << c << endl;
//    使用noskipws流不忽略空白字符
   cin >> noskipws >> a >> b >> c;
   cout << a << ' ' << b << ' ' << c << endl;

//    ----------cin.get()用法----------
   char a1, a2;
   // cin.get(char& a); 从缓冲区读取单个字符，不忽略分隔符
   a1 = cin.get();
   cin.get(a2);
   cout << a1 << ' ' << a2 << endl;
//    cin.get(char* s, n, delim) 读取一行，不设置delim默认用换行符作为结束，n表示streamsize，
//    不对结尾的换行符做处理，'\n'仍留在缓冲区，这点与getline不同，
//    且cin.get()只能读取char*，而不能读取string，所以读取行时使用getline()更好
   char a3[20];
   cin.get(a3, 20);
   cin.get(a1);
   cout << a3 << ' ' << (int)a1 << endl;

//    ----------getline()用法----------
//    getline函数的参数使用了string，声明在了<string>头文件中
   string test;
   char x = getchar();
//    getline不忽略缓冲区的换行符，读取换行符后将换行符转换为空字符'\0'
//    相当于getline会将结尾的换行符从缓冲区中删除
   getline(cin, test);
   cout << "test:" << test << endl;

//    ----------cin.getline()用法----------
// 会读取结束符并清除，不会将结束符或者换行符残留在输入缓冲区中。
// 属于istream流，而getline()属于string流，是不一样的两个函数。
    char a4[20];
//  注意，读取了20个字符，包括了结尾的结束符，所以相当于只读取了19个字符！
    cin.getline(a4, 20, '\n');
    return 0;
}