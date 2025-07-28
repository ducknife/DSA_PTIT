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
    node *root = new node(a[l]);
    int m = l + 1;
    while (m <= r && a[m] <= root->val) m++;
    root->left = buildTree(a, l + 1, m - 1);
    root->right = buildTree(a, m, r);
    return root;
}

int depthOfTree(node *root, int d){
    if (!root) return 0;
    if (root->left == NULL && root->right == NULL){
        return d;
    }
    return max(depthOfTree(root->left, d + 1),
    depthOfTree(root->right, d + 1));
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        node *root = buildTree(a, 0, n - 1);
        int depth = depthOfTree(root, 0);
        cout << depth << endl;
    }
    return 0;
}