#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
int sum = 0;

// Let T be a nonempty, full binary tree Then:

// If T has I internal nodes, the number of leaves is L = I + 1.
// This is known as the full binary tree theorem.

// Facts derived from the theorem:

// If T has I internal nodes, the total number of nodes is N = 2I + 1.
// If T has a total of N nodes, the number of internal nodes is I = (N – 1)/2.
// If T has a total of N nodes, the number of leaves is L = (N + 1)/2.
// If T has L leaves, the total number of nodes is N = 2L – 1.
// If T has L leaves, the number of internal nodes is I = L – 1. 

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

void countLeafNode(node *root){
    if (root == NULL) return;
    if (root->right == NULL && root->left == NULL){
        sum++;
        return;
    }
    countLeafNode(root->left);
    countLeafNode(root->right);
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        node *root = NULL;
        map<int, node*> mp;
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
        int numNode = mp.size();
        countLeafNode(root);
        if ((numNode + 1) % 2 == 0 && sum == (numNode + 1) / 2) cout << 1 << endl;
        else cout << 0 << endl;
        sum = 0;
    }
    return 0;
}