// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-08-23
// demo： sstream

#include <bits/stdc++.h>

using namespace std;

int main() {
    // 1. 将不同的数据类型拼接到一个字符串里
    string str = "Hello 12345";
    stringstream ss;
    double pi = 3.1415926;
    int count = 5;
    ss << "add new sentence " << pi << ' ' << count;
    cout << ss.str() << endl;                       // 打印ss中存的字符
    ss.clear();                                     // 清空ss中存放的字符

    return 0;
}