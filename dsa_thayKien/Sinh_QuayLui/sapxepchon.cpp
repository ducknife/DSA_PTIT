#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

void selectionsort(vector<int> &a, int n){
    int cnt = 0;
    for (int i = 0; i < n - 1; i++){
        int min_p = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[min_p]){
                min_p = j;
            }
        }
        swap(a[min_p], a[i]);
        cnt++;
        cout << "Buoc " << cnt << ": ";
        for (int i : a) cout << i << " ";
        cout << endl;
    }
}

int main(){
    fio();
    /* ducknife */

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    selectionsort(a, n);
    return 0;
}