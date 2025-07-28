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
    ll val;
    node *left, *right;
    node (ll x){
        val = x;
        left = right = NULL;
    }
};

node* buildTree(ll a[], int l, int r){
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    node *root = new node(a[mid]);
    root->left = buildTree(a, l, mid - 1);
    root->right = buildTree(a, mid + 1, r);
    return root;
}

int countLeaves(node *root){
    if (!root) return 0;
    int count = 0;
    if (root->left == NULL && root->right == NULL){
        count++;
    }
    count += countLeaves(root->left);
    count += countLeaves(root->right);
    return count;
}

void inorder(node *root){
    if (root){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
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
        int res = countLeaves(root);
        cout << res << endl;
    }   
    return 0;
}