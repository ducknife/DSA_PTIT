#include <bits/stdc++.h>
using namespace std;

int a[100005], n;

string solve() {
    vector<int> digits(a, a + n);
    sort(digits.begin(), digits.end(), greater<int>());
    int sum = accumulate(digits.begin(), digits.end(), 0);
    vector<int> mod1, mod2;

    for (int x : digits) {
        if (x % 3 == 1) mod1.push_back(x);
        else if (x % 3 == 2) mod2.push_back(x);
    }

    if (sum % 3 == 1) {
        if (!mod1.empty()) digits.erase(find(digits.begin(), digits.end(), mod1.back()));
        else if (mod2.size() >= 2) {
           digits.erase(find(digits.begin(), digits.end(), mod2.back())); mod2.pop_back();
            digits.erase(find(digits.begin(), digits.end(), mod2.back()));
        } else return "-1";
    } else if (sum % 3 == 2) {
        if (!mod2.empty()) digits.erase(find(digits.begin(), digits.end(), mod2.back()));
        else if (mod1.size() >= 2) {
            digits.erase(find(digits.begin(), digits.end(), mod1.back())); mod1.pop_back();
            digits.erase(find(digits.begin (), digits.end(), mod1.back()));
        } else return "-1";
    }

    if (digits.empty()) return "-1";
    if (digits[0] == 0) return "0"; // toàn số 0

    string res;
    for (int d : digits) res += (d + '0');
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve() << '\n';
    }
    return 0;
}
