#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define endl "\n"
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int dep[10005];
bool checkInternal = true, checkDepthNode = true;

struct node{
    int val;
    node *left, *right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

void hasTwoNodes(node *root){
    if (!root) return;
    if (root->left == NULL && root->right != NULL || (root->left != NULL && root->right == NULL)){
        checkInternal = false;
        return;
    }
    hasTwoNodes(root->left);
    hasTwoNodes(root->right);
}

void depth(node *root, int d){
    if (!root) return;
    if (root->left == NULL && root->right == NULL){
        dep[root->val] = d;
        return;
    }
    depth(root->left, d + 1);
    depth(root->right, d + 1);
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        node *root = NULL;
        map<int, node*> mp;
        memset(dep, 0, sizeof(dep));
        for (int i = 1; i <= n; i++){
            int x, y;
            char c;
            cin >> x >> y >> c;
            if (mp.find(x) == mp.end()){
                mp[x] = new node(x);
                if (!root) root = mp[x];
            }
            node *child = new node(y);
            if (c == 'L') mp[x]->left = child;
            else mp[x]->right = child;
            mp[y] = child;
        }
        hasTwoNodes(root);
        depth(root, 0);
        int level = -1;
        for (int i = 1; i <= 10000; i++){
            if (dep[i]){
                level = dep[i];
                break;
            }
        }
        for (int i = 1; i <= 10000; i++){
            if (dep[i] && dep[i] != level){
                checkDepthNode = false;
                break;
            }
        }
        if (checkInternal && checkDepthNode) cout << "Yes" << endl;
        else cout << "No" << endl;
        checkDepthNode = checkInternal = true;
    }
    return 0;
}