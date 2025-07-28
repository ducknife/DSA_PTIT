#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

struct Matrix
{
    int n, m;
    vector<vector<int>> matrix;

    Matrix() {}

    Matrix(int n, int m) : n(n), m(m)
    {
        matrix.assign(n, vector<int>(m, 0));
    }

    void setMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }
};

Matrix mulMatrix(const Matrix &a, const Matrix &b)
{
    int n = a.n, p = a.m, m = b.m;
    Matrix c(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                c.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                c.matrix[i][j] %= MOD;
            }
        }
    }
    return c;
}

Matrix powMatrix(const Matrix &a, int k)
{
    if (k == 1)
        return a;

    Matrix res = powMatrix(a, k / 2);
    res = mulMatrix(res, res);

    if (k & 1)
        res = mulMatrix(res, a);
    return res;
}

void prepare()
{
}

void solve()
{
    int n, s, t, k;
    cin >> n >> s >> t >> k;

    Matrix ans(n, n);
    ans.setMatrix();

    ans = powMatrix(ans, k);

    cout << ans.matrix[s - 1][t - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prepare();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}