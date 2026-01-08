#include <bits/stdc++.h>
using namespace std;

// 引用作为函数参数传递
/////////////////////////////////////////////////////////////
// 传值调用无法修改指针变量的值
void Modify_passval(int* ptr) {
    int a = 200;
    ptr = &a;
}

// 引用修改指针的值
void Modify_passref(int*& ptr) {
    int a = 100;
    ptr = &a;  // 修改指针的引用
}

// 二级指针修改指针变量的值
void Modify_passptr(int** ptr) {
    int a = 1000;
    *ptr = &a;
}

// const + reference：只能通过引用读取，但是不能通过应用修改
void PrintString(const string& str) {
    // str += "123";                // 编译错误，无法修改，因为有const修饰引用
    cout << str << endl;
}
/////////////////////////////////////////////////////////////
int& self_add(int& num) {
    num++;
    return num;
}

int main() {
    int a = 65535;
    int& ref_a = a;                         // ref_a作为a的引用

    /////////////////////////////////////////////////////////////////////
    // 别名机制，ref_a和a是同一个变量的不同名称
    cout << "a : " << a << endl;
    cout << "ref_a : " << ref_a << endl;
    cout << "&a : " << &a << endl;
    cout << "&ref_a : " << &ref_a << endl;
    /////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////
    // 操作ref_a就等于操作a
    int b = 100;
    ref_a = b;                              // 和a = b是一个道理
    cout << "b : " << b << endl;
    cout << "&b : " << &b << endl;
    cout << "a : " << a << endl;
    cout << "&a : " << &a << endl;
    cout << "&ref_a : " << &ref_a << endl;
    cout << "ref_a : " << ref_a << endl;
    /////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////
    // 引用代替二级指针修改指针的值
    int* p = nullptr;
    Modify_passval(p);
    cout << "p : " << p << endl;
    Modify_passref(p);
    cout << "p : " << p << endl;
    Modify_passptr(&p);
    cout << "p : " << p << endl;
    /////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////
    // const修饰的reference只能通过reference读取，不能修改
    string str = "Hello";
    const string& const_ref = "Hello";        // const 引用可以绑定在右值或者左值上
    string& str_ref = str;                    // 非const引用只能绑定在左值上    
    PrintString(str);                         // 函数内部不能修改str的值，是只读引用
    /////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////
    // 引用作为函数返回值
    int res = 199;
    int& ref_res = res;                         // ref_res作为res的引用 

    cout << "Before self_add : " << endl;
    cout << "res : " << res << endl;
    cout << "ref_res : " << ref_res << endl;
    cout << "&res : " << &res << endl;
    cout << "&ref_res : " << &ref_res << endl;

    cout << "&self_add(ref_res) : " << &self_add(ref_res) << endl;
    cout << "After self_add : " << endl;
    cout << "res : " << res << endl;
    cout << "ref_res : " << ref_res << endl;
    cout << "&res : " << &res << endl;
    cout << "&ref_res : " << &ref_res << endl;

    self_add(ref_res) += 1;
    cout << "After self_add(ref_res) += 1 : " << endl;
    cout << "res : " << res << endl;
    cout << "ref_res : " << ref_res << endl;

    return 0;
}
