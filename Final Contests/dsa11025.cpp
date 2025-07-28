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
bool visited[1005];

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

node *buildTree(int a[], int l, int r){
    if (l > r) return NULL;
    int m = (l + r) / 2;
    node *root = new node(a[m]);
    root->left = buildTree(a, l, m - 1);
    root->right = buildTree(a, m + 1, r);
    return root;
}

void preOrder(node *root){
    if (root){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        sort(a, a + n);
        node *root = buildTree(a, 0, n - 1);
        preOrder(root);
        cout << endl;
    }
    return 0;
}