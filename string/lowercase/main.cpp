#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

std::string tolowerAllianceName(const std::string& name) {
    auto new_name = name;
    std::transform(new_name.begin(), new_name.end(), new_name.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    return new_name;
}

int main() {
    std::string name = "Hello World!";
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){
        return std::tolower(c);
    });
    std::cout << name << std::endl;

    std::cout << tolowerAllianceName("ABC") << std::endl;
    std::cout << tolowerAllianceName("我是中国人A") << std::endl;
    std::cout << tolowerAllianceName("A我b是c中D国E人!") << std::endl;
    std::cout << tolowerAllianceName("不要熬夜") << std::endl;
    return 0;
}

