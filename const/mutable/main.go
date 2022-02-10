#include <iostream>

using namespace std;

class Test {
private:
    mutable int age;
public:
    Test() : age(0) {}
    int getAge() const { age += 1; return age; }
};

int main() {
	Test t;
    cout << t.getAge() << endl;
}
