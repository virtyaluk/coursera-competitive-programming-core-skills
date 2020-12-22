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

    vi A, B;
    copy_n(istream_iterator<int>(cin), n, back_inserter(A));
    copy_n(istream_iterator<int>(cin), n, back_inserter(B));

    vvi dp(n + 1, vi(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][n];
    vi seqA(len), seqB(len);

    for (int i = n, j = n, k = len - 1; i > 0 && j > 0;) {
        if (A[i - 1] == B[j - 1]) {
            seqA[k] = i - 1;
            seqB[k] = j - 1;
            i--;
            j--;
            k--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        }
    }

    cout << dp[n][n] << endl;
    copy(seqA.begin(), seqA.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(seqB.begin(), seqB.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
