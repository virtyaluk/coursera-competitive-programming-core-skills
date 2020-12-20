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

    vector<ll> A, ans, pref(n + 1), suf(n + 1);

    copy_n(istream_iterator<ll>(cin), n, back_inserter(A));

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + A[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + A[i];
    }

    lli sum = pref[n];

    for (int i = 1; i <= n; i++) {
        pref[i] = min(pref[i], pref[i - 1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = min(suf[i], suf[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        ans.push_back(sum - pref[i] - suf[i + 1]);
    }

    copy(ans.begin(), ans.end(), ostream_iterator<ll>(cout, " "));
    cout << endl;

    return 0;
}
