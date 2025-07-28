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

struct node
{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

void postOrder(node *root){
    if (root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

node* insertNode(node *root, int x){
    if (!root) return new node(x);
    else if (x < root->val) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    for (int i = 1; i <= t; i++){
        int n; cin >> n;
        node *root = NULL;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            root = insertNode(root, a[i]);
        }
        cout << "Test #" << i << ": ";
        postOrder(root);
        cout << endl;
    }
    return 0;
}