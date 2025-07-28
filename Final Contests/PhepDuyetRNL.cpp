#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define pst pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

struct node{
    string val;
    node *left, *right;
    node (string x){
        val = x;
        left = right = NULL;
    }
};

node *buildTree(vector<string> &vs){
    queue<node*> q;
    node *root = new node(vs[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vs.size()){
        node *top = q.front(); q.pop();
        if (vs[i] != "N" && i < vs.size()){
            top->left = new node(vs[i]);
            q.push(top->left);
        }
        i++;
        if (vs[i] != "N" && i < vs.size()){
            top->right = new node(vs[i]);
            q.push(top->right);
        }
        i++;
    }
    return root;
}

void rnlOrder(node *root){
    if (root){
        rnlOrder(root->right);
        cout << root->val << " ";
        rnlOrder(root->left);
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s;
        getline(cin >> ws, s);
        vector<string> vs;
        stringstream ss(s);
        string x;
        while (ss >> x){    
            vs.push_back(x);
        }
        node *root = buildTree(vs);
        rnlOrder(root);
        cout << endl;
    }
    return 0;
}