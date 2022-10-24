#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    std::string name = "Hello World!";
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    std::cout << name << std::endl;

    // std::string name1 = "Hello World!";
    // std::for_each(name1.begin(), name1.end(), std::tolower);
    // std::cout << name1 << std::endl;
    return 0;
}

