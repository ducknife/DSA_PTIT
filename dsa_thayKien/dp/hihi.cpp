#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pob pop_back
const int MAX = 1005;
const int MOD = 1e9 + 7;
void solve(){
	int n; cin>> n;
	int x, y, z; cin>> x>> y>> z;
	
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[1] = x;
	for(int i = 2; i <= n; ++i){
		if(i % 2 == 0){
			dp[i] = min(dp[i/2] + z, dp[i-1] + x);
		}
		else dp[i] = min(dp[i-1] + x, dp[(i + 1)/2] + z + y);
	}
	cout<< dp[n]<< endl;
}
int main(){
	std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin>> t;
	while(t--){
		solve();
	}
	return 0;
}