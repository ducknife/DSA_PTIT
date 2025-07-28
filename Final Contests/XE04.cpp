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
int a[100005], n;

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};
//cach 1:
void inorder(int i){
    if (i >= n) return;
    inorder(2 * i + 1);
    cout << a[i] << " ";
    inorder(2 * i + 2);
}

void postorder(int i){
    if (i >= n) return;
    postorder(2 * i + 1);
    postorder(2 * i + 2);
    cout << a[i] << " ";
}

node* buildTree(int i){
    if (i >= n) return NULL;
    node *root = new node(a[i]);
    root->left = buildTree(2 * i + 1);
    root->right = buildTree(2 * i + 2);
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
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        node *root = buildTree(0);
        postorder(root);
        cout << endl;
    }
    return 0;
}