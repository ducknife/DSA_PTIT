// #include <bits/stdc++.h>
// using namespace std;

// int maxDiffForPair(const string& s, char x, char y) {
//     vector<int> arr;
//     // Chỉ lấy các ký tự x hoặc y, gán +1 cho x, -1 cho y
//     for (char c : s) {
//         if (c == x) arr.push_back(1);
//         else if (c == y) arr.push_back(-1);
//     }
//     int maxSum = INT_MIN;
//     int curSum = 0;
//     bool hasX = false, hasY = false;
//     int res = 0;

//     for (int val : arr) {
//         if (curSum + val < val) {
//             curSum = val;
//             hasX = (val == 1);
//             hasY = (val == -1);
//         } else {
//             curSum += val;
//             if (val == 1) hasX = true;
//             if (val == -1) hasY = true;
//         }
//         if (hasX && hasY && curSum > maxSum) {
//             maxSum = curSum;
//         }
//     }
//     if (maxSum == INT_MIN) return 0;
//     return maxSum;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N; cin >> N;
//     string S; cin >> S;

//     // Tìm các ký tự xuất hiện
//     vector<bool> appeared(26, false);
//     for (char c : S) appeared[c - 'a'] = true;

//     int ans = 0;
//     vector<int> chars;
//     for (int i = 0; i < 26; i++) {
//         if (appeared[i]) chars.push_back(i);
//     }

//     for (int i = 0; i < (int)chars.size(); i++) {
//         for (int j = i+1; j < (int)chars.size(); j++) {
//             char x = chars[i] + 'a';
//             char y = chars[j] + 'a';

//             int res1 = maxDiffForPair(S, x, y);
//             int res2 = maxDiffForPair(S, y, x);
//             ans = max(ans, max(res1, res2));
//         }
//     }

//     cout << ans << "\n";
//     return 0;
// }
