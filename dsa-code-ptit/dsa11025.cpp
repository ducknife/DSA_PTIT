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

node* bs(int a[], int l, int r){
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    node *root = new node(a[mid]);
    root->left = bs(a, l, mid - 1);
    root->right = bs(a, mid + 1, r);
    return root;
}

void preorder(node *root){
    if (root){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        sort(a, a + n);
        node *root = bs(a, 0, n - 1);
        preorder(root);
        cout << endl;
    }
    return 0;
}