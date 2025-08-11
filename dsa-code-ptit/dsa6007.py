

if __name__ == "__main__":
    t = int(input())
    for i in range(0, t):
        n = int(input())
        a = list(map(int, input().split()))
        b = sorted(a)
        fp, lp = -1, -1
        for i in range(0, n):
            if a[i] != b[i]:
                fp = i + 1;
                break
        for i in range(n - 1, -1, -1):
            if a[i] != b[i]:
                lp = i + 1
                break
                
        print(fp, lp)