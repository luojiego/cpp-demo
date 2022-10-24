#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSameEquipment(const std::string& last, const std::string& current) {
    if (last.empty() || current.empty()) {
        // 由于之前调用之前的逻辑已经判断过两者是否相同了
        // 所以此处不可能同时为 empty
        return false;
    }

    std::vector<std::string> last_vec, current_vec;

    int begin = 0;
    for (int i=begin; i<last.size(); i++) {
        if (last[i]=='|') {
            if (i-1 <= begin) {
                last_vec.push_back("");
                begin = i;
            } else {
                // cout << "(" << begin+1 << "," << i - begin -1 << ")" << endl;
                last_vec.push_back(last.substr(begin+1, i-begin-1));
                begin = i;
            }
        }
    }

    begin = 0;
    for (int i=begin; i<current.size(); i++) {
        if (current[i]=='|') {
            if (i-1 <= begin) {
                current_vec.push_back("");
                begin = i;
            } else {
                // cout << "(" << begin+1 << "," << i - begin -1 << ")" << endl;
                current_vec.push_back(current.substr(begin+1, i-begin-1));
                begin = i;
            }
        }
    }
    
    if (last_vec.size() != current_vec.size()) {
        cout << "1" << endl;
        return false;
    }

    for (int i = 0; i < last_vec.size(); i++) {
        if (last_vec[i].empty() == false) {
            if (last_vec[i] == current_vec[i]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // string s = "|||A|B|";
    string last = "|||2d943f3b-e1cc-40ed-9857-a6d36c368d9d|b9163e1bf85b5dda4e6ec7a471f92eaa|";
    string current = "|||2d943f3b-e1cc-40ed-9857-a6d36c368d9d|b9163e1bf85b5dda4e6ec7a471f92eaa|";
    string current1 = "||||b9163e1bf85b5dda4e6ec7a471f92eaa|";
    string current2 = "|||2d943f3b-e1cc-40ed-9857-a6d36c368d9d||";
    string current3 = "||||b9163e1bf85b5dda4e6ec7a471f92eaaa|";
    cout << std::boolalpha << isSameEquipment(last, current) << endl;
    cout << std::boolalpha << isSameEquipment(last, current1) << endl;
    cout << std::boolalpha << isSameEquipment(last, current2) << endl;
    cout << std::boolalpha << isSameEquipment(last, current3) << endl;
#if 0
    cout << "s.size() " << current.size() << endl;
    // cout << "s.substr(2,4): " << s.substr(2,4) << endl;
    // cout << "s.substr(4,6): " << s.substr(4,6) << endl;
    vector<string> v;
    int begin = 0;
    for (int i=begin; i<current.size(); i++) {
        if (current[i]=='|') {
            if (i-1 <= begin) {
                v.push_back("");
                begin = i;
            } else {
                cout << "(" << begin+1 << "," << i - begin -1 << ")" << endl;
                v.push_back(current.substr(begin+1, i-begin-1));
                begin = i;
            }
        }
    }

    cout << "s: " << current << endl;
    cout << "v.size(): " << v.size() << endl;
    for(auto iter = v.begin(); iter != v.end(); ++iter) {
        cout << (*iter).size() << ":" <<*iter << endl;
    }
#endif
    return 0;
}