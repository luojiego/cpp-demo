/*
 * =====================================================================================
 *
 *       Filename:  2-1-1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/11/2022 01:29:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

// 平台信息相关的宏越丰富，代码的多平台支持越准确
int main() {
    cout << "Standard Clib: " << __STDC_HOSTED__ << endl; // 1
    cout << "Standard C: " << __STDC__ << endl; // 1
    // gcc version 4.8.5 20150623 (Red Hat 4.8.5-44) (GCC) not has __STDC__VERSION__
    // cout << "C Standard version: " << __STDC__VERSION__ << endl;
    cout << "ISO/IEC " << __STDC_ISO_10646__ << endl; // 201103
}


