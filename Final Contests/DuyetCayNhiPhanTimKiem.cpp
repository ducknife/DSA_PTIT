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

node *buildTree(node *root, int x){
    if (!root) return new node(x);
    if (x < root->val) root->left = buildTree(root->left, x);
    else if (x > root->val) root->right = buildTree(root->right, x);
    return root;
}

void preOrder(node *root){
    if (root){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        node *root = NULL;
        for (int i : a){
            root = buildTree(root, i);
        }
        preOrder(root);
        cout << endl;
    }
    return 0;
}