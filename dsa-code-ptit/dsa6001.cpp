#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        sort(a, a + n);
        int l = 0, r = n - 1;
        for (int i = 0; i < n / 2; i++){
            cout << a[n - 1 - i] << " " << a[i] << " ";
        }
        if (n % 2) cout << a[n / 2];
        cout << endl;
    }
    return 0;   
}


#include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[1005];
// bool visited[1005];

// int main(){
//     fio();
//     /* ducknife */
//     int t; cin >> t;
//     while (t--){
//         int n; cin >> n;
//         int a[n]; for (int &x : a) cin >> x;
//         sort(a, a + n);
//         int l = 0, r = n - 1;
//         while (l <= r){
//             if (l == r){
//                 cout << a[l];
//             }
//             else {
//                 cout << a[r] << " " << a[l] << " ";
//                 r--; l++;
//             }
//         }
//         cout << endl;
//     }
//     return 0;   
// }