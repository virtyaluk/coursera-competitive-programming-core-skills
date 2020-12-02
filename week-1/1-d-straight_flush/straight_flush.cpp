/*
* Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
* Example: $ g++ -std=c++11 c++ source.cpp
*
* Author: Bohdan Shtepan
* GitHub: https://github.com/virtyaluk
* Site: https://modern-dev.com
*
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N = 5;

int main() {
    vector<string> cards;
    unordered_set<char> suits;

    copy_n(istream_iterator<string>(cin), N, back_inserter(cards));

    transform(cards.begin(), cards.end(), inserter(suits, suits.end()), [](string& card) { return card[1]; });

    function<vector<int>(bool)> getCardValues = [&](bool startFromAce, vector<int> vals = {}) {
        transform(cards.begin(), cards.end(), back_inserter(vals), [=](string& card) {
            char val = card[0];

            if (isalpha(val)) {
                switch (val) {
                    case 'A': return startFromAce ? 1 : 14;
                    case 'K': return 13;
                    case 'Q': return 12;
                    case 'J': return 11;
                    case 'T': return 10;
                }
            }

            return val - '0';
        });

        return vals;
    };

    function<bool(vector<int>)> isStraightHand = [=](vector<int> cardValues) {
        return N == *max_element(cardValues.begin(), cardValues.end()) - *min_element(cardValues.begin(), cardValues.end()) + 1;
    };

    vector<int> lo = getCardValues(true), hi = getCardValues(false);

    if (cards.size() == N && suits.size() == 1 && (isStraightHand(lo) || isStraightHand(hi))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
