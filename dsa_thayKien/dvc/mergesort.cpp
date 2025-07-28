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

void merge(int a[], int l, int mid, int r){
    vector<int> left;
    vector<int> right;
    for (int i = l; i < mid; i++) left.push_back(a[i]);
    for (int i = mid + 1; i < r; i++) right.push_back(a[i]);
    
}

void mergeSort(int a[], int l, int r){
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}
int main(){
    fio();
    /* ducknife */

    return 0;
}