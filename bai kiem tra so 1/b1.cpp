#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int getFX(string s){
    sort(s.begin(), s.end(), greater<char>());
    return s[1] - '0';
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string a, b;
        cin >> a >> b;
        int l = stoi(a), r = stoi(b);
        int sum = 0;
        for (int i = l; i <= r; i++){
            sum += getFX(to_string(i));
        }
        cout << sum << endl;
    }
    return 0;
}