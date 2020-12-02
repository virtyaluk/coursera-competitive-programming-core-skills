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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    long long ans = 0;
    vi nums;

    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));

    vector<long long int> left(nums.size()), right(nums.size());
    stack<pair<int, int>> st1, st2;

    for (int i = 0; i < nums.size(); i++) {
        int count = 1;

        while (!st1.empty() && st1.top().first > nums[i]) {
            count += st1.top().second;
            st1.pop();
        }

        st1.push({nums[i], count});

        left[i] = count;
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
        int count = 1;

        while (!st2.empty() && st2.top().first >= nums[i]) {
            count += st2.top().second;
            st2.pop();
        }

        st2.push({nums[i], count});

        right[i] = count;
    }

    for (int i = 0; i < nums.size(); i++) {
        ans += nums[i] * left[i] * right[i];
    }

    cout << ans << endl;

    return 0;
}
