#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

int SumBT(node *root){
    if (!root) return 0;
    else return root->val;
    int sumLeft = SumBT(root->left);
    int sumRight = SumBT(root->right);
    return sumLeft + sumRight;
}

bool check(node *root){
    if (!root) return false;
    int sum = root->val;
    int sumLeft = SumBT(root->left);
    int sumRight = SumBT(root->right);
    if (sumLeft + sumRight == sum) return true;
    return check(root->left) && check(root->right);
}

signed main(){
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
                if (!root) root = mp[x];
            }
            node *child = new node(y);
            if (c == 'L') mp[x]->left = child;
            else mp[x]->right = child;
            mp[y] = child;
        }
        cout << check(root) << endl;
    }
    return 0;
}