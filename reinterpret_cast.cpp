#include <bits/stdc++.h>

using namespace std;

// new_type a = reinterpret_cast<new_type>(expression)
// 等同于强制类型转换

enum DataType{
    INT,
    FLOAT,
    C_STRING
};

void processBuffer(void* buffer, DataType type) {
    if(buffer == nullptr) {
        cout << "Buffer is null " << endl;
        return;
    }
    switch(type) {
        case INT: {
            int* tmp = reinterpret_cast<int*>(buffer);
            cout << "Processing INT : " << *tmp << endl;
            break;
        }
        case FLOAT: {
            float* tmp = reinterpret_cast<float*>(buffer);
            cout << "Processing FLOAT : " << *tmp << endl;
            break;
        }
        case C_STRING: {
            const char* tmp = reinterpret_cast<const char*>(buffer);
            cout << "Processing C_STRING : " << *tmp << endl;
            break;
        }
        default: {
            cout << "Unknown Type ！ " << endl;
            break;
        }
    }

}

int main() {

    // const char* cstring = "12345";
    // cout << cstring;
    // 3. 在 main 函数中进行测试
    // --- Test Case 1: Integer ---
    int myInt = 12345;
    cout << "Original INT value: " << myInt << endl;
    // 将 myInt 的地址传递给 processBuffer
    processBuffer(&myInt, DataType::INT); 
    cout << "-------------------------" << endl;
    // --- Test Case 2: Float ---
    float myFloat = 98.76f;
    cout << "Original FLOAT value: " << myFloat << endl;
    // 将 myFloat 的地址传递给 processBuffer
    processBuffer(&myFloat, DataType::FLOAT);
    cout << "-------------------------" << endl;
    // --- Test Case 3: C String ---
    const char* myCString = "Hello, reinterpret_cast!";
    cout << "Original C_STRING value: " << myCString << endl;
    // 注意：myCString 本身是一个指针 (char*)，
    // 我们需要传递它的地址 (char**) 给 processBuffer，
    // 这样 processBuffer 内部才能正确地将其转换回 char*
    processBuffer(&myCString, DataType::C_STRING); 
    cout << "-------------------------" << endl;
    // --- Test Case 4: Null Buffer ---
    cout << "Testing null buffer:" << endl;
    processBuffer(nullptr, DataType::INT);
    cout << "-------------------------" << endl;
    // --- Test Case 5: Unknown Type ---
    cout << "Testing unknown type:" << endl;
    processBuffer(&myInt, static_cast<DataType>(99)); // 使用一个无效的枚举值
    cout << "-------------------------" << endl;
    return 0;

    return 0;
}