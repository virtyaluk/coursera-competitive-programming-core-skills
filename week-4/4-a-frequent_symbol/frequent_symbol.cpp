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

    string s;
    cin >> s;

    unordered_map<char, vector<int>> m;
    int n = s.size();

    for (char ch = 'a'; ch <= 'z'; ch++) {
        m[ch].resize(n + 1, 0);
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == ch) {
                m[ch][i] = m[ch][i - 1] + 1;
            } else {
                m[ch][i] = m[ch][i - 1];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        char ans;
        int len = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int newLen = m[ch][r] - m[ch][l - 1];

            if (newLen > len) {
                len = newLen;
                ans = ch;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
