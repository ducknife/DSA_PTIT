
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

string add(string a, string b){
    int lmax = max(a.size(), b.size());
    while (a.size() < lmax) a = "0" + a;
    while (b.size() < lmax) b = "0" + b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int nho = 0; string res = "";
    for (int i = 0; i < lmax; i++){
        int tmp = a[i] - '0' + b[i] - '0' + nho;
        res.push_back((tmp % 10) + '0');
        nho = tmp / 10;
    }
    if (nho) res.push_back(nho + '0');
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    fio();
    string a, b; cin >> a >> b;
    for (char &x : a) if (x == '6') x = '5';
    for (char &x : b) if (x == '6') x = '5';
    cout << add(a, b) << " ";
    for (char &x : a) if (x == '5') x = '6';
    for (char &x : b) if (x == '5') x = '6';
    cout << add(a, b);
    return 0;

}