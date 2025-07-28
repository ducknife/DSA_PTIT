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

node *insertNode(node *root, int x){
    if (!root) return new node(x);
    if (x < root->val) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

node *minNode(node *root){
    node *tmp = root;
    while (tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }
    return tmp;
}

node *deleteNode(node *root, int x){
    if (!root) return NULL;
    if (root->val < x){
        root->right = deleteNode(root->right, x);
    }
    else if (root->val > x){
        root->left = deleteNode(root->left, x);
    }
    else {
        if (root->left == NULL){
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL){
            node *tmp = root->left;
            delete root;
            return tmp;
        }
        else {
            node *tmp = minNode(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, tmp->val);
        }
    }
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
    int q; cin >> q;   
    node *root = NULL; 
    for (int i = 1; i <= q; i++){
        string s; cin >> s;
        int x; cin >> x;
        cout << "Query #" << i << ": ";
        if (s == "ins"){
            root = insertNode(root, x);
        }
        else {
            root = deleteNode(root, x);
        }
        preOrder(root);
        cout << endl;
    }
    return 0;
}