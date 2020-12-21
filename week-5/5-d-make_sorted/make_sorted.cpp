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

    int n;
    cin >> n;

    vi A;
    copy_n(istream_iterator<int>(cin), n, back_inserter(A));

    int m = *max_element(A.begin(), A.end());
    vvi dp(n + 1, vi(m + 1));

    for (int i = 1; i <= n; i++) {
        int best = INF;

        for (int j = 0; j <= m; j++) {
            best = min(best, dp[i - 1][j]);
            dp[i][j] = best + abs(A[i - 1] - j);
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;

    return 0;
}
