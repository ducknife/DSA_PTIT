#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = prices[0]; 
        int maxProfit = 0;        
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};


int main(){
    fio();
    /* ducknife */
    Solution x;
    int n;
    vector<int> prices;
    while (cin >> n){
        prices.push_back(n);
    }
    cout << x.maxProfit(prices);
    return 0;
}