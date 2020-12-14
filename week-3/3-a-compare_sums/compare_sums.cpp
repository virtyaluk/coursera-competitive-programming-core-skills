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

    vd first, second;
    copy_n(istream_iterator<double >(cin), n, back_inserter(first));
    copy_n(istream_iterator<double >(cin), n, back_inserter(second));

    double A = accumulate(first.begin(), first.end(), 0.0);
    double B = accumulate(second.begin(), second.end(), 0.0);
    double error = 1e-6;

    if (abs(A - B) < error) {
        cout << "SUM(A)=SUM(B)" << endl;
    } else if (A > B + error) {
        cout << "SUM(A)>SUM(B)" << endl;
    } else {
        cout << "SUM(A)<SUM(B)" << endl;
    }

    return 0;
}
