#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//mục tiêu: mỗi bước tìm K tổng nhỏ nhất đến hàng i;
const int N = 305;
int a[N][N];

signed main(){
    fio();
    int k; cin >> k;
    for (int i = 1; i <= k; i++){
        for (int j = 1; j <= k; j++){
            cin >> a[i][j];
        }
        sort(a[i] + 1, a[i] + k + 1);
    }
    vector<int> res;
    for (int i = 1; i <= k; i++) res.push_back(a[1][i]);
    for (int i = 2; i <= k; i++){
        priority_queue<int, vector<int>, greater<int>> q;
        for (int j = 1; j <= k; j++){
            for (int x : res){
                q.push(x + a[i][j]);
            }
        }
        res.clear();
        for (int i = 0; i < k; i++){
            res.push_back(q.top());
            q.pop();
        }
    }
    for (int i = 0; i < k; i++) cout << res[i] << " ";
    return 0;
}