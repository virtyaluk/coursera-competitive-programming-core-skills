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

    lli max = 100007, right = 0;
    lli s[max];

    memset(s, 0, sizeof(s));

    while (n--) {
        lli l, r;
        cin >> l >> r;

        s[l - 1]++;
        s[r]--;

        if (r > right) {
            right = r;
        }
    }

    for (lli i = 1; i <= right; i++) {
        s[i] += s[i - 1];
    }

    for (lli i = 0; i <= right; i++) {
        if (s[i]) {
            cout << (i + 1) << " " << s[i] << endl;
        }
    }

    return 0;
}
