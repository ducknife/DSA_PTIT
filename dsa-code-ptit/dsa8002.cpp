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
    int n; cin >> n;
    queue<int> q;
    string option;
    while (n--){
        cin >> option;
        if (option == "PUSH"){
            int x; cin >> x;
            q.push(x);
        }
        else if (option == "POP"){
            if (!q.empty()){
                q.pop();
            }
        }
        else {
            if (!q.empty()){
                cout << q.front() << endl;
            }
            else {
                cout << "NONE" << endl;
            }
        }
    }
    return 0;
}