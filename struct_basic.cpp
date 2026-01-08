#include <bits/stdc++.h>
#pragma pack(1)    // 修改内存对齐的规则，”1“表示内存间无空隙
using namespace std;

struct st_girl {
    const char* name = "a";     // 结构体中的变量允许赋缺省值，c++ 11以上
    int age = 18;
    double weight;       
    char sex = 'x';
    bool yanzhi = false;
};

// 可以在定义结构体的时候定义结构体变量
struct triangle {
    double base;
    double height;
} tri1, tri2{5.0, 6.0};   // 定义时初始化

void tri1_init() {
    tri1.base = 3.0;
    tri1.height = 4.0;
}

void show_struct_trash(st_girl& in) {
    cout << "name: " << in.name << endl;
    cout << "age: " << in.age << endl;
    cout << "weight: " << in.weight << endl;        
    cout << "sex: " << in.sex << endl;
    cout << "yanzhi: " << in.yanzhi << endl;
}

int main() {
    st_girl girl;
    cout << "-----------------------------------------" << endl;    
    // 直接打印有垃圾数据
    show_struct_trash(girl);
    cout << "-----------------------------------------" << endl;

    /////////////////////////////////////////////////////////////
    // 赋值
    girl.name = "alice";
    girl.age = 18;
    girl.weight = 90;
    girl.sex = 'x';
    girl.yanzhi = true;
    cout << "girl.name = " << girl.name << endl;
    cout << "girl.age = " << girl.age << endl;
    cout << "girl.weight = " << girl.weight << endl;
    cout << "girl.sex = " << girl.sex << endl;
    cout << "girl.yanzhi = " << girl.yanzhi << endl;
    cout << "-----------------------------------------" << endl;

    // 初始化 ———— 全置0
    st_girl pepper;
    memset(&pepper, 0, sizeof(pepper));                     // 全0初始化——方法1 !!!! 非常重要
    bzero(&pepper, sizeof(pepper));                         // 全0初始化——方法2
    pepper.name = "pepper";                                 // 重新赋值
    cout << "pepper.name = " << pepper.name << endl;
    cout << "pepper.age = " << pepper.age << endl;
    cout << "pepper.weight = " << pepper.weight << endl;
    cout << "pepper.sex = " << pepper.sex << endl;
    cout << "pepper.yanzhi = " << pepper.yanzhi << endl;
    cout << "-----------------------------------------" << endl;

    ///////////////////////////////////////////////////////////
    // 初始化 ———— 初始化列表
    st_girl alice{"alice", 18, 90, 'x', true};     // 使用列表初始化对结构体变量初始化
    // st_girl alice{0};                           // 全0初始化方法1
    // st_girl alice = {};                         // 全0初始化方法2
    cout << "alice.name = " << alice.name << endl;
    cout << "alice.age = " << alice.age << endl;
    cout << "alice.weight = " << alice.weight << endl;
    cout << "alice.sex = " << alice.sex << endl;
    cout << "alice.yanzhi = " << alice.yanzhi << endl;
    cout << "-----------------------------------------" << endl;

    ///////////////////////////////////////////////////////////
    // 结构体变量的内存占用
    cout << "sizeof(int) : " << sizeof(int) << " Bytes "<< endl;
    cout << "sizeof(double) : " << sizeof(double) << " Bytes "<< endl;
    cout << "sizeof(char) : " << sizeof(char) << " Bytes "<< endl;
    cout << "sizeof(bool) : " << sizeof(bool) << " Bytes "<< endl;
    cout << "sizeof(st_girl) = " << sizeof(st_girl) << " Bytes "<< endl;
    cout << "sizeof(triangle) = " << sizeof(triangle) << " Bytes "<< endl;
    cout << "-----------------------------------------" << endl;

    // 结构体变量的复制
    st_girl girl2, girl1;
    girl2 = girl;
    memcpy(&girl1, &girl, sizeof(girl));
    cout << "girl2.name = " << girl2.name << endl;
    cout << "girl2.age = " << girl2.age << endl;
    cout << "girl2.weight = " << girl2.weight << endl;
    cout << "girl2.sex = " << girl2.sex << endl;
    cout << "girl2.yanzhi = " << girl2.yanzhi << endl;

    cout << "girl1.name = " << girl1.name << endl;
    cout << "girl1.age = " << girl1.age << endl;
    cout << "girl1.weight = " << girl1.weight << endl;
    cout << "girl1.sex = " << girl1.sex << endl;
    cout << "girl1.yanzhi = " << girl1.yanzhi << endl;
    cout << "-----------------------------------------" << endl;

    // 动态分配内存
    st_girl* ptr = new st_girl{" ", 5, 60, 'y', true};
    ptr->name = "tiger";
    cout << "ptr->name = " << ptr->name << endl;
    cout << "ptr->age = " << ptr->age << endl;
    cout << "ptr->weight = " << ptr->weight << endl;
    cout << "ptr->sex = " << ptr->sex << endl;
    cout << "ptr->yanzhi = " << ptr->yanzhi << endl;
    delete ptr;

    return 0;
}
