// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[1005];
// bool visited[1005];

// int n, target;
// vector<int> tmp;
// vector<vector<int>> res;

// void Try(int i, vector<int> a, int sum){
//     if (sum > target) return;
//     if (sum == target){
//         res.push_back(tmp);
//         return;
//     }
//     else {
//         for (int j = i; j < n; j++){
//             if (sum + a[j] <= target){
//                 tmp.push_back(a[j]);
//                 Try(j + 1, a, sum + a[j]);
//                 tmp.pop_back();
//             }
//         }
//     }
// }

// int sumOf(vector<int> tmp){
//     int sum = 0;
//     for (int x : tmp) sum += x;
//     return sum;
// }

// int main(){
//     fio();
//     /* ducknife */
//     int t; cin >> t;
//     while (t--){
//         res.clear();
//         int sum = 0; cin >> n;
//         vector<int> a(n);
//         for (int &x : a){
//             cin >> x;
//             sum += x;
//         }
//         target = sum / 2;
//         Try(0, a, 0);
//         sort(res.begin(), res.end());
//         bool check = false;
//         for (int i = 0; i < res.size() - 1; i++){
//             for (int j = i + 1; j < res.size(); j++){
//                 if (sumOf(res[i]) == sumOf(res[j]) && res[i].size() + res[j].size() == n){
//                     check = true;
//                     break;
//                 }
//             }
//             if (check){
//                 cout << "YES" << endl;
//             }
//         }
//         if (!check) cout << "NO" << endl;
//     }
//     return 0;
// }

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
        int sum = 0;
        int a[n]; 
        for (int &x : a){
            cin >> x;
            sum += x;
        }
        if (sum % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}