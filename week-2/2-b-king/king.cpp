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

int getCost(vector<vi>& mat, vi& pi) {
    int ans = 0;

    for (int i = 0; i < pi.size(); i++) {
        ans += mat[pi[i] - 1][pi[i + 1] - 1];
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int r, c;

    cin >> r >> c;

    int total = r * c;
    int king = ceil(r * 1.0 / 3.0) * ceil(c * 1.0 / 3.0);

    cout << (total - king) << endl;

    return 0;
}
