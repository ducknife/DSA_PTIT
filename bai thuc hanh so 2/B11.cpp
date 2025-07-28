#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005][1005];

set<string> dict;
int n, m;
char a[1005][1005];
string word;

int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};


bool check;

void dfs(int i, int j, int cnt){
    visited[i][j] = true;
    cnt++;
    if (word[cnt] == 'q') cnt++;
    if (cnt == word.size()){
        check = true;
        return;
    }
    for (int k = 0; k < 8; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 0 && i1 < m && j1 >= 0 && j1 < m && !visited[i1][j1] && a[i1][j1] == word[cnt]){
            dfs(i1, j1, cnt);
        }
    }
    visited[i][j] = false;
}

signed main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 1; i <= n; i++){
        string x; cin >> x;
        dict.insert(x);
    }
    while (1){
        cin >> m;
        if (m == 0) break;
        vector<string> res;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++) cin >> a[i][j];
        }
        for (string w : dict){
            check = false;
            word = w;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < m; j++){
                    if (a[i][j] == word[0]){
                        dfs(i, j, 0);
                        if (check){
                            res.push_back(word);
                            break;
                        }
                    }
                    if (check) break;
                }
                if (check) break;
            }
        }
        for (string i : res) cout << i << endl;
    }
    return 0;
}