/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
* Example: $ g++ -std=c++11 c++ source.cpp
*
* Author: Bohdan Shtepan
* GitHub: https://github.com/virtyaluk
* Site: https://modern-dev.com
*
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = all_of(s.begin(), s.end(), [](char &ch) {
        return ch == '9';
    }) ? s.size() + 1 : s.size();

    cout << n << endl;

    return 0;
}
