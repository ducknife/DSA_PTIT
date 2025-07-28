#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second
#define fre(A) freopen(A".inp","r",stdin); freopen(A".out","w",stdout);
#define ii pair<int,int>
#define vt vector
const int N = 1e6 + 1;
int a[N], b[N], ar[N], sum = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //fre("ACM");
    int n;
    cin >> n;
    for(int i = 1; i <= 2 *n ; ++i){
        cin >> a[i] >> b[i];
        ar[i] = b[i] - a[i];
        sum += a[i];
    }
    sort(ar + 1, ar + 2 * n + 1);
    for(int i = 1; i <= n; ++i)
       sum += ar[i];
    cout << sum;
    return 0;
}
