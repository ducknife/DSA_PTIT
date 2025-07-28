#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

bool visited[12];
int w[12];
vector<vector<int>> tmp;
int ans = 1e9;

void Try(int idx){
    if (tmp.size() == 4){
        vector<int> s;
        for (auto i : tmp){
            int sum = 0;
            for (int j : i) sum += w[j];
            s.push_back(sum);
        }   
        int diff = *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end());
        ans = min(ans, diff);
        return;
    }
    for (int i = idx; i < 12; i++){
        if (visited[i]) continue;
        for (int j = i + 1; j < 12; j++){
            if (visited[j]) continue;
            for (int k = j + 1; k < 12; k++){
                if (visited[k]) continue;
                visited[i] = visited[j] = visited[k] = true;
                tmp.push_back({i, j, k});
                Try(idx + 1);
                tmp.pop_back();
                visited[i] = visited[j] = visited[k] = false;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    for (int &x : w) cin >> x;
    Try(0);
    cout << ans;
    return 0;
}