#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

vector<string> res;

int main(){
    fio();
    /* ducknife */
    queue<string> q;
    set<string> se;
    q.push("0");
    q.push("2");
    while (!q.empty()){
        string x = q.front();
        q.pop();
        if (x.size() == 8){
            int d = stoi(x.substr(0, 2));
            int m = stoi(x.substr(2, 2));
            int y = stoi(x.substr(4, 4));
            if (d >= 2 && m <= 12 && m >= 2 && y >= 2000){
                string tmpx = "";
                tmpx += x.substr(0, 2);
                tmpx += "/";
                tmpx += x.substr(2, 2);
                tmpx += "/";
                tmpx += x.substr(4, 4);
                se.insert(tmpx);
            }
        }
        else {
            q.push(x + "2");
            q.push(x + "0");
        }
    }
    for (auto i : se) cout << i << endl;
    return 0;
}