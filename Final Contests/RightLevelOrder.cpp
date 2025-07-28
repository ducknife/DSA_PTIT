#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

vector<int> adj[1005];
bool visited[1005];

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = nullptr;
    }
};

node *buildTree(node *root, int x){
    if (!root) return new node(x);
    if (x < root->val) root->left = buildTree(root->left, x);
    else root->right = buildTree(root->right, x);
    return root;
}

void rightLevelOrder(node *root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node *top = q.front();
        q.pop();
        cout << top->val << " ";
        if (top->right != NULL){
            q.push(top->right);
        }
        if (top->left != NULL){
            q.push(top->left);
        }
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        node *root = new node(a[0]);
        for (int i = 1; i < n; i++){
            root = buildTree(root, a[i]);
        }
        rightLevelOrder(root);
        cout << endl;
    }
    return 0;
}