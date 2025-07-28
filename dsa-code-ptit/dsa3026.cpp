#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int n, s; cin >> n >> s;
    if ((n > 0 && s == 0) || s > n * 9) cout << "-1 -1";
    else {
        int min_digit[n], max_digit[n];
        int tmp = s;
        for (int i = 0; i < n; i++){
            if (s >= 9){
                max_digit[i] = 9;
                s -= 9;
            }
            else {
                max_digit[i] = s;
                s = 0;
            }
        }
        tmp--;
        for (int i = n - 1; i >= 0; i--){
            if (tmp >= 9){
                min_digit[i] = 9;
                tmp -= 9;
            }
            else {
                min_digit[i] = tmp;
                tmp = 0;
            }
        }
        min_digit[0]++;
        for (int i = 0; i < n; i++) cout << min_digit[i];
        cout << " ";
        for (int i = 0; i < n; i++) cout << max_digit[i];
    }
    return 0;
}