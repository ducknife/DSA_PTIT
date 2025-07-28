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
vector<string> vs;

struct node{
    string val;
    node *left, *right;
    node (string x){
        val = x;
        left = right = NULL;
    }
};

node *buildTree(string a[], int idx, int n){
    if (idx >= n) return NULL;
    node *root = new node(a[idx]);
    int m = 2 * idx + 1;
    int r = 2 * idx + 2;
    root->left = buildTree(a, m, n);
    root->right = buildTree(a, r, n);
    return root;
}

void postorder(node *root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        vs.push_back(root->val);
    }
}

bool isOperand(string s){
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int calc(){
    stack<int> st;
    for (int i = 0; i < vs.size(); i++){
        if (!isOperand(vs[i])){
            st.push(stoi(vs[i]));
        }
        else {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            if (vs[i] == "+") st.push(y + x);
            else if (vs[i] == "-") st.push(y - x);
            else if (vs[i] == "*") st.push(y * x);
            else st.push(y / x);
        }
    }
    return st.top();
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        vs.clear();
        int n; cin >> n;
        string a[n]; for (string &x : a) cin >> x;
        node *root = buildTree(a, 0, n);
        postorder(root);
        cout << calc();
        cout << endl;
    }
    return 0;
}