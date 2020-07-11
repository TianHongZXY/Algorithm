#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void sprintf_example(){ // 数字 --> 字符串

    int H, M, S, seconds;
    scanf("%d", &seconds);
    string time_str;
    H = seconds/3600;
    M = (seconds%3600) / 60;
    S = (seconds%3600) % 60;
    char ctime[100];
    sprintf(ctime, "%02d hour(s) %02d min(s) %02d sec(s)", H, M, S);
    time_str = ctime;
    cout << time_str << endl;
}

void sscanf_example(){ // 字符串 --> 数字
    char str[] = "15.455";
    int it;
    float fp;
    sscanf(str, "%d", &it);
    sscanf(str, "%f", &fp);
    cout << "Integer = " << it << endl;
    cout << "Float = " << fp - it << endl;
}

void sstream_example(){
    // 提示：sstream速度比ssprintf和sscanf慢得多
    double ft = 6243353.75433423489; // 数字 --> 字符串
    stringstream ss;
    ss.precision(4); // 设置精度为4位有效数字，默认为6位，遇到较长数字会使用科学计数法
    // ss.setf(std::ios::fixed); // 不会用科学计数法表示，精确到小数点后六位
    ss << ft;
    string s;
    ss >> s;
    cout << "精度:" << ss.precision() << endl;
    cout << s << endl;


    double num; // 字符串 --> 数字
    stringstream ssss("123.056");
    ssss >> num;
    cout << num << endl; 
}

int main(){
    // sprintf_example();
    sscanf_example();
    sstream_example();

}