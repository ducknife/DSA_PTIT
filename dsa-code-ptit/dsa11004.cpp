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
const int INF = 1e9;

struct node{
    int data;
    node *left;
    node *right;
    node (int x) : data(x), left(NULL), right(NULL){}
};

void level_order(node *root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node *top = q.front(); q.pop();
        cout << top->data << " ";
        if (top->left != NULL){
            q.push(top->left);
        }
        if (top->right != NULL){
            q.push(top->right);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        node *root = NULL;
        map<int, node*>mp;
        for (int i = 1; i <= n; i++){
            int u, v;
            char c;
            cin >> u >> v >> c;
            if (mp.find(u) == mp.end()){
                root = new node(u);
                mp[u] = root;
            }
            node *child = new node(v);
            if (c == 'L') mp[u]->left = child;
            else mp[u]->right = child;
            mp[v] = child;
        }
        level_order(root);
        cout << endl;
    }
    return 0;
}