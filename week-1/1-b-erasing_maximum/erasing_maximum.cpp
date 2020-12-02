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
    int n, maxEl = INT_MIN, maxCount = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] == maxEl) {
            maxCount++;
        } else if (a[i] > maxEl) {
            maxEl = a[i];
            maxCount = 1;
        }
    }

    for (int i = 0, count = 0; i < a.size(); i++) {
        if (a[i] == maxEl) {
            count++;

            if (maxCount == 1) {
                a.erase(a.begin() + i);
                break;
            } else if (maxCount > 1 && count == 3) {
                a.erase(a.begin() + i);
                break;
            }
        }
    }

    for (int i = 0; i < a.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;

    return 0;
}