#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

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
    node *tmp = head;
    while (tmp->next != NULL){
        tmp  = tmp->next;
    }
    tmp->next = new_node;
}

void print_list(node *head){
    node *tmp = head;
    while (tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void remove_duplicates(node *&head){
    if (head == NULL) return;

    set<int> seen;  // Sử dụng set để lưu các phần tử đã gặp
    node *tmp = head;
    node *prev = NULL;

    while (tmp != NULL){
        if (seen.find(tmp->data) != seen.end()) {  // Nếu phần tử đã có trong set, xóa
            prev->next = tmp->next;
            delete tmp;
            tmp = prev->next;
        } else {  // Nếu phần tử chưa gặp, thêm vào set và tiếp tục
            seen.insert(tmp->data);
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

int main(){
    fio();
    int n; cin >> n;
    node *head = NULL;
    
    // Đọc vào danh sách các phần tử
    while (n--){
        int x; cin >> x;
        add_last(head, x);
    }

    // Lọc bỏ các phần tử trùng lặp
    remove_duplicates(head);
    
    // In ra danh sách sau khi lọc
    print_list(head);
    
    return 0;
}
