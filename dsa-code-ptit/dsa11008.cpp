#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int depth[100005];

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};


void depthOfLeaf(node *root, int d){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL){
        depth[root->val] = d;
        return;
    }
    depthOfLeaf(root->left, d + 1);
    depthOfLeaf(root->right, d + 1);
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, node*> mp;
        node *root = NULL;
        for (int i = 1; i <= n; i++){
            int x, y; 
            char c;
            cin >> x >> y >> c;
            if (mp.find(x) == mp.end()){
                mp[x] = new node(x);
                if (root == NULL) root = mp[x];
            }
            if (mp.find(y) == mp.end()) mp[y] = new node(y);
            if (c == 'L') mp[x]->left = mp[y];
            else mp[x]->right = mp[y];
        }
        depthOfLeaf(root, 0);
        bool check = true;
        int level = -1;
        for (int i = 1; i <= 10005; i++){
            if (depth[i]){
                level = depth[i];
                break;
            }
        }
        for (int i = 1; i <= 10005; i++){
            if (depth[i] && depth[i] != level){
                check = false;
                break;
            }
        }
        if (check) cout << 1 << endl;
        else cout << 0 << endl;
        memset(depth, 0, sizeof(depth));
    }
    return 0;
}