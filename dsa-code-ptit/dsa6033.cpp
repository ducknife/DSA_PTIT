//https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/ sua thanh > thi moi AC

/* For a given array arr[], 
   calculates the maximum j – i
   such that arr[j] > arr[i] */
   #include <bits/stdc++.h>
   using namespace std;
    
   int main()
   {
        int t; cin >> t;
        while (t--){
            int n; cin >> n;
            vector<long long int> v(n);
            for (int i = 0; i < n; i++) cin >> v[i];
            vector<long long int> maxFromEnd(n + 1, INT_MIN);
         
            // create an array maxfromEnd
            for (int i = v.size() - 1; i >= 0; i--) {
                maxFromEnd[i] = max(maxFromEnd[i + 1], v[i]);
            }
         
            int result = 0;
         
            for (int i = 0; i < v.size(); i++) {
                int low = i + 1, high = v.size() - 1, ans = i;
         
                while (low <= high) {
                    int mid = (low + high) / 2;
         
                    if (v[i] < maxFromEnd[mid]) {
                       
                        // We store this as current answer and look
                        // for further larger number to the right
                        // side
                        ans = max(ans, mid);
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
                // keeping a track of the
                // maximum difference in indices
                result = max(result, ans - i);
            }
            if (result == 0) cout << -1 << endl;
            else cout << result << endl;
        }

   }