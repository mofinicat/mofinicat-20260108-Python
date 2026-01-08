// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-08-21
// demo：函数指针

#include <bits/stdc++.h>
using namespace std;

void func(int a) {
    cout << "func(int a) called with value: " << a << endl;
}

using FuncPtr = void(*)(int);   // 定义函数指针类型，C++-style, 函数指针的类型就是函数指针去掉标识符
typedef void(*FuncPtr)(int);    // 另一种定义方式， C-style

// 回调函数：以函数指针为参数的函数
void invoke_callback(FuncPtr cb, int val) {
    if(cb)  cb(val);
}

void invoke_callback2(void (*funcptr)(int), int val) {
    if(funcptr) funcptr(val);
}

int main() {
    ///////////////////////// 1. 用using或者typedef声明的函数指针类型调用函数 /////////////////////////
    FuncPtr fptr = func;            // 可以直接使用这个类型接收匹配的函数首地址
    void (*funcptr)(int) = func;    // 可以现场声明
    funcptr(1234);                  
    (*funcptr)(115123);             
    fptr(42);               // 通过函数指针调用 func
    (*fptr)(100);           // 也可以通过解引用调用

    ///////////////////////////// 2. 回调函数的使用 ///////////////////////////////
    // 函数名实际上是函数的首地址
    cout << "0x" << hex << reinterpret_cast<intptr_t>(func) << endl;           // std::intptr_t（这些类型专门用于保存指针的整数表示）
    invoke_callback2(func, 100);
    

    return 0;
}