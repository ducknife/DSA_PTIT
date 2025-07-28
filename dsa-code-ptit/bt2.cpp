#include <bits/stdc++.h>
using namespace std;
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct node{
    int val;
    node *left, *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

void skibidi(node *root){
    queue<node*> q;
    q.push(root);
    while (!q.empty()){
        node *top = q.front(); q.pop();
        cout << top->val << ' ';
        if (top->left != NULL){
            q.push(top->left);
        }
        if (top->right != NULL){
            q.push(top->right);
        }
    }
}

int main(){
    fio();
    int t; cin >> t;
    while (t--){
        map<int, node*> mp;
        node *root = NULL;
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            int x, y; 
            char c;
            cin >> x >> y >> c;
            if (mp.find(x) == mp.end()){
                mp[x] = new node (x);
                if (!root) root = mp[x];
            }
            node *child = new node(y);
            if (c == 'L') mp[x]->left = child;
            else mp[x]->right = child;
            mp[y] = child;
        }
        skibidi(root);
        cout << endl;
    }
    return 0;
}