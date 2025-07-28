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

struct  node
{
    string data;
    node *next;
    node (string x) : data(x), next(NULL) {}
};

void traverse(node *head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    fio();
    /* ducknife */
    node *head = NULL;
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        string x; cin >> x;
        /* them dau */
        node *new_node = new node(x);
        // new_node->next = head;
        // head = new_node;
        /* them cuoi */
        if (head == NULL){
            head = new_node;
        }
        else {
            node *tmp = head;
            while (tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = new_node;
        }
    }
    /* Chen truoc */
    // node *insertedNode = new node("5");
    // node *tmp = head;
    // while (tmp->next->data != "2"){
    //     tmp = tmp->next;
    // }
    // insertedNode->next = tmp->next;
    // tmp->next = insertedNode;
    /* Chen sau */
    // node *insertedNode = new node("5");
    // node *tmp = head;
    // while (tmp->next->data != "3"){
    //     tmp = tmp->next;
    // }
    // if (tmp->next->data == "3"){
    //     insertedNode->next = tmp->next->next;
    //     tmp->next->next = insertedNode;
    // }

    /* xoa dau */
    // node *tmp = head;
    // head = tmp->next;

    /* xoa cuoi */
    // node *tmp = head;
    // while (tmp->next->next != NULL){
    //     tmp = tmp->next;
    // }
    // tmp->next = NULL;

    /* xoa giua */
    node *tmp = head;
    while (tmp->next->data != "3"){
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
    traverse(head);
    return 0;
}