#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

class Solution{
    private:
        string data;
    public:
        void HELLO_PTIT(string data){
            vector<string> tmp;
            string word;
            stringstream ss(data);
            int cnt = 0;
            while (ss >> word){
                cnt++;
                word[0] = toupper(word[0]);
                if (cnt == 2) for (char &x : word) x = toupper(x);
                tmp.push_back(word);
            }
            this->data = tmp[0] + " " + tmp[1] + ".";
        }
        string getDATA(){
            return data;
        }
};
int main(){
    fio();
    /* ducknife */
    Solution ducknife;
    ducknife.HELLO_PTIT("hello ptit");
    string res = ducknife.getDATA();
    cout << res;
    return 0;
} 