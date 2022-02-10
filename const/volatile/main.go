#include <iostream>

using namespace std;

// 如果不加 volatile，程序执行会 coredump
const volatile int VALUE = 1024;

int main() {
    int* ptr = (int*)(&VALUE);
    cout << VALUE << endl;
    *ptr = 2048;
    cout << VALUE << endl;
    cout << "hello" << endl;
    return 0;
}
