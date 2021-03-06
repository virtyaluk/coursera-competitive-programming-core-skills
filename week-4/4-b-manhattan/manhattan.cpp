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
#define lli long long int
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<double> vd;

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

    int n;
    cin >> n;

    int a = 1, b = 1, c = 1, d = 1, A = INT_MIN, B = INT_MAX, C = INT_MIN, D = INT_MAX;
    vi x(n), y(n), f(n), s(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        if (A < x[i] + y[i]) {
            A = x[i] + y[i];
            a = i + 1;
        }

        if (B > x[i] + y[i]) {
            B = x[i] + y[i];
            b = i + 1;
        }

        if (C < x[i] - y[i]) {
            C = x[i] - y[i];
            c = i + 1;
        }

        if (D > x[i] - y[i]) {
            D = x[i] - y[i];
            d = i + 1;
        }

        if (A - B > C - D) {
            f[i] = a;
            s[i] = b;
        } else {
            f[i] = c;
            s[i] = d;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << f[i] << " " << s[i] << endl;
    }

    return 0;
}
