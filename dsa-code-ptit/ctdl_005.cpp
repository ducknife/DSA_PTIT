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

struct node{
    int data;
    node *next;
    node(int x) : data(x), next(NULL) {}
};

void add_last(node *&head, int x){
    node *new_node = new node(x);
    if (head == NULL){
        head = new_node;
        return;
    }
    if (head->next == NULL){
        head->next = new_node;
        return;
    }
    node *tmp = head;
    while (tmp->next != NULL){
        tmp  = tmp->next;
    }
    tmp->next = new_node;
}

void remove_first(node *&head){
    if (head == NULL) return;
    node *tmp = head;
    head = head->next;
    delete tmp;
}

void remove_last(node *&head){
    if (head == NULL) return;
    node *tmp = head;
    if (head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    delete tmp;
    tmp = NULL;
}

void remove(node *&head, int key){
    if (head == NULL) return;
    if (head->data == key){
        remove_first(head);
        return;
    }
    node *tmp = head;
    node *tmp1 = NULL;
    while (tmp->next != NULL && tmp->data != key){
        tmp1 = tmp;
        tmp = tmp->next;
    }
    if (tmp->next == NULL && tmp->data == key){
        remove_last(head);
    }
    else if (tmp->next == NULL) return;  
    else {
        tmp1->next = tmp->next;
        delete tmp;
    }
}

bool search_by_key(node *&head, int key){
    if (head == NULL) return false;
    node *tmp = head;
    while (tmp->next != NULL){
            if (tmp->data == key) return true;
        tmp = tmp->next;
    }
    return false;
}


int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    node *head = NULL;
    while (n--){
        int x; cin >> x;
        add_last(head, x);
    }
    int key; cin >> key;
    while (search_by_key(head, key)){
        remove(head, key);
    }
    node *tmp = head;
    while (tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    return 0;
}