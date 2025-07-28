/* Count inversion */
#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
/* ban chat bai toan:
trong qua trinh sap xep tron (co tinh chat stable), nen khi sap xep thi 
nhung phan tu bi doi cho se thoa man i < j va a[i] > a[j] */
int merge(int a[], int l, int r, int mid){
    vector<int>left(a + l, a + mid + 1);
    vector<int>right(a + mid + 1, a + r + 1);
    int i = 0, j = 0, cnt = 0, k = l;
    while (i < left.size() && j < right.size()){
        if (left[i] <= right[j]){
            a[k++] = left[i++];
            cnt += j;
        }
        else {
            a[k++] = right[j++];
        }
    }
    while (i < left.size()){
        a[k++] = left[i++];
        cnt += j;
    }
    while (j < right.size()){
        a[k++] = right[j++];
    }
    return cnt;
}
int MergeSort(int a[], int l, int r){
    if (l == r) return 0;
    int mid = (l + r) / 2;
    return MergeSort(a, l, mid) + MergeSort(a, mid + 1, r) + merge(a, l, r, mid);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        cout << MergeSort(a, 0, n - 1) << endl;
    }
    return 0;
}