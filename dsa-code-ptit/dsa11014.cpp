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
int sum = 0;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node (int x){
        left = right = NULL;
        val = x;
    }
};

void sumRightLeafs(Node *root){
    if (root == NULL) return;
    if (root->right && root->right->left == NULL && root->right->right == NULL){
        sum += root->right->val;
    }
    sumRightLeafs(root->left);
    sumRightLeafs(root->right);
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        sum = 0;
        Node *root = NULL;
        map<int, Node*>mp;
        for (int i = 1; i <= n; i++){
            int x, y;
            char c;
            cin >> x >> y >> c;
            if (mp.find(x) == mp.end()){
                mp[x] = new Node(x);
                if (!root) root = mp[x];
            }
            Node *child = new Node(y);
            if (c == 'L') mp[x]->left = child;
            else mp[x]->right = child;
            mp[y] = child;
        }
        sumRightLeafs(root);
        cout << sum << endl;
    }
    return 0;
}