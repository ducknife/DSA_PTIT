#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pob pop_back
#define fi first
#define se second
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, m;
vector<int> a(MAX, 0);
void solve(){
	cin>> n>> m;
	a = vector<int>(n, 0);
	for(int i = 0; i < n; ++i){
		cin>> a[i];
	}
	sort(a.begin(), a.end());
	int l = 0, r = 1e9, mid;
    int ans = 0;
	while(l <= r){
		int mid = (l+r)/2;
		int tmp = m;
		stack<int> st;
		int i = 0;
		while(i < n){
			if(st.empty() || a[i] - a[st.top()] >= mid){
				st.push(i);
				tmp--;
			}
			i++;
		}
		if(tmp > 0){
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout<< (l + r) / 2;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	while(t-- ){
		solve();
	}
}