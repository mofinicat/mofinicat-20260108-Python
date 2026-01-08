#include <bits/stdc++.h>
using namespace std;

// 声明定义分开写的时候只在声明中填写默认值
// 某个参数开始有默认值，其后面所有值都需要有默认值
void PrintStringAdd_Sent1Sent2(const string& in, 
                                const string& Sent1=" Very ", 
                                const string& Sent2=" BAD ! ",
                                const string& Sent3 = " worse ");

void PrintStringAdd_Sent1Sent2(const string& in, 
                                const string& Sent1, 
                                const string& Sent2,
                                const string& Sent3) {
    cout << in+Sent1+Sent2+Sent3 << endl;
}

int main() {
    PrintStringAdd_Sent1Sent2("Tiger is bad tiger ! ");                         // 全用默认参数
    PrintStringAdd_Sent1Sent2("Tiger is bad tiger ! ", " A ");                  // 传入Sent1，Sent2、Sent3用默认
    PrintStringAdd_Sent1Sent2("Tiger is bad tiger ! ", " A ", " B ");           // 传入Sent1、Sent2，Sent3用默认
    PrintStringAdd_Sent1Sent2("Tiger is bad tiger ! ", " A ", " B ", " C ");    // 传入Sent1、Sent2，Sent3用默认
    return 0;
}
