#include <bits/stdc++.h>
using namespace std;

int countSubarraysWithSumK(vector<int> &a, int n, int k) {
    unordered_map<long long, int> freq;
    freq[0] = 1;
    long long sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (freq.count(sum - k)) {
            count += freq[sum - k];
        }
        freq[sum]++;
    }
    return count;
}

int main(){
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int &x : a) cin >> x;
        if (countSubarraysWithSumK(a, n, k)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}