#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

class phanSo{
    public:
    int tu, mau;
    phanSo(){}
    phanSo (int a, int b){
        tu = a;
        mau = b;
    }
    static void rutGon(phanSo &a){
        int ucln = __gcd(a.tu, a.mau);
        a.tu /= ucln;
        a.mau /= ucln;
        if (a.mau < 0){
            a.mau *= -1;
            a.tu *= -1;
        }
    }
    friend phanSo operator + (phanSo a, phanSo b){
        phanSo res;
        res.mau = a.mau * b.mau;
        int hs1  = res.mau / a.mau;
        int hs2 = res.mau / b.mau;
        res.tu = a.tu * hs1 + b.tu * hs2;
        rutGon(res);
        return res;
    }   
    friend phanSo operator * (phanSo a, phanSo b){
        phanSo res;
        res.mau = a.mau * b.mau;
        res.tu = a.tu * b.tu;
        rutGon(res);
        return res;
    }
    void print(){
        cout << tu << "/" << mau;
    }
};

void mainProc(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    phanSo a(x1, y1);
    phanSo b(x2, y2);
    phanSo tmp1 = a + b;
    phanSo c = tmp1 * tmp1;
    phanSo tmp2 = a * b;
    phanSo d = tmp2 * c;
    c.print();
    cout << " ";
    d.print();
    cout << endl;
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        mainProc();
    }
    return 0;
}