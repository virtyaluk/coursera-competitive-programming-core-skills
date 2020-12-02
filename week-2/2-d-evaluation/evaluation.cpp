/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
* Example: $ g++ -std=c++11 c++ source.cpp
*
* Author: Bohdan Shtepan
* GitHub: https://github.com/virtyaluk
* Site: https://modern-dev.com
*
*/

#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
typedef vector<int> vi;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    long long ans = 0;
    int lastNum = 0, sign = 1;

    cin >> s;

    for (char ch: s) {
        if (ch == '+' || ch == '-') {
            ans += lastNum * sign;

            if (ch == '-') {
                sign = -1;
            } else {
                sign = 1;
            }

            lastNum = 0;
        } else {
            lastNum = lastNum * 10 + (ch - '0');
        }
    }

    ans += lastNum * sign;

    cout << ans << endl;

    return 0;
}
