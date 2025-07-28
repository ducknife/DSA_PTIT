#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string Y_TUONG = R"(
1. Tại mỗi vị trí r (1 <= r <= N), ta coi nó là vị trí kết thúc của 1 cửa sổ.
2. Giới hạn cửa số là l sao cho r - l + 1 (độ dài cửa sổ) phải nằm trong đoạn [U, V]
3. Suy ra, U <= r - l + 1 <= V => r - V + 1 <= l <= r - U + 1 => r - V <= l - 1 <= r - U
4. Mục tiêu là tìm tổng liên tiếp lớn nhất trong các cửa sổ có kích thước nằm trong phạm vi [U, V] và kết thúc tại vị trí r
5. Tức là, ta cần tìm l sao cho prefix[r] - prefix[l - 1] lớn nhất, đồng nghĩa với việc tìm prefix[l - 1] nhỏ nhất
6. Khi r - U >= 0, là tại vị trí r, ta đã đạt được chiều dài tối thiểu là bằng U, khi đó ta sẽ kiểm tra như sau:
7. Nếu deque còn chưa rỗng và prefix[dq.back()] >= prefix[l - 1] thì ta xóa dq.back() vì ta cần đảm bảo dq luôn lưu tổng tăng dần
để khi ta lấy ra prefix[l - 1] min, ta chỉ cần lấy prefix[dq.front()] là được
8. Ta loại bỏ các phần tử nằm ngoài cửa sổ, bằng cách xóa các vị trí dq.front() < r - V, tức là nhỏ hơn cả giới hạn trái của phạm vi 
[U, V] và kết thúc tại vị trí r
9. Nếu dq không rỗng, ta cập nhật kết quả: res = max(res, prefix[r] - prefix[dq.front()]);
)";
signed main(){
    fio();
    int n, u, v; cin >> n >> u >> v;
    deque<int> dq;
    int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
    int pre[n];
    pre[0] = 0;
    int res = -1e9;
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }   
    for (int r = 1; r <= n; r++){
        if (r - u >= 0){
            while (!dq.empty() && pre[dq.back()] >= pre[r - u]){
                dq.pop_back();
            }
            dq.push_back(r - u);
        }
        while (!dq.empty() && dq.front() < r - v) dq.pop_front();
        if (!dq.empty()) res = max(res, pre[r] - pre[dq.front()]);
    }
    cout << res << endl;
    return 0;
}