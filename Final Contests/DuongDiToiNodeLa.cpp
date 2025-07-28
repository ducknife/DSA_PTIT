#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 1000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int res = -1e9;

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = nullptr;
    }
};

int dfs(node *root, int cnt){
    if (!root) return 0;
    if (isPrime(root->val)) cnt++;
    if (root->left == NULL && root->right == NULL) return cnt;
    int cnt_left = dfs(root->left, cnt);
    int cnt_right = dfs(root->right, cnt);
    return max(cnt_left, cnt_right);
}


int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        res = -1e9;
        node *root = NULL;
        map<int, node*> mp;
        for (int i = 1; i <= n; i++){
            int x, y; char c;
            cin >> x >> y >> c;
            if (mp.find(x) == mp.end()){
                mp[x] = new node(x);
                if (!root) root = mp[x];
            }
            node *child = new node(y);
            if (c == 'L') mp[x]->left = child;
            else mp[x]->right = child;
            mp[y] = child;
        }
        cout << dfs(root, 0) << endl;
    }
    return 0;
}