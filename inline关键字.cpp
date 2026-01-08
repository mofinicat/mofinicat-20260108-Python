// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-08-23

#include <bits/stdc++.h>
using namespace std;

inline int add(int a, int b) {
    cout << "Calling add(int a, int b) : " << endl;
    return a+b;
}

inline double add(double a, double b) {
    cout << "Calling add(double, double) : " << endl;
    return a+b;
}

inline string add(const string& s1, const string& s2) {
    cout << "Calling add(string, string) : " << endl;
    return s1+s2;
}

int main() {
    int int_res;
    double double_res;
    string str_res;

    cout << "add(5, 10) : " << add(5, 10) << endl;
    cout << "add(3.14, 2.17) : " << add(3.14, 2.17) << endl;
    cout << "add(\"123\", \"bcd\")" << add("123", "bcd") << endl;
}

