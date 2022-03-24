#include <iostream>

using namespace std;

class Node {
public:
    Node(int value): _value(value) {}
    Node(int value, Node* next): _value(value), _next(next) {}
public:
    int _value = 0;
    Node* _next = nullptr;
};

void print(Node* list) {
    for (; list != nullptr; list = list->_next) {
        cout << list->_value;
        if (list->_next != nullptr) {
            cout << "->";
        }
    }
    cout << endl;
}

Node* mergeByLoop(Node* first, Node* second) {
    Node* head = new Node(0);
    Node* tmp = head;
    for (; first != nullptr && second != nullptr; ) {
        if (first->_value < second->_value) {
            tmp->_next = first;
            first = first->_next;
        } else {
            tmp->_next = second;
            second = second->_next;
        }
        tmp = tmp->_next;
    }

    if (first != nullptr) {
        tmp->_next = first;
    }

    if (second != nullptr) {
        tmp->_next = second;
    }
    // 此处会有内存问题？
    return head->_next;
}

Node* mergeByRecursion(Node* first, Node* second) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;
    if (first->_value <= second->_value) {
        first->_next = mergeByRecursion(first->_next, second);
        return first;
    } else {
        second->_next = mergeByRecursion(first, second->_next);
        return second;
    }
}

int main() {
    Node* first = new Node(1, new Node(3, new Node(5, new Node(7, nullptr))));
    Node* second = new Node(2, new Node(4, new Node(6, new Node(8, nullptr))));
    print(first);
    print(second);
    // print(mergeByRecursion(first, second));
    print(mergeByLoop(first, second));
}