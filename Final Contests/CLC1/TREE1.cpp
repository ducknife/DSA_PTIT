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
        left = right = NULL;
        val = x;
    }
};

node *buildTree(node *root, vector<int> &a){
    queue<node*> q;
    root = new node(a[0]);
    q.push(root);
    int i = 1;
    while (!q.empty()){
        node *top = q.front(); q.pop();
        if (i < a.size() && top->left == NULL){
            top->left = new node(a[i]);
            q.push(top->left);
        }
        i++;
        if (i < a.size() && top->right == NULL){
            top->right = new node(a[i]);
            q.push(top->right);
        }
        i++;
    }
    return root;
}

void inOrder(node *root){
    if (root){
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        node *root = NULL;
        root = buildTree(root, a);
        inOrder(root);
        cout << endl;
    }   
    return 0;
}