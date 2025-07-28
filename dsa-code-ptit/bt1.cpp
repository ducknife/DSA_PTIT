#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
vector<int> a;

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

bool search(node *root, int key){
    if (!root) return false;
    if (root->val == key){
        return true;
    }
    return search(root->left, key) || search(root->right, key);
}

node *buildTree(int i, int a[]){
    if (i >= n) return NULL;
    node *root = new node(a[i]);
    root->left = buildTree(2 * i + 1, a);
    root->right = buildTree(2 * i + 2, a);
    return root;
}

void preOrder(node *root){
    if (root){
        cout << root->val << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }
}

signed main(){
    fio();
    cin >> n;
    int a[n]; for (int &x : a) cin >> x;
    node *root = buildTree(0, a);
    preOrder(root);
    cout << endl;
    cout << search(root, 100);
    return 0;
}