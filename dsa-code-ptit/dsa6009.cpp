#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int NumOfTwoSum(vector<int> &a, int n, int k) {
    unordered_map<int, int> freq;
    int cnt = 0;
    for (int x : a) {
        cnt += freq[k - x]; // Nếu `k - x` đã xuất hiện trước đó
        freq[x]++;          // Cập nhật số lần xuất hiện của `x`
    }
    return cnt;
}

int NumOfTwoSumBS(vector<int> a, int n, int k){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int val = k - a[i];
        int first_pos = lower_bound(a.begin() + i + 1, a.end(), val) - a.begin();
        int last_pos = upper_bound(a.begin() + i + 1, a.end(), val) - a.begin();
        cnt += last_pos - first_pos;
    }
    return cnt;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());
        cout << NumOfTwoSum(a, n, k) << endl;
    }
    return 0;
}