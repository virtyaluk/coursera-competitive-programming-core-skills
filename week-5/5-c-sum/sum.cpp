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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
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

    int S, L, ans = 0;
    cin >> S >> L;

    if (S == 0) {
        cout << int(L == 1) << endl;
    } else {
        vvll dp(L + 1, vll(S + 1));

        for (int i = 1; i <= L; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= min(S, 9); j++) {
            dp[1][j] = 1;
        }

        for (int i = 2; i <= L; i++) {
            for (int j = 1; j <= S; j++) {
                for (int d = int(i == L); d <= 9; d++) {
                    if (j - d >= 0) {
                        dp[i][j] += dp[i - 1][j - d];
                    }
                }
            }
        }

        cout << dp[L][S] << endl;
    }

    return 0;
}
