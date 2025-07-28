#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    string s; cin >> s;
    int n = s.size();
    vector<int> tail, a;
    for (char i : s){
        a.push_back(i - 64);
    }
    for (int i = 0; i < n; i++){
        int x = a[i];
        // auto it = upper_bound(tail.begin(), tail.end(), x);
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()){
            tail.push_back(a[i]);
        }
        else {
            *it = a[i];
        }
    }
    cout << tail.size() << endl;
    return 0;
}