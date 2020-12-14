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
typedef pair<int, int> pii;

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

    int n, w;
    cin >> n >> w;

    vector<pii> items;

    for (int i = 0; i < n; i++) {
        int weight, value;

        cin >> weight >> value;

        items.push_back({weight, value});
    }

    sort(items.begin(), items.end(), [](pii& lhs, pii& rhs) {
        return lhs.first < rhs.first;
    });

    reverse(items.begin(), items.end());

    int totalValue = 0;
    vi candidates;

    for (int power = 0; power <= 30; power++) {
        int weight = 1 << power;

        while (!items.empty() && items.back().first == weight) {
            candidates.push_back(items.back().second);
            items.pop_back();
        }

        sort(candidates.begin(), candidates.end());

        if (weight & w) {
            if (!candidates.empty()) {
                totalValue += candidates.back();
                candidates.pop_back();
            }
        }

        vi newCandidates;

        while (candidates.size() >= 2) {
            int combinedVal = candidates.back();
            candidates.pop_back();
            combinedVal += candidates.back();
            candidates.pop_back();

            newCandidates.push_back(combinedVal);
        }

        if (candidates.size() >= 1) {
            newCandidates.push_back(candidates.back());
            candidates.pop_back();
        }

        candidates = newCandidates;
    }

    cout << totalValue << endl;

    return 0;
}
