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
const int INF = 1e9;
map<int, int> mp;
int dp[100005];

void setup(){
    mp[0] = mp[6] = mp[9] = 6;
    mp[1] = 2;
    mp[2] = mp[3] = mp[5] = 5;
    mp[4] = 4;
    mp[7] = 3;
    mp[8] = 7;
}


int main(){
    fio();
    /* ducknife */
    setup();
    int n, k; cin >> n >> k;
    int a[k]; for (int &x : a) cin >> x;
    sort(a, a + k, greater<int>());
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 2; i <= 100000; i++){
        for (int j = 0; j < k; j++){
            if (i - mp[a[j]] >= 0 && dp[i - mp[a[j]]] >= 0){
                dp[i] = max(dp[i], dp[i - mp[a[j]]] + 1);
            }
        }
    }
    int now = n; // xét số que diêm hiện tại
    for (int i = dp[n]; i > 0; i--){ //in ra đủ dp[n] số
        for (int j = 0; j < k; j++){ // dãy sắp xếp giảm dần nên luôn đảm bảo tìm số lớn nhất
            if (now >= mp[a[j]] && dp[now - mp[a[j]]] + 1 == dp[now]){ //nếu độ dài tối ưu tạo bởi now - mp[a[j]] que diêm
                // mà chỉ cần cộng thêm 1 là bằng độ dài tối ưu tạo bởi now que thì ta in luôn a[j]
                //và giảm now đi 1 lượng mp[a[j]]
                cout << a[j];
                now -= mp[a[j]];
                break;
            }
        }
    }
    cout << endl;
    return 0;
}