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
    int n, q; cin >> n >> q;
    int a[n]; for (int &x : a) cin >> x;
    stack<int> st;
    int res[n], dis[n];
    memset(res, -1, sizeof(res));
    memset(dis, 0, sizeof(dis));
    for (int i = 0; i < n; i++){
        while (!st.empty() && a[st.top()] < a[i]){
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = n - 1; i >= 0; i--){
        if (res[i] == -1) dis[i] = 0;
        else dis[i] = dis[res[i]] + 1;
    }
    while (q--){
        int x; cin >> x;
        cout << dis[x - 1] << endl;
    }
    return 0;                                                                                                                                          
}   