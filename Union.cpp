#include <bits/stdc++.h>

using namespace std;

union udata {
    int a;
    double b;
    char c[23];
};

struct DataPacket {
    enum Type {INT_TYPE, FLOAT_TYPE} dataType;
    // 声明匿名共同体
    union {
        int intVal;         // 不需要浪费重复的空间
        float floatVal;
    };
};

int main() {
    udata data;
    
    // 共同体的大小，为成员变量中最大的那个成员变量的大小
    cout << "sizeof(data) : " << sizeof(data) << endl;

    // 三个成员变量占用同一块内存空间
    cout << &data.a << endl;
    cout << &data.b << endl;
    cout << &data.c << endl;

    // 联合体变量的值是最后一个赋值语句的值
    data.a = 100;
    // data.b = 8.8;
    strcpy(data.c, "TigerPepperAlice");
    cout << data.a << endl;
    cout << data.b << endl;
    cout << data.c << endl;

    DataPacket packet;
    packet.dataType = DataPacket::INT_TYPE;
    packet.intVal = 100;
    if(packet.dataType == DataPacket::INT_TYPE) 
        cout << "Stored as integer: " << packet.intVal << std::endl;
    else   
        std::cout << "This packet does not hold an integer." << std::endl;
    
    packet.dataType == DataPacket::FLOAT_TYPE;
    packet.floatVal = 3.14f;
    if(packet.dataType == DataPacket::FLOAT_TYPE) 
        cout << "Stored as floating point: " << packet.intVal << std::endl;
    else   
        std::cout << "This packet does not hold a floating point." << std::endl;
}
