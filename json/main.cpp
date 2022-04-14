/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  try JSON for Modern C++
 *
 *        Version:  1.0
 *        Created:  03/24/2022 04:26:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Roger (罗杰), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <json.hpp>
#include <iostream>
#include <cstdio>

using namespace std;
using json = nlohmann::json;

int main() {
    auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141, \"id\": 1 }");
    cout << j3 << endl;
    cout << "happy: " << j3["happy"] << endl;
    cout << "size: " << j3.size() << endl;
    auto t = j3["id"].type();
    printf("id type: %d\n", t);
    // cout << "happy type: " << t << endl;

    json j;
    j["name"] = "罗杰";
    j["age"] = 33;
    j["money"] = -10;
    j["number"] = 100;
    j["number2"] = 500000015399052129;
    j["phone"] = "15399052129";
    j["children"] = {"罗明灿", "罗灿宇"};
    j["data"] = {{"C++","Good"},{"Go","Greate"}};
    cout << "j.dump(): " << j.dump() << endl;
    cout << "j.dump(4): " << endl << j.dump(4) << endl;
    // cout << "j[\"money\"].type(): " << j["money"].type() << endl;
    // cout << j["money"].type() << endl;
    
    printf("age type: %d money type: %d number type: %d number2 type: %d\n", 
            j["age"].type(), j["money"].type(), j["number"].type(), j["number2"].type());
    /*
    auto result = json::parse(j.dump());
    cout << result["money"].type() << endl;
    */
    return 0;
}
