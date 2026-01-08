// Copyright (c) 2025 Him
// Author: Him
// Date: 2025-08-23
// demo: 命名空间

/*
@ 命名空间（namespace）: 用于将一组标识符（变量、函数、类等）组织在一起，防止命名冲突
@ 让代码更容易维护，方便阅读
@ 命名空间可以相互嵌套
@ 命名空间可以用inline修饰，表示该命名空间中的内容是默认使用的
*/

#include <bits/stdc++.h>
using namespace std;

// inline 修饰的namespace是默认实现
namespace v2025 {
    // inline: version_1 被默认使用
    // 当一个命名空间（比如 v2025）被声明为 inline 时，
    // 它里面的所有成员（包括其他命名空间）都会被视为直接位于其父命名空间（在这里是全局命名空间）的成员。
    inline namespace version_1 {
        int add(int a, int b) {
            std::cout << "Calling version_1 add() , result is ";
            return a+b;
        }
        int multiply(int a, int b) {
            std::cout << "Calling version_1 multiply() , result is ";
            return a*b;         
        }
    }

    namespace version_2 {
        int add(int a, int b) {
            std::cout << "Calling version_2 add() , result is ";
            return a+b;
        }
        int multiply(int a, int b) {
            std::cout << "Calling version_2 multiply() , result is ";
            return a*b;         
        }
    }
}

int main() {
    int a=10, b=100;
    // 命名空间::子命名空间::函数 （显式指定完整限定名）
    cout << v2025::version_1::add(a, b) << endl;

    // 命名空间 + inline，默认使用含有inline的命名空间中的函数
    cout << v2025::add(a, 12340) << endl;

    // using namespace 可以改变 inline 对 v2025::version_1的默认效果
    using namespace v2025::version_2;          
    cout << add(b, 114514) << endl;

    return 0;
}