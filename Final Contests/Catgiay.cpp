#include <stdio.h>
#define ll long long

int main(){
    int t; scanf("%d", &t);
    while (t--){
        int w, h, n;
        scanf("%d%d%d", &w, &h, &n);
        int res = 1;
        bool check = false;
        ll area = 1ll * w * h;
        while (area % 2 == 0){
            area /= 2;
            res *= 2;
            if (res >= n) break;
        }
        if (res >= n) printf("YES");
        else printf("NO");
    }
    return 0;
}