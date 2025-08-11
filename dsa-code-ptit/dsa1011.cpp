#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n;
string s;


int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    int cnt = 1;
    while (t--){
        cin >> n >> s;
        cout << cnt++ << " ";
        if (!next_permutation(s.begin(), s.end())) cout << "BIGGEST" << endl;
        else {
            cout << s << endl;
        }
    }
    return 0;
}