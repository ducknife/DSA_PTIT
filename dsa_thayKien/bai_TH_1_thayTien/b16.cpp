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
    int n; cin >> n;
    int a[n]; for (int &x : a) cin >> x;
    int ti = 0, teo = 0, cnti = 0;
    int i = 0, j = n - 1;
    while (i <= j){
        if (cnti % 2 == 0){
            if (a[i] >= a[j]){
                ti += a[i];
                i++;
            }
            else {
                ti += a[j];
                j--;
            }
            cnti++;
        }
        else {
            if (a[i] >= a[j]){
                teo += a[i];
                i++;
            }
            else {
                teo += a[j];
                j--;
            }
            cnti++;
        }
    }
    cout << ti << " " << teo;
    return 0;
}