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
int height;

struct node{
    int val;
    node *left;
    node *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

bool isPerfect(node* root, int depth, int level = 0) {
    if (!root) return true;
    if (!root->left && !root->right)
        return depth == level;

    if (!root->left || !root->right)
        return false;

    return isPerfect(root->left, depth, level + 1) &&
           isPerfect(root->right, depth, level + 1);
}

int treeDepth(node* node) {
    int d = 0;
    while (node) {
        d++;
        node = node->left;
    }
    return d;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, node*> mp;
        height = 0;
        node *root = NULL;
        for (int i = 1; i <= n; i++){
            int x, y;
            char c; cin >> x >> y >> c;
            if (mp.find(x) == mp.end()){
                mp[x] = new node(x);
                if (!root) root = mp[x];
            }
            node *child = new node(y);
            if (c == 'L') mp[x]->left = child;
            else mp[x]->right = child;
            mp[y] = child;
        }
        int d = treeDepth(root);
        cout << isPerfect(root, d) << endl;         
        height = 0;
    }
    return 0;
}