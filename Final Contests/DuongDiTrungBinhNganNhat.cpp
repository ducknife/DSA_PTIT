#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e15;

ll C[505][505];
ll dp[505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Nhập ma trận trọng số, loại self-loop
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll x; cin >> x;
            C[i][j] = (i == j ? INF : x);
        }
    }

    // dp[k][v] = cost nhỏ nhất đến đỉnh v sau k bước
    for (int v = 0; v < n; ++v) dp[0][v] = 0;

    for (int k = 1; k <= n; ++k) {
        for (int v = 0; v < n; ++v) {
            dp[k][v] = INF;
            for (int u = 0; u < n; ++u) {
                if (dp[k - 1][u] < INF)
                    dp[k][v] = min(dp[k][v], dp[k - 1][u] + C[u][v]);
            }
        }
    }

    // Tìm chu trình có trung bình nhỏ nhất
    ll best_num = INF, best_den = 1;

    for (int v = 0; v < n; ++v) {
        if (dp[n][v] >= INF / 2) continue;

        ll max_num = -1, max_den = 1;
        for (int k = 0; k <= n - 2; ++k) {
            if (dp[k][v] >= INF / 2) continue;
            ll num = dp[n][v] - dp[k][v];
            ll den = n - k;

            if (max_num == -1 || num * max_den > max_num * den) {
                max_num = num;
                max_den = den;
            }
        }

        if (max_num != -1) {
            if (best_num == INF || max_num * best_den < best_num * max_den) {
                best_num = max_num;
                best_den = max_den;
            }
        }
    }

    ll g = __gcd(best_num, best_den);
    cout << (best_num / g) << '/' << (best_den / g) << '\n';
    return 0;
}
