#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

char x;
string tmp;
vector<string> res;
int n;
bool used[1005];

bool check(string s){
    for (int i = 1; i < s.size() - 1; i++){
        if ((s[i] == 'A' || s[i] == 'E') && s[i - 1] != 'A' && s[i - 1] != 'E' && s[i + 1] != 'E' && s[i + 1] != 'A'){
            return false;
        }
    }
    return true;
}

void Try(int i){
    if (tmp.size() == n){
        if (check(tmp)) cout << tmp << endl;
        return;
    }
    else {
        for (int j = 1; j <= n; j++){
            if (!used[j]){
                used[j] = true;
                tmp.push_back(char(j + 64));
                Try(j + 1);
                tmp.pop_back();
                used[j] = false;
            } 
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> x;
    n = int(x) - 64;
    Try(1);
    return 0;
}