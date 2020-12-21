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
typedef vector<vi> vvi;
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

    string _, u, w;
    int I, D, S, n, m;

    cin >> _ >> _ >> u >> w;
    cin >> I >> D >> S;

    m = u.size();
    n = w.size();
    vvi dp(m + 1, vi(n + 1));

    for (int i = 1; i <= m; i++) {
        dp[i][0] = i * D;
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = j * I;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min({
               dp[i - 1][j - 1] + (u[i - 1] == w[j - 1] ? 0 : S),
               dp[i][j - 1] + I,
               dp[i - 1][j] + D
            });
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}
