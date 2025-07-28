#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;
int n;
void backtrack(int start,int sum,vector<int> &a, vector<int> &b, set<string> &res) {
    if(sum % 2 != 0) {
        string s;
        for (auto x : b) {
            s += to_string(x) + " ";
        }
        res.insert(s);  // Chỉ tạo s khi cần, tránh lỗi
    }
    
    for(int j=start;j<n;j++) {
        b.push_back(a[j]);
        backtrack(j+1,sum+a[j],a,b,res);
        b.pop_back();
    }
}


int main(){
    fio();
    int t;cin>>t;
    while(t--) {
        cin>>n;
        vector<int> a(n),b;
        set<string>res;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end(),greater<int> ());
        backtrack(0,0,a,b,res);
        for(auto &x:res){
            cout << x << endl;
        }
    }
    return 0;
}