#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
int x[100];
vector<string> v;
int len, n;
void Try(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == len){
            string s = "";
            for (int i = 1; i <= len; i++) s.push_back(x[i] + '0');
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            if (n % 2){
                v.push_back(s + "0" + tmp);
                v.push_back(s + "1" + tmp);
            }
            else {
                v.push_back(s + tmp);
            }
        }
        else Try(i + 1);
    }
}
int main(){
    fio();
    /* ducknife */
    cin >> n;
    len = n / 2;
    Try(1);
    sort(v.begin(), v.end());
    for (auto i : v){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}