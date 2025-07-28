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

struct node {
    ll val;
    node *left, *right;
    node (ll x){
        val = x;
    }
};

node *buildTree(ll a[], int l, int r){
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    node *root = new node(a[mid]);
    root->left = buildTree(a, l, mid - 1);
    root->right = buildTree(a, mid + 1, r);
    return root;
}

void postorder(node *root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        ll a[n]; for (ll &x : a) cin >> x;
        sort(a, a + n);
        node *root = buildTree(a, 0, n - 1);
        postorder(root);
        cout << endl;
    }
    return 0;
}