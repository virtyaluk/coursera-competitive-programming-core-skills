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
    int ans = -1, x, y, z;
    long long int res = 0;

    cin >> x >> y >> z;

    for (int i = 0; i <= 2000; i++) {
        if (res == z) {
            ans = i;
            break;
        }

        // `i` is odd - add `x`, `i` is even - subtract `y`
        res += ((i & 1) == 0) ? x : -y;
    }

    cout << ans << endl;

    return 0;
}
